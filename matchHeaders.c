/*
*	Author		    -	Apoorv Bhargava
*	File Name	  -	matchHeaders.c
* Description - This project intends to read and analyze the content of a file. 
*               The file contains any number of well-formed HTTP headers in the 
*               format [Field:Value]. The objective of the the code is to
*               determine the number of times a set of field headers (provided 
*               at compile time) appear in the file.
* Example     - If the program tracks 'Connection', 'Accept', and 
*               'Content-Length' headers, and is run against the following file:
*               
*               <file start>
*               Content-Length: 10
*               User-Agent: Test
*               Content-Length: 14
*               Accept: comedy
*               Content-Length: 100
*               Content-Encoding: gzip
*               Connection: close
*               User-Agent: Test
*               Accept: flash
*               User-Agent: Test1
*               Content-Length: 20
*               User-Agent: Test2
*               User-Agent: Test3
*               Accept: gzip
*               <file end>
*               
*               Output - Content-length 3 times.
*                        Accept 3 times.
*                        Connection 1 times.
*
* Assumption  - The solution optimizes the  CPU utilization, meaning that it's 
*               takes extra memory to reduce the processing.
*/

#include "matchHeaders.h"

/*	Function usage - Prints the usage instructions */
void usage(char* errorMessage){
 if(errorMessage){
  printf("%s\n",errorMessage);
 }
 printf("Please use the following command to execute the Program::\n");
 printf("\t./matchHeaders <filename> <NumberOfTrackedFields> [Field1] [Field2] .. [Fieldi]\n");
 printf("\tfilename:: File Name which contains the well-formed HTTP headers\n");
 printf("\tNumberOfTrackedFields:: Number of HTTP header fields tracked\n");
 printf("\t[Fields]::  HTTP header field names\n");
};

unsigned int alphaValue(char alphabet){
 if(alphabet >= 65 && alphabet <= 90){
  return (alphabet-64);
 }else if(alphabet >= 97 && alphabet <= 122){
  return (alphabet-96);
 }else{
  return alphabet;
 }
}

int main(int argc, const char* argv[]){
 unsigned int numFields = 0;
 FILE *filePointer;
 char *buffer = NULL;
 unsigned int counter = 0, icounter = 0, fieldTotal = 0, fieldLength = 0 ;
 unsigned int fieldCounter;
 const char *bufferPointer;
 
 /* Verify Command-Line Arguments -- Start */
 if(argc < 4){
  usage("");
  return 0;
 }
 /* Verify Command-Line Arguments -- End */
 
 /* Read NumberOfTrackedFields and FileName from Command-Line Arguments -- Start */
 
 numFields = atoi(argv[2]);
 
 if(numFields == 0){
  usage("\tError:: Please provide correct value for NumberOfTrackedFields.\n");
  return 0;
 }
 
 filePointer = fopen(argv[1], "r");
 
 if (filePointer == NULL) {
  usage("\tError:: Please provide valid File Name. \n");
  return 0;
 }
 
 /* Read NumberOfTrackedFields and FileName from Command-Line Arguments -- End */
 
 /* Buffer the file content -- Start */
 
 if(fseek(filePointer, 0L, SEEK_END) == 0){
  long int bufferSize = ftell(filePointer);
  if(bufferSize == -1){ 
   usage("\tError:: Unable to buffer provided file. \n");
   return 0;
  }
  
  buffer = malloc(sizeof(char) * (bufferSize + 1));
  
  if(fseek(filePointer, 0L, SEEK_SET) != 0){
   usage("\tError:: Unable to buffer provided file. \n");
   return 0;
  }
  
  /* Reading the file into memory. */
  size_t newLength = fread(buffer, sizeof(char), bufferSize, filePointer);
  
  if(newLength == 0){
   usage("\tError:: Unable to buffer provided file. \n");
   return 0;
  }else{
   buffer[++newLength] = '\0';
  }
 }
 fclose(filePointer);
 
 /* Read Field Name from Command-Line Arguments -- Start */
 
 //struct field *fields = (struct field*) malloc(numFields * sizeof(struct field));
 for(counter=0; counter < numFields; counter++){
  fieldCounter = 0;
  bufferPointer = buffer;
  
  /* Check if the field exists */
  if(argv[3+counter] == NULL) {
   usage("\tError:: Number of valid Field Names do not match NumberOfTrackedFields value. \n");
   return 0;
  }
  
  while((bufferPointer=strstr(bufferPointer,argv[3+counter])) != NULL){
   bufferPointer += strlen(argv[3+counter]);
   fieldCounter++;
  }
  printf("%s was seen %d times.\n",argv[3+counter], fieldCounter);
  
  /* Iterate through each character of the field and calculate length and ascii total */
  
 /* fieldTotal = 0;
  fieldLength = 0;
  while(argv[3+counter][fieldLength] != '\0'){
   fieldTotal += alphaValue(argv[3+counter][fieldLength]);
   fieldLength++;
  }
  fields[counter].total = fieldTotal;
  fields[counter].length = fieldLength;
  fields[counter].count = 0;
  printf("%s == \t%d\t%d\n",argv[3+counter], fieldTotal, fieldLength);
  //printf("%s\n",argv[3+counter]);*/
 }
 
 
 /* Read Field Name from Command-Line Arguments -- End */
 
 
 /* Buffer the file content -- End */
 //struct *headerField headerField = (struct window*) malloc(count * sizeof(struct window));
 //struct 
 //processFields(buffer);
 
 //printf("Hello World %s\n", argv[0]);
 //printf("%s",buffer);
 //free(fields);
 free(buffer);
 return 0;
}