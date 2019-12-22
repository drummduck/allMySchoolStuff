//Nathan Donaldson/ndonalds
//CS4400 Lab3

#include "cachelab.h"
#include <math.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <stdint.h>

typedef unsigned long long int mem_add;


typedef struct  //All of the paramater of the cache.
{
  int s;  //number of set index bits(log2S)
  int b;  //number of block offset bits
  int S;  //number of cache sets
  int B;  //cache block size
  int E;  //number of blocks per set
  int C;  //cache capacity
  int t;  //number of tag bits(m-s-b)
  int m;  //number of main memory address bits

  int hits;
  int misses;
  int evicts;
}
  mem_stats;

typedef struct   //The line of the set.
{
  int LRU;
  int valid;
  int tag;
}
  set_line;

typedef struct   //The set of the cache.
{
  set_line *lines;
}
 cache_set;

typedef struct   //The whole cache.
{
  cache_set *sets;
}
  cache;

/*
Prints out information about the program.
 */
void help(char* argv[])    
{
  printf("Usage: %s [-hv] -s <num> -E <num> -b <num> -t <file>\n",argv[0]);
    printf("Options:\n");
    printf("  -h         Print this help message\n");
    printf("  -v         Optional verbose flag\n");
    printf("  -s <num>   Number of set index bits\n");
    printf("  -E <num>   Number of lines per set\n");
    printf("  -b <num>   Number of block offset bits\n");
    printf("  -t <file>  Trace file\n");
    printf("\n");
    printf("Examples:\n");
    printf("%s  linux>    ./csim-ref -s 4 -E 1 -b 4 -t traces/yi.trace\n",argv[0]);
    printf("%s  linux>    ./csim-ref -v -s 8 -E 2 -b 4 -t traces/yi.trace\n",argv[0]);
   
}

/*
This function is to allocate the space needed for the cache.
It also initializes all the variables in the cache.
 */
cache build(int num_sets, int num_lines)
{
  cache build_cache; //cache to return
  cache_set set;  //set to initianitialize then set equal to cache set line
  set_line line;

  int set_count;  //used with input so we create just enough space.
  int line_count;

  build_cache.sets = (cache_set *) malloc(sizeof(cache_set) * num_sets);   //allocates the space for the sets.

  for(set_count = 0; set_count < num_sets; set_count++)                  //for loop that allocates space needed for each line in the set.
    {
      set.lines = (set_line *) malloc(sizeof(set_line) * num_lines);
      build_cache.sets[set_count] = set;

      for(line_count = 0; line_count < num_lines; line_count++)         //for loop that initializes each line's information.
	{
	  line.LRU = 0;
	  line.valid = 0;
	  line.tag = 0;
	  set.lines[line_count] = line;
	}

    }
  
  return build_cache;
}

/*
This function calculates the tag and set index. It then uses those to find the
data we are looking for. It goes to the set we need and does three things: First,
it checks every valid line. If the valid line has the tag we are looking for, we 
have a hit. If no valid lines have the tag we are looking for, then we look for
a non-valid line(an empty line) and set the valid bit to 1 and update the tag. If 
there is no empty line, then we must evict the least recently used line and update
the tag.
 */
mem_stats calculate(mem_add address,cache test_cache,mem_stats stats, int v)
{

  int tag_size = (64 - (stats.b + stats.s));                   //Calculate tag and set index
  unsigned long long int tag = address >> (stats.b + stats.s);
  unsigned long long int temp = address << tag_size;
  unsigned long long int set_index = temp  >> (tag_size + stats.b);

  cache_set set;          //initialize some variables
  set_line line;
  set_line line_2;
  int max_LRU;
  int min_LRU_index;
  int min_LRU;
  
  set = test_cache.sets[set_index];    //Use the following set.
  
  int num_lines = stats.E;
  int line_counter;
  int inner_line_counter;

  for(line_counter = 0; line_counter < num_lines; line_counter++)  //This for loop checks for valid lines, if the valid line
    {                                                              //has a matching tag, then we have a hit. We update the LRU and return.
      line = set.lines[line_counter];

      if(line.valid == 1)
	{



	  if(line.tag == tag)
	    {
	  stats.hits++;
	 
          line_2 = set.lines[0];
	  max_LRU = line_2.LRU;
      
      
      for(inner_line_counter = 0; inner_line_counter < num_lines; inner_line_counter++)
	{
	  line_2 = set.lines[inner_line_counter];
	  
	  if(max_LRU < line_2.LRU)
	    {
	      max_LRU = line_2.LRU;
	    	      
	    }
	}
         
	  line.LRU = max_LRU + 1;
	  set.lines[line_counter] = line;
	  test_cache.sets[set_index] = set;
	  if(v == 1)
	    {
	      printf(" Hit");
	    }
	  return stats;
	    }
	}
    
      
    }


  for(line_counter = 0; line_counter < num_lines; line_counter++)       //This for loop checks for any lines that are empty.
    {                                                                   //If there are any, we set the valid bit to 1 and update tag.     
      line = set.lines[line_counter];                                   //Also update LRU. Also this is a miss.

      if(line.valid == 0)
	{


	  line.valid = 1;
	  line.tag = tag;
	  stats.misses++;
	 
          line_2 = set.lines[0];
	  max_LRU = line_2.LRU;
      
      
      for(inner_line_counter = 0; inner_line_counter < num_lines; inner_line_counter++)
	{
	  line_2 = set.lines[inner_line_counter];
	  
	  if(max_LRU < line_2.LRU)
	    {
	      max_LRU = line_2.LRU;
	    	      
	    }
	}
         
	  line.LRU = max_LRU + 1;
	  set.lines[line_counter] = line;
	  test_cache.sets[set_index] = set;
	  if(v == 1)
	    {
	      printf(" Miss");
	    }
	  return stats;
	
	}
      
    }



  // This section is if the cache is full. We find the max_LRU integer and the LRU_index. 
  // We then update the line at LRU_index and set the LRU to max_LRU + 1 so now it is last used.
  // This is considered a miss and evict. 
  
      line_2 = set.lines[0];
      min_LRU_index = 0;
      min_LRU = line_2.LRU;
      max_LRU = line_2.LRU;
      
      
      for(line_counter = 1; line_counter < num_lines; line_counter++)   //find max_LRU value
	{
	  line_2 = set.lines[line_counter];
	  
	  if(max_LRU < line_2.LRU)
	    {
	      max_LRU = line_2.LRU;
	    	      
	    }
	}

      for(line_counter = 1; line_counter < num_lines; line_counter++)  //find min_LRU index.
      	{
      	  line_2 = set.lines[line_counter];
	  
      	  if(min_LRU > line_2.LRU)
      	    {
            
	      min_LRU = line_2.LRU;
	      min_LRU_index = line_counter;
	      
          }
      	}
	 
	 line = set.lines[min_LRU_index];
	 line.tag = tag;
	 line.LRU = max_LRU + 1;

	 set.lines[min_LRU_index] = line;
	 test_cache.sets[set_index] = set;

	 stats.misses++;
	 stats.evicts++;
	 if(v == 1)
	   {
	 printf(" Miss");
	 printf(" Evict");
	   }
	 return stats;
  
}

