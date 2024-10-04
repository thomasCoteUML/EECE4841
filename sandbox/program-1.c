//Program1

//Sample Program to Read/Write Image
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
  unsigned sizeX; //image width
  unsigned sizeY; //image height
  unsigned char *image; //image array
  unsigned levels;

  /* Read Image */
  FILE *iFile = fopen("mri.pgm","r");
  if(iFile==0) return 1;
  if(3!=fscanf(iFile, "P5 %d %d %d ", &sizeX, &sizeY, &levels)) return 1;
  image=(unsigned char *) malloc(sizeX*sizeY);
  fread(image,sizeof(unsigned char),sizeX*sizeY,iFile);
  fclose(iFile);

/*write image to file*/
iFile = fopen("mri2.pgm","w");
if(iFile==0) return 1; //error handling
fprintf(iFile, "P5 %d %d %d ",sizeX,sizeY,255);//write header
fwrite(image, sizeof(unsigned char), sizeX*sizeY, iFile); //write binary image
fclose(iFile);
return 0;
}
