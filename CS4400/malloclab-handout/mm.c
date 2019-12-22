/*
This is a doubly linked explicit free list that does
a first fit scanning algorithm. A block is allocating by scanning through the free list and deleting the first block that is found to have a greater or equal size of the requested size in our paramater. If the block is too big, we split the block if the split part is big enouh to be a free block and then delete the other split. Then we change the header and footer of the block if we need to.

When freeing a block, we change the header and footer of that block to include an allocation bit. Freed blocks are put at the beginning of the list and if a freed block is next to a free block, we coalesce.

When reallocating, if we decrease the size and change the header and footer information. Otherwise when increasing, we call malloc with the new size and free the old block. If the size is the same then we just just keep the same block.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>

#include "mm.h"
#include "memlib.h"

/*********************************************************
 * NOTE TO STUDENTS: Before you do anything else, please
 * provide your identifying information in the following struct.
 ********************************************************/
team_t team = {
    /* Team name */
     "Sexy_Elbows",
    /* First member's full name */
    "Nathan Donaldson",
    /* First member's UID */
    "u0632803",
    /* Second member's full name (leave blank if none) */
    "",
    /* Second member's UID (leave blank if none) */
    ""
};

static void checkBlock(void *ptr);
static void printBlock(void *ptr);
static void *growHeap(size_t extend);
static void *coalesce(void *ptr);
static void place(void *ptr, size_t asize);
static void *findFit(size_t asize);
static void removeBlock(void *p);

#define DEBUG(dbg_printf, dbg_mm_checkheap)

#ifdef DEBUG
#define dbg_printf(...) printf(__VA_ARGS__)
#define dbg_mm_checkheap(...) mm_checkheap(__VA_ARGS__)
#else
#define eprintf(...)
#define mm_checkheap(...)
#endif


/* single word (4) or double word (8) alignment */
#define ALIGNMENT 8

/* rounds up to the nearest multiple of ALIGNMENT */
#define ALIGN(size) (((size) + (ALIGNMENT-1)) & ~0x7)


#define SIZE_T_SIZE (ALIGN(sizeof(size_t)))

#define Word_Size 4
#define Double_WSize 8
#define Init_Heap (1<<12)
#define Min_BlockSize 24
#define BUFFER  (1<<7) 

#define LISTS     20

#define Pack(size,alocbit) ((size) | (alocbit))

#define Read(ptr) (*(unsigned int *)(ptr))

#define Write(ptr,val) (*(unsigned int *)(ptr) = (val))

#define Get_Size(ptr) (Read(ptr) & ~0x7)

#define Get_Alloc(ptr) (Read(ptr) & 0x1)

#define Max(x,y) ((x) > (y) ? (x) : (y))

//#define Write_Addr (ptr,val) (*(int *(ptr) = (int)(long)(val))

#define Align(ptr) (((size_t)(ptr) + (ALIGNMENT - 1)) & ~0x7)

//#define Size_T (Align(sizeof(size_t)))

#define Head_Ptr(ptr) ((void *)(ptr) - Word_Size)

#define Foot_Ptr(ptr) ((void *)(ptr) + Get_Size(Head_Ptr(ptr)) - Double_WSize)

#define Next_Free_Ptr(ptr) (*( void **)(ptr + Double_WSize))

#define Prev_Free_Ptr(ptr) (*(void **)(ptr))

#define Next_Ptr(ptr) ((void *)(ptr) + Get_Size(Head_Ptr(ptr)))

#define Prev_Ptr(ptr) ((void *)(ptr) - Get_Size(Head_Ptr(ptr) - Word_Size))

static char *heap_P = 0;
static char *free_P;



/* 
 * mm_init - initialize the malloc package.
 * Grabs the heap space and aligns by padding and creating block to make sure payload is 4-byte aligned.
 */
int mm_init(void)
{

  free_P = heap_P;


  if((heap_P = mem_sbrk(4*Word_Size)) == (void *)-1)
    {
      return -1;
    }

  Write(heap_P,0);

  Write(heap_P + Word_Size, Pack(Double_WSize,1));

Write(heap_P + (2 * Word_Size), Pack(Double_WSize, 1));

Write(heap_P + (3 * Word_Size), Pack(0,1));

heap_P += (2 * Word_Size);

if(growHeap(Init_Heap/Word_Size) == NULL)
  {
    return -1;
  }

return 0;
}



/* 
 * mm_malloc - Allocate a block by incrementing the brk pointer.
 * Always allocate a block whose size is a multiple of the alignment.
 * The block size is calculated by taking the maximum size and the requesting size,
 * then searches the free list until we find somewhere to put it.
 * If no space was found, we ask for more memory and place at the beginning of new heap. 
 * 
 */
