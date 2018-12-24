/*
============================================================================
Name        : Assembler.c
Author      : Elena Barishenskaya(ID 336542196) & Dmitriy Chudnovsky (ID 324793900)
============================================================================
*/
#include "checkData.h"
#include "parsing.h"
#include "output.h"
#include "data.h"

/* ====== Global Data ====== */
/* Labels */
/****************************************************
It is recommended to avoid global variables. (-3)
*****************************************************/
SymbolTables array_labels[MAX_COUNT_LABEL]; /*save of all labels without repetition*/
int count_label = 0;						/*count of found labels*/
											/* Entry Lines */
instructionLine *array_entry[MAX_COUNT_LABEL];
int count_entryLabels = 0;					/*count of found .entry labels*/
											/* Data */
int array_data[MEMORY_SIZE];

/* *argv - file names list
*  argc -  */
int main(int argc, char *argv[])
{
	int i;
	if (argc < 2)
	{
		printf("No files to compile.\n");
		return 1;
	}
	for (i = 1; i < argc; i++)
	{
		/*start adress for SymbolTables and Data*/
		int IC = 0, DC = 0;
		int count_Error = 0, Number_line = 0; /*counting the number of lines*/
		instructionLine linesArr[MAX_COUNT_LABEL];
		int memoryArr[MEMORY_SIZE] = { 0 };

		/* Open File */
		FILE *fp = openFile(argv[i], ".as", "r");

		if (fp)
		{
			printf("\nThe file \"%s.as\" was opened.\n\n", argv[i]);
			count_Error += firstReadFile(fp, linesArr, &Number_line, &IC, &DC);
			if (count_Error == 0)
				printf("\nThe first reading was successful. Errors not found.\n\n");
			else
			{ 
				printf("\n%d errors were found in first read the file \"%s.as\". The program is stopped\n\n", count_Error, argv[i]);
				exit(1);
			}
				

			count_Error += secondFileRead(memoryArr, linesArr, Number_line, IC, DC);

			/*-----If count_Error=0, can go on and parser the output------*/
			if (count_Error == 0)
			{
				printf("The second reading was successful. Errors not found.\n\n");
				/* Create Output Files */
				OpenObjectFile(argv[i], IC, DC, memoryArr);
				OpenExternalFile(argv[i], linesArr, Number_line);
				OpenEntryFile(argv[i]);

			}
			else
			{
				printf("\n%d errors were found in second read the file \"%s.as\". The program is stopped\n\n", count_Error, argv[i]);
			}
		}
		else
		{
			printf("\nCan't open file\"%s.as\".\n", argv[i]);
			return 1;
		}
		clearData(linesArr, Number_line, IC + DC);

		/* Close File */
		fclose(fp);
	}
	printf("Files are compiled\n");
	return 0;
}



