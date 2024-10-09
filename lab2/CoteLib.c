/* cote.c
	AUTHOR: T. COTE
	DATE  : 9-24-24
	SCOPE : This is the implimentation of a custom library of functions to be used in UMass Lowells EECE4841





End File Header*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <fftw2.h>


#include "cote.h"

void helloWorld(void) { printf("Hello World!\n"); }

void cmdInitTC(void) { printf("Running"); }

void cmdStepTC(void) { printf("."); }

void cmdCloseTC(void) { printf("Complete\n"); }

int errorTC(int code) { 
	
	printf("\nError Code %d: ", code);
	
	switch (code) {
	
	case 1:
	printf("Default Error"); break;// Placeholder
	
	case 2:
	printf("Image File Read Error - file not found"); break;
	
	case 3:
	printf("Image File Read Error - file format incorrect"); break;
	
	case 4:
	printf("Image File Write Error - file not found"); break;
	
	default:
	printf("Unknown Error Code"); break;

	}
	
	printf("\n");
	
	return code;
		
}

imgTC imageReadTC(char * fileName) {

	// init vars
	imgTC image;
  
  	// open image file
	FILE *iFile = fopen(fileName,"r");
	
	// check if file is open
	if(iFile == 0) {
		errorTC(2);
		return;
	}
	
	// check file for header information, save header information
	if(3 != fscanf(iFile, "P5 %d %d %d ", &(image.sizeX), &(image.sizeY), &(image.levels) ) ) {
		errorTC(3);
		return;
	}
	
	// allocate memory for image
	image.array = (unsigned char *) malloc( image.sizeX * image.sizeY);
	
	// read data from file and store in allocated memory
	fread(image.array,sizeof(unsigned char), image.sizeX * image.sizeY,iFile);
	
	// close image file
	fclose(iFile);
	
	// return image 
	return image;
}



void imageWriteTC(char * fileName, imgTC image) {

	// open/create image file
	FILE *iFile = fopen(fileName,"w");
	
	// check if file is open
	if(iFile==0) { 
		errorTC(4);
		return;
	}
	
	// Write image file header
	fprintf(iFile, "P5 %d %d %d ",image.sizeX, image.sizeY, image.levels);
	
	// Write image file data
	fwrite(image.array, sizeof(unsigned char), image.sizeX * image.sizeY, iFile);
	
	// close image file
	fclose(iFile);
	
	// exit
	return;

}

imgTC pixelProcTC(imgTC image, unsigned char (*func)(int, int, unsigned char) ){
	
	// create temporary image
	imgTC imageTemp;
	imageTemp.array = (unsigned char *) malloc(image.sizeX * image.sizeY);
	imageTemp.levels = image.levels;

	// create process matrix of size X by Y
	unsigned char processMatrix [image.sizeX][image.sizeY];
	
	
	// copy input image (1D array) to process matrix (2D array)
	memcpy(processMatrix, image.array, image.sizeX * image.sizeY * sizeof(unsigned char));


	int k = 0;
	unsigned char tmp;

	/* INDEX THROUGH IMAGE AND PROCESS EACH PIXEL */
	
	// index through x dimension of processMatrix
	for(int i = 0; i<image.sizeX; i++){
	
		// index through y dimension of processMatrix
		for(int j = 0; j<image.sizeY; j++){

			/* 
				Pass to unknown function
				loop variables i and j and the pixel at (i,j)
				store the output pixel from unkown function at index k of temporary image 
			*/
			tmp = (*func)(i, j, processMatrix[i][j]);
			if (tmp != 0x00) {
				imageTemp.array[k] = tmp;
				k++;
			}
			else {
				processMatrix[i][j] = 0x00;
			}
		}
	}
	
	/* DYNAMICALLY CALCULATE IMAGE SIZE (I know that this part stinks) */
	
	int tmpX,tmpY;
	
	int scale = (image.sizeX * image.sizeY) / k;
	
	
	tmpX = 2 * image.sizeX / scale;
	tmpY = 2 * image.sizeY / scale;
	
	// set output image size X and Y
	imageTemp.sizeX = tmpX;
	imageTemp.sizeY = tmpY;
	
	return imageTemp;
}