void *mm_malloc(size_t size)
{


  size_t asize;
  size_t extendsize;
  char *ptr;

  if(heap_P == 0)
    {
      mm_init();
    }
  
  if(size == 0)
    {
      return NULL;
    }

  if(size <= Double_WSize)
    {
      asize = 2*Double_WSize;
    }

  else
    {
      asize = Double_WSize * ((size + (Double_WSize) + (Double_WSize - 1)) / Double_WSize);
    }

      if((ptr = findFit(asize)) != NULL)
	{
	  place(ptr, asize);
	  return ptr;
	}
      
      extendsize = Max(asize, Init_Heap);
      if((ptr = growHeap(extendsize/Word_Size)) == NULL)
	{
	  return NULL;
	}
      place(ptr, asize);

      return ptr;
}

/*
 * mm_free - Adds a block to the free list. Using the pointer we set
the allocation bits to 0 in the header and footer then coalesce with blocks next to them.
 */
void mm_free(void *ptr)
{
  if(ptr == 0)
    {
      return 0;
    }

  size_t size = Get_Size(Head_Ptr(ptr));

  if(heap_P == 0)
    {
      mm_init();
    }

  Write(Head_Ptr(ptr), Pack(size,0));

  Write(Foot_Ptr(ptr), Pack(size,0));

  coalesce(ptr);
}

/*
* growHeap - Extends heap with a free block and returns the pointer
*We take the header of the first new block and overwrite the epilogue of previous heap space, then we add a new epilogue header in the new space. So we give a size to extend by and return the pointer to first pointer in new heap space.
*/
static void *growHeap(size_t extend)
{
  char *ptr;
  size_t size;

  size = (extend % 2) ? (extend + 1) * Word_Size : extend * Word_Size;
  
  if(size < Min_BlockSize)
    {
      size = Min_BlockSize;
    }

  if((long)(ptr = mem_sbrk(size)) == -1)
    {
      return NULL;
    }


  Write(Head_Ptr(ptr), Pack(size, 0));

  Write(Foot_Ptr(ptr), Pack(size, 0));

  Write(Head_Ptr(Next_Ptr(ptr)), Pack(0,1));

  return coalesce(ptr);
}


/*
 * mm_realloc - Decreases or increases the allocated block.
 * If the size is negative or 0 then we free the blocks.
 * If the size is the same , then just return the ptr.
 * If the size is less than old size, then we shrink the block.
 * We do this by changing the footer and header size.
 * If the new size is greater, we call malloc with the new size
 * and copy the old data and free the original block.
 */
void *mm_realloc(void *ptr, size_t size)
{
 void *newptr;
    size_t copySize;
    
    if(size == 0)
      {
	mm_free(ptr);
	  return 0;
      }

    if(ptr == NULL)
      {
	return mm_malloc(size);
      }

    newptr = mm_malloc(size);

    if(!newptr)
      {
	return 0;
      }

      copySize = Get_Size(Head_Ptr(ptr));

 if(size < copySize)
   {
     copySize = size;
   }
 memcpy(newptr, ptr, copySize);

	  mm_free(ptr);
	  return newptr;

}

/*
 coalesce - Joins blocks next to each other by finding the size of the new block and removing the free blocks from the free list. It then changes the header and footer infromation and add a new free block to front of list. Gets pointer to freed block and returns pointer to coalesced block.
*/

static void *coalesce(void *ptr)
{
  size_t prev;
  prev = Get_Alloc(Foot_Ptr(Prev_Ptr(ptr)));
  size_t next = Get_Alloc(Head_Ptr(Next_Ptr(ptr)));
  size_t size = Get_Size(Head_Ptr(ptr));

  if(prev && next)
    {
      return ptr;
    }

  else if(prev && !next)
    {
      size += Get_Size(Head_Ptr(Next_Ptr(ptr)));
      Write(Head_Ptr(ptr), Pack(size, 0));
      Write(Foot_Ptr(ptr), Pack(size, 0));
    }

  else if(!prev && next)
    {
      size += Get_Size(Head_Ptr(Prev_Ptr(ptr)));
      Write(Foot_Ptr(ptr), Pack(size, 0));
      Write(Head_Ptr(Prev_Ptr(ptr)), Pack(size, 0));
      ptr = Prev_Ptr(ptr);
    }

  else
    {
      size += Get_Size(Head_Ptr(Prev_Ptr(ptr))) + Get_Size(Foot_Ptr(Next_Ptr(ptr)));
      Write(Head_Ptr(Prev_Ptr(ptr)), Pack(size, 0));
      Write(Foot_Ptr(Next_Ptr(ptr)), Pack(size, 0));
      ptr = Prev_Ptr(ptr);
    }



  return ptr;

}

/*
* place - Places the block by comparing sizes. If the difference
* is at least the minimum block size, we split the block into an allocated block and free it as well. Otherwise we say it is allocated. 
*/

