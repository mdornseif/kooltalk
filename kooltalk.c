#include <stdio.h>   
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define VERSION "2.1.0"

typedef char stringtype[5];
typedef struct listtype {
  char character;   
  stringtype kool[4];
} listtype;
typedef listtype list[26];
static list koolset;  
static int use_heavy_koolness;
static char filename[256];

static void heavy_koolness()
{
  char c;
  stringtype s;
  short n, i;
  FILE *infile;
  
  if (strlen(filename)>0) {
  	infile = fopen(filename, "r");
	if (infile == NULL) {
		fprintf (stderr, "Couldn't open %s\n", filename);
		exit(1);
	}
}	
else infile = stdin;

while (!feof(infile)) {
	c = fgetc(infile);
	if (c >= 65 && c <= 90)
	c += 32;
	if ((c < 97 || c > 122) && (!feof(infile)))
     	putchar(c);
	if (c < 97 || c > 122)
	continue;
    i = 0;
    while (i <= 25) {  
      if (c == koolset[i].character) {
	n = 1+(int) (3.0*rand()/(RAND_MAX+1.0));
	strcpy(s, koolset[i].kool[n]);
	if (!feof(infile)) {fputs(s, stdout);}   
	i = 26; 
      }
      i++;   
    }
  }
}

static void light_koolness()
{
    char c, d;
    stringtype s;
    FILE *infile;
  
    if (strlen(filename)>0) {
  	infile = fopen(filename, "r");
	if (infile == NULL) {
		fprintf (stderr, "Couldn't open %s\n", filename);
		exit(1);
	}
    }	
    else infile = stdin; 
    while (!feof(infile)) {
    c = fgetc(infile);
    if (feof(infile)) {break;}
    switch (c) {
    case 'i': 
    case 'I': strcpy (s, "1"); fputs(s,stdout); break;
    case 'e': 
    case 'E': strcpy (s, "3"); fputs(s,stdout); break;
    case 'o': 
    case 'O': strcpy (s, "0"); fputs(s,stdout); break;
    case 'f': strcpy (s, "ph"); fputs(s,stdout); break;
    case 'F': strcpy (s, "Ph"); fputs(s,stdout); break;
    case 's': 
    		d = fgetc(infile);
    		if (feof(infile)) {break;} 
    		switch (d) {
			case ' ':
			case '\n':
			case '\t':
			case ',':
			case '.':
			case '?':
			case '!':
			case ';':
			case '-':
			case '_': strcpy (s, "z"); fputs(s,stdout); 
				  putchar(d); break;
			default: putchar(c); putchar(d); break;
		}
		break;
    default: putchar(c);
    } 
  }
}

