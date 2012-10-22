/*  zint.h - definitions for libzint

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

//#ifndef ZINT_H
//#define ZINT_H

//#ifdef __cplusplus
//extern "C" {
//#endif /* __cplusplus */

//#include <stdio.h>

function zint_render_line() {
	//float x, y, length, width;
	//struct zint_render_line *next;      /* Pointer to next line */
    this.x=0;this.y=0;this.length=0;this.width=0;
	this.next=undefined;
}

function zint_render_string() {
	this.x=0;this.y=0;this.fsize=0;//float x, y, fsize;
	this.width=0;//float width;                        /* Suggested string width, may be 0 if none recommended */
	this.length;//int length;
	this.text;//unsigned char *text;
	this.next=null;//struct zint_render_string *next;    /* Pointer to next character */
}

function zint_render_ring() {
	//float x, y, radius, line_width;
	this.x=0;this.y=0;this.radius=0;this.line_width=0;
	//struct zint_render_ring *next;      /* Pointer to next ring */
	this.next=null;
};

/*struct*/ function zint_render_hexagon() {
	this.x=0;this.y=0;//float x, y;
	this.next=null;//struct zint_render_hexagon *next;   /* Pointer to next hexagon */
};

/*struct*/function zint_render() {
	//float width, height;
	this.width=0;this.height=0;
	/*struct zint_render_line**/ this.lines=null;	 	/* Pointer to first line */
	/*struct zint_render_string**/ this.strings=null;	/* Pointer to first string */
	/*struct zint_render_ring**/this.rings=null;         /* Pointer to first ring */
	/*struct zint_render_hexagon**/this.hexagons=null;   /* Pointer to first hexagon */
};

/*struct*/function zint_symbol() {
	/*int*/ this.symbology=0;
	/*int*/ this.height=0;
	/*int*/ this.whitespace_width=0;
	/*int*/this.border_width=0;
	/*int */this.output_options=0;
	/*char*/this.fgcolour="";//new Array(10);
	/*char */this.bgcolour="";//new Array(10);
	/*char */this.outfile="";//[FILENAME_MAX];
	/*float */this.scale=0;
	/*int */this.option_1=0;
	/*int */option_2=0;
	/*int*/ this.option_3=0;
	/*int */this.show_hrt=0;
	/*int */this.input_mode=0;
	/*unsigned char */this.text="";//[128];
	/*int */this.rows=0;
	/*int */this.width=0;
	/*char*/this.primary="";//[128];
	/*char*/this.errtxt=""//[100];
/*#define*/ var ZINT_ROWS_MAX=178;
/*#define*/ var ZINT_COLS_MAX=178
	/*unsigned char encoded_data[ZINT_ROWS_MAX][ZINT_COLS_MAX];*/
	this.encoded_data=[];
	for(var __a=0;__a<ZINT_ROWS_MAX;__a++) {
	var __tmp=[]; 
	for(var __b=0;__b<ZINT_COLS_MAX;__b++) { 
	__tmp.push(0); 
	} 
	this.encoded_data.push(__tmp); 
	}//every element is a string :)
	/*int */this.row_height=[];/*new Array(ZINT_ROWS_MAX);*/for(var __a=0;__a<ZINT_ROWS_MAX;__a++) this.row_height.push(0); /* Largest symbol is 177x177 QR Code */
	/*char **/this.bitmap="";
	/*int*/this.bitmap_width=0;
	/*int*/this.bitmap_height=0;
	/*struct zint_render **/this.rendered=null;
};


/* Tbarcode 7 codes */
var BARCODE_CODE11	=	1
var BARCODE_C25MATRIX=	2
var BARCODE_C25INTER   =3
var BARCODE_C25IATA		=4
var BARCODE_C25LOGIC	=6
var BARCODE_C25IND		=7
var BARCODE_CODE39		=8
var BARCODE_EXCODE39	=9
var BARCODE_EANX		=13
var BARCODE_EAN128		=16
var BARCODE_CODABAR		=18
var BARCODE_CODE128		=20
var BARCODE_DPLEIT		=21
var BARCODE_DPIDENT		=22
var BARCODE_CODE16K		=23
var BARCODE_CODE49		=24
var BARCODE_CODE93		=25
var BARCODE_FLAT		=28
var BARCODE_RSS14		=29
var BARCODE_RSS_LTD		=30
var BARCODE_RSS_EXP		=31
var BARCODE_TELEPEN		=32
var BARCODE_UPCA		=34
var BARCODE_UPCE		=37
var BARCODE_POSTNET		=40
var BARCODE_MSI_PLESSEY	=47
var BARCODE_FIM		=49
var BARCODE_LOGMARS	=	50
var BARCODE_PHARMA	=	51
var BARCODE_PZN		=52
var BARCODE_PHARMA_TWO	=53
var BARCODE_PDF417		=55
var BARCODE_PDF417TRUNC	=56
var BARCODE_MAXICODE	=57
var BARCODE_QRCODE		=58
var BARCODE_CODE128B	=60
var BARCODE_AUSPOST		=63
var BARCODE_AUSREPLY	=66
var BARCODE_AUSROUTE	=67
var BARCODE_AUSREDIRECT	=68
var BARCODE_ISBNX		=69
var BARCODE_RM4SCC		=70
var BARCODE_DATAMATRIX	=71
var BARCODE_EAN14		=72
var BARCODE_CODABLOCKF	=74
var BARCODE_NVE18		=75
var BARCODE_JAPANPOST	=76
var BARCODE_KOREAPOST	=77
var BARCODE_RSS14STACK	=79
var BARCODE_RSS14STACK_OMNI	=80
var BARCODE_RSS_EXPSTACK	=81
var BARCODE_PLANET		=82
var BARCODE_MICROPDF417	=84
var BARCODE_ONECODE		=85
var BARCODE_PLESSEY		=86

