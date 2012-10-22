/* large.c - Handles binary manipulation of large numbers */

/*
    libzint - the open source barcode library
    Copyright (C) 2008 Robin Stuart <robin@zint.org.uk>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

//#include <stdio.h>
//#include <string.h>
//#include "common.h"
//#include "large.h"

/*const short int*/ var BCD/*[40]*/ = [
	0, 0, 0, 0,
	1, 0, 0, 0,
	0, 1, 0, 0,
	1, 1, 0, 0,
	0, 0, 1, 0,
	1, 0, 1, 0,
	0, 1, 1, 0,
	1, 1, 1, 0,
	0, 0, 0, 1,
	1, 0, 0, 1
];

/*void*/function binary_add(/*short int*/ accumulator/*[]*/, /*short int*/ input_buffer/*[]*/)
{ /* Binary addition */
	/*int*/var i, carry, done;
	carry = 0;

	for(i = 0; i < 112; i++) {
		done = 0;
		if(((input_buffer[i] == 0) && (accumulator[i] == 0)) && ((carry == 0) && (done == 0))) {
			accumulator[i] = 0;
			carry = 0;
			done = 1;
		}
		if(((input_buffer[i] == 0) && (accumulator[i] == 0)) && ((carry == 1) && (done == 0))) {
			accumulator[i] = 1;
			carry = 0;
			done = 1;
		}
		if(((input_buffer[i] == 0) && (accumulator[i] == 1)) && ((carry == 0) && (done == 0))) {
			accumulator[i] = 1;
			carry = 0;
			done = 1;
		}
		if(((input_buffer[i] == 0) && (accumulator[i] == 1)) && ((carry == 1) && (done == 0))) {
			accumulator[i] = 0;
			carry = 1;
			done = 1;
		}
		if(((input_buffer[i] == 1) && (accumulator[i] == 0)) && ((carry == 0) && (done == 0))) {
			accumulator[i] = 1;
			carry = 0;
			done = 1;
		}
		if(((input_buffer[i] == 1) && (accumulator[i] == 0)) && ((carry == 1) && (done == 0))) {
			accumulator[i] = 0;
			carry = 1;
			done = 1;
		}
		if(((input_buffer[i] == 1) && (accumulator[i] == 1)) && ((carry == 0) && (done == 0))) {
			accumulator[i] = 0;
			carry = 1;
			done = 1;
		}
		if(((input_buffer[i] == 1) && (accumulator[i] == 1)) && ((carry == 1) && (done == 0))) {
			accumulator[i] = 1;
			carry = 1;
			done = 1;
		}
	}
}

/*void*/function binary_subtract(/*short int*/ accumulator/*[]*/, /*short int*/ input_buffer/*[]*/)
{ 	/* 2's compliment subtraction */
	/* take input_buffer from accumulator and put answer in accumulator */
	/*int*/var i;
	/*short int*/ sub_buffer=[]/*[112]*/;

	for(i = 0; i < 112; i++) {
		if(input_buffer[i] == 0) {
			sub_buffer[i] = 1;
		} else {
			sub_buffer[i] = 0;
		}
	}
	binary_add(accumulator, sub_buffer);

	sub_buffer[0] = 1;

	for(i = 1; i < 112; i++) {
		sub_buffer[i] = 0;
	}
	binary_add(accumulator, sub_buffer);
}

/*void*/function shiftdown(/*short int*/ buffer/*[]*/)
{
	/*int*/ i;

	buffer[102] = 0;
	buffer[103] = 0;

	for(i = 0; i < 102; i++) {
		buffer[i] = buffer[i + 1];
	}
}

/*void*/function shiftup(/*short int*/ buffer/*[]*/)
{
	/*int*/ i;

	for(i = 102; i > 0; i--) {
		buffer[i] = buffer[i - 1];
	}

	buffer[0] = 0;
}

/*short int*/function islarger(/*short int*/ accum/*[]*/, /*short int*/ reg/*[]*/)
{
	/* Returns 1 if accum[] is larger than reg[], else 0 */
	/*int*/var i, latch, larger;
	latch = 0;
	i = 103;
	larger = 0;


	do {
		if((accum[i] == 1) && (reg[i] == 0)) {
			latch = 1;
			larger = 1;
		}
		if((accum[i] == 0) && (reg[i] == 1)) {
			latch = 1;
		}
		i--;
	} while ((latch == 0) && (i >= -1));

	return larger;
}

/*void*/function binary_load(/*short int*/ reg/*[]*/, /*char*/ data/*[]*/, /*const unsigned int*/ src_len)
{
	/*int*/var read, i;
	/*short int*/ var temp/*[112]*/ =[] /*{ 0 }*/; while(temp.length<112) temp.push(0);

	for(i = 0; i < 112; i++) {
		reg[i] = 0;
	}

	for(read = 0; read < src_len; read++) {

		for(i = 0; i < 112; i++) {
			temp[i] = reg[i];
		}

		for(i = 0; i < 9; i++) {
			binary_add(reg, temp);
		}

		temp[0] = BCD[ctoi(data[read]) * 4];
		temp[1] = BCD[(ctoi(data[read]) * 4) + 1];
		temp[2] = BCD[(ctoi(data[read]) * 4) + 2];
		temp[3] = BCD[(ctoi(data[read]) * 4) + 3];
		for(i = 4; i < 112; i++) {
			temp[i] = 0;
		}

		binary_add(reg, temp);
	}
}

/*void*/function hex_dump(/*short int*/ input_buffer/*[]*/)
{
	/*int*/ i, digit, byte_space;
    var out=""
	byte_space = 1;
	for(i = 100; i >= 0; i-=4) {
		digit = 0;
		digit += 1 * input_buffer[i];
		digit += 2 * input_buffer[i + 1];
		digit += 4 * input_buffer[i + 2];
		digit += 8 * input_buffer[i + 3];

		switch(digit) {
			case 0: /*printf*/(out+="0"); break;
			case 1: /*printf*/(out+="1"); break;
			case 2: /*printf*/(out+="2"); break;
			case 3: /*printf*/(out+="3"); break;
			case 4: /*printf*/(out+="4"); break;
			case 5: /*printf*/(out+="5"); break;
			case 6: /*printf*/(out+="6"); break;
			case 7: /*printf*/(out+="7"); break;
			case 8: /*printf*/(out+="8"); break;
			case 9: /*printf*/(out+="9"); break;
			case 10: /*printf*/(out+="A"); break;
			case 11: /*printf*/(out+="B"); break;
			case 12: /*printf*/(out+="C"); break;
			case 13: /*printf*/(out+="D"); break;
			case 14: /*printf*/(out+="E"); break;
			case 15: /*printf*/(out+="F"); break;
		}
		if(byte_space == 1) {
			byte_space = 0;
		} else {
			byte_space = 1;
			/*printf*/(out+=" ");
		}
	}
	/*printf*/(out+="\n");
}