static void place(void *ptr, size_t asize)
{
  size_t fsize = Get_Size(Head_Ptr(ptr));

  if((fsize - asize) >= (2*Double_WSize))
    {
      Write(Head_Ptr(ptr), Pack(asize, 1));
      
      Write(Foot_Ptr(ptr), Pack(asize, 1));

      ptr = Next_Ptr(ptr);
      
      Write(Head_Ptr(ptr), Pack(fsize - asize, 0));
      
      Write(Foot_Ptr(ptr), Pack(fsize - asize, 0));

       coalesce(ptr);
    }

  else
    {
      Write(Head_Ptr(ptr), Pack(fsize, 1));

      Write(Foot_Ptr(ptr), Pack(fsize, 1));
      
    }
}


/*
 findFit - Find a fit for a block with size sent in. The function
* iterates through the free list and finds the first free block with a size greater or equal to the block size.
*/

static void *findFit(size_t asize)
{

  void *ptr;

  for(ptr = heap_P; Get_Size(Head_Ptr(ptr)) >  0; ptr = Next_Ptr(ptr))
    {
      if(!Get_Alloc(Head_Ptr(ptr)) && (asize <= Get_Size(Head_Ptr(ptr))))
	{
	  return ptr;
	}
    }
  return NULL;
}

/*
*Checks the previous and next pointers to see if they are within the heap. It also checks for alignment, headers, and footers.
*/

static void checkBlock(void *ptr)
{
// Reports if the next and prev pointers are within heap bounds
  if (Next_Free_Ptr(ptr)< mem_heap_lo() || Next_Free_Ptr(ptr) > mem_heap_hi())
{
   printf("Error: next pointer %p is not within heap bounds \n" , Next_Free_Ptr(ptr));
}
  if (Prev_Free_Ptr(ptr)< mem_heap_lo() || Prev_Free_Ptr(ptr) > mem_heap_hi())
{
   printf("Error: prev pointer %p is not within heap bounds \n", Prev_Free_Ptr(ptr));
}
/* Reports if there isn't 8-byte alignment by checking if the block pointer is divisible by 8.*/
if ((size_t)ptr % 8)
   {
     printf("Error: %p is not doubleword aligned\n", ptr);
   }

// Reports if the header information does not match the footer information
if (Read(Head_Ptr(ptr)) != Read(Foot_Ptr(ptr)))
  {
    printf("Error: header does not match footer\n");
  }
}

/*
* Prints out details of block as well as next and previous pointers if the block is fee.
*/

static void printBlock(void *ptr)
{
 int hsize, halloc, fsize, falloc;

 /* Basic header and footer information */
 hsize = Get_Size(Head_Ptr(ptr));
 halloc = Get_Alloc(Head_Ptr(ptr));
 fsize = Get_Size(Foot_Ptr(ptr));
 falloc = Get_Alloc(Foot_Ptr(ptr));

 if (hsize == 0) 
     {
       printf("%p: EOL\n", ptr);
        return;
     }
	
/* Prints out header and footer info if it's an allocated block.
 * Prints out header and footer info and next and prev info
 * if it's a free block.*/
 if (halloc)
   {
    printf("%p: header:[%d:%c] footer:[%d:%c]\n", ptr,hsize, (halloc ? 'a' : 'f'),fsize, (falloc ? 'a' : 'f'));
   }
 else
   {
     printf("%p:header:[%d:%c] prev:%p next:%p footer:[%d:%c]\n",ptr, hsize, (halloc ? 'a' : 'f'), Prev_Free_Ptr(ptr),Next_Free_Ptr(ptr), fsize, (falloc ? 'a' : 'f'));
   }
}

/*
* Checks the epilogue and prologue blocks for size and allocation bits. 
* Checks alignment for each block in free list and checks pointer bounds.
* Checks header/footer size and allocation bits.
*/

void mm_checkheap(int verbose) 
{
 void *ptr = heap_P; 

 if (verbose)
   {
     printf("Heap (%p):\n", heap_P);
   }
 
   if ((Get_Size(Head_Ptr(heap_P)) != Min_BlockSize) || !Get_Alloc(Head_Ptr(heap_P)))
     {
	printf("Bad prologue header\n");
	checkBlock(heap_P);
     }

   for (ptr = heap_P; Get_Alloc(Head_Ptr(ptr))==0; ptr = Next_Free_Ptr(ptr)) 
	{
	  if (verbose)
	    { 
	       printBlock(ptr);
	       checkBlock(ptr);
	    }
	}

    if (verbose)
      {
        printBlock(ptr);
      }

 if ((Get_Size(Head_Ptr(ptr)) != 0) || !(Get_Alloc(Head_Ptr(ptr))))
   {
     printf("Bad epilogue header\n");
   }
}


static void removeBlock(void *ptr)
{
 if(Prev_Free_Ptr(ptr))
   {
    Next_Free_Ptr(Prev_Free_Ptr(ptr)) = Next_Free_Ptr(ptr);
   }
 else
   {
    free_P = Next_Free_Ptr(ptr);
   }
 Prev_Free_Ptr(Next_Free_Ptr(ptr))= Prev_Free_Ptr(ptr);
}
