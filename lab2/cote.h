/* CoteLib.h
	AUTHOR: T. COTE
	DATE  : 9-24-24
	SCOPE : This is the implimentation of a custom library of functions to be used in UMass Lowell's EECE4841





End File Header*/

#ifndef COTELIB_H

#define COTELIB_H

typedef struct {
	int sizeX;		// image X dim
	int sizeY;		// image Y dim
	int levels;		// image pixel depth
	unsigned char * array;	// iamge array pointer
} imgTC;

typedef struct cplx{
	float real;
	float imag;
} cplx;


void helloWorld(void);
/*
	helloWorld
	INPUTS : None
	OUTPUTS: None
	SCOPE: A Hello World Test program created to test the library
*/

void cmdInitTC(void);
/*
	cmdInitTC
	INPUTS : None
	OUTPUTS: None
	SCOPE: A prorgam to print a line to the command line at the start of a program
*/


void cmdStepTC(void);
/*
	cmdStepTC
	INPUTS : None
	OUTPUTS: None
	SCOPE: A program to print a period (.) to the command line
*/

void cmdCloseTC(void);
/*
	cmdCloseTC
	INPUTS : None
	OUTPUTS: None
	SCOPE: A program to print complete to the command line at the completion of a program
*/

int errorTC(int code);
/*
	errorTC
	INPUTS : error code [integer]
	OUTPUTS: error code [integer]
	SCOPE: A Personal error handler for debugging programs
*/

imgTC imageReadTC(char * fileName);
/*
	imageReadTC
	INPUTS : 
		file Name [char *]
	OUTPUTS: 
		image struct
	SCOPE: A program to read images from files
*/

void imageWriteTC(char * fileName, imgTC image);
/*
	imageWriteTC
	INPUTS : 
		file Name [char *]
		image struct
	OUTPUTS: None
	SCOPE: A program to write images to files
*/

imgTC pixelProcTC(imgTC image, unsigned char (*func)(int, int, unsigned char) );
/*
	pixelProcTC
	INPUTS : 
		image struct, per pixel processing function
	OUTPUTS: 
		image struct
	SCOPE: A program perform pixel processing on images
*/

#endif // COTELIB_H