/* Tbarcode 8 codes */
var BARCODE_TELEPEN_NUM	=87
var BARCODE_ITF14		=89
var BARCODE_KIX		=90
var BARCODE_AZTEC		=92
var BARCODE_DAFT		=93
var BARCODE_MICROQR		=97

/* Tbarcode 9 codes */
var BARCODE_HIBC_128	=98
var BARCODE_HIBC_39		=99
var BARCODE_HIBC_DM		=102
var BARCODE_HIBC_QR		=104
var BARCODE_HIBC_PDF	=106
var BARCODE_HIBC_MICPDF	=108
var BARCODE_HIBC_BLOCKF	=110
var BARCODE_HIBC_AZTEC	=112

/* Zint specific */
var BARCODE_AZRUNE		=128
var BARCODE_CODE32		=129
var BARCODE_EANX_CC		=130
var BARCODE_EAN128_CC	=131
var BARCODE_RSS14_CC	=132
var BARCODE_RSS_LTD_CC	=133
var BARCODE_RSS_EXP_CC	=134
var BARCODE_UPCA_CC		=135
var BARCODE_UPCE_CC		=136
var BARCODE_RSS14STACK_CC	=137
var BARCODE_RSS14_OMNI_CC	=138
var BARCODE_RSS_EXPSTACK_CC	=139
var BARCODE_CHANNEL		=140
var BARCODE_CODEONE		=141
var BARCODE_GRIDMATRIX	=142

var BARCODE_NO_ASCII	=1
var BARCODE_BIND		=2
var BARCODE_BOX		=4
var BARCODE_STDOUT		=8
var READER_INIT		=16
var SMALL_TEXT		=32

var DATA_MODE	=0
var UNICODE_MODE	=1
var GS1_MODE	=2
var KANJI_MODE	=3
var SJIS_MODE	=4

var DM_SQUARE	=100

var ZWARN_INVALID_OPTION	=2
var ZERROR_TOO_LONG		    =5
var ZERROR_INVALID_DATA	    =6
var ZERROR_INVALID_CHECK	=7
var ZERROR_INVALID_OPTION	=8
var ZERROR_ENCODING_PROBLEM	=9
var ZERROR_FILE_ACCESS	    =10
var ZERROR_MEMORY		    =11

/*#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32)
#  if defined (DLL_EXPORT) || defined(PIC) || defined(_USRDLL)
# 	 define ZINT_EXTERN __declspec(dllexport)
#  elif defined(ZINT_DLL)
#	 define ZINT_EXTERN __declspec(dllimport)
#  else
#    define ZINT_EXTERN extern
#  endif
#else
#  define ZINT_EXTERN extern
#endif*/
/* we do not need these is javascript i guess :)
ZINT_EXTERN struct zint_symbol *ZBarcode_Create(void);
ZINT_EXTERN void ZBarcode_Clear(struct zint_symbol *symbol);
ZINT_EXTERN void ZBarcode_Delete(struct zint_symbol *symbol);

ZINT_EXTERN int ZBarcode_Encode(struct zint_symbol *symbol, unsigned char *input, int length);
ZINT_EXTERN int ZBarcode_Encode_File(struct zint_symbol *symbol, char *filename);
ZINT_EXTERN int ZBarcode_Print(struct zint_symbol *symbol, int rotate_angle);
ZINT_EXTERN int ZBarcode_Encode_and_Print(struct zint_symbol *symbol, unsigned char *input, int length, int rotate_angle);
ZINT_EXTERN int ZBarcode_Encode_File_and_Print(struct zint_symbol *symbol, char *filename, int rotate_angle);

ZINT_EXTERN int ZBarcode_Render(struct zint_symbol *symbol, float width, float height);

ZINT_EXTERN int ZBarcode_Buffer(struct zint_symbol *symbol, int rotate_angle);
ZINT_EXTERN int ZBarcode_Encode_and_Buffer(struct zint_symbol *symbol, unsigned char *input, int length, int rotate_angle);
ZINT_EXTERN int ZBarcode_Encode_File_and_Buffer(struct zint_symbol *symbol, char *filename, int rotate_angle);

ZINT_EXTERN int ZBarcode_ValidID(int symbol_id);
*/

//#ifdef __cplusplus
//}
//#endif /* __cplusplus */

//#endif /* ZINT_H */
