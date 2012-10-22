/* svg.c - Scalable Vector Graphics */

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

//#include <locale.h>
//#include <string.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include "common.h"

var SSET="0123456789ABCDEF";

/*int*/function svg_plot(/*struct zint_symbol **/symbol)
{
	/*int*/var i, block_width, latch, r, this_row;
	/*float*/var textpos, large_bar_height, preset_height, row_height, row_posn = 0.0;
	/*FILE **/var fsvg="";
	/*int */var error_number = 0;
	/*int*/var textoffset, xoffset, yoffset, textdone, main_width;
	/*char*/var textpart=[]/*[10]*/, addon=[]/*[6]*/;
	/*int*/var large_bar_count, comp_offset;
	/*float*/var addon_text_posn;
	/*float*/var scaler = symbol./*->*/scale;
	/*float*/var default_text_posn;
	/*int*/var plot_text = 1;
	/*const char **/var locale = null;

	row_height=0;
	textdone = 0;
	main_width = symbol./*->*/width;
	addon="";//strcpy(addon, "");
	comp_offset = 0;
	addon_text_posn = 0.0;

	if((symbol./*->*/output_options & BARCODE_STDOUT) != 0) {
		//fsvg = stdout;
	} else {
		//fsvg = fopen(symbol->outfile, "w");
	}
	if(fsvg == null) {
		//strcpy(symbol->errtxt, "Could not open output file");
		//return ZERROR_FILE_ACCESS;
	}

	/* sort out colour options */
	/*to_upper*/(/*(unsigned char*)*/symbol./*->*/fgcolour=symbol./*->*/fgcolour.toUpperCase());
	/*to_upper*/(/*(unsigned char*)*/symbol./*->*/bgcolour=symbol./*->*/bgcolour.toUpperCase());

	if(/*strlen*/(symbol./*->*/fgcolour.length) != 6) {
		/*strcpy*/(symbol./*->*/errtxt/*,*/= "Malformed foreground colour target");
		return ZERROR_INVALID_OPTION;
	}
	if(/*strlen*/(symbol./*->*/bgcolour.length) != 6) {
		/*strcpy*/(symbol./*->*/errtxt/*,*/= "Malformed background colour target");
		return ZERROR_INVALID_OPTION;
	}
	error_number = is_sane(SSET, /*(unsigned char*)*/symbol./*->*/fgcolour, /*strlen*/(symbol./*->*/fgcolour.length));
	if (!error_number){// == ZERROR_INVALID_DATA) {
		/*strcpy*/(symbol./*->*/errtxt=/*,*/ "Malformed foreground colour target");
		return ZERROR_INVALID_OPTION;
	}
	error_number = is_sane(SSET, /*(unsigned char*)*/symbol./*->*/bgcolour, /*strlen*/(symbol./*->*/bgcolour.length));
	if (!error_number){// == ZERROR_INVALID_DATA) {
		/*strcpy*/(symbol./*->*/errtxt=/*,*/ "Malformed background colour target");
		return ZERROR_INVALID_OPTION;
	}
//	locale = setlocale(LC_ALL, "C");

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
	large_bar_height = (symbol./*->*/height - preset_height) / large_bar_count;

	if (large_bar_count == 0) {
		symbol./*->*/height = preset_height;
	}

	while(!(module_is_set(symbol, symbol./*->*/rows - 1, comp_offset))) {
		comp_offset++;
	}

	/* Certain symbols need whitespace otherwise characters get chopped off the sides */
	if ((((symbol./*->*/symbology == BARCODE_EANX) && (symbol./*->*/rows == 1)) || (symbol./*->*/symbology == BARCODE_EANX_CC))
		|| (symbol./*->*/symbology == BARCODE_ISBNX)) {
		switch(/*ustrlen*/(symbol./*->*/text.length)) {
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
		for(i = 0; i < /*ustrlen*/(symbol./*->*/text.length); i++) {
			if (latch == 1) {
				addon[r] = symbol./*->*/text[i];
				r++;
			}
			if (symbol./*->*/text[i] == '+') {
				latch = 1;
			}
		}
	}
	//addon[r] = '\0';

	if((symbol./*->*/show_hrt == 0) || (/*ustrlen*/(symbol./*->*/text) == 0)) {
		plot_text = 0;
	}
	if(plot_text>0) {
		textoffset = 9;
	} else {
		textoffset = 0;
	}
	xoffset = symbol./*->*/border_width + symbol./*->*/whitespace_width;
	yoffset = symbol./*->*/border_width;

	/* Start writing the header */
	/*fprintf*/(fsvg/*,*/+= "<?xml version=\"1.0\" standalone=\"no\"?>\n");
	/*fprintf*/(fsvg+=/*,*/ "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n");
	/*fprintf*/(fsvg+=/*,*/ "   \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n");
	if(symbol./*->*/symbology != BARCODE_MAXICODE) {
		///*fprintf*/(fsvg+=/*,*/ "<svg width=\""+/*%d*/+"\" height=\""+/*%d*/+"\" version=\"1.1\"\n", roundup((symbol->width + xoffset + xoffset) * scaler), roundup((symbol->height + textoffset + yoffset + yoffset) * scaler));
	fsvg+= "<svg width=\""+roundup((symbol./*->*/width + xoffset + xoffset) * scaler)+"\" height=\""+ roundup((symbol./*->*/height + textoffset + yoffset + yoffset) * scaler)+"\" version=\"1.1\"\n"; 
	} else {
		//fprintf(fsvg, "<svg width=\""+/*%d*/+"\" height=\""+/*%d*/+"\" version=\"1.1\"\n", roundup((74.0 + xoffset + xoffset) * scaler), roundup((72.0 + yoffset + yoffset) * scaler));
	    fsvg+= "<svg width=\""+roundup((74.0 + xoffset + xoffset) * scaler)+"\" height=\""+roundup((72.0 + yoffset + yoffset) * scaler)+"\" version=\"1.1\"\n";
	}
	/*fprintf*/(fsvg+=/*,*/ "   xmlns=\"http://www.w3.org/2000/svg\">\n");
	if(/*ustrlen*/(symbol./*->*/text.length) != 0) {
		/*fprintf*/(fsvg+=/*,*/ "   <desc>"+/*%s*/symbol./*->*/text+"\n" );
	} else {
		/*fprintf*/(fsvg+=/*,*/ "   <desc>Zint Generated Symbol\n");
	}
	/*fprintf*/(fsvg+=/*,*/ "   </desc>\n");
	/*fprintf*/(fsvg+=/*,*/ "\n   <g id=\"barcode\" fill=\"#"+/*%s*/symbol./*->*/fgcolour+"\">\n" );

	if(symbol./*->*/symbology != BARCODE_MAXICODE) {
		/*fprintf*/(fsvg+=/*,*/ "      <rect x=\"0\" y=\"0\" width=\""+/*%d*/roundup((symbol./*->*/width + xoffset + xoffset) * scaler)+"\" height=\""+/*%d*/roundup((symbol./*->*/height + textoffset + yoffset + yoffset) * scaler)+"\" fill=\"#"+/*%s*/symbol./*->*/bgcolour+"\" />\n");
	} else {
		/*fprintf*/(fsvg+=/*,*/ "      <rect x=\"0\" y=\"0\" width=\""+/*%d*/roundup((74.0 + xoffset + xoffset) * scaler)+"\" height=\""+/*%d*/roundup((72.0 + yoffset + yoffset) * scaler)+"\" fill=\"#"+/*%s*/symbol./*->*/bgcolour+"\" />\n");
	}

	if(((symbol./*->*/output_options & BARCODE_BOX) != 0) || ((symbol./*->*/output_options & BARCODE_BIND) != 0)) {
		default_text_posn = (symbol./*->*/height + textoffset + symbol./*->*/border_width + symbol./*->*/border_width) * scaler;
	} else {
		default_text_posn = (symbol./*->*/height + textoffset + symbol./*->*/border_width) * scaler;
	}

	if(symbol./*->*/symbology == BARCODE_MAXICODE) {
		/* Maxicode uses hexagons */
		/*float*/var ax, ay, bx, by, cx, cy, dx, dy, ex, ey, fx, fy, mx, my;


		textoffset = 0.0;
		if (((symbol./*->*/output_options & BARCODE_BOX) != 0) || ((symbol./*->*/output_options & BARCODE_BIND) != 0)) {
			/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/0.0+"\" y=\""+/*%.2f*/0.0+"\" width=\""+/*%.2f*/(74.0 + xoffset + xoffset) * scaler+"\" height=\""+/*%.2f*/symbol./*->*/border_width * scaler+"\" />\n");
			/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/0.0+"\" y=\""+/*%.2f*/(72.0 + symbol./*->*/border_width) * scaler+"\" width=\""+/*%.2f*/(74.0 + xoffset + xoffset) * scaler+"\" height=\""+/*%.2f*/symbol./*->*/border_width * scaler+"\" />\n");
		}
		if((symbol./*->*/output_options & BARCODE_BOX) != 0) {
			/* side bars */
			/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/0.0+"\" y=\""+/*%.2f*/0.0+"\" width=\""+/*%.2f*/symbol./*->*/border_width * scaler+"\" height=\""+/*%.2f*/(72.0 + (2 * symbol./*->*/border_width)) * scaler+"\" />\n");
			/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/(74.0 + xoffset + xoffset - symbol./*->*/border_width) * scaler+"\" y=\""+/*%.2f*/0.0+"\" width=\""+/*%.2f*/symbol./*->*/border_width * scaler+"\" height=\""+/*%.2f*/(72.0 + (2 * symbol./*->*/border_width)) * scaler+"\" />\n" );
		}
		/*fprintf*/(fsvg+=/*,*/ "      <circle cx=\""+/*%.2f*/(35.76 + xoffset) * scaler+"\" cy=\""+/*%.2f*/(35.60 + yoffset) * scaler+"\" r=\""+/*%.2f*/10.85 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/fgcolour+"\" />\n");
		/*fprintf*/(fsvg+=/*,*/ "      <circle cx=\""+/*%.2f*/(35.76 + xoffset) * scaler+"\" cy=\""+/*%.2f*/(35.60 + yoffset) * scaler+"\" r=\""+/*%.2f*/8.97 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/bgcolour+"\" />\n");
		/*fprintf*/(fsvg+=/*,*/ "      <circle cx=\""+/*%.2f*/(35.76 + xoffset) * scaler+"\" cy=\""+/*%.2f*/(35.60 + yoffset) * scaler+"\" r=\""+/*%.2f*/7.10 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/fgcolour+"\" />\n");
		/*fprintf*/(fsvg+=/*,*/ "      <circle cx=\""+/*%.2f*/(35.76 + xoffset) * scaler+"\" cy=\""+/*%.2f*/(35.60 + yoffset) * scaler+"\" r=\""+/*%.2f*/5.22 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/bgcolour+"\" />\n");
		/*fprintf*/(fsvg+=/*,*/ "      <circle cx=\""+/*%.2f*/(35.76 + xoffset) * scaler+"\" cy=\""+/*%.2f*/(35.60 + yoffset) * scaler+"\" r=\""+/*%.2f*/3.31 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/fgcolour+"\" />\n");
		/*fprintf*/(fsvg+=/*,*/ "      <circle cx=\""+/*%.2f*/(35.76 + xoffset) * scaler+"\" cy=\""+/*%.2f*/(35.60 + yoffset) * scaler+"\" r=\""+/*%.2f*/1.43 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/bgcolour+"\" />\n");
		for(r = 0; r < symbol./*->*/rows; r++) {
			for(i = 0; i < symbol./*->*/width; i++) {
				if(module_is_set(symbol, r, i)) {
					/* Dump a hexagon */
					my = r * 2.135 + 1.43;
					ay = my + 1.0 + yoffset;
					by = my + 0.5 + yoffset;
					cy = my - 0.5 + yoffset;
					dy = my - 1.0 + yoffset;
					ey = my - 0.5 + yoffset;
					fy = my + 0.5 + yoffset;
					if(r & 1) {
						mx = (2.46 * i) + 1.23 + 1.23;
					} else {
						mx = (2.46 * i) + 1.23;
					}
					ax = mx + xoffset;
					bx = mx + 0.86 + xoffset;
					cx = mx + 0.86 + xoffset;
					dx = mx + xoffset;
					ex = mx - 0.86 + xoffset;
					fx = mx - 0.86 + xoffset;
					/*fprintf*/(fsvg+=/*,*/ "      <path d=\"M "+/*%.2f*/ax * scaler+" "+/*%.2f*/ay * scaler+" L "+/*%.2f*/bx * scaler+" "+/*%.2f*/by * scaler+" L "+/*%.2f*/cx * scaler+" "+/*%.2f*/cy * scaler+" L "+/*%.2f*/dx * scaler+" "+/*%.2f*/dy * scaler+" L "+/*%.2f*/ex * scaler+" "+/*%.2f*/ey * scaler+" L "+/*%.2f*/fx * scaler+" "+/*%.2f*/fy * scaler+" Z\" />\n");
				}
			}
		}
	}

	if(symbol./*->*/symbology != BARCODE_MAXICODE) {
		/* everything else uses rectangles (or squares) */
		/* Works from the bottom of the symbol up */
		/*int*/var addon_latch = 0;

		for(r = 0; r < symbol./*->*/rows; r++) {
			this_row = r;
			if(symbol./*->*/row_height[this_row] == 0) {
				row_height = large_bar_height;
			} else {
				row_height = symbol./*->*/row_height[this_row];
			}
			row_posn = 0;
			for(i = 0; i < r; i++) {
				if(symbol./*->*/row_height[i] == 0) {
					row_posn += large_bar_height;
				} else {
					row_posn += symbol./*->*/row_height[i];
				}
			}
			row_posn += yoffset;

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
				if((addon_latch == 0) && (r == (symbol./*->*/rows - 1)) && (i > main_width)) {
					addon_text_posn = (row_posn + 8.0) * scaler;
					addon_latch = 1;
				}
				if(latch == 1) {
					/* a bar */
					if(addon_latch == 0) {
						/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/(i + xoffset) * scaler+"\" y=\""+/*%.2f*/row_posn * scaler+"\" width=\""+/*%.2f*/block_width * scaler+"\" height=\""+/*%.2f*/row_height * scaler+"\" />\n");
					} else {
						/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/(i + xoffset) * scaler+"\" y=\""+/*%.2f*/(row_posn + 10.0) * scaler+"\" width=\""+/*%.2f*/block_width * scaler+"\" height=\""+/*%.2f*/(row_height - 5.0) * scaler+"\" />\n");
					}
					latch = 0;
				} else {
					/* a space */
					latch = 1;
				}
				i += block_width;

			} while (i < symbol./*->*/width);
		}
	}
	/* That's done the actual data area, everything else is human-friendly */

	xoffset += comp_offset;
	row_posn = (row_posn + large_bar_height) * scaler;

	if(plot_text) {
		if ((((symbol./*->*/symbology == BARCODE_EANX) && (symbol./*->*/rows == 1)) || (symbol./*->*/symbology == BARCODE_EANX_CC)) ||
			(symbol./*->*/symbology == BARCODE_ISBNX)) {
			/* guard bar extensions and text formatting for EAN8 and EAN13 */
			switch(/*ustrlen*/(symbol./*->*/text.length)) {
				case 8: /* EAN-8 */
				case 11:
				case 14:
					/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/(0 + xoffset) * scaler+"\" y=\""+/*%.2f*/row_posn+"\" width=\""+/*%.2f*/scaler+"\" height=\""+/*%.2f*/5.0 * scaler+"\" />\n");
					/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/(2 + xoffset) * scaler+"\" y=\""+/*%.2f*/row_posn+"\" width=\""+/*%.2f*/scaler+"\" height=\""+/*%.2f*/5.0 * scaler+"\" />\n");
					/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/(32 + xoffset) * scaler+"\" y=\""+/*%.2f*/row_posn+"\" width=\""+/*%.2f*/scaler+"\" height=\""+/*%.2f*/5.0 * scaler+"\" />\n");
					/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/(34 + xoffset) * scaler+"\" y=\""+/*%.2f*/row_posn+"\" width=\""+/*%.2f*/scaler+"\" height=\""+/*%.2f*/5.0 * scaler+"\" />\n");
					/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/(64 + xoffset) * scaler+"\" y=\""+/*%.2f*/row_posn+"\" width=\""+/*%.2f*/scaler+"\" height=\""+/*%.2f*/5.0 * scaler+"\" />\n");
					/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/(66 + xoffset) * scaler+"\" y=\""+/*%.2f*/row_posn+"\" width=\""+/*%.2f*/scaler+"\" height=\""+/*%.2f*/5.0 * scaler+"\" />\n");
					for(i = 0; i < 4; i++) {
						textpart[i] = symbol./*->*/text[i];
					}
					textpart[4] = '\0';
					textpos = 17;
					/*fprintf*/(fsvg+=/*,*/ "      <text x=\""+/*%.2f*/(textpos + xoffset) * scaler+"\" y=\""+/*%.2f*/default_text_posn+"\" text-anchor=\"middle\"\n");
					/*fprintf*/(fsvg+=/*,*/ "         font-family=\"Helvetica\" font-size=\""+/*%.1f*/11.0 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/fgcolour+"\" >\n");
					/*fprintf*/(fsvg+=/*,*/ "         "+/*%s*/textpart+"\n");
					/*fprintf*/(fsvg+=/*,*/ "      </text>\n");
					for(i = 0; i < 4; i++) {
						textpart[i] = symbol./*->*/text[i + 4];
					}
					textpart[4] = '\0';
					textpos = 50;
					/*fprintf*/(fsvg+=/*,*/ "      <text x=\""+/*%.2f*/(textpos + xoffset) * scaler+"\" y=\""+/*%.2f*/default_text_posn+"\" text-anchor=\"middle\"\n");
					/*fprintf*/(fsvg+=/*,*/ "         font-family=\"Helvetica\" font-size=\""+/*%.1f*/11.0 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/fgcolour+"\" >\n");
					/*fprintf*/(fsvg+=/*,*/ "         "+/*%s*/textpart+"\n");
					/*fprintf*/(fsvg+=/*,*/ "      </text>\n");
					textdone = 1;
					switch(/*strlen*/(addon.length)) {
						case 2:
							textpos = xoffset + 86;
							/*fprintf*/(fsvg+=/*,*/ "      <text x=\""+/*%.2f*/textpos * scaler+"\" y=\""+/*%.2f*/addon_text_posn * scaler+"\" text-anchor=\"middle\"\n");
							/*fprintf*/(fsvg+=/*,*/ "         font-family=\"Helvetica\" font-size=\""+/*%.1f*/11.0 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/fgcolour+"\" >\n");
							/*fprintf*/(fsvg+=/*,*/ "         "+/*%s*/addon+"\n");
							/*fprintf*/(fsvg+=/*,*/ "      </text>\n");
							break;
						case 5:
							textpos = xoffset + 100;
							/*fprintf*/(fsvg+=/*,*/ "      <text x=\""+/*%.2f*/textpos * scaler+"\" y=\""+/*%.2f*/addon_text_posn * scaler+"\" text-anchor=\"middle\"\n");
							/*fprintf*/(fsvg+=/*,*/ "         font-family=\"Helvetica\" font-size=\""+/*%.1f*/11.0 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/fgcolour+"\" >\n");
							/*fprintf*/(fsvg+=/*,*/ "         "+/*%s*/addon+"\n");
							/*fprintf*/(fsvg+=/*,*/ "      </text>\n");
							break;
					}

					break;
				case 13: /* EAN 13 */
				case 16:
				case 19:
					/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/(0 + xoffset) * scaler+"\" y=\""+/*%.2f*/row_posn+"\" width=\""+/*%.2f*/scaler+"\" height=\""+/*%.2f*/5.0 * scaler+"\" />\n");
					/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/(2 + xoffset) * scaler+"\" y=\""+/*%.2f*/row_posn+"\" width=\""+/*%.2f*/scaler+"\" height=\""+/*%.2f*/5.0 * scaler+"\" />\n");
					/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/(46 + xoffset) * scaler+"\" y=\""+/*%.2f*/row_posn+"\" width=\""+/*%.2f*/scaler+"\" height=\""+/*%.2f*/5.0 * scaler+"\" />\n");
					/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/(48 + xoffset) * scaler+"\" y=\""+/*%.2f*/row_posn+"\" width=\""+/*%.2f*/scaler+"\" height=\""+/*%.2f*/5.0 * scaler+"\" />\n");
					/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/(92 + xoffset) * scaler+"\" y=\""+/*%.2f*/row_posn+"\" width=\""+/*%.2f*/scaler+"\" height=\""+/*%.2f*/5.0 * scaler+"\" />\n");
					/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/(94 + xoffset) * scaler+"\" y=\""+/*%.2f*/row_posn+"\" width=\""+/*%.2f*/scaler+"\" height=\""+/*%.2f*/5.0 * scaler+"\" />\n");
					textpart[0] = symbol./*->*/text[0];
					textpart[1] = '\0';
					textpos = -7;
					/*fprintf*/(fsvg+=/*,*/ "      <text x=\""+/*%.2f*/(textpos + xoffset) * scaler+"\" y=\""+/*%.2f*/default_text_posn+"\" text-anchor=\"middle\"\n");
					/*fprintf*/(fsvg+=/*,*/ "         font-family=\"Helvetica\" font-size=\""+/*%.1f*/11.0 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/fgcolour+"\" >\n");
					/*fprintf*/(fsvg+=/*,*/ "         "+/*%s*/textpart+"\n");
					/*fprintf*/(fsvg+=/*,*/ "      </text>\n");
					for(i = 0; i < 6; i++) {
						textpart[i] = symbol./*->*/text[i + 1];
					}
					textpart[6] = '\0';
					textpos = 24;
					/*fprintf*/(fsvg+=/*,*/ "      <text x=\""+/*%.2f*/(textpos + xoffset) * scaler+"\" y=\""+/*%.2f*/default_text_posn+"\" text-anchor=\"middle\"\n");
					/*fprintf*/(fsvg+=/*,*/ "         font-family=\"Helvetica\" font-size=\""+/*%.1f*/11.0 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/fgcolour+"\" >\n");
					/*fprintf*/(fsvg+=/*,*/ "         "+/*%s*/textpart+"\n");
					/*fprintf*/(fsvg+=/*,*/ "      </text>\n");
					for(i = 0; i < 6; i++) {
						textpart[i] = symbol./*->*/text[i + 7];
					}
					textpart[6] = '\0';
					textpos = 71;
					/*fprintf*/(fsvg+=/*,*/ "      <text x=\""+/*%.2f*/(textpos + xoffset) * scaler+"\" y=\""+/*%.2f*/default_text_posn+"\" text-anchor=\"middle\"\n");
					/*fprintf*/(fsvg+=/*,*/ "         font-family=\"Helvetica\" font-size=\""+/*%.1f*/11.0 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/fgcolour+"\" >\n");
					/*fprintf*/(fsvg+=/*,*/ "         "+/*%s*/textpart+"\n");
					/*fprintf*/(fsvg+=/*,*/ "      </text>\n");
					textdone = 1;
					switch(/*strlen*/(addon.length)) {
						case 2:
							textpos = xoffset + 114;
							/*fprintf*/(fsvg+=/*,*/ "      <text x=\""+/*%.2f*/textpos * scaler+"\" y=\""+/*%.2f*/addon_text_posn * scaler+"\" text-anchor=\"middle\"\n");
							/*fprintf*/(fsvg+=/*,*/ "         font-family=\"Helvetica\" font-size=\""+/*%.1f*/11.0 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/fgcolour+"\" >\n");
							/*fprintf*/(fsvg+=/*,*/ "         "+/*%s*/addon+"\n");
							/*fprintf*/(fsvg+=/*,*/ "      </text>\n");
							break;
						case 5:
							textpos = xoffset + 128;
							/*fprintf*/(fsvg+=/*,*/ "      <text x=\""+/*%.2f*/textpos * scaler+"\" y=\""+/*%.2f*/addon_text_posn * scaler+"\" text-anchor=\"middle\"\n");
							/*fprintf*/(fsvg+=/*,*/ "         font-family=\"Helvetica\" font-size=\""+/*%.1f*/11.0 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/fgcolour+"\" >\n");
							/*fprintf*/(fsvg+=/*,*/ "         "+/*%s*/addon+"\n");
							/*fprintf*/(fsvg+=/*,*/ "      </text>\n");
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
					/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/(i + xoffset - comp_offset) * scaler+"\" y=\""+/*%.2f*/row_posn+"\" width=\""+/*%.2f*/block_width * scaler+"\" height=\""+/*%.2f*/5.0 * scaler+"\" />\n");
					latch = 0;
				} else {
					/* a space */
					latch = 1;
				}
				i += block_width;
			} while (i < 11 + comp_offset);
			/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/(46 + xoffset) * scaler+"\" y=\""+/*%.2f*/row_posn+"\" width=\""+/*%.2f*/scaler+"\" height=\""+/*%.2f*/5.0 * scaler+"\" />\n");
			/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/(48 + xoffset) * scaler+"\" y=\""+/*%.2f*/row_posn+"\" width=\""+/*%.2f*/scaler+"\" height=\""+/*%.2f*/5.0 * scaler+"\" />\n");
			latch = 1;
			i = 85 + comp_offset;
			do {
				block_width = 0;
				do {
					block_width++;
				} while (module_is_set(symbol, symbol./*->*/rows - 1, i + block_width) == module_is_set(symbol, symbol./*->*/rows - 1, i));
				if(latch == 1) {
					/* a bar */
					/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/(i + xoffset - comp_offset) * scaler+"\" y=\""+/*%.2f*/row_posn+"\" width=\""+/*%.2f*/block_width * scaler+"\" height=\""+/*%.2f*/5.0 * scaler+"\" />\n");
					latch = 0;
				} else {
					/* a space */
					latch = 1;
				}
				i += block_width;
			} while (i < 96 + comp_offset);
			textpart[0] = symbol./*->*/text[0];
			textpart[1] = '\0';
			textpos = -5;
			/*fprintf*/(fsvg+=/*,*/ "      <text x=\""+/*%.2f*/(textpos + xoffset) * scaler+"\" y=\""+/*%.2f*/default_text_posn+"\" text-anchor=\"middle\"\n");
			/*fprintf*/(fsvg+=/*,*/ "         font-family=\"Helvetica\" font-size=\""+/*%.1f*/8.0 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/fgcolour+"\" >\n");
			/*fprintf*/(fsvg+=/*,*/ "         "+/*%s*/textpart+"\n");
			/*fprintf*/(fsvg+=/*,*/ "      </text>\n");
			for(i = 0; i < 5; i++) {
				textpart[i] = symbol./*->*/text[i + 1];
			}
			textpart[5] = '\0';
			textpos = 27;
