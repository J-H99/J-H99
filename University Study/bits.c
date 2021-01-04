</* 
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
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


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

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

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
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
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
/* Copyright (C) 1991-2019 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
// 1
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
	  return ~(~x | ~y);
}
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
	return ~(~x & ~y);
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
	return ~(~x & ~y) & ~(x & y);
}
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) { // compare allEvenBits num(comp) to x(input)
						 // if x is not allEvenBits, !(comp ^ x) is considered 'false'
						 // if x is allEvenBits, !(comp ^ x) is considered 'true'
	int comp = 0x5;
	comp |= (comp << 4);
	comp |= (comp << 8);
	comp |= (comp << 16);
	return !((comp & x) ^ comp);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) { // compare allOddBits num(comp) to x(input)
						// if x is not allOddBits, !(comp ^ x) is considered 'false'
						// if x is allOddBits, !(comp ^ x) is considered 'true'
	int comp = 0xA;
	comp |= (comp << 4);
	comp |= (comp << 8);
	comp |= (comp << 16);
	return !((comp & x) ^ comp);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) { // 0x1 = 0000 0000 0000 0000 0000 0000 0000 0001
				 // minimum value in two's complement is 1000 0000 0000 0000 0000 0000 0000 0000
				 // minimum value in two's complement = 0x1 << 31;
	return (0x1 << 31);
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) { // 0x1 = 0000 0000 0000 0000 0000 0000 0000 0001
				 // 0x1 << 31 = 1000 0000 0000 0000 0000 0000 0000 0000
				 // maximum value in two's complement is 0111 1111 1111 1111 1111 1111 1111 1111
				 // maximum value in two's complement = ~(0x << 31)
	return ~(0x1 << 31);
}
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) { // if x is the maximum value in two's complement number, x = 0111 1111 1111 1111 1111 1111 1111 1111
					// if x is the maximum value, then x + 1 is Tmin and ~(x + 1) is eqaul to x
	int temp = ~(x + 1); // check whethere temp is eqaul to x
	int checkneg1 = !(~x); //if x is -1, x + 1 operation will make Overflow.
						   // So if x = -1, then return false

	return !(temp ^ x | checkneg1); // if temp != x, then temp ^ x is nonzero (if x^y = 0, then x = y)
									// if x is -1, checkneg1 is nonzero
}
/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) { // if x is the minimum value in two's complement number, x = 1000 0000 0000 0000 0000 0000 0000 000
				    // if x is the minimum value, then ~x value is Tmax and ~x + 1 = x
	int temp = (~x + 1); // check whether temp is equal to x
	int checkzero = !x; // if x is 0, ~x + 1 operation will make Overflow. 
						// So if x = 0, then return false

	return !(temp ^ x | checkzero); // if temp != x, then temp ^ x is nonzero (if x^y = 0, then x = y)
									// if x is 0, checkzero is nonzero
}
// 2
/* #include "allOddBits.c" */
/* #include "isTmax.c" */
/* 
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateLeft(int x, int n) {
	//Shifting n first -> Then, attatch the sliced bits
	int firstshift = x << n; 

	// we need sliced n bits (to attach)
	int k = 32 + (~n + 1); // k = 32 - n
	int sliced_n_bits_moved = x >> k; 

	//ignore (32 - n) digit MSB of sliced_n_bits_moved (since we can not know MSB is 0 or 1)
	int Tmin = 0x1 << 31; 
	int l = 31 + (~n + 1); // require (32 - n) digit 0 bits and n digits 1 bits to ignore (32 - n) digit MSB
						   // Tmin has MSB(1) bit, so we use left shift only (31 -n) bits
						   // l = 31 -n n
	int ndigit1= Tmin >> l; // ndigit1 = (32 - n) digit 1 bits and n digit 0 bits in order
	int ignore_digit = sliced_n_bits_moved & ~(ndigit1); // use Bitwise NOT to obtain needed bits

	return firstshift | ignore_digit; // shifted bits OR sliced bits
}
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x187654321
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) { 
	// Shifting n first -> Then, attach the sliced bits
	int firstshift = x >> n; //shift first
	int Tmin = 0x1 << 31; // To ignore n-digit MSB bits, we need bits containing n digit 0 and (32 - n) digit 1 in order
	int n_minus_1 = n + (~0); // n - 1
	int ndigit1 = (Tmin >> n_minus_1); // Already Tmin has a MSB bit, So we use right shift only (n - 1) bits
									   // ndigit0 = n digit 1 bits and (32 - n) digit 0 bits in order
	int shifted = firstshift & ~(ndigit1); // use Bitwise NOT to obtain needed bits
										   // shifted bits : n digit 0 bits and (32 - n) digit rotated bits

	// Obtain the sliced n bits
	int k = 32 + (~n + 1); // 32 - n
	int sliced_n_bits_moved = x << k; // sliced n bits and (32 - n) digit 0 bits in order
	return shifted | sliced_n_bits_moved; // attach
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) { // using the two's complement formula
	return ~x + 1;
}
// 3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) { // comp1 : check whether tens digit value is 3 (if x is not 0x3_, comp1 is considered 'false')
						  // comp2 : check whether units digit value is 0 ~ 9 (if x is not between 0 and 9 like A or B, comp2 is considered 'false')

	int comp1 = !((~0xF & x) ^ 0x30); // ~0xF & x : ignore the units digit value bits, just check if tens digit value is 3 (remove all bits but tens digit bits)
									  // ^ 0x30 : if tens digit value is not 3, (~0xF & x) ^ 0x30 is not 0 (since to be x ^ y = 0, then x = y)
	int comp2 = !(((x & 0xF) + 6) & 0x10); // if units digit value > 9, a carry value occurs when adding 6 to the value 
										   // Therefore, we need only units digit value (removed all bits but units digit bits) : x & 0xF
										   // To know carry value occurs when adding operation, use bitwise AND : (x & 0xF + 6) & 0x10
										   // if result of this operation is not 0 value, x(input) is not between 0x_0 and 0x_9
	return comp1 & comp2; // To check if 0x30 <= x <= 0x39, Both comp1 and comp2 should be satisfied.
}
// 4
// float
/* #include "floatFloat2Int.c" */
/* #include "floatPower2.c" */
/* #include "floatScale2.c" */
