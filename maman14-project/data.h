/*
============================================================================
Name        : Assembler.c
Author      : Elena Barishenskaya(ID 336542196) & Dmitriy Chudnovsky (ID 324793900)
============================================================================
*/

#ifndef MEMORY_BLOCK
#define MEMORY_BLOCK

/*Bits*/
#define TWO_BITS		 2
#define FOUR_BITS		 4
#define EIGHT_BITS		 8


/* Machine instruction structure */

typedef struct /* 10 bits */
{
	unsigned int era : TWO_BITS; /* ABSOLUTE = 00, EXTERNAL = 01, RELOCATABLE = 10*/

	union /* 8 bits */
	{
		/* Commands */
		struct
		{
			int dest : TWO_BITS;	/* Address Destination */
			int src : TWO_BITS;		/* Addressing a source operand */
			int opcode : FOUR_BITS;	 /*commandInfo ID */
		} commandInfBits;

		/* Registers */
		struct
		{
			int destBits : FOUR_BITS;
			int srcBits : FOUR_BITS;

		} registersBits;

		/*Struct*/
		struct
		{
			int field : EIGHT_BITS; /*00000001+era(00) or 00000010+era(00)*/
		}structFieldBits;

		struct
		{
			int value : EIGHT_BITS;
		}structAdressBits;

		/* Other operands */
		int value : EIGHT_BITS;

	} valueBits;

} memory_block;

typedef enum { ABSOLUTE = 0, EXTERNAL, RELOCATABLE } eraType;

/* Adds the value of memory block to the memoryArr */
void addWordToMemory(int *memoryArr, int *memoryCounter, memory_block memory);
/*Returns an error if the  label values were not declared*/
/*if no error this method is updating the value address of the label.  */
bool addAdressOperand(operandInfo *op, int Number_Line);
/* Adds line into the memoryArr, and increment the memoryCounter. */
/* Don't do anything if the line is error or if it's not a command line. returns an error if found while adding the line to the memory */
bool addLineToMemory(int *memoryArr, int *memoryCounter, instructionLine *line, int Number_Line);
/* Returns a memory instruction structure which represents the command in a line. */
memory_block getCommandMemory_block(instructionLine line);
/* Returns a memory instruction structure which represents the operand in a line.*/
memory_block getOpMemory_block(operandInfo op, bool isDest);
/*performs the second scan on the assembly source files and It converts all the lines into the memory_block. */
int secondFileRead(int *memoryArr, instructionLine *linesArr, int Number_Line, int IC, int DC);

#endif