//			/*fprintf*/(fsvg+=/*,*/ "      <text x=\""+/*%.2f*/+"\" y=\""+/*%.2f*/+"\" text-anchor=\"middle\"\n", (textpos + xoffset) * scaler, default_text_posn);
//			/*fprintf*/(fsvg+=/*,*/ "         font-family=\"Helvetica\" font-size=\""+/*%.1f*/+"\" fill=\"#"+/*%s*/+"\" >\n", 11.0 * scaler, symbol./*->*/fgcolour);
//			/*fprintf*/(fsvg+=/*,*/ "         "+/*%s*/+"\n", textpart);
//			/*fprintf*/(fsvg+=/*,*/ "      </text>\n");
			/*fprintf*/(fsvg+=/*,*/ "      <text x=\""+/*%.2f*/(textpos + xoffset) * scaler+"\" y=\""+/*%.2f*/default_text_posn+"\" text-anchor=\"middle\"\n");
			/*fprintf*/(fsvg+=/*,*/ "         font-family=\"Helvetica\" font-size=\""+/*%.1f*/11.0 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/fgcolour+"\" >\n");
			/*fprintf*/(fsvg+=/*,*/ "         "+/*%s*/textpart+"\n");
			/*fprintf*/(fsvg+=/*,*/ "      </text>\n");			
			for(i = 0; i < 5; i++) {
				textpart[i] = symbol./*->*/text[i + 6];
			}
			textpart[6] = '\0';
			textpos = 68;
