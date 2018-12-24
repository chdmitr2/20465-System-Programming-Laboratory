/*
============================================================================
Name        : Assembler.c
Author      : Elena Barishenskaya(ID 336542196) & Dmitriy Chudnovsky(ID 324793900)
============================================================================
*/

#ifndef OUTPUT_WRITER_H
#define OUTPUT_WRITER_H

#include "checkData.h"
#include "output.h"
#include <stdlib.h>

#define FileEntry	 ".ent"
#define FileExtern	 ".ext"
#define FileOdject	 ".ob"


/* Converts binary number presented as integer to base 32. */
int intToBase32(int num, char *buf, int index);
/* Prints a number in base 32 in the file. */
void fprintfBase32(FILE *file, int num, int strMinWidth);
/* Creates a file for writing (mode="w").  The function gets the name of the file, its format (.ob, .ext or .ent) and returns a pointer to it. */
FILE *openFile(char *name, char *format, const char *mode);
/* Creates the .obj file for writing addresses of the assembled lines */
void OpenObjectFile(char *name, int IC, int DC, int *memory_block);
/* Creates the .ent file for writing addresses of the .entry labels */
void OpenEntryFile(char *name);
/* Creates the .ext file for writing addresses of the .extern labels*/
void OpenExternalFile(char *name, instructionLine *linesArr, int Number_line);
/* free all the malloc  and Clear all the globals data */
void clearData(instructionLine *linesArr, int Number_line, int dataCount);
#endif



#pragma once
