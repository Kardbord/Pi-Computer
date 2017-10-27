// All code in this file is the work of Dr. Mathias

#ifndef _PI_COMPUTER_HPP
#define _PI_COMPUTER_HPP

// ------------------------------------------------------------------
//
// Adapted From: http://stackoverflow.com/questions/5905822/function-to-find-the-nth-digit-of-pi
// Other references:
//      http://bellard.org/pi/pi_n2/pi_n2.html
//      https://web.archive.org/web/20150627225748/http://en.literateprograms.org/Pi_with_the_BBP_formula_%28Python%29
//
// ------------------------------------------------------------------
/*
   * Computation of the n'th decimal digit of \pi with very little memory.
   * Written by Fabrice Bellard on January 8, 1997.
   *
   * We use a slightly modified version of the method described by Simon
   * Plouffe in "On the Computation of the n'th decimal digit of various
   * transcendental numbers" (November 1996). We have modified the algorithm
   * to get a running time of O(n^2) instead of O(n^3log(n)^3).
   *
   * This program uses mostly integer arithmetic. It may be slow on some
   * hardwares where integer multiplications and divisons must be done
   * by software. We have supposed that 'int' has a size of 32 bits. If
   * your compiler supports 'long long' integers of 64 bits, you may use
   * the integer version of 'mul_mod' (see HAS_LONG_LONG).
   */

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <string>

/* uncomment the following line to use 'long long' integers */
/* #define HAS_LONG_LONG */

//#ifdef HAS_LONG_LONG
    #define mul_mod(a,b,m) (( (long long) (a) * (long long) (b) ) % (m))
//#else
//  #define mul_mod(a,b,m) std::fmod( (double) a * (double) b, m)
//#endif

/* Computes the nth digit of pi */
unsigned int computePiDigit(int n);

/* Computes the nth digit of pi in hex  */
unsigned long long piDigitHex(unsigned long long n);

/* return the inverse of x mod y */
int inv_mod(int x, int y);

/* return (a^b) mod m */
int pow_mod(int a, int b, int m);

/* return true if n is prime */
int is_prime(int n);

/* return the prime number immediatly after n */
int next_prime(int n);

// ------------------------------------------------------------------
//
// Code adapted from this source: 
// https://web.archive.org/web/20150627225748/http://en.literateprograms.org/Pi_with_the_BBP_formula_%28Python%29
//
// ------------------------------------------------------------------
double powneg(unsigned long long b, long long pow);

unsigned long long s(unsigned long long j, unsigned long long n);



#endif
