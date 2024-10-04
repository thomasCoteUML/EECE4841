//Program-2

//Takes an image and removes the 4th quadrant
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CoteLib.h"

int main(int argc, char *argv[]){

	cmdInitTC();

	unsigned sizeX; //image width
	unsigned sizeY; //image height
	unsigned char *image; //image array
	unsigned char *imageTemp; //temporary image array
	unsigned int k; //iterator for storing image data from a matrix
	unsigned levels;
	
	

    	// Read Image
	image = imageReadTC("clover.pgm");

	// Create New image
	imageTemp = (unsigned char *) malloc(sizeX*sizeY);

	//Convert image array into a matrix
	unsigned char processMatrix [sizeX][sizeY];
	//This line copies a 1D array into an 2D array 
	memcpy(processMatrix, image, sizeX*sizeY*sizeof(unsigned char));

    	k = 0;
    	for(unsigned int i=0; i<256; i++){
		for(unsigned int j=0; j<256; j++){

			if ( !((i % 2) || (j % 2)) ) {
				imageTemp[k] = processMatrix[i][j];
				k++;
			}
		}
	}

	/*write image to file*/
	iFile = fopen("processedClover1.pgm","w");
	if(iFile==0) return 1; //error handling
	fprintf(iFile, "P5 %d %d %d ",sizeX,sizeY,255);//write header
	fwrite(imageTemp, sizeof(unsigned char), sizeX*sizeY, iFile); //write binary image
	fclose(iFile);
	return 0;
}
