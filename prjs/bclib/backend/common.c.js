/* The most commonly used set */
var NEON="0123456789";

//require("zint.h");

//#ifdef __cplusplus
//extern "C"
//{
//#endif /* __cplusplus */
/*
extern int ustrlen(const unsigned char source[]);
extern void ustrcpy(unsigned char target[], const unsigned char source[]);
extern void concat(char dest[], const char source[]);
extern void uconcat(unsigned char dest[], const unsigned char source[]);
extern int ctoi(char source);
extern char itoc(int source);
extern void to_upper(unsigned char source[]);
extern int is_sane(char test_string[], unsigned char source[], int length);
extern void lookup(char set_string[], const char *table[], char data, char dest[]);
extern int posn(char set_string[], char data);
extern void expand(struct zint_symbol *symbol, char data[]);
extern int is_stackable(int symbology);
extern int is_extendable(int symbology);
extern int roundup(float input);
extern int module_is_set(struct zint_symbol *symbol, int y_coord, int x_coord);
extern void set_module(struct zint_symbol *symbol, int y_coord, int x_coord);
extern void unset_module(struct zint_symbol *symbol, int y_coord, int x_coord);
extern int istwodigits(unsigned char source[], int position);
extern float froundup(float input);
extern int parunmodd(unsigned char llyth);
extern int latin1_process(struct zint_symbol *symbol, unsigned char source[], unsigned char preprocessed[], int *length);
extern int utf8toutf16(struct zint_symbol *symbol, unsigned char source[], int vals[], int *length);
*/
/*static inline void*/function bscan(/*char **/binary, /*int*/ data, /*int*/ h)
{
	for (; h>0; h>>=1) {
		binary+=((data & h)>0 ? "1" : "0");
	}
	return binary;
}


/*int*/function ctoi(/*char*/ source)
{ /* Converts a character 0-9 to its equivalent integer value */
     var zeroCode = "0".charCodeAt(0);
	 var nineCode = "9".charCodeAt(0);
	if((source.charCodeAt(0) >= zeroCode) && (source.charCodeAt(0) <= nineCode))
		return (source.charCodeAt(0) - zeroCode);
	return(source.charCodeAt(0) - "A".charCodeAt(0) + 10);
}

/** Converts an integer value to its hexadecimal character */
/*char*/function itoc(/*int*/ source)
{
     var codeing=["0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"];
//	if ((source >= 0) && (source <= 9)) {
	//	return ('0' + source); }
	//else {
		//return ('A' + (source - 10)); }
		return codeing[source];
}

/** Converts lower case characters to upper case in a string source[] */
/*void to_upper(unsigned char source[])
{
	unsigned int src_len = ustrlen(source);

	for (unsigned int i = 0; i < src_len; i++) {
		if ((source[i] >= 'a') && (source[i] <= 'z')) {
			source[i] = (source[i] - 'a') + 'A'; }
	}
}
*/
/*int*/ function is_sane(/*char */test_string/*[]*/, /*unsigned char */source/*[]*/, /*int*/ length)
{ /* Verifies that a string only uses valid characters */
	/*unsigned int*/var latch;
	/*unsigned int*/var lt = test_string.length;//strlen(test_string);

	for(/*unsigned int*/var i = 0; i < length; i++) {
		latch = false;
		for(/*unsigned int*/var j = 0; j < lt; j++) {
			if (source.charAt(i) == test_string.charAt(j)) {
				latch = true;
				break;
			}
		}
		if (!latch) {
			return /*ZERROR_INVALID_DATA*/false; 
		}
	}

	return true;
}

