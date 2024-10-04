// LibTest.c

#include "CoteLib.h"


int main(void) {

	cmdInitTC();

	imgTC image;

	cmdStepTC();

	image = imageReadTC("clover.pgm");
	
	cmdStepTC();

	imageWriteTC("cloverCopy.pgm", image);
	
	cmdCloseTC(); 
	
	return 0;
}
