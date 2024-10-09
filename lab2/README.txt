**********************
* Prog2 Sample Files *

Fall 2023
EECE 4841/EECE 5841
Prof. Megherbi
**********************



Intro:
  This is the sample code for Prog2.  The sample program creates
  a 2D complex array, initializing it to constant data, performing the forward
  2D fft, then the inverse 2D fft of the results, outputing the results of each
  step.


Executables:
  TestFour2floats: C version with array of floats as described in class
  

Instructions:
  run make, then run the sample program.    
  
Files:
  makefile: builds the c files  and links them into the executable
  
  TestFour2floats.c: C version to test Four2 using floats as described in class
  
   
  Four2.h: contains function prototype for fft_Four2 which is accessable to
           the students
  
  Four2_Private.h: countains prototype for functions needed by fft_Four2
  
  Four2.c: contains the fft_Four2 function and all dependancies as prototyped in
           Four2.h and Four2_Private.h, as well as some local variables.
  
               
               