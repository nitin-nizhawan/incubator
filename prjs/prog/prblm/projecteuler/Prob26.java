/*
 * Implemanttion of function to find number period of recurring digits of 1/n for a given, it is based on the algo given by Dr. Rob from mathforum.org
From: Doctor Rob
Subject: Re: Long numbers

You have started on an odyssey that can lead you (eventually) to a 
fact known as Fermat's Little Theorem. It is a worthy journey, and you 
can learn much along the way.

The length of the repeating part is the smallest number of 9's such 
that the denominator divides 9999...999000...0000 evenly. For example, 
7 divides 999999 evenly, so the repeating part has length 6. 
Furthermore, the digits in the repeating part of 1/7 are the digits of 
the quotient 999999/7 = 142857.

   1/7 = 142857/999999 = 142857/10^6 + 142857/10^12
          + 142857/10^18 + ...

       = 0.142857 + 0.000000142857 + 0.000000000000142857 + ...

You will recognize this as a geometric series.

Since 13 is a divisor of 999999, with quotient 76923, you can safely 
predict that

   1/13 = 0.076923 076923 076923 076923 076923 076923 076923 ...

without needing a high-precision calculator.

Next you probably want to know in advance what number 
999...999000...000 is a multiple of some denominator N. This is done 
by factoring N as a product of prime powers, which can be done only 
one way. They fall into two classes: ones dividing 10 and ones not 
dividing 10 (the base of our system of numerals). The first consists 
of just {2,5}, and the second is all the other primes. The number of 
zeroes in the number in the first line of this paragraph is just the 
larger of the two exponents of 2 and 5. That's the easy part. And if 
there are no other primes, then that larger exponent E is such that N 
is a divisor of 10^E, and the decimal terminates after E decimal 
places. 1/N = Q/10^E, where Q = 10^E/N.

The next step is to find for the rest of the primes p dividing into N 
evenly what smallest power of 10 has the property that 10^k - 1 is a 
multiple of p. That number k is called the order of 10 modulo p.  The 
most helpful fact about k is that it is a divisor of p-1.  Recall that 
for p = 7, we had k = 6, and, sure enough, 6 is a divisor of 7-1 = 6. 
This limits you to just a few possibilities. There is no easy way to 
tell which of these divisors of p-1 is actually k, you just have to 
try them.

The next step is to find the highest power of p dividing 10^k - 1. We 
know that it is at least 1, but it may be more. For example, if p = 3, 
the divisors of 3-1 = 2 are 1 and 2. It turns out that k = 1, because 
3 is a divisor of 10^1 - 1 = 9, but, in fact, 3^2 is also a divisor of 
9 as well. Call that highest power p^e.

Now if the power of p dividing N is p^n, and n <= e, then the period 
length of 1/p^n is k. If, on the other hand, n > e, then the period 
length of 1/p^n is k*p^(n-e).

Now to get the length of the period of 1/N, take the least common 
multiple of the lengths of the periods of 1/p^n, for all primes other 
than 2 or 5 dividing N.

Example: Find the length of the period of 1/9450. Start by factoring 
9450 = 2 * 3^3 * 5^2 * 7. The number of zeroes will be the larger of 1 
and 2 (the exponents of 2 and 5 in this factorization), namely 2. Now 
first consider 3^3 = p^n. The order of 10 modulo 3 is 1, and 3^2 is a 
divisor of 10^1 - 1 = 9, so e = 2. Since n = 3 > 2, the period length 
of 1/3^3 is 1*3^(3-2) = 3. Next consider 7^1 = p^n. The order of 10 
modulo 7 is 6, as above, and 7^1 is the largest power of 7 dividing 
10^6 - 1 = 999999 = 3^3 * 7 * 11 * 13 * 37, so e = 1. Thus the period 
length of 1/7 is 6. Taking the LCM of 3 and 6 gives 6. That tells me 
that the number of 9's should be 6, and 9450 must divide evenly into 
99999900. Sure enough, it does, and the quotient is 10582. Thus

   1/9450 = 10582/99999900 = 0.00 010582 010582 010582 010582...

Notice the 2 digits to the right of the decimal before the repeating 
part begins, corresponding to the two zeroes at the end of the number 
99999900, corresponding to the larger of the exponents of 2 and 5 in 
the factorization of 9450. Similarly,

   4567/9450 = 48327994/99999900 = 0.48 328042 328042 328042...


Example: Find the period length of 1/73. Since 73 is prime, we need to 
find the order of 10 modulo 73. It must be a divisor of 72, so it 
could be 72, 36, 24, 18, 12, 9, 8, 6, 4, 3, 2 or 1.  It turns out to 
be 8, so k = 8, and 73 divides evenly into 99999999. The period length 
must be 8. The quotient is 1369863, so the decimal expansion must be

 *  1/73 = 0.01369863 01369863 01369863 01369863...
 *
 *  Get the idea?
 *
 *  Proofs of the above facts are a part of a subject called Number 
 *  Theory, which you can study as an advanced undergraduate at a college 
 *  or university.
 * 
 *
 *
 */
/*
 From another source it was found that length of recurring decimals is equal to the multiplicative order of 10 w.r.t to d in 1/d
 

*/
 import java.util.HashMap;

 public class Prob26{
	 public static int multiplicative_order_10(int n){
		 int ret = 1;
		 for(int i=1;i<=n;i++){
			 ret*=10;
			 ret = ret%n;
			 if(ret == 1){
				 return i;
			 }
		 }
		 return -1;
	 }
	 public static void main(String args[]){
                 int max = 1;
                 int max_i = 0;
		 for(int i=1;i<=1000;i++){
			 int mo_10 =     multiplicative_order_10(i);
			 //prints all, find the max
                         if(mo_10 > max){
                             max = mo_10;
                             max_i = i;
                         }
		 }
		 System.out.println((max+","+max_i));
                
	 }
 }
