/*
============================================================================
Name        : Assembler.c
Author      : Elena Barishenskaya(ID 336542196) & Dmitriy Chudnovsky (ID 324793900)
============================================================================
*/


#include "checkData.h"
#include <ctype.h>
#include <stdlib.h>


/*This array will give the info about the parameters number for each command */
commandType cmdTab[] =
{	/* cmd_str | Opcode | operandsInputNum */
	{ "mov", 0, 2 } ,
	{ "cmp", 1, 2 } ,
	{ "add", 2, 2 } ,
	{ "sub", 3, 2 } ,
	{ "not", 4, 1 } ,
	{ "clr", 5, 1 } ,
	{ "lea", 6, 2 } ,
	{ "inc", 7, 1 } ,
	{ "dec", 8, 1 } ,
	{ "jmp", 9, 1 } ,
	{ "bne", 10, 1 } ,
	{ "red", 11, 1 } ,
	{ "prn", 12, 1 } ,
	{ "jsr", 13, 1 } ,
	{ "rts", 14, 0 } ,
	{ "stop", 15, 0 }
};


extern SymbolTables array_labels[];
extern int count_label;
instructionLine *array_entry[MAX_COUNT_LINES];
extern int count_entryLabels;

/* Removes spaces(removes spaces at the beginning of a string) */
void SKIPSPACE(char **ptr)
{
	if (ptr)
	{
		while (isspace(**ptr))
		{
			++*ptr;
		}
	}
	else
		return;
	
}

/* if there are spaces, it removes spaces at the beginning and end of a string */
void SKIPNONSPACE(char **ptr)
{
	char *next;

	/* Return if empty ptr */
	if (!ptr || **ptr == '\0')
	{
		return;
	}
	SKIPSPACE(ptr);/* removes spaces at the beginning of a ptr*/
	next = *ptr + strlen(*ptr) - 1;/*-1  this is '\0' */

	/* Remove spaces from the end of a ptr */
	while (isspace(*next) && next!= *ptr)
	{
		*next-- = '\0';
	}
}

/*returns pointing to the word before the first occurrence of the character. if the character is not found, returns FALSE*/
char *subString(char *string_label, char symbol)
{
	int label_size;
	char *label;
	int  i;
	char *found_dot = strchr(string_label, symbol);

	/*if the character is not found*/
	if ((found_dot == NULL) || (string_label == NULL))
		return FALSE;

	label_size = found_dot - string_label; /*length of word*/
	label = malloc(label_size);

	for (i = 0; i < label_size; i++) {
		*(label + i) = *(string_label + i);
	}

	label[i] = '\0';
	return label;
}

/* Returns a pointer to the label with name in array_labels or NULL if there isn't such label. */
SymbolTables *getLabel(char *labelName)
{
	int i = 0;

	if (labelName)
	{
		for (i = 0; i < count_label; i++)
		{
			if (strcmp(labelName, array_labels[i].name) == 0)
			{
				return &array_labels[i];
			}
		}
	}
	return NULL;
}
/* search for command cmd in cmdTab and return the ID of the command or -1 if there isn't such command.*/
int GetCommandByName(char *commandName)
{
	int i = 0;
	/* Go over the commands and find the command that equal to the command name */
	while (cmdTab[i].cmd_str)
	{
		if (strcmp(commandName, cmdTab[i].cmd_str) == 0)
		{
			return i;
		}

		i++;
	}
	return -1;
}


/* Returns a pointer to the start and point at the last char after the command_string. */
char *Command_string(char *cmd_string, char **end_Cmdstring)
{
	char *first_Cmdstring = cmd_string;
	char *end = NULL;

	SKIPSPACE(&first_Cmdstring);

	/* Find the end of the first word */
	end = first_Cmdstring;
	while (*end != '\0' && !isspace(*end))
	{
		end++;
	}

	/* Add \0 at the end in the end_Cmdstring */
	if (*end != '\0')
	{
		*end = '\0';
		end++;
	}
	
	if (end_Cmdstring)
	{
		*end_Cmdstring = end; /* to point at the last char after the token */
	}
	return first_Cmdstring;
}

/* Returns if string contains only white spaces. */
bool isWhiteSpaces(char *str)
{
	while (*str)
	{
		if (!isspace(*str++))
		{
			return FALSE;
		}
	}
	return TRUE;
}

/* Returns if label is a legal name. */
bool checkLegalLabel(char *string_label, int Number_Line, bool Errors)
{
	int labelLength = strlen(string_label), i;

	/* check that the length of the label is not larger than the allowed size */
	if (strlen(string_label) > MAX_LABEL_LENGTH)
	{
		if (Errors)
		{
			printf("ERROR. At line %d:\tinvalid label (too long).\n", Number_Line);
		}
		return FALSE;
	}

	/* Check if the label isn't an empty */
	if (*string_label == '\0')
	{
		if (Errors)
		{
			printf("ERROR. At line %d:\tMissing argument in directive.\n", Number_Line);
		}
		return FALSE;
	}

	/* check that the label does not start in first column */
	if (isspace(*string_label))
	{
		if (Errors)
		{
			printf("ERROR. At line %d:\tlabel does not start in first column (optional error! label is ignored).\n", Number_Line);
		}
		return FALSE;

	}

	/* check that the name consists only of letters and numbers */
	for (i = 1; i < labelLength; i++)
	{
		if (!isalnum(string_label[i]))
		{
			if (Errors)
			{
				printf("ERROR. At line %d:\t\"%s\" is invalid label (use letters and numbers ).\n", Number_Line, string_label);
			}
			return FALSE;
		}
	}

	/* check that the first character is a letter. */
	if (!isalpha(*string_label))
	{
		if (Errors)
		{
			printf("ERROR. At line %d:\t\"%s\" is invalid label(non-alphabetic first character).\n", Number_Line, string_label);
		}
		return FALSE;

	}

	/* Check if it's not a name of a register */
	if (checkRegister(string_label, NULL))
	{
		if (Errors)
		{
			printf("ERROR. At line %d:\t\"%s\" is invalid label (cannot be a register).\n", Number_Line, string_label);
		}
		return FALSE;

	}

	/* Check if it's not a name of a command */
	if (GetCommandByName(string_label) != -1)
	{
		if (Errors)
		{
			printf("ERROR. At line %d:\t\"%s\" Invalid label (cannot be an instruction).\n", Number_Line, string_label);
		}
		return FALSE;

	}

	return TRUE;
}

