/* png.c - Handles output to PNG file */

/*
    libzint - the open source barcode library
    Copyright (C) 2009 Robin Stuart <robin@zint.org.uk>

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
//#include <stdlib.h>
//#include <string.h>
//#include "common.h"

//#ifndef NO_PNG
//#include "png.h"        /* libpng header; includes zlib.h and setjmp.h */
//#endif /* NO_PNG */
//#include "maxipng.h"	/* Maxicode shapes */

//#include "font.h"	/* Font for human readable text */

/*#define*/var SSET	="0123456789ABCDEF";

/*#define*/var	PNG_DATA = 100;
/*#define*/var	BMP_DATA = 200;

//#ifndef NO_PNG

/*void*/function draw_bar(/*char **/p/*ixelbuf*/, /*int*/ xpos, /*int*/ xlen, /*int*/ ypos, /*int*/ ylen, /*int*/ image_width, /*int*/ image_height)
{
	/* Draw a rectangle */
	/*int*/var i, j, png_ypos;

	png_ypos = image_height - ypos - ylen;
	/* This fudge is needed because EPS measures height from the bottom up but
	PNG measures y position from the top down */

	for(i = (xpos); i < (xpos + xlen); i++) {
		for( j = (png_ypos); j < (png_ypos + ylen); j++) {
			//*(pixelbuf + (image_width * j) + i) = '1';
			p.buffer[p.index(i,j)] = p.color(0,0,0);
		}
	}
}



/*void*/function draw_letter(/*char **/p/*ixelbuf*/, /*unsigned char*/ letter, /*int*/ xposn, /*int*/ yposn, /*int*/ smalltext, /*int*/ image_width, /*int*/ image_height)
{
	/* Put a letter into a position */
	/*int*/var skip, i, j, glyph_no, alphabet;

	skip = 0;
	alphabet = 0;
    var letterCode = letter.charCodeAt(0);
	if(letterCode < 33) { skip = 1; }
	if((letterCode > 127) && (letterCode < 161)) { skip = 1; }

	if(skip == 0) {
		if(letter > 128) {
			alphabet = 1;
			glyph_no = letterCode - 161;
		} else {
			glyph_no = letterCode - 33;
		}

		if(smalltext>0) {
			for(i = 0; i <= 8; i++) {
				for(j = 0; j < 5; j++) {
					if(alphabet == 0) {
						if(small_font[(glyph_no * 5) + (i * 475) + j - 1] == 1) {
							//*(pixelbuf + (i * image_width) + (yposn * image_width) + xposn + j) = '1';
							p.buffer[p.index(i+yposn,j+xposn)]=p.color(0,0,0);
						}
					} else {
						if(small_font_extended[(glyph_no * 5) + (i * 475) + j - 1] == 1) {
							//*(pixelbuf + (i * image_width) + (yposn * image_width) + xposn + j) = '1';
							p.buffer[p.index(i+yposn,j+xposn)]=p.color(0,0,0);
						}
					}
				}
			}
		} else {
			for(i = 0; i <= 13; i++) {
				for(j = 0; j < 7 ; j++) {
					if(alphabet == 0) {
						if(ascii_font[(glyph_no * 7) + (i * 665) + j - 1] == 1) {
							//*(pixelbuf + (i * image_width) + (yposn * image_width) + xposn + j) = '1';
								p.buffer[p.index(i+yposn,j+xposn)]=p.color(0,0,0);		
						}
					} else {
						if(ascii_ext_font[(glyph_no * 7) + (i * 665) + j - 1] == 1) {
							//*(pixelbuf + (i * image_width) + (yposn * image_width) + xposn + j) = '1';
							    p.buffer[p.index(i+yposn,j+xposn)]=p.color(0,0,0);	
						}
					}
				}
			}
		}
	}
}

