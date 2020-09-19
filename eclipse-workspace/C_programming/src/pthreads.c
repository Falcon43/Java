/*
 * pthreads.c
 *
 *  Created on: Sep 14, 2019
 *      Author: aishwaya
 */

/*
 *  Running on linux:
 * >> gcc -o
 *
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>



void main(int argc, char *argv[])
{

	pthread_t thread1, thread2;
	char *msg1 = "First thread";
	char *msg2 = "Second thread";
	int ret1, ret2;

	// create
	ret1 = pthread_create(thread1, NULL, myfunc, (void *) msg1);  // varname,const,  function, arguments
	ret2 = pthread_create(thread2, NULL, myfunc, (void *) msg2);
	// to create we need to declare thread1 var, var msg1 and we need the function myfunc

	printf("\nAfter pthread_create!!!!\n);


	// join with main
	pthread_join(thread1, NULL);  // end point of thread
	pthread_join(thread2, NULL);

	printf("\nAfter pthread_join!!!!\nFirst thread ret1 = %d\n Second thread ret2 = %d\n",ret1,ret2);

}


void *myfunc(void *myvar){
	char *msg;
	msg = (char *)myvar;
	int i;
	for (i= 0; i<10; i++){
		printf("%s %d\n",msg, i);
		sleep(1);
	}
	return NULL;
}