/* Returns if str is a register name*/
bool checkRegister(char *str, int *value)
{
	if (str[0] == 'r'  && str[1] >= '0' && str[1] - '0' <= MAX_REGISTER && str[2] == '\0')
	{
		/* Update value if it's not NULL */
		if (value)
		{
			*value = str[1] - '0'; /* -'0' To get the actual number the char represents */
		}
		return TRUE;
	}

	return FALSE;
}

/* Returns a pointer to the start of the first operand in line*/
char *foundFirstOp(char *line, char **endOp, bool *Comma)
{
	if (!isWhiteSpaces(line))
	{
		char *end = strchr(line, ','); /* Find the first comma */
		if (end)
		{
			*Comma = TRUE;
			*end = '\0';
			end++;
		}
		else
		{
			*Comma = FALSE;
		}

		if (endOp)
		{
			if (end)
			{
				*endOp = end;
			}
			else
			{
				*endOp = strchr(line, '\0'); /*to point at the next char after the operand*/
			}
		}
	}

	SKIPNONSPACE(&line);
	return line;
}
/* Returns if the string is a directive. */
bool checkDirective(char *str)
{
	return (*str == '.') ? TRUE : FALSE;
}

/* Returns if the string for .string is a legal string (enclosed in quotes)*/
bool CheckLegalString(char **strParam, int Number_Line)
{
	/* check if the string param is enclosed in quotes */
	if ((*strParam)[0] == '"' && (*strParam)[strlen(*strParam) - 1] == '"')
	{
		/* remove the quotes */
		(*strParam)[strlen(*strParam) - 1] = '\0';
		++*strParam;
		return TRUE;
	}

	if (**strParam == '\0')
	{
		printf("ERROR. At line %d:\tNo parameters.\n", Number_Line);
	}
	else
	{
		printf("ERROR. At line %d:\tinvalid characters ( parameter string must be enclosed in quotes.\n", Number_Line);
	}
	return FALSE;
}

/* check if the num is a legal number for .data or for coomand*/
bool CheckLegalNumber(char *numStr, int Number_Line, int *value, int max, int min)
{
	char *endOfNum;

	int maxNumber = max;
	int minNumber = min;
	if (isWhiteSpaces(numStr))
	{
		printf("ERROR. At line %d:\tEmpty parameter/n.\n", Number_Line);
		return FALSE;
	}

	*value = strtol(numStr, &endOfNum, 10);

	/* Check if endOfNum is at the end of the string */
	if (*endOfNum)
	{
		printf("ERROR. At line %d:\tInvalid characters \"%s\".\n", Number_Line, numStr);
		return FALSE;
	}
	if (*value < minNumber)
	{
		if (minNumber == MINDATANUM)
		{
			/*check for datasize*/
			printf("ERROR. At line %d:\tnegative value \"%s\" too large to fit in 10 bits.\n", Number_Line, numStr);
			return FALSE;
		}
		else
		{
			/*check for immedsize, use just 8 bits*/
			printf("ERROR. At line %d:\tnegative immediate \"%s\" too large to fit in 8 bits.\n", Number_Line, numStr);
			return FALSE;
		}

	}
	if (*value > maxNumber)
	{
		if (maxNumber == MAXDATANUM)
		{
			/*check for datasize*/
			printf("ERROR. At line %d:\tpositive value \"%s\" too large to fit in 10 bits.\n", Number_Line, numStr);
			return FALSE;
		}
		else
		{
			/*check for immedsize, use just 8 bits*/
			printf("ERROR. At line %d:\tpositive immediate \"%s\" too large to fit in 8 bits.\n", Number_Line, numStr);
			return FALSE;
		}
	}
	return TRUE;
}
/* check if the data is a legal for .struct */
bool CheckLegalStruct(char *string_label, int *value, int Number_Line, bool printErrors) {
	char *label;
	int label_size;

	label = subString(string_label, '.');

	if (label == NULL) return FALSE;

	label_size = strlen(label) + 1; /*name size and Add  +1 for \0 at the end in the label in struct*/
	/* check if label is a legal name.*/
	if (checkLegalLabel(label, Number_Line, FALSE))
	{
		/*check that the field number for struct is set correctly or 1 or 2*/
		if ((string_label[label_size + 1] != '\0'))
		{
			*value = 0;
			return FALSE;
		}
		else if (string_label[label_size] == '1')
		{
			*value = 1;
			return TRUE;
		}
		else if (string_label[label_size] == '2')
		{
			*value = 2;
			return TRUE;
		}

		else
		{
			printf("ERROR. At line %d:\tStruct field is illigal.\n", Number_Line);
			return FALSE;
		}
	}
	else
	{
		printf("ERROR. At line %d:\tStruct label is illigal.\n", Number_Line);
		return FALSE;
	}

}