/*void*/function draw_string(/*char **/p/*ixbuf*/, /*char*/ input_string/*[]*/, /*int*/ xposn, /*int*/ yposn, /*int*/ smalltext, /*int*/ image_width, /*int*/ image_height)
{
	/* Plot a string into the pixel buffer */
	/*int*/ i, string_length, string_left_hand;

	string_length = /*strlen*/(input_string.length);
	string_left_hand = xposn - ((7 * string_length) / 2);

	for(i = 0; i < string_length; i++) {
		draw_letter(p/*ixbuf*/, input_string[i], string_left_hand + (i * 7), yposn, smalltext, image_width, image_height);
	}

}


/*void*/function to_latin1(/*unsigned char*/ source/*[]*/, /*unsigned char*/ preprocessed/*[]*/)
{
	/*int*/var j, i, input_length;

	input_length = /*ustrlen*/(source.length);
    preprocessed=[];
	j = 0;
	i = 0;
	do {
		if(source[i] < 128) {
			preprocessed[j] = source[i];
			j++;
			i++;
		} else {
			if(source[i] == 0xC2) {
				preprocessed[j] = source[i + 1];
				j++;
				i += 2;
			}
			if(source[i] == 0xC3) {
				preprocessed[j] = source[i + 1] + 64;
				j++;
				i += 2;
			}
		}
	} while (i < input_length);
	//preprocessed[j] = '\0';

	return preprocessed.join("");
}