/*int posn(char set_string[], char data)
{*/ /* Returns the position of data in set_string */
/*	unsigned int n = strlen(set_string);

	for(unsigned int i = 0; i < n; i++)
		if (data == set_string[i])
			return i;
	return 0;
}
*/
/** Replaces huge switch statements for looking up in tables */
/*void*/function lookup(/*char */set_string/*[]*/, /*const char **/table/*[]*/, /*char */data, /*char */dest/*[]*/)
{
	/*unsigned int*/var n = /*strlen*/(set_string.length);

	for(/*unsigned int*/var i = 0; i < n; i++)
		if (data == set_string.charAt(i))
			/*concat*/(dest[0]+=/*,*/ table[i]);
		return dest[0];
}

/*int*/function module_is_set(/*struct zint_symbol **/symbol, /*int*/ y_coord, /*int*/ x_coord)
{
	return ((symbol./*->*/encoded_data[y_coord][Math.floor(x_coord / 7)] >> (x_coord % 7)) & 1>0);
}

/*void*/function set_module(/*struct zint_symbol **/symbol, /*int*/ y_coord, /*int*/ x_coord)
{
	symbol./*->*/encoded_data[y_coord][Math.floor(x_coord / 7)] |= 1 << (x_coord % 7);
}

/*void*/function unset_module(/*struct zint_symbol **/symbol, /*int*/ y_coord, /*int*/ x_coord)
{
	symbol./*->*/encoded_data[y_coord][Math.floor(x_coord / 7)] &= ~(1 << (x_coord % 7));
}

/*void*/function expand(/*struct zint_symbol **/symbol, /*char*/ data/*[]*/)
{ /* Expands from a width pattern to a bit pattern */

	/*unsigned int */var reader, n = /*strlen*/(data.length);
	/*int*/var writer;
	/*char*/var latch;

	writer = 0;
	latch = '1';

	for(reader = 0; reader < n; reader++) {
		for(/*int*/var i = 0; i < ctoi(data[reader]); i++) {
			if(latch == '1') { set_module(symbol, symbol./*->*/rows, writer); }
			writer++;
		}

		latch = (latch == '1' ? '0' : '1');
	}

	if(symbol./*->*/symbology != BARCODE_PHARMA) {
		if(writer > symbol./*->*/width) {
			symbol./*->*/width = writer;
		}
	} else {
		/* Pharmacode One ends with a space - adjust for this */
		if(writer > symbol./*->*/width + 2) {
			symbol./*->*/width = writer - 2;
		}
	}
	symbol./*->*/rows = symbol./*->*/rows + 1;
}

/*int*/function is_stackable(/*int*/ symbology) {
	/* Indicates which symbologies can have row binding */
	if(symbology < BARCODE_PDF417) { return true; }
	if(symbology == BARCODE_CODE128B) { return true; }
	if(symbology == BARCODE_ISBNX) { return true; }
	if(symbology == BARCODE_EAN14) { return true; }
	if(symbology == BARCODE_NVE18) { return true; }
	if(symbology == BARCODE_KOREAPOST) { return true; }
	if(symbology == BARCODE_PLESSEY) { return true; }
	if(symbology == BARCODE_TELEPEN_NUM) { return true; }
	if(symbology == BARCODE_ITF14) { return true; }
	if(symbology == BARCODE_CODE32) { return true; }

	return false;
}

/*int*/function is_extendable(/*int*/ symbology) {
	/* Indicates which symbols can have addon */
	if(symbology == BARCODE_EANX) { return true; }
	if(symbology == BARCODE_UPCA) { return true; }
	if(symbology == BARCODE_UPCE) { return true; }
	if(symbology == BARCODE_ISBNX) { return true; }
	if(symbology == BARCODE_UPCA_CC) { return true; }
	if(symbology == BARCODE_UPCE_CC) { return true; }
	if(symbology == BARCODE_EANX_CC) { return true; }

	return false;
}

/*int*/function roundup(/*float*/ input)
{
	/*float*/ var remainder;
	/*int*/var integer_part;

	integer_part = Math.floor(input);
	remainder = input - integer_part;

	if(remainder > 0.1) {
		integer_part++;
	}

	return integer_part;
}

