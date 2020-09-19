/*
 * union.c
 *
 *  Created on: Sep 9, 2019
 *      Author: aishwaya
 */


/* union:
 * works like structure but diff
 *
 *  int: 4byte
 *  char : 1byte
 *
 *struct : 4byte + 1byte
 *
 *union : memory mapping is different
 *
 *memory = max memory among all the variables
 *union : 4byte (in the same 4 byte it can allocate car also along with int)
 *
 *members inside union SHARE the memory space
 *
 *first u assign 4 to id: then the 4byte memory space has value 4
 *then u assign uni.c variable so this 4 byte memory space is overwritten
 *
 *usage: embedded programming
 *
*/

union student{
	int id;
	char c;
} ;

void student_print_union()
{
	union student uni;
	uni.id = 4;
	uni.c = 'd';
	printf("\nFrom External union file: %d, %c",uni.id, uni.c);  // int wrong value
	// output: From External union file: 100, d
	printf("\nsize union: %d",sizeof(uni));

}