static void check_params(argc, argv)
int argc;
char *argv[];
{
  char c;
  
  while ((c = getopt(argc, argv, "clh")) !=EOF) {
	switch (c){
        case 'c':
  	printf ("kooltalk %s -- phOR eLi~|~E 0nL`!\n\n", VERSION);
  	printf ("%s", 
"The following copyright statement covers all of kooltalk - either text or
the binary code compiled from the source text.

Copyright (c) 1994-1998 Jens Ohlig <jo@koeln.ccc.de>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
	This product includes software developed by Jens Ohlig
	and contributors.
4. Neither the name of the author nor the names of any co-contributors
   may be used to endorse or promote products derived from this software
   without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
SUCH DAMAGE.\n");
	exit(0);
	case 'h': printf ("kooltalk %s -- phOR eLi~|~E 0nL`!\n", VERSION);
		  printf ("%s", "Usage:\n");
		  printf ("%s", "\tkooltalk [options] [file]\n");
		  printf ("%s", "Options:\n");
		  printf ("%s", "\t-l use light koolness ");
		  printf ("%s", "(heavy koolness is default)\n");
	          printf ("%s", "\t-c display the copying license\n");
		  printf ("%s", "\t-h display this help\n"); 
		  exit(0);
	case 'l': use_heavy_koolness = 0; break;
    }
  }
if (argc > optind) strcpy (filename, argv[optind]);
else strcpy (filename, "\0");
if (strchr(filename, 45) != NULL) strcpy (filename, "\0");
}

static void init()
{
  koolset[0].character = 'a';
  koolset[1].character = 'b';
  koolset[2].character = 'c';
  koolset[3].character = 'd';
  koolset[4].character = 'e';
  koolset[5].character = 'f';
  koolset[6].character = 'g';
  koolset[7].character = 'h';
  koolset[8].character = 'i';
  koolset[9].character = 'j';
  koolset[10].character = 'k';
  koolset[11].character = 'l';
  koolset[12].character = 'm';
  koolset[13].character = 'n';
  koolset[14].character = 'o';
  koolset[15].character = 'p';
  koolset[16].character = 'q';
  koolset[17].character = 'r';
  koolset[18].character = 's';
  koolset[19].character = 't';
  koolset[20].character = 'u';
  koolset[21].character = 'v';
  koolset[22].character = 'w';
  koolset[23].character = 'x';
  koolset[24].character = 'y';
  koolset[25].character = 'z';
  strcpy(koolset[0].kool[0], "a");
  strcpy(koolset[0].kool[1], "A");
  strcpy(koolset[0].kool[2], "@");
  strcpy(koolset[0].kool[3], "a");
  strcpy(koolset[1].kool[0], "b");
  strcpy(koolset[1].kool[1], "B");
  strcpy(koolset[1].kool[2], "|3");
  strcpy(koolset[1].kool[3], "b");
  strcpy(koolset[2].kool[0], "c");
  strcpy(koolset[2].kool[1], "C");
  strcpy(koolset[2].kool[2], "(");
  strcpy(koolset[2].kool[3], "[");
  strcpy(koolset[3].kool[0], "d");
  strcpy(koolset[3].kool[1], "D");
  strcpy(koolset[3].kool[2], "c|");
  strcpy(koolset[3].kool[3], "|)");
  strcpy(koolset[4].kool[0], "e");
  strcpy(koolset[4].kool[1], "E");
  strcpy(koolset[4].kool[2], "3");
  strcpy(koolset[4].kool[3], "[-");
  strcpy(koolset[5].kool[0], "f");
  strcpy(koolset[5].kool[1], "F");
  strcpy(koolset[5].kool[2], "/=");
  strcpy(koolset[5].kool[3], "ph");
  strcpy(koolset[6].kool[0], "g");
  strcpy(koolset[6].kool[1], "G");
  strcpy(koolset[6].kool[2], "9");
  strcpy(koolset[6].kool[3], "g");
  strcpy(koolset[7].kool[0], "h");
  strcpy(koolset[7].kool[1], "H");
  strcpy(koolset[7].kool[2], "#");
  strcpy(koolset[7].kool[3], "|-|");
  strcpy(koolset[8].kool[0], "i");
  strcpy(koolset[8].kool[1], "I");
  strcpy(koolset[8].kool[2], "1");
  strcpy(koolset[8].kool[3], "!");
  strcpy(koolset[9].kool[0], "j");
  strcpy(koolset[9].kool[1], "J");
  strcpy(koolset[9].kool[2], "_/");
  strcpy(koolset[9].kool[3], "j");
  strcpy(koolset[10].kool[0], "k");
  strcpy(koolset[10].kool[1], "K");
  strcpy(koolset[10].kool[2], "|<");
  strcpy(koolset[10].kool[3], "k");
  strcpy(koolset[11].kool[0], "l");
  strcpy(koolset[11].kool[1], "L");
  strcpy(koolset[11].kool[2], "|_");
  strcpy(koolset[11].kool[3], "/_");
  strcpy(koolset[12].kool[0], "m");
  strcpy(koolset[12].kool[1], "M");
  strcpy(koolset[12].kool[2], "|\\/|");
  strcpy(koolset[12].kool[3], "m");
  strcpy(koolset[13].kool[0], "n");
  strcpy(koolset[13].kool[1], "N");
  strcpy(koolset[13].kool[2], "|\\|");
  strcpy(koolset[13].kool[3], "/v");
  strcpy(koolset[14].kool[0], "o");
  strcpy(koolset[14].kool[1], "O");
  strcpy(koolset[14].kool[2], "0");
  strcpy(koolset[14].kool[3], "()");
  strcpy(koolset[15].kool[0], "p");
  strcpy(koolset[15].kool[1], "P");
  strcpy(koolset[15].kool[2], "/>");
  strcpy(koolset[15].kool[3], "p");
  strcpy(koolset[16].kool[0], "q");
  strcpy(koolset[16].kool[1], "Q");
  strcpy(koolset[16].kool[2], "(,)");
  strcpy(koolset[16].kool[3], "q");
  strcpy(koolset[17].kool[0], "r");
  strcpy(koolset[17].kool[1], "R");
  strcpy(koolset[17].kool[2], "/~");
  strcpy(koolset[17].kool[3], "/^");
  strcpy(koolset[18].kool[0], "s");
  strcpy(koolset[18].kool[1], "S");
  strcpy(koolset[18].kool[2], "5");
  strcpy(koolset[18].kool[3], "$");
  strcpy(koolset[19].kool[0], "t");
  strcpy(koolset[19].kool[1], "T");
  strcpy(koolset[19].kool[2], "+");
  strcpy(koolset[19].kool[3], "~|~");
  strcpy(koolset[20].kool[0], "u");
  strcpy(koolset[20].kool[1], "U");
  strcpy(koolset[20].kool[2], "(_)");
  strcpy(koolset[20].kool[3], "|_|");
  strcpy(koolset[21].kool[0], "v");
  strcpy(koolset[21].kool[1], "V");
  strcpy(koolset[21].kool[2], "\\/");
  strcpy(koolset[21].kool[3], "v");
  strcpy(koolset[22].kool[0], "w");
  strcpy(koolset[22].kool[1], "W");
  strcpy(koolset[22].kool[2], "|/\\|");
  strcpy(koolset[22].kool[3], "\\/\\/");
  strcpy(koolset[23].kool[0], "x");
  strcpy(koolset[23].kool[1], "X");
  strcpy(koolset[23].kool[2], "><");
  strcpy(koolset[23].kool[3], "x");
  strcpy(koolset[24].kool[0], "y");
  strcpy(koolset[24].kool[1], "Y");
  strcpy(koolset[24].kool[2], "`/");
  strcpy(koolset[24].kool[3], "v/");
  strcpy(koolset[25].kool[0], "z");
  strcpy(koolset[25].kool[1], "Z");
  strcpy(koolset[25].kool[2], "2");
  strcpy(koolset[25].kool[3], "~/_");
}

int main(argc, argv)
int argc;
char *argv[];
{
  time_t mytime;
  mytime = time(0);
  
  srand(mytime);    
  use_heavy_koolness = 1;
  check_params(argc, argv);  
  if (use_heavy_koolness) {
  	init();         
 	heavy_koolness();
  }
  else {
	light_koolness();
  } 
  exit(0);
}
