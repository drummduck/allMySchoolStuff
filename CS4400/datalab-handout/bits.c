/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {

//Take the complement of first integer and second integer. Then, take the ones complement of the 2 OR'd together.
    int Var_x = ~x;
    int Var_y = ~y;

    return ~(Var_x|Var_y);

}
/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {

//Multiply n by 8 by shifting and that will be the amount of bits we need to shift right. Then AND it with 0xFF to just seclude the byte we need from the word.

return (x >> (n << 3)) & 0xFF;

}
/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int logicalShift(int x, int n) {

//Create a mask that will move a 1 to the MSB and then we will arithmetically shift that to the right an n amount. Then we will do the actual shift and AND it with the ones complement of the mask. Making the n highest bits 0's and the rest 1's. This will create a logical shift instead of an arithmetic one.

int mask = ((1 << 31) >> n) << 1;
  return (x >> n) & ~mask;

  
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {

	//First make a mask of 01010101... and shift x by 1. Mask the original x by the mask make and the shifted x also. Continue this up to 5 times and double the mask and shift each time. Worked on this with a classmate :P
	int mask, copy;

	mask = 0x55;				///1
	mask = (mask << 8)|(0x55);
	mask = (mask << 16)|(mask);
	
	copy = x;
	x = x >> 1;
	
	x = (x & mask) + (copy & mask);


	mask = 0x33;				///2
	mask = (mask << 8)|(0x33);
	mask = (mask << 16)|(mask);
	
	copy = x;
	x = x >> 2;
	
	x = (x & mask) + (copy & mask);

	mask = 0x0F;				///3
	mask = (mask << 8)|(0x0F);
	mask = (mask << 16)|(mask);
	
	copy = x;
	x = x >> 4;
	
	x = (x & mask) + (copy & mask);

	mask = 0xFF;				///4
	mask = (mask << 16)|(mask);
	
	copy = x;
	x = x >> 8;
	
	x = (x & mask) + (copy & mask);

	mask = 0xFF;				///5
	mask = (mask << 8)|(0xFF);
	mask = (0x00)|(mask);
	
	copy = x;
	x = x >> 16;
	
	x = (x & mask) + (copy & mask);

	return x;


	//Original solution, but it was way over the amount of operations.

   /* int mask = 0x01;
    int sum = 0;

    sum = sum + (x & mask);
    sum = sum + ((x >> 1)& mask);
    sum = sum + ((x >> 2)& mask);
    sum = sum + ((x >> 3)& mask);
    sum = sum + ((x >> 4)& mask);
	sum = sum + ((x >> 5)& mask);
    sum = sum + ((x >> 6)& mask);
    sum = sum + ((x >> 7)& mask);
    sum = sum + ((x >> 8)& mask);
    sum = sum + ((x >> 9)& mask);
    sum = sum + ((x >> 10)& mask);
    sum = sum + ((x >> 11)& mask);
    sum = sum + ((x >> 12)& mask);
    sum = sum + ((x >> 13)& mask);
    sum = sum + ((x >> 14)& mask);
    sum = sum + ((x >> 15)& mask);
    sum = sum + ((x >> 16)& mask);
    sum = sum + ((x >> 17)& mask);
    sum = sum + ((x >> 18)& mask);
    sum = sum + ((x >> 19)& mask);
    sum = sum + ((x >> 20)& mask);
    sum = sum + ((x >> 21)& mask);
    sum = sum + ((x >> 22)& mask);
    sum = sum + ((x >> 23)& mask);
    sum = sum + ((x >> 24)& mask);
    sum = sum + ((x >> 25)& mask);
    sum = sum + ((x >> 26)& mask);
    sum = sum + ((x >> 27)& mask);
    sum = sum + ((x >> 28)& mask);
    sum = sum + ((x >> 29)& mask);
    sum = sum + ((x >> 30)& mask);
    sum = sum + ((x >> 31)& mask);
    return (sum);
	*/

  
}
/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x) {

  // The logical negative value of x.
	int negative_x = ~x + 1;

	// If x does not equal zero, then the most significant bit (or sign bit) of either x or -x will be 1. XOR the sign bit of x or -x with the mask 0x01 to do the operation !.

	int positive_signBit = ((x >> 31) & 0x01);
	int negative_signBit = ((negative_x >> 31) & 0x01);

	return((positive_signBit | negative_signBit) ^ 0x01);
}
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {

//This is the most negative number for a 32 bit number that can be represented.
  return (0x01 << 31);
}
/*
 * fitsBits - return 1 if x can be represented as an
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  
//Finds how many high bits are remaining after n lower bits.
 int mask = x >> 31;
 int size = n + ~0;

//Zero out the higher order bits.
 int tmp1 = ~x & mask;
 int tmp2 = x & ~mask;

return !((tmp1 + tmp2) >> size);

}
/*
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {

//Subtract 1 from n so we get x+2^(k)-1. 
int Mask = ((1 << n) + ~0);

int Sign_fix = (x >> 31) & Mask;

//Adds 1 if x sign bit was 1

//Adds 0 if x sign bit is 0

return ((x + Sign_fix) >> n);


}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
//Invert bits
int complement = ~x;
//Add one
return (complement + 1);
}
/*
 * isPositive - return 1 if x > 0, return 0 otherwise
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {

//negative mask for negative check.
int negative = 0x1 << 31;  

//checks if number is negative.
int negative_Check = (x & negative);

//checks if number is zero.
int zero_Check = !x;


//If a number is not negative or zero, then return 1.
return !(negative_Check | zero_Check);

}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
//Keep track of sign of x and y for later use.
int sign_X = x >> 31;

int sign_Y = y >> 31;

//Used for when negatives are being used. Used with SameSign to offset when they are the same sign or not.
int combined_Sign = sign_X ^ sign_Y;


//Used if they are the same sign. If both signs of x and y are the same than this is 0 or 1 depending on the sign of x. Otherwise this is 0. 
int if_SameSign = combined_Sign & sign_X;


//To do subtraction we take x and take its two's complement and then add it to y.
int negative_X = (~x + 1);

int subtraction = negative_X + y;


//Get the sign bit of the subtraction. Combined sign is used if x or y is negative and SameSign is used if they are the same sign.
int sign_Bit = (subtraction >> 31);

return !((sign_Bit | combined_Sign)^if_SameSign);


}
/*
 * ilog2 - return floor(log base 2 of   x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {

//Since we know x > 0 we can shift one bit at a time and see if the number remaining is 0 or not. If it is not zero we increment our count which is basically how many times we divide by 2. 
  
int count = 0;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

x = x>>1;

count += !!x;

return count;

}
/*
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {

//First we check if uf is NaN or infinite. Otherwise we flip the sign bit.

if((uf<<1)>0xFF000000)
{
return uf;
}

else
{
 return (uf + (1<<31));
}


}
/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {



//The code below is from the site rooftrellen.com/blog/computer-systems-a-programmers-perspective-data-lab-old/. It is not mine. I did my best to understand what was going in this code. Unfortunately this is the only problem i was unable to truly understand.


 /* Determine by different value */
    unsigned uNonSign;
    unsigned uExp;
    unsigned uTemp;
    if (x) { // Non-zero
        if (x < 0) { // Choose sign and exp part by sign
            uExp = 0xCF800000;
            uNonSign = -x;
        } else {
            uExp = 0x4F800000;
            uNonSign = x;
        }
        while (1) { // Calculate frac and exp part
            uTemp = uNonSign;
            uNonSign <<= 1;
            uExp -= 0x800000;
            if (uTemp & 0x80000000) {
                break;
            }
        }
        uExp += (uNonSign >> 9);
        if ((uNonSign & 0x3FF) == 0x300) { // Round frac
            ++ uExp;
        } else if ((uNonSign & 0x1FF) > 0x100) {
            ++ uExp;
        }
        return uExp;
    } else { // Zero
        return 0;
    }








//This is the code i had originally. This is as far as i could get by working with multiple people. The problem we ran into was the rounding. So i used the code above that i found on a 

/*
int temp, count, frac, exp, msb, mask;

temp = x;
count = 0;

if(x == 0)
{
return 0;
}
 msb = ((x>>31) & 1);
 
if (msb)
{
x = ~x+1;
}

while(temp > 1)
{
count = count+1;
temp = temp >> 1;

}

exp = 127 + count;

mask = 0x007fffff;

frac = (((x << (32-(count-1))) >> 9) & mask);

msb = msb << 31;

exp = exp << 23;

return ((msb | exp | frac)); 
*/

}
/*
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {

int exp = (uf >> 23) & 0xFF;
int sign = uf & 0x80000000
;
int frac = uf & 0x007FFFFF;
if (exp == 255 || (exp == 0 && frac == 0)) //NaN, exp is all 1's
{
return uf;
}

if (exp) //Normalized if exp is not 0
{
exp++;
}
 
else if (frac == 0x7FFFFF) //denormalized, decrease fraction and increase exponent
{
frac--;
exp++;
}
 
else 	//rounding
{
frac <<= 1;
}

return ((sign) | (exp << 23) | (frac));
}
