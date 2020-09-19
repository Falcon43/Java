/*
 * dist_jacobi.c
 *
 *  Created on: Sep 23, 2019
 *      Author: aishwaya
 */


/* Sequential Jacobi iteration

   usage: <executable> gridSize numIters

*/

/*
>> mpicc -o dist-jacobi dist-jacobi.c
>> mpirun --oversubscribe -host localhost -np 4 ./dist-jacobi 16 4


Expected:
>> gcc -o seq-jacobi seq-jacobi.c
>> ./seq-jacobi 4 4
0 0 0.000 0.05936

>> ./seq-jacobi 4 4
0 0 0.000 0.03485

>> ./seq-jacobi 8 16
0 0 0.000 0.01350

>> ./seq-jacobi 16 16
0 0 0.000 0.01203

>> ./seq-jacobi 32 16
0 0 0.000 0.01119

>> ./seq-jacobi 64 16
0 0 0.002 0.01119

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <mpi.h>






void InitializeGrids(int r, int s, int e);
double **AllocateGrid(int, int);
//void *Work(void * id);
//double Elapsed(struct timeval, struct timeval);
//void* barrier_conditional();
void InitializeGrids1_zeros(int s, int e);

int gridSize, numIters, cores;
double maxDiff = 0.0;
double **grid1, **grid2;
//int *done = 1;
double striprows;

#define TOLERANCE 0.001

/* main() -- read command line, initialize grids, and create threads
             when the threads are done, print the results */

int main(int argc, char *argv[]) {
   MPI_Init(NULL, NULL);

  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  //struct timeval start, end;
  //printf("maxdiff : %f", maxdiff);
  /* read command line and initialize grids */
  gridSize = atoi(argv[1]);
  numIters = atoi(argv[2]);
  striprows = gridSize / world_size;
  if (gridSize%world_size != 0){
  	printf("Gridsize must be a multiple of number of MPI processes.");
  	exit(1);
  }
  int i;
  printf("cores : %d, striprows : %f\n", cores, striprows);

  int start = world_rank * striprows +1 ;
  int end = start+striprows-1 ;


  if (world_rank == 0) {
  grid1 = AllocateGrid(striprows+1, gridSize+2);
  grid2 = AllocateGrid(striprows+1, gridSize+2);
  InitializeGrids1_zeros(1, striprows);
  InitializeGrids(0, 0, striprows+1);
  }
  else if  (world_rank == world_size-1) {
  grid1 = AllocateGrid(striprows+1, gridSize+2);
  grid2 = AllocateGrid(striprows+1, gridSize+2);
  InitializeGrids1_zeros(0, striprows-1);
  InitializeGrids(striprows+1, 0, striprows+1);
  }
  else{
  grid1 = AllocateGrid(striprows, gridSize+2);
  grid2 = AllocateGrid(striprows, gridSize+2);
  InitializeGrids1_zeros(0, striprows-1);
  InitializeGrids(-1, 0, striprows);
  }


/*
  	InitializeGrids();

  gettimeofday(&start, NULL);
  int * j ;
  for (i = 0; i < cores; i++) {
  	j = &i;
  	pthread_create(&threads[i], NULL, Work, (void *)j);
  }
  //int * j;
  //for (*j = 0; *j < cores; (*j)++)
  //	pthread_create(&threads[*j], NULL, Work, (void *) j);


  for (i = 0; i < cores; i++)
  	pthread_join(threads[i], NULL);

  gettimeofday(&end, NULL);

  double max = 0;
  for (i = 0; i < cores; i++)
  	if (max < maxDiff[i])
  		max = maxDiff[i];


  // print the results in the format required by the assignment
  printf("0 0 %.3f %.5f\n", Elapsed(end, start), max);
  */
  MPI_Finalize();
}

/*
double Elapsed(struct timeval end, struct timeval start) {
  return ((end.tv_sec + end.tv_usec*0.000001) - (start.tv_sec + start.tv_usec*0.000001));
}

void *Work(void * id) {
  double maxdiff, temp;
  int i, j, iters = 0, done = 0;
  int start = *(int *)id * striprows + 1 ;
  int end = start+striprows-1 ;
  printf("start : %d, end : %d\n", start, end);

  while (!done) {
    //update my points
    for (i = start; i <= end; i++) {
      for (j = 1; j <= gridSize; j++) {
        grid2[i][j] = (grid1[i-1][j] + grid1[i+1][j] +
                       grid1[i][j-1] + grid1[i][j+1]) * 0.25;
      }
    }
    // insert barrier
    MPI_Barrier(MPI_COMM_WORLD);

    maxdiff = 0.0;
    // update my points again and find the max difference between any two points
    for (i = start; i <= end; i++) {
      for (j = 1; j <= gridSize; j++) {
        grid1[i][j] = (grid2[i-1][j] + grid2[i+1][j] +
               grid2[i][j-1] + grid2[i][j+1]) * 0.25;
        temp = grid1[i][j]-grid2[i][j];
        if (temp < 0)
          temp = -temp;
        if (maxdiff < temp)
          maxdiff = temp;
      }
    }
    // insert barrier
    MPI_Barrier(MPI_COMM_WORLD);


    iters++;
    if (maxdiff < TOLERANCE || iters >= numIters) {
      done = 1;
    }
  }

  maxDiff = maxdiff;
  return NULL;
}

*/



/* allocate an N x M grid */
double **AllocateGrid(int N, int M) {
  int i;
  double *vals, **temp;

  // allocate values
  vals = (double *) malloc (N * M * sizeof(double));

  // allocate vector of pointers
  temp = (double **) malloc (N * sizeof(double*));

  for(i=0; i < N; i++)
    temp[i] = &(vals[i * M]);

  return temp;
}

/* initialize the grids (grid1 and grid2)
   set boundaries to 1.0 and interior points to 0.0  */

void InitializeGrids1_zeros(int s, int e) {
  int i, j;
  for (i = s; i <= e; i++)
    for (j = 1; j <= gridSize; j++) {
      grid1[i][j] = 0.0;
      printf("i %d, j %d, grid1[i][j] %f", i, j , grid1[i][j]);
    }
}

void InitializeGrids(int r, int s, int e) {
  int i, j;

  /*for (i = 1; i <= gridSize; i++)
    for (j = 1; j <= gridSize; j++) {
      grid1[i][j] = 0.0;
    }
*/

  for (i = s; i <= e; i++) {
    grid1[i][0] = 1.0;
    grid1[i][gridSize+1] = 1.0;
    grid2[i][0] = 1.0;
    grid2[i][gridSize+1] = 1.0;
  }
  if (r != -1){
  for (j = 0; j <= gridSize+1; j++) {
    grid1[r][j] = 1.0;
    grid2[r][j] = 1.0;
  }
  }
}
