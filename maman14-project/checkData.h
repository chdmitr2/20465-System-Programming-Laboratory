/*
============================================================================
Name        : Assembler.c
Author      : Elena Barishenskaya(ID 336542196) & Dmitriy Chudnovsky (ID 324793900)
============================================================================
*/

#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <string.h>

/* Constants */
#define MEMORY_SIZE		255
#define BEGIN_OFFSET	100
#define MAX_REGISTER	7
#define BYTE_SIZE		8


/* min and max value for.Data lines*/
#define MINDATANUM		-512
#define MAXDATANUM		 511
#define MEMORY_DATA		 10

/* Min and Max values for Direct addressing*/
#define DIRECTMIN		-128 
#define DIRECTMAX		 127 

#define MAX_LINE_LENGTH		81
#define MAX_LABEL_LENGTH	31

#define MAX_COUNT_LABEL		500

/*Constants for Boolean*/
#define TRUE 1
#define FALSE 0
typedef int bool;

/* Defining Constants */
#define MAX_COUNT_LINES		MAX_COUNT_LABEL

/*------management of information------ */

typedef struct
{
	char name[MAX_LABEL_LENGTH];   /*label */
	int  address;					/* The address of DIRECT it contains */
	bool isExtern;
	bool isData;					/*if the data, then this is .data or .string or .struct */
} SymbolTables;

/* --------Commands--------------------------------------- */

typedef struct command {
	char *cmd_str;
	unsigned int opcode : 4;
	int operandsInputNum;       /*0,1,2*/
} commandType;


/*------- Operands --------------------------------------*/
/*all the addresses types the assembler supports */
typedef enum {
	NUMBER = 0,
	LABEL,
	STRUCT,
	REGISTER,
	ERROR = -1
} OperandType;

typedef struct
{
	int value;
	char *str;
	OperandType type;
	int address;			/* The adress of the operand in the memory */
	int value_field;			/*used for Struct type. store value of field*/
	int adress_field;			/* used for Struct type. The adress of the field in the memory */
} operandInfo;

/*This data structure contains all information about  Line */
typedef struct
{
	/*line*/
	int Number_Line;
	int address;				/* The address of the first word in the line */
	char *line_string;			/* The original pointer */
	char *lineStringNext;		/* The text changed while using parsingLine) */
								/*Errors*/
	bool isError;
	/*saving label*/
	SymbolTables *label;	/* A poniter to the label in labelArr */
							/* Command */
	char *cmd_str;
	commandType *cmd;		/* A pointer to the command in cmdTab */
	operandInfo op1;
	operandInfo op2;

} instructionLine;

/* Removes spaces*/
void SKIPSPACE(char **ptr);
/* if there are spaces, it removes spaces at the beginning and end of a string */
void SKIPNONSPACE(char **ptr);
/* search for command in cmdTab and return the ID of the command or -1 if there isn't such command.*/
int GetCommandByName(char *commandName);
/* Returns a pointer to the label with name in array_labels or NULL if there isn't such label. */
SymbolTables *getLabel(char *labelName);
/* Returns a pointer to the start and point at the last char after the command_string. */
char *Command_string(char *cmd_string, char **end_Cmdstring);
/* Returns a pointer to the start of the first operand in line*/
char *foundFirstOp(char *line, char **endOp, bool *Comma);
/*returns pointing to the word before the first occurrence of the character. if the character is not found, returns FALSE*/
char *subString(char *string_label, char symbol);
/* Returns if string contains only white spaces. */
bool isWhiteSpaces(char *str);
/* Returns if label is a legal name. */
bool checkLegalLabel(char *label, int Number_Line, bool Error);
/* Returns if str is a register name*/
bool checkRegister(char *str, int *value);
/* Returns if the string for .string is a legal string (enclosed in quotes)*/
bool CheckLegalString(char **strParam, int Number_Line);
/* check if the num is a legal number for .data or for coomand*/
bool CheckLegalNumber(char *numStr, int Number_Line, int *value, int max, int min);
/* check if the data is a legal for .struct (legal name for struct and the field number for struct is set correctly or 1 or 2*/
bool CheckLegalStruct(char *string_label, int *value, int Number_Line, bool printErrors);
/* Returns if the string is a directive. */
bool checkDirective(char *str);





#endif

