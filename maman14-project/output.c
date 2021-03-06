/*
============================================================================
Name        : Assembler.c
Author      : Elena Barishenskaya(ID 336542196) & Dmitriy Chudnovsky (ID 324793900)
============================================================================
*/
#include "output.h"

extern SymbolTables array_labels[];
extern int count_label;
instructionLine *array_entry[MAX_COUNT_LABEL];
extern int count_entryLabels;
extern int array_data[];

/* Convert binary number presented as integer to base 32. */
int intToBase32(int num, char *buf, int index)
{
	const int base = 32;
	const char digits[] = "!@#$%^&*<>abcdefghijklmnopqrstuv";
	if (num)
	{
		index = intToBase32(num / base, buf, index);
		buf[index] = digits[num % base];
		return ++index;
	}

	return 0;
}

/* Prints a number in base 32 in the file. */
void fprintfBase32(FILE *file, int num, int strMinWidth)
{
	int numOfZeros, i;
	char buf[3] = { 0 }; /* 2 char are enough to represent 10 bits in base 32 + the last char is \0 */

	intToBase32(num, buf, 0);
	numOfZeros = strMinWidth - strlen(buf);
	for (i = 0; i < numOfZeros; i++)
	{
		fprintf(file, "!");
	}
	fprintf(file, "%s", buf);
}

/* Creates a file for writing (mode="w") or reading.  The function gets the name of the file, its format (.ob, .ext or .ent) and returns a pointer to it. */
FILE *openFile(char *name, char *format, const char *mode)
{
	FILE *file;
	char *mallocStr = (char *)malloc(strlen(name) + strlen(format) + 1), *fileName = mallocStr;
	sprintf(fileName, "%s%s", name, format);

	file = fopen(fileName, mode);
	free(mallocStr);

	return file;
}

/* Creates the .obj file for writing addresses of the assembled lines */
void OpenObjectFile(char *name, int IC, int DC, int *memoryArr)
{
	int i;
	FILE *file;
	file = openFile(name, FileOdject, "w");

	/* Print IC and DC */
	fprintfBase32(file, IC, 1);
	fprintf(file, "\t\t");
	fprintfBase32(file, DC, 1);

	/* Print all of memoryArr */
	for (i = 0; i < IC + DC; i++)
	{
		fprintf(file, "\n");
		fprintfBase32(file, BEGIN_OFFSET + i, 2);
		fprintf(file, "\t\t");
		fprintfBase32(file, memoryArr[i], 2);
	}

	fclose(file);
}

/* Creates the .ent file for writing addresses of the .entry labels */
void OpenEntryFile(char *name)
{
	int i;
	FILE *file;

	/* Don't create the entries file if count_entryLabels=0 */
	if (count_entryLabels == 0)
	{
		return;
	}

	file = openFile(name, FileEntry, "w");

	for (i = 0; i < count_entryLabels; i++)
	{
		fprintf(file, "%s\t\t", array_entry[i]->lineStringNext);
		fprintfBase32(file, getLabel(array_entry[i]->lineStringNext)->address, 1);

		if (i != count_entryLabels - 1)
		{
			fprintf(file, "\n");
		}
	}

	fclose(file);
}

/* Creates the .ext file for writing addresses of the .extern labels*/
void OpenExternalFile(char *name, instructionLine *linesArr, int Number_line)
{
	int i;
	SymbolTables *label;
	bool firstPrint = TRUE; /* This bool meant to prevent the creation of the file if there aren't any externs */
	FILE *file = NULL;

	for (i = 0; i < Number_line; i++)
	{
		/* Check if the 1st operand is extern label, and print it. */
		if (linesArr[i].cmd && linesArr[i].cmd->operandsInputNum >= 2 && linesArr[i].op1.type == LABEL)
		{
			label = getLabel(linesArr[i].op1.str);
			if (label && label->isExtern)
			{
				if (firstPrint)
				{
					/* Create the file only if there is at least one extern */
					file = openFile(name, FileExtern, "w");
				}
				else
				{
					fprintf(file, "\n");
				}

				fprintf(file, "%s\t\t", label->name);
				fprintfBase32(file, linesArr[i].op1.address, 1);
				firstPrint = FALSE;
			}
		}

		/* Check if the 2nd operand is extern label, and print it. */
		if (linesArr[i].cmd && linesArr[i].cmd->operandsInputNum >= 1 && linesArr[i].op2.type == LABEL)
		{
			label = getLabel(linesArr[i].op2.str);
			if (label && label->isExtern)
			{
				if (firstPrint)
				{
					/* Create the file only if there is at least 1 extern */
					file = openFile(name, FileExtern, "w");
				}
				else
				{
					fprintf(file, "\n");
				}

				fprintf(file, "%s\t\t", label->name);
				fprintfBase32(file, linesArr[i].op2.address, 1);
				firstPrint = FALSE;
			}
		}
	}

	if (file)
	{
		fclose(file);
	}
}

/* free all the malloc  and Clear all the globals data */
void clearData(instructionLine *linesArr, int Number_line, int dataCount)
{
	int i;
	/* Clean global labels */
	for (i = 0; i < count_label; i++)
	{
		array_labels[i].address = 0;
		array_labels[i].isData = 0;
		array_labels[i].isExtern = 0;
	}
	count_label = 0;

	/* Clean global .entry */
	for (i = 0; i < count_entryLabels; i++)
	{
		array_entry[i] = NULL;
	}
	count_entryLabels = 0;

	/* Clean global data */
	for (i = 0; i < dataCount; i++)
	{
		array_data[i] = 0;
	}

	/* Free malloc*/
	for (i = 0; i < Number_line; i++)
	{
		free(linesArr[i].line_string);
	}

}