/*int*/function png_plot(/*struct zint_symbol **/symbol, /*int*/ rotate_angle, /*int*/ data_type)
{
	/*int*/var textdone, main_width, comp_offset, large_bar_count;
	/*char*/var textpart=[/*10*/], addon=[/*6*/];
	/*float*/var addon_text_posn, preset_height, large_bar_height;
	/*int*/var i, r, textoffset, yoffset, xoffset, latch, image_width, image_height;
	/*char */var p;/*ixelbuf*/;
	/*int*/var addon_latch = 0, smalltext = 0;
	/*int*/var this_row, block_width, plot_height, plot_yposn, textpos;
	/*float*/var row_height, row_posn;
	/*int*/var error_number;
	/*int*/var default_text_posn;
	/*int*/var next_yposn;
	/*unsigned char*/var local_text=[];//[ustrlen(symbol./*->*/text) + 1];

	if(symbol./*->*/show_hrt != 0) {
		local_text = to_latin1(symbol./*->*/text, local_text);
	} else {
		local_text="";//[0] = '\0';
	}

	textdone = 0;
	main_width = symbol./*->*/width;
	/*strcpy*/(addon=/*,*/ "");
	comp_offset = 0;
	addon_text_posn = 0.0;
	row_height = 0;
	if(symbol./*->*/output_options & SMALL_TEXT) {
		smalltext = 1;
	}

	if (symbol./*->*/height == 0) {
		symbol./*->*/height = 50;
	}

	large_bar_count = 0;
	preset_height = 0.0;
	for(i = 0; i < symbol./*->*/rows; i++) {
		preset_height += symbol./*->*/row_height[i];
		if(symbol./*->*/row_height[i] == 0) {
			large_bar_count++;
		}
	}

	if (large_bar_count == 0) {
		symbol./*->*/height = preset_height;
		large_bar_height = 10;
	} else {
		large_bar_height = (symbol./*->*/height - preset_height) / large_bar_count;
	}

	while(!(module_is_set(symbol, symbol./*->*/rows - 1, comp_offset))) {
		comp_offset++;
	}

	/* Certain symbols need whitespace otherwise characters get chopped off the sides */
	if ((((symbol./*->*/symbology == BARCODE_EANX) && (symbol./*->*/rows == 1)) || (symbol./*->*/symbology == BARCODE_EANX_CC))
		|| (symbol./*->*/symbology == BARCODE_ISBNX)) {
		switch(/*ustrlen*/(local_text.length)) {
			case 13: /* EAN 13 */
			case 16:
			case 19:
				if(symbol./*->*/whitespace_width == 0) {
					symbol./*->*/whitespace_width = 10;
				}
				main_width = 96 + comp_offset;
				break;
			default:
				main_width = 68 + comp_offset;
		}
	}

	if (((symbol./*->*/symbology == BARCODE_UPCA) && (symbol./*->*/rows == 1)) || (symbol./*->*/symbology == BARCODE_UPCA_CC)) {
		if(symbol./*->*/whitespace_width == 0) {
			symbol./*->*/whitespace_width = 10;
			main_width = 96 + comp_offset;
		}
	}

	if (((symbol./*->*/symbology == BARCODE_UPCE) && (symbol./*->*/rows == 1)) || (symbol./*->*/symbology == BARCODE_UPCE_CC)) {
		if(symbol./*->*/whitespace_width == 0) {
			symbol./*->*/whitespace_width = 10;
			main_width = 51 + comp_offset;
		}
	}

	latch = 0;
	r = 0;
	/* Isolate add-on text */
	if(is_extendable(symbol./*->*/symbology)) {
		for(i = 0; i < /*ustrlen*/(local_text.length); i++) {
			if (latch == 1) {
				addon[r] = local_text[i];
				r++;
			}
			if (symbol./*->*/text[i] == '+') {
				latch = 1;
			}
		}
	}
	//addon[r] = '\0';

	if(/*ustrlen*/(local_text.length) != 0) {
		textoffset = 9;
	} else {
		textoffset = 0;
	}
	xoffset = symbol./*->*/border_width + symbol./*->*/whitespace_width;
	yoffset = symbol./*->*/border_width;
	image_width = 2 * (symbol./*->*/width + xoffset + xoffset);
	image_height = 2 * (symbol./*->*/height + textoffset + yoffset + yoffset);
/*
	if (!(pixelbuf = (char *) malloc(image_width * image_height))) {
		printf("Insufficient memory for pixel buffer");
		return ZERROR_ENCODING_PROBLEM;
	} else {
		for(i = 0; i < (image_width * image_height); i++) {
			*(pixelbuf + i) = '0';
		}
	}
*/ 
     p = new PNGlib(image_width, image_height, 256);
	 for(var _x=0;_x<image_height;_x++){
	     for(var _y=0;_y<image_width;_y++){
		     p.buffer[p.index(_x,_y)] = p.color(255,255,255);
		 }
	 }
	if(((symbol./*->*/output_options & BARCODE_BOX) != 0) || ((symbol./*->*/output_options & BARCODE_BIND) != 0)) {
		default_text_posn = image_height - 17;
	} else {
		default_text_posn = image_height - 17 - symbol./*->*/border_width - symbol./*->*/border_width;
	}

	row_posn = textoffset + yoffset;
	next_yposn = textoffset + yoffset;
	row_height = 0;

	/* Plot the body of the symbol to the pixel buffer */
	for(r = 0; r < symbol./*->*/rows; r++) {
		this_row = symbol./*->*/rows - r - 1; /* invert r otherwise plots upside down */
		row_posn += row_height;
		plot_yposn = next_yposn;
		if(symbol./*->*/row_height[this_row] == 0) {
			row_height = large_bar_height;
		} else {
			row_height = symbol./*->*/row_height[this_row];
		}
		next_yposn = /*(int)*/Math.floor(row_posn + row_height);
		plot_height = next_yposn - plot_yposn;

		i = 0;
		if(module_is_set(symbol, this_row, 0)) {
			latch = 1;
		} else {
			latch = 0;
		}

		do {
			block_width = 0;
			do {
				block_width++;
			} while (module_is_set(symbol, this_row, i + block_width) == module_is_set(symbol, this_row, i));
			if((addon_latch == 0) && (r == 0) && (i > main_width)) {
				plot_height = /*(int)*/(row_height - 5.0);
				plot_yposn = /*(int)*/(row_posn - 5.0);
				addon_text_posn = row_posn + row_height - 8.0;
				addon_latch = 1;
			}
			if(latch == 1) {
				/* a bar */
				draw_bar(p/*ixelbuf*/, (i + xoffset) * 2, block_width * 2, plot_yposn * 2, plot_height * 2, image_width, image_height);
				latch = 0;
			} else {
				/* a space */
				latch = 1;
			}
			i += block_width;

		} while (i < symbol./*->*/width);
	}

	xoffset += comp_offset;

	if ((((symbol./*->*/symbology == BARCODE_EANX) && (symbol./*->*/rows == 1)) || (symbol./*->*/symbology == BARCODE_EANX_CC)) || (symbol./*->*/symbology == BARCODE_ISBNX)) {
		/* guard bar extensions and text formatting for EAN8 and EAN13 */
		switch(/*ustrlen*/(local_text.length)) {
			case 8: /* EAN-8 */
			case 11:
			case 14:
				draw_bar(p/*ixelbuf*/, (0 + xoffset) * 2, 1 * 2, (4 + /*(int)*/Math.floor(yoffset)) * 2, 5 * 2, image_width, image_height);
				draw_bar(p/*ixelbuf*/, (2 + xoffset) * 2, 1 * 2, (4 + /*(int)*/Math.floor(yoffset)) * 2, 5 * 2, image_width, image_height);
				draw_bar(p/*ixelbuf*/, (32 + xoffset) * 2, 1 * 2, (4 + /*(int)*/Math.floor(yoffset)) * 2, 5 * 2, image_width, image_height);
				draw_bar(p/*ixelbuf*/, (34 + xoffset) * 2, 1 * 2, (4 + /*(int)*/Math.floor(yoffset)) * 2, 5 * 2, image_width, image_height);
				draw_bar(p/*ixelbuf*/, (64 + xoffset) * 2, 1 * 2, (4 + /*(int)*/Math.floor(yoffset)) * 2, 5 * 2, image_width, image_height);
				draw_bar(p/*ixelbuf*/, (66 + xoffset) * 2, 1 * 2, (4 + /*(int)*/Math.floor(yoffset)) * 2, 5 * 2, image_width, image_height);
				for(i = 0; i < 4; i++) {
					textpart[i] = symbol./*->*/text[i];
				}
				textpart[4] = '\0';
				textpos = 2 * (17 + xoffset);

				draw_string(p/*ixelbuf*/, textpart, textpos, default_text_posn, smalltext, image_width, image_height);
				for(i = 0; i < 4; i++) {
					textpart[i] = symbol./*->*/text[i + 4];
				}
				textpart[4] = '\0';
				textpos = 2 * (50 + xoffset);
				draw_string(p/*ixelbuf*/, textpart, textpos, default_text_posn, smalltext, image_width, image_height);
				textdone = 1;
				switch(/*strlen*/(addon.length)) {
					case 2:
						textpos = 2 * (xoffset + 86);
						draw_string(p/*ixelbuf*/, addon, textpos, image_height - (addon_text_posn * 2) - 13, smalltext, image_width, image_height);
						break;
					case 5:
						textpos = 2 * (xoffset + 100);
						draw_string(p/*ixelbuf*/, addon, textpos, image_height - (addon_text_posn * 2) - 13, smalltext, image_width, image_height);
						break;
				}

				break;
			case 13: /* EAN 13 */
			case 16:
			case 19:
				draw_bar(p/*ixelbuf*/, (0 + xoffset) * 2, 1 * 2, (4 + /*(int)*/Math.floor(yoffset)) * 2, 5 * 2, image_width, image_height);
				draw_bar(p/*ixelbuf*/, (2 + xoffset) * 2, 1 * 2, (4 + /*(int)*/Math.floor(yoffset)) * 2, 5 * 2, image_width, image_height);
				draw_bar(p/*ixelbuf*/, (46 + xoffset) * 2, 1 * 2, (4 + /*(int)*/Math.floor(yoffset)) * 2, 5 * 2, image_width, image_height);
				draw_bar(p/*ixelbuf*/, (48 + xoffset) * 2, 1 * 2, (4 + /*(int)*/Math.floor(yoffset)) * 2, 5 * 2, image_width, image_height);
				draw_bar(p/*ixelbuf*/, (92 + xoffset) * 2, 1 * 2, (4 + /*(int)*/Math.floor(yoffset)) * 2, 5 * 2, image_width, image_height);
				draw_bar(p/*ixelbuf*/, (94 + xoffset) * 2, 1 * 2, (4 + /*(int)*/Math.floor(yoffset)) * 2, 5 * 2, image_width, image_height);

				textpart[0] = symbol./*->*/text[0];
				textpart[1] = '\0';
				textpos = 2 * (-7 + xoffset);
				draw_string(p/*ixelbuf*/, textpart, textpos, default_text_posn, smalltext, image_width, image_height);
				for(i = 0; i < 6; i++) {
					textpart[i] = symbol./*->*/text[i + 1];
				}
				textpart[6] = '\0';
				textpos = 2 * (24 + xoffset);
				draw_string(p/*ixelbuf*/, textpart, textpos, default_text_posn, smalltext, image_width, image_height);
				for(i = 0; i < 6; i++) {
					textpart[i] = symbol./*->*/text[i + 7];
				}
				textpart[6] = '\0';
				textpos = 2 * (71 + xoffset);
				draw_string(p/*ixelbuf*/, textpart, textpos, default_text_posn, smalltext, image_width, image_height);
				textdone = 1;
				switch(strlen(addon)) {
					case 2:
						textpos = 2 * (xoffset + 114);
						draw_string(p/*ixelbuf*/, addon, textpos, image_height - (addon_text_posn * 2) - 13, smalltext, image_width, image_height);
						break;
					case 5:
						textpos = 2 * (xoffset + 128);
						draw_string(p/*ixelbuf*/, addon, textpos, image_height - (addon_text_posn * 2) - 13, smalltext, image_width, image_height);
						break;
				}
				break;

		}
	}

	if (((symbol./*->*/symbology == BARCODE_UPCA) && (symbol./*->*/rows == 1)) || (symbol./*->*/symbology == BARCODE_UPCA_CC)) {
		/* guard bar extensions and text formatting for UPCA */
		latch = 1;

		i = 0 + comp_offset;
		do {
			block_width = 0;
			do {
				block_width++;
			} while (module_is_set(symbol, symbol./*->*/rows - 1, i + block_width) == module_is_set(symbol, symbol./*->*/rows - 1, i));
			if(latch == 1) {
				/* a bar */
				draw_bar(p/*ixelbuf*/, (i + xoffset - comp_offset) * 2, block_width * 2, (4 + /*(int)*/Math.floor(yoffset)) * 2, 5 * 2, image_width, image_height);
				latch = 0;
			} else {
				/* a space */
				latch = 1;
			}
			i += block_width;
		} while (i < 11 + comp_offset);
		draw_bar(p/*ixelbuf*/, (46 + xoffset) * 2, 1 * 2, (4 + /*(int)*/Math.floor(yoffset)) * 2, 5 * 2, image_width, image_height);
		draw_bar(p/*ixelbuf*/, (48 + xoffset) * 2, 1 * 2, (4 + /*(int)*/Math.floor(yoffset)) * 2, 5 * 2, image_width, image_height);
		latch = 1;
		i = 85 + comp_offset;
		do {
			block_width = 0;
			do {
				block_width++;
			} while (module_is_set(symbol, symbol./*->*/rows - 1, i + block_width) == module_is_set(symbol, symbol./*->*/rows - 1, i));
			if(latch == 1) {
				/* a bar */
				draw_bar(p/*ixelbuf*/, (i + xoffset - comp_offset) * 2, block_width * 2, (4 + /*(int)*/Math.floor(yoffset)) * 2, 5 * 2, image_width, image_height);
				latch = 0;
			} else {
				/* a space */
				latch = 1;
			}
			i += block_width;
		} while (i < 96 + comp_offset);
		textpart[0] = symbol./*->*/text[0];
		textpart[1] = '\0';
		textpos = 2 * (-5 + xoffset);
		draw_string(p/*ixelbuf*/, textpart, textpos, default_text_posn, smalltext, image_width, image_height);
		for(i = 0; i < 5; i++) {
			textpart[i] = symbol./*->*/text[i + 1];
		}
		textpart[5] = '\0';
		textpos = 2 * (27 + xoffset);
		draw_string(p/*ixelbuf*/, textpart, textpos, default_text_posn, smalltext, image_width, image_height);
		for(i = 0; i < 5; i++) {
			textpart[i] = symbol./*->*/text[i + 6];
		}
		textpart[6] = '\0';
		textpos = 2 * (68 + xoffset);
		draw_string(p/*ixelbuf*/, textpart, textpos, default_text_posn, smalltext, image_width, image_height);
		textpart[0] = symbol./*->*/text[11];
		textpart[1] = '\0';
		textpos = 2 * (100 + xoffset);
		draw_string(p/*ixelbuf*/, textpart, textpos, default_text_posn, smalltext, image_width, image_height);
		textdone = 1;
		switch(/*strlen*/(addon.length)) {
			case 2:
				textpos = 2 * (xoffset + 116);
				draw_string(p/*ixelbuf*/, addon, textpos, image_height - (addon_text_posn * 2) - 13, smalltext, image_width, image_height);
				break;
			case 5:
				textpos = 2 * (xoffset + 130);
				draw_string(p/*ixelbuf*/, addon, textpos, image_height - (addon_text_posn * 2) - 13, smalltext, image_width, image_height);
				break;
		}

	}

	if (((symbol./*->*/symbology == BARCODE_UPCE) && (symbol./*->*/rows == 1)) || (symbol./*->*/symbology == BARCODE_UPCE_CC)) {
		/* guard bar extensions and text formatting for UPCE */
		draw_bar(p/*ixelbug*/, (0 + xoffset) * 2, 1 * 2, (4 + /*(int)*/Math.floor(yoffset)) * 2, 5 * 2, image_width, image_height);
		draw_bar(p/*ixelbug*/, (2 + xoffset) * 2, 1 * 2, (4 + /*(int)*/Math.floor(yoffset)) * 2, 5 * 2, image_width, image_height);
		draw_bar(p/*ixelbug*/, (46 + xoffset) * 2, 1 * 2, (4 + /*(int)*/Math.floor(yoffset)) * 2, 5 * 2, image_width, image_height);
		draw_bar(p/*ixelbuf*/, (48 + xoffset) * 2, 1 * 2, (4 + /*(int)*/Math.floor(yoffset)) * 2, 5 * 2, image_width, image_height);
		draw_bar(p/*ixelbuf*/, (50 + xoffset) * 2, 1 * 2, (4 + /*(int)*/Math.floor(yoffset)) * 2, 5 * 2, image_width, image_height);

		textpart[0] = symbol./*->*/text[0];
		textpart[1] = '\0';
		textpos = 2 * (-5 + xoffset);
		draw_string(p/*ixelbuf*/, textpart, textpos, default_text_posn, smalltext, image_width, image_height);
		for(i = 0; i < 6; i++) {
			textpart[i] = symbol./*->*/text[i + 1];
		}
		textpart[6] = '\0';
		textpos = 2 * (24 + xoffset);
		draw_string(p/*ixelbuf*/, textpart, textpos, default_text_posn, smalltext, image_width, image_height);
		textpart[0] = symbol./*->*/text[7];
		textpart[1] = '\0';
		textpos = 2 * (55 + xoffset);
		draw_string(p/*ixelbuf*/, textpart, textpos, default_text_posn, smalltext, image_width, image_height);
		textdone = 1;
		switch(strlen(addon)) {
			case 2:
				textpos = 2 * (xoffset + 70);
				draw_string(p/*ixelbuf*/, addon, textpos, image_height - (addon_text_posn * 2) - 13, smalltext, image_width, image_height);
				break;
			case 5:
				textpos = 2 * (xoffset + 84);
				draw_string(p/*ixelbuf*/, addon, textpos, image_height - (addon_text_posn * 2) - 13, smalltext, image_width, image_height);
				break;
		}

	}

	xoffset -= comp_offset;

	/* Put boundary bars or box around symbol */
	if(((symbol./*->*/output_options & BARCODE_BOX) != 0) || ((symbol./*->*/output_options & BARCODE_BIND) != 0)) {
		/* boundary bars */
		draw_bar(p/*ixelbuf*/, 0, (symbol./*->*/width + xoffset + xoffset) * 2, textoffset * 2, symbol./*->*/border_width * 2, image_width, image_height);
		draw_bar(p/*ixelbuf*/, 0, (symbol./*->*/width + xoffset + xoffset) * 2, (textoffset + symbol./*->*/height + symbol./*->*/border_width) * 2, symbol./*->*/border_width * 2, image_width, image_height);
		if((symbol./*->*/output_options & BARCODE_BIND) != 0) {
			if((symbol./*->*/rows > 1) && (is_stackable(symbol./*->*/symbology) == 1)) {
				/* row binding */
				for(r = 1; r < symbol./*->*/rows; r++) {
					draw_bar(p/*ixelbuf*/, xoffset * 2, symbol./*->*/width * 2, ((r * row_height) + textoffset + yoffset - 1) * 2, 2 * 2, image_width, image_height);
				}
			}
		}
	}

	if((symbol./*->*/output_options & BARCODE_BOX) != 0) {
		/* side bars */
		draw_bar(p/*ixelbuf*/, 0, symbol./*->*/border_width * 2, textoffset * 2, (symbol./*->*/height + (2 * symbol./*->*/border_width)) * 2, image_width, image_height);
		draw_bar(p/*ixelbuf*/, (symbol./*->*/width + xoffset + xoffset - symbol./*->*/border_width) * 2, symbol./*->*/border_width * 2, textoffset * 2, (symbol./*->*/height + (2 * symbol./*->*/border_width)) * 2, image_width, image_height);
	}

	/* Put the human readable text at the bottom */
	if((textdone == 0) && (/*ustrlen*/(local_text.length) != 0)) {
		textpos = (image_width / 2);
		draw_string(p/*ixelbuf*/, /*(char*)*/local_text, textpos, default_text_posn, smalltext, image_width, image_height);
	}

	//error_number=png_to_file(symbol, image_height, image_width, pixelbuf, rotate_angle, data_type);
	//free(pixelbuf);
	return p/*error_number*/;
}

//#ifndef NO_PNG
/*
int png_handle(struct zint_symbol *symbol, int rotate_angle)
{
	int error;

	if(symbol->symbology == BARCODE_MAXICODE) {
		error = maxi_png_plot(symbol, rotate_angle, PNG_DATA);
	} else {

		error = png_plot(symbol, rotate_angle, PNG_DATA);
	}

	return error;
}
*/
//#endif /* NO_PNG */

/*
int bmp_handle(struct zint_symbol *symbol, int rotate_angle)
{
	int error;

	if(symbol->symbology == BARCODE_MAXICODE) {
		error = maxi_png_plot(symbol, rotate_angle, BMP_DATA);
	} else {
		error = png_plot(symbol, rotate_angle, BMP_DATA);
	}

	return error;
}
*/