int main(int argc, char **argv )
{

  cache test_cache;   //Our cache

  mem_stats stats;   //Our cache info

  FILE *file_read;  //Will be used to read the trace file.

  char arg;        //used for switch statemnt

  char cmd;        //used for operation scan and print.

  int size;        //used for size of operation scan and print.

  mem_add  address;  //64 bit address

  char *trace_file;  //The trace file.

  int v;            //used for verbosity setting, if its 1 we print all operations, hits, misses, and evictions. 
 

  while((arg=getopt(argc,argv,"s:E:b:t:hv")) != -1)
    {
      switch(arg)
	{
	case 's':
	  stats.s = atoi(optarg);
	  break;
	case 'E':
	  stats.E = atoi(optarg);
	  break;
	case 'b':
	  stats.b = atoi(optarg);
	  break;
	case 't':
	  trace_file = optarg;
	  break;
	case 'v':
	  v = 1;
	  break;
	case'h':
	  help(argv);
	    exit(0);
	  break;
	default:
	  help(argv);
	  exit(1);
	  break;
	}
    }  

  //Cant have 0 values or a NULL file
  if(stats.E == 0 || stats.b == 0 || stats.s == 0 || trace_file == NULL)
    {
      printf("%s:Arguments cannot be 0 or NULL\n",argv[0]);
      help(argv);
      exit(1);
    }

  //Setting all the stats.

  stats.S  = pow(2,stats.s);

  stats.B  = pow(2,stats.b);

  stats.m = 64;

  stats.t = (stats.m - stats.s - stats.b);

  stats.C = (stats.S * (stats.E * stats.B));

  stats.hits = 0;
  stats.misses = 0;
  stats.evicts = 0;

  test_cache = build(stats.S, stats.E);  //cache allocation and initialization.
  
  file_read = fopen(trace_file,"r");    //stream reader
  
 
  if(file_read != NULL)
    {
      while(fscanf(file_read, " %c %llx,%d", &cmd, &address, &size) == 3) //while all 3 arguments match syntax....
	{
	  printf("\n");
	  switch(cmd)             //switch statement for the Operation. I does nothing, M calls calculate twice.
	    {                       //L and S call calculate onces. If v is active, we print the operations.
	 case 'I':
	   if(v == 1)
	     {
	       printf("%s %llx,%d", &cmd, address, size);
	     }
	    break;
	 case 'M':
             if(v == 1)
	     {
	       printf("%s %llx,%d", &cmd, address, size);
	     }
	    stats = calculate(address,test_cache,stats,v);
	    stats =  calculate(address,test_cache,stats,v);
	    break;
	 case 'L':
	     if(v == 1)
	     {
	       printf("%s %llx,%d", &cmd, address, size);
	     }
	    stats =  calculate(address,test_cache,stats,v);
	    break;
	 case 'S':
	    if(v == 1)
	     {
	       printf("%s %llx,%d", &cmd, address, size);
	     }
	   stats = calculate(address,test_cache,stats,v);
	    break;
	  default:
	    break;
	  }

	}
    }

  //print results
  printf("\n");
  printSummary(stats.hits,stats.misses, stats.evicts);
  fclose(file_read);
    return 0;
}


