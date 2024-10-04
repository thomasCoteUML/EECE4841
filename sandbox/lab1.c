/* lab1.c
	AUTHOR: T. COTE
	DATE  : 10-01-24
	COURSE: UMass Lowell's EECE4841: Computer Vision and Digital Image Processing
	SCOPE : The purpose of this program is to complete lab 1 of the associated course
	
	Lab1 of UML:EECE4841 tasks the student to load an image from a file into memory, remove every other pixel of 
	the image, and then write the image from memory to a new image file.

End File Header*/

// personal library
#include "CoteLib.h"

// pixel processing function definition
unsigned char pixelFunc(int i, int j, unsigned char p, int *k);

// file names for input and output image files
static char * INPUTFILE = "clover.pgm";
static char * OUTPUTFILE = "processedClover.pgm";
static const unsigned char (*PTR)(int, int, unsigned char, int*) = pixelFunc;

// main function
int main(void) { 
	
	// start program
	cmdInitTC();

	// initialize variable
	imgTC image; cmdStepTC();

	// read image from file to memory
	image = imageReadTC(INPUTFILE); cmdStepTC();
	
	// process image with pixelFunc
	image = pixelProcTC(image, PTR); cmdStepTC();

	// write image from memory to file
	imageWriteTC(OUTPUTFILE, image); cmdStepTC();
	
	// end program
	cmdCloseTC(); return 0;
	
} 

unsigned char pixelFunc(int i, int j, unsigned char p, int *k) {
	
	// if pixel index is odd in either x or y return NULL
	if ( (i % 2) || (j % 2) ) {
		return 0x00;	
	}
	// else return input pixel and increment array index
	else {
		(*k)++;
		return p;
		
	}
	
} // EoF