//			/*fprintf*/(fsvg+=/*,*/ "      <text x=\""+/*%.2f*/+"\" y=\""+/*%.2f*/+"\" text-anchor=\"middle\"\n", (textpos + xoffset) * scaler, default_text_posn);
//			/*fprintf*/(fsvg+=/*,*/ "         font-family=\"Helvetica\" font-size=\""+/*%.1f*/+"\" fill=\"#"+/*%s*/+"\" >\n", 11.0 * scaler, symbol./*->*/fgcolour);
//			/*fprintf*/(fsvg+=/*,*/ "         "+/*%s*/+"\n", textpart);
//			/*fprintf*/(fsvg+=/*,*/ "      </text>\n");
			/*fprintf*/(fsvg+=/*,*/ "      <text x=\""+/*%.2f*/(textpos + xoffset) * scaler+"\" y=\""+/*%.2f*/default_text_posn+"\" text-anchor=\"middle\"\n");
			/*fprintf*/(fsvg+=/*,*/ "         font-family=\"Helvetica\" font-size=\""+/*%.1f*/11.0 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/fgcolour+"\" >\n");
			/*fprintf*/(fsvg+=/*,*/ "         "+/*%s*/textpart+"\n");
			/*fprintf*/(fsvg+=/*,*/ "      </text>\n");			
			textpart[0] = symbol./*->*/text[11];
			textpart[1] = '\0';
			textpos = 100;
		//	/*fprintf*/(fsvg+=/*,*/ "      <text x=\""+/*%.2f*/+"\" y=\""+/*%.2f*/+"\" text-anchor=\"middle\"\n", (textpos + xoffset) * scaler, default_text_posn);
		//	/*fprintf*/(fsvg+=/*,*/ "         font-family=\"Helvetica\" font-size=\""+/*%.1f*/+"\" fill=\"#"+/*%s*/+"\" >\n", 8.0 * scaler, symbol./*->*/fgcolour);
		//	/*fprintf*/(fsvg+=/*,*/ "         "+/*%s*/+"\n", textpart);
		//	/*fprintf*/(fsvg+=/*,*/ "      </text>\n");
			/*fprintf*/(fsvg+=/*,*/ "      <text x=\""+/*%.2f*/(textpos + xoffset) * scaler+"\" y=\""+/*%.2f*/default_text_posn+"\" text-anchor=\"middle\"\n");
			/*fprintf*/(fsvg+=/*,*/ "         font-family=\"Helvetica\" font-size=\""+/*%.1f*/8.0 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/fgcolour+"\" >\n");
			/*fprintf*/(fsvg+=/*,*/ "         "+/*%s*/textpart+"\n");
			/*fprintf*/(fsvg+=/*,*/ "      </text>\n");			
			textdone = 1;
			switch(/*strlen*/(addon.length)) {
				case 2:
					textpos = xoffset + 116;
					/*fprintf*/(fsvg+=/*,*/ "      <text x=\""+/*%.2f*/textpos * scaler+"\" y=\""+/*%.2f*/addon_text_posn * scaler+"\" text-anchor=\"middle\"\n");
					/*fprintf*/(fsvg+=/*,*/ "         font-family=\"Helvetica\" font-size=\""+/*%.1f*/11.0 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/fgcolour+"\" >\n");
					/*fprintf*/(fsvg+=/*,*/ "         "+/*%s*/addon+"\n");
					/*fprintf*/(fsvg+=/*,*/ "      </text>\n");
					break;
				case 5:
					textpos = xoffset + 130;
					/*fprintf*/(fsvg+=/*,*/ "      <text x=\""+/*%.2f*/textpos * scaler+"\" y=\""+/*%.2f*/addon_text_posn * scaler+"\" text-anchor=\"middle\"\n");
					/*fprintf*/(fsvg+=/*,*/ "         font-family=\"Helvetica\" font-size=\""+/*%.1f*/11.0 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/fgcolour+"\" >\n");
					/*fprintf*/(fsvg+=/*,*/ "         "+/*%s*/addon+"\n");
					/*fprintf*/(fsvg+=/*,*/ "      </text>\n");
					break;
			}

		}

		if (((symbol./*->*/symbology == BARCODE_UPCE) && (symbol./*->*/rows == 1)) || (symbol./*->*/symbology == BARCODE_UPCE_CC)) {
			/* guard bar extensions and text formatting for UPCE */
			/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/(0 + xoffset) * scaler+"\" y=\""+/*%.2f*/row_posn+"\" width=\""+/*%.2f*/scaler+"\" height=\""+/*%.2f*/5.0 * scaler+"\" />\n");
			/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/(2 + xoffset) * scaler+"\" y=\""+/*%.2f*/row_posn+"\" width=\""+/*%.2f*/scaler+"\" height=\""+/*%.2f*/5.0 * scaler+"\" />\n");
			/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/(46 + xoffset) * scaler+"\" y=\""+/*%.2f*/row_posn+"\" width=\""+/*%.2f*/scaler+"\" height=\""+/*%.2f*/5.0 * scaler+"\" />\n");
			/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/(48 + xoffset) * scaler+"\" y=\""+/*%.2f*/row_posn+"\" width=\""+/*%.2f*/scaler+"\" height=\""+/*%.2f*/5.0 * scaler+"\" />\n");
			/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/(50 + xoffset) * scaler+"\" y=\""+/*%.2f*/row_posn+"\" width=\""+/*%.2f*/scaler+"\" height=\""+/*%.2f*/5.0 * scaler+"\" />\n");
			textpart[0] = symbol./*->*/text[0];
			textpart[1] = '\0';
			textpos = -5;
			/*fprintf*/(fsvg+=/*,*/ "      <text x=\""+/*%.2f*/(textpos + xoffset) * scaler+"\" y=\""+/*%.2f*/default_text_posn+"\" text-anchor=\"middle\"\n");
			/*fprintf*/(fsvg+=/*,*/ "         font-family=\"Helvetica\" font-size=\""+/*%.1f*/ 8.0 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/fgcolour+"\" >\n");
			/*fprintf*/(fsvg+=/*,*/ "         "+/*%s*/textpart+"\n");
			/*fprintf*/(fsvg+=/*,*/ "      </text>\n");
			for(i = 0; i < 6; i++) {
				textpart[i] = symbol./*->*/text[i + 1];
			}
			textpart[6] = '\0';
			textpos = 24;
			/*fprintf*/(fsvg+=/*,*/ "      <text x=\""+/*%.2f*/(textpos + xoffset) * scaler+"\" y=\""+/*%.2f*/default_text_posn+"\" text-anchor=\"middle\"\n");
			/*fprintf*/(fsvg+=/*,*/ "         font-family=\"Helvetica\" font-size=\""+/*%.1f*/11.0 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/fgcolour+"\" >\n");
			/*fprintf*/(fsvg+=/*,*/ "         "+/*%s*/textpart+"\n");
			/*fprintf*/(fsvg+=/*,*/ "      </text>\n");
			textpart[0] = symbol./*->*/text[7];
			textpart[1] = '\0';
			textpos = 55;
			/*fprintf*/(fsvg+=/*,*/ "      <text x=\""+/*%.2f*/(textpos + xoffset) * scaler+"\" y=\""+/*%.2f*/default_text_posn+"\" text-anchor=\"middle\"\n");
			/*fprintf*/(fsvg+=/*,*/ "         font-family=\"Helvetica\" font-size=\""+/*%.1f*/8.0 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/fgcolour+"\" >\n");
			/*fprintf*/(fsvg+=/*,*/ "         "+/*%s*/textpart+"\n");
			/*fprintf*/(fsvg+=/*,*/ "      </text>\n");
			textdone = 1;
			switch(/*strlen*/(addon.length)) {
				case 2:
					textpos = xoffset + 70;
					/*fprintf*/(fsvg+=/*,*/ "      <text x=\""+/*%.2f*/textpos * scaler+"\" y=\""+/*%.2f*/addon_text_posn * scaler+"\" text-anchor=\"middle\"\n");
					/*fprintf*/(fsvg+=/*,*/ "         font-family=\"Helvetica\" font-size=\""+/*%.1f*/11.0 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/fgcolour+"\" >\n");
					/*fprintf*/(fsvg+=/*,*/ "         "+/*%s*/addon+"\n");
					/*fprintf*/(fsvg+=/*,*/ "      </text>\n");
					break;
				case 5:
					textpos = xoffset + 84;
					/*fprintf*/(fsvg+=/*,*/ "      <text x=\""+/*%.2f*/textpos * scaler+"\" y=\""+/*%.2f*/ addon_text_posn * scaler+"\" text-anchor=\"middle\"\n");
					/*fprintf*/(fsvg+=/*,*/ "         font-family=\"Helvetica\" font-size=\""+/*%.1f*/11.0 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/fgcolour+"\" >\n");
					/*fprintf*/(fsvg+=/*,*/ "         "+/*%s*/addon+"\n");
					/*fprintf*/(fsvg+=/*,*/ "      </text>\n");
					break;
			}

		}
	} /* if (plot_text) */

	xoffset -= comp_offset;

	switch(symbol./*->*/symbology) {
		case BARCODE_MAXICODE:
			/* Do nothing! (It's already been done) */
			break;
		default:
			if((symbol./*->*/output_options & BARCODE_BIND) != 0) {
				if((symbol./*->*/rows > 1) && (is_stackable(symbol./*->*/symbology) == 1)) {
					/* row binding */
					for(r = 1; r < symbol./*->*/rows; r++) {
						/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/xoffset * scaler+"\" y=\""+/*%.2f*/((r * row_height) + yoffset - 1) * scaler+"\" width=\""+/*%.2f*/symbol./*->*/width * scaler+"\" height=\""+/*%.2f*/2.0 * scaler+"\" />\n");
					}
				}
			}
			if (((symbol./*->*/output_options & BARCODE_BOX) != 0) || ((symbol./*->*/output_options & BARCODE_BIND) != 0)) {
				/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/0.0+"\" y=\""+/*%.2f*/0.0+"\" width=\""+/*%.2f*/(symbol./*->*/width + xoffset + xoffset) * scaler+"\" height=\""+/*%.2f*/symbol./*->*/border_width * scaler+"\" />\n");
				/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/0.0+"\" y=\""+/*%.2f*/(symbol./*->*/height + symbol./*->*/border_width) * scaler+"\" width=\""+/*%.2f*/(symbol./*->*/width + xoffset + xoffset) * scaler+"\" height=\""+/*%.2f*/symbol./*->*/border_width * scaler+"\" />\n");
			}
			if((symbol./*->*/output_options & BARCODE_BOX) != 0) {
				/* side bars */
				/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/0.0+"\" y=\""+/*%.2f*/0.0+"\" width=\""+/*%.2f*/symbol./*->*/border_width * scaler+"\" height=\""+/*%.2f*/(symbol./*->*/height + (2 * symbol./*->*/border_width)) * scaler+"\" />\n");
				/*fprintf*/(fsvg+=/*,*/ "      <rect x=\""+/*%.2f*/(symbol./*->*/width + xoffset + xoffset - symbol./*->*/border_width) * scaler+"\" y=\""+/*%.2f*/0.0+"\" width=\""+/*%.2f*/symbol./*->*/border_width * scaler+"\" height=\""+/*%.2f*/(symbol./*->*/height + (2 * symbol./*->*/border_width)) * scaler+"\" />\n");
			}
			break;
	}

	/* Put the human readable text at the bottom */
	if(plot_text && (textdone == 0)) {
		textpos = symbol./*->*/width / 2.0;
		/*fprintf*/(fsvg, "      <text x=\""+/*%.2f*/(textpos + xoffset) * scaler+"\" y=\""+/*%.2f*/default_text_posn+"\" text-anchor=\"middle\"\n");
		/*fprintf*/(fsvg, "         font-family=\"Helvetica\" font-size=\""+/*%.1f*/8.0 * scaler+"\" fill=\"#"+/*%s*/symbol./*->*/fgcolour+"\" >\n");
		/*fprintf*/(fsvg, "         "+/*%s*/symbol./*->*/text+"\n");
		/*fprintf*/(fsvg, "      </text>\n");
	}
	/*fprintf*/(fsvg+=/*,*/ "   </g>\n");
	/*fprintf*/(fsvg+=/*,*/ "</svg>\n");

	//fclose(fsvg);

	//if (locale)
		//setlocale(LC_ALL, locale);

	return fsvg;
}

