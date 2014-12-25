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

int main(int argc, const char* argv[]){
 printf("Hello World %s\n", argv[0]);
 return 0;
}