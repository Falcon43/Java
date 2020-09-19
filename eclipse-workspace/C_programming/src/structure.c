/*
 * structure.c
 *
 *  Created on: Sep 8, 2019
 *      Author: aishwaya
 */

// Structure is collection of different variable, grouped logically
// dont need to assign to single single variable for all the groups having similar variable
// eg. dont need to assign to single single variable for all the *students* having similar variable

// structure allocates different memory location
//to different variables belonging to it unlike union
// struct size:  actual size +padding to make the multiple of 4

struct student{
	int id;
	char name[30];
	float percentage;
} s2;



void student_print_structure()
{
	// call structure
	struct student s1;

	//assign values
	s1.id = 1;
	strcpy(s1.name, "amy");
	s1.percentage = 95.88;

	printf("\nFrom External struct file: %d, %s, %f",s1.id, s1.name, s1.percentage);


	// struct student s2;  // dont need cuz created at struc definition
	s2.id = 2;
	strcpy(s2.name, "cady");
	s2.percentage = 40.88;

	printf("\nFrom External struct file: %d, %s, %f",s2.id, s2.name, s2.percentage);

	return;
}
