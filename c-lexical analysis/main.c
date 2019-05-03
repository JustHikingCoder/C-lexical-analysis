/****************************************************/
/* File: main.c                                     */
/* Main program for C- compiler                   */
/****************************************************/

#include"globals.h"

/* set NO_PARSE to TRUE to get a scanner-only compiler */
#define NO_PARSE TRUE
/* set NO_ANALYZE to TRUE to get a parser-only compiler */
#define NO_ANALYZE FALSE

/* set NO_CODE to TRUE to get a compiler that does not
 * generate code
 */
#define NO_CODE FALSE

#include"util.h"
#if NO_PARSE
#include"scan.h"
#else
 //#include "parse.h"
 //#if !NO_ANALYZE
 //#include "analyze.h"
 //#if !NO_CODE
 //#include "cgen.h"
 //#endif
 //#endif
#endif

/* allocate global variables */
int lineno = 0;
FILE * source;
FILE * listing;
FILE * code;

/* allocate and set tracing flags */
int EchoSource = FALSE;
int TraceScan = TRUE;
int TraceParse = FALSE;
int TraceAnalyze = FALSE;
int TraceCode = FALSE;

int Error = FALSE;

main(int argc, char * argv[])
{
	char pgm[120]; /* source code file name */
	if (argc != 2)
	{
		fprintf(stderr, "usage: %s <filename>\n", argv[0]);
		exit(1);
	}
	strcpy(pgm, argv[1]);
	if (strchr(pgm, '.') == NULL)
		strcat(pgm, ".tny");
	source = fopen(pgm, "r");
	if (source == NULL)
	{
		fprintf(stderr, "File %s not found\n", pgm);
		exit(1);
	}
	listing = stdout; /* send listing to screen */
	fprintf(listing, "\nTINY COMPILATION: %s\n", pgm);

	while (getToken() != ENDFILE);

	fclose(source);
	system("pause");
	return 0;
}


