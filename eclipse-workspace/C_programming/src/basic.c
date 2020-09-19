/*
 * main.c
 *
 *  Created on: Sep 8, 2019
 *      Author: aishwarya
 */
// pre processor compiler header files
#include <stdio.h>  // printf
#include <stdlib.h> // main part of
#include <string.h> // perform different functionality with strings

int student_print_structure(); // this tells the compiler that there is a function defined and the linker will sort the right adress to call out.
void student_print_union();
//void pthread_main();


//global variable
int g;  // default value = 0 // visible everywhere

// prototyping of function / forward declaration of function
void sub(); // good practice to prototype

// definition function
int add(int a, int b){
	return a+b;
}

//array parameter
void array_get(int a[], int size);  // no size required in function parameter

//pointer parameter
void get_value(int *p){  // pointer argument // function pointer initialization
	*p = 10000; //value of variable pointed by pointer changed
	return;
}


int main()  // only 1 main and atlease 1 main
{
	// placeholder
	printf("Hello world ! \n");
	printf("int: %d, large int: %ld float: %f, large float: %lf char: %c, str: %s   \n",32, 56,4.443, 7.482, 'a', "hi");
	printf("hexa decimal: %x  \n",16);

	// local variable : default garbage value // global initialized default by 0
	printf("global var g: %d\n", g);
	g = 1;
	printf("global var g: %d\n", g);

	// datatypes basic
	int x = 21; //declaration
	float pi = 3.14;
	char a = 'a';
	double bigpi = 3.14564775;
	int age = 0;

	// if
	if  (x == 21){
		printf("Please enter age: ");
		scanf("%d", &age); // input user // correct way
		printf("Age: %d", age);
	}
	if (age == 21){
		printf("21");
	} else if (age > 21){
		printf(">21");
	}else {
		printf("<21");
	}

	// ternary operator
	int y = (age == 21)?21:22;
	printf("\n%d",y);


	// switch
	switch (age){
	case 21:
		printf("switch: 21\n");
		break;
	//or case conditions
	case 24:
	case 25:
	case 26:
			printf("switch: 24 or 25 or 26\n");
			break;
	default:
		printf("no age\n");
	}


	// while loop
	int i = 0;
	while(i <= 10){
		printf("%d ", i);
		i++;
	}

	// do while
	i = 0;
		do{
			printf("\ndo while %d \n", i);
			i++;
		}
		while(i < 1);

	// for loop
	for (i = 0; i<2; i++){
		printf("\nfor %d \n", i);
	}
	for (int j = 0; j<2; j++){
			printf("for %d ", j);
		}

	// calling functions
	int sum = add(3,4);
	printf("\nsum %d , a: %c\n", sum, a);
	sub();


	//1D array
	int z[3] = {20,30,40}; // 0-indexed
	for(i=0; i<3; i++){
	printf("%d ",z[i]);
	}
	char c[4] = {'a','b','c','d'};
	for(i=0; i<4; i++){
		printf("%c ",c[i]);
		}

	// 2D or 3D array
	int two[2] [3] = {  // 2 for loop to iterate
			{1,2,3}, // row 0
			{4,5,6} // row 1
	};
	int three [2] [3] [2] = {// 3 for loop to iterate
			{{1,2}, {4,5}, {7,8}},
			{{9,8}, {6,5}, {8,7}},
	};
	printf("\n3D\n");
	for(i=0; i<2; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<2; k++){
				printf("%d ",three[i][j][k]);
	}}}


	/* pointers :
		variable whose value is the address of another variable
	 	 used: & *
	 */
	int val = 30; // c stores in some memory address in your computer
	printf("\naddress &val: %x \n",&val); // access this address of val variable
	int *pointer; // * tells u want to declare pointer; not hex datatype but int datatype of pointer
	pointer = &val; // * not needed when assigning pointer
	printf("\naddress pointer: %x ",pointer); // access this stored in pointer
	printf("\nval of var pointer points: %d ", *pointer); // access pointer pointing value

	// pointer function call
	get_value(pointer);
	printf("\nfun address pointer: %x ",pointer); // access this stored in pointer
	printf("\nfunval of var pointer points: %d ", *pointer); // access pointer pointing value


	// array pointers
	int arr_val[3] = {30,40,50};
	int *arr_pointer[3];
	for (i=0; i<3; i++){
	arr_pointer[i] = &arr_val[i];
	printf("\narr address pointer: %x ",arr_pointer[i]);
	printf("\narr val of var pointer points: %d", *arr_pointer[i]);
	}


	// string : terminated by null char
	char string[6] = {'h', 'e', 'l', 'l','o', '\0'}; // this is string
	char string_easy[] = "hello AI"; //non definite size, better! // char datatype, array of chars
	printf("\n1. %s, %s",string, string_easy);

	// string.h file functions usage:
	char string_easy2[30];
	strcpy(string_easy2, string_easy); // strcpy(dest, src)
	printf("\n2. %s, %s",string_easy, string_easy2);
	strcat(string_easy2, string_easy); // concat: add str2 to str1
	printf("\n3. %s, %s",string_easy, string_easy2);
	int l = strlen(string_easy2);
	printf("\n3. %d",l);
	printf("\n4. %d",strcmp(string_easy, string_easy2));


	// call external file function
	student_print_structure();
	student_print_union();
	//pthread_main();


	return 0;
}

void sub(){
	printf("\nI'm below main(); Do prototype me!!\n");
}



/*  Output:

Hello world !
int: 32, large int: 56 float: 4.443000, large float: 7.482000 char: a, str: hi
hexa decimal: 10
global var g: 0
global var g: 1
Please enter age: 25
Age: 25>21
22switch: 24 or 25 or 26
0 1 2 3 4 5 6 7 8 9 10
do while 0

for 0

for 1
for 0 for 1
sum 7 , a: a

I'm below main(); Do prototype me!!
20 30 40 a b c d
3D
1 2 4 5 7 8 9 8 6 5 8 7
address &val: e54713a8

address pointer: e54713a8
val of var pointer points: 30
fun address pointer: e54713a8
funval of var pointer points: 10000
arr address pointer: e54713e0
arr val of var pointer points: 30
arr address pointer: e54713e4
arr val of var pointer points: 40
arr address pointer: e54713e8
arr val of var pointer points: 50
1. hello, hello AI
2. hello AI, hello AI
3. hello AI, hello AIhello AI
3. 16
4. -104
From External struct file: 1, amy, 95.879997
From External struct file: 2, cady, 40.880001
From External union file: 100, d
size union: 4

*/