/*int*/function istwodigits(/*unsigned char */source/*[]*/, /*int*/ position)
{
    var srcp = source.charCodeAt(position);
	var srcp1 = source.charCode(position+1);
	var code0 = "0".charCodeAt(0);
	var code9 = "9".charCodeAt(0);
	if((srcp >= code0) && (srcp <= code9)) {
		if((srcp1 >= code0) && (srcp1 <= code9)) {
			return true;
		}
	}

	return false;
}

/*float*/function froundup(/*float*/ input)
{
	/*float*/var fraction, output = 0.0;

	fraction = input - /*(int)*/Math.floor(input);
	if(fraction > 0.01) { output = (input - fraction) + 1.0; } else { output = input; }

	return output;
}

/*int*/function latin1_process(/*struct zint_symbol **/symbol, /*unsigned char*/ source/*[]*/, /*unsigned char*/ preprocessed/*[]*/, /*int **/length)
{
	/*int*/var j = 0, i = 0, next;

	/* Convert Unicode to Latin-1 for those symbologies which only support Latin-1 */
	do {
		next = -1;
		if(source[i] < 128) {
			preprocessed[j] = source[i];
			j++;
			next = i + 1;
		} else {
			if(source[i] == 0xC2) {
				preprocessed[j] = source[i + 1];
				j++;
				next = i + 2;
			}
			if(source[i] == 0xC3) {
				preprocessed[j] = source[i + 1] + 64;
				j++;
				next = i + 2;
			}
		}
		if(next == -1) {
			strcpy(symbol./*->*/errtxt=/*,*/ "error: Invalid character in input string (only Latin-1 characters supported)");
			return ZERROR_INVALID_DATA;
		}
		i = next;
	} while(i < /***/length[0]);
	preprocessed[j] = '\0';
	/***/length[0] = j;

	return 0;
}

/*int*/function utf8toutf16(/*struct zint_symbol **/symbol, /*unsigned char*/ source/*[]*/, /*int*/ vals/*[]*/, /*int **/length)
{
	/*int*/var bpos, jpos, error_number;
	/*int*/var next;

	bpos = 0;
	jpos = 0;
	error_number = 0;
	next = 0;

	do {
		if(source[bpos] <= 0x7f) {
			/* 1 byte mode (7-bit ASCII) */
			vals[jpos] = source[bpos];
			next = bpos + 1;
			jpos++;
		} else {
			if((source[bpos] >= 0x80) && (source[bpos] <= 0xbf)) {
				/*strcpy*/(symbol./*->*/errtxt=/*,*/ "Corrupt Unicode data");
				return ZERROR_INVALID_DATA;
			}
			if((source[bpos] >= 0xc0) && (source[bpos] <= 0xc1)) {
				/*strcpy*/(symbol./*->*/errtxt=/*,*/ "Overlong encoding not supported");
				return ZERROR_INVALID_DATA;
			}

			if((source[bpos] >= 0xc2) && (source[bpos] <= 0xdf)) {
				/* 2 byte mode */
				vals[jpos] = ((source[bpos] & 0x1f) << 6) + (source[bpos + 1] & 0x3f);
				next = bpos + 2;
				jpos++;
			} else
			if((source[bpos] >= 0xe0) && (source[bpos] <= 0xef)) {
				/* 3 byte mode */
				vals[jpos] = ((source[bpos] & 0x0f) << 12) + ((source[bpos + 1] & 0x3f) << 6) + (source[bpos + 2] & 0x3f);
				next = bpos + 3;
				jpos ++;
			} else
			if(source[bpos] >= 0xf0) {
				/*strcpy*/(symbol./*->*/errtxt=/*,*/ "Unicode sequences of more than 3 bytes not supported");
				return ZERROR_INVALID_DATA;
			}
		}

		bpos = next;

	} while(bpos < /***/length[0]);
	/***/length[0] = jpos;

	return error_number;
}
