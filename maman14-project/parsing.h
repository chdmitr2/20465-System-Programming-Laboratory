/*
============================================================================
Name        : Assembler.c
Author      : Elena Barishenskaya(ID 336542196) & Dmitriy Chudnovsky (ID 324793900)
============================================================================
*/

#ifndef PARSING_H
#define PARSING_H

#include "checkData.h"
#include <ctype.h>
#include <stdlib.h>

/* Finds the label in line->lineStringNext and add it to the label list. */
/* Returns a pointer to the next char after the label, or NULL is there isn't a legal label. */
char *findLabel(instructionLine *line, int IC);
/* Updates the type and value of operand. */
void parsingOpInfo(operandInfo *operand, int Number_Line);
/* Parsing the operands in a command line. */
void parsingOpCmd(instructionLine *line, int *IC, int *DC);
void DircDataParsing(instructionLine *line, int *IC, int *DC);
void DircStringParsing(instructionLine *line, int *IC, int *DC);
void DircStructParsing(instructionLine *line, int *IC, int *DC);
void DircEntryExternParsing(instructionLine *line);
/* Adds the label to the labelArr. Returns a pointer to the label in the array. */
SymbolTables *addLabelToArr(SymbolTables label, instructionLine *line);
/* Adds the string to the array_data. Returns FALSE if there isn't enough space in array_data */
bool addStringToData(char *str, int *IC, int *DC, int Number_Line);
/* Parsing a line and if an error is found reported it and return isERROR=True in instructionLine*/
void parsingLine(instructionLine *line, char *lineStringNext, int Number_Line, int *IC, int *DC);
/*First reading the file and parsing it. Returns count of errors that were found */
int firstReadFile(FILE *file, instructionLine *linesArr, int *Number_line, int *IC, int *DC);
#endif

