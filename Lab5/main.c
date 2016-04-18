//
//  main.c
//  Lab5
//
//  Created by Alan Weide on 4/17/16.
//  Copyright © 2016 weidea. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

#define ITERATIONS 1000000

int main(int argc, char * argv[]) {
	int rank, i;
	double *buf;
	double start32, dur32, start256, dur256, start512, dur512, start1024, dur1024, start2048, dur2048;
	double bandwidth32, bandwidth256, bandwidth512, bandwidth1024, bandwidth2048;
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if (rank == 0) {
		// Process 0
		buf = (double*)malloc(32 * sizeof(double));
		MPI_Barrier(MPI_COMM_WORLD);
		start32 = MPI_Wtime();
		for (i = 0; i < ITERATIONS; i++) {
			MPI_Send(buf, 32, MPI_DOUBLE, 1, 32, MPI_COMM_WORLD);
			MPI_Recv(buf, 32, MPI_DOUBLE, 1, 32, MPI_COMM_WORLD, &status);
			MPI_Send(buf, 32, MPI_DOUBLE, 1, 32, MPI_COMM_WORLD);
			MPI_Recv(buf, 32, MPI_DOUBLE, 1, 32, MPI_COMM_WORLD, &status);
		}
		dur32 = MPI_Wtime() - start32;
		bandwidth32 = 4  * sizeof(double) * 32 / dur32 ;
		printf("Buffer size 32 bandwidth: %lf MB/s\n", bandwidth32);
		buf = (double*)malloc(256 * sizeof(double));
		MPI_Barrier(MPI_COMM_WORLD);
		start256 = MPI_Wtime();
		for (i = 0; i < ITERATIONS; i++) {
			MPI_Send(buf, 256, MPI_DOUBLE, 1, 256, MPI_COMM_WORLD);
			MPI_Recv(buf, 256, MPI_DOUBLE, 1, 256, MPI_COMM_WORLD, &status);
			MPI_Send(buf, 256, MPI_DOUBLE, 1, 256, MPI_COMM_WORLD);
			MPI_Recv(buf, 256, MPI_DOUBLE, 1, 256, MPI_COMM_WORLD, &status);
		}
		dur256 = MPI_Wtime() - start256;
		bandwidth256 = 4 * sizeof(double) * 256 / dur256;
		printf("Buffer size 256 bandwidth: %lf MB/s\n", bandwidth256);
		buf = (double*)malloc(512 * sizeof(double));
		MPI_Barrier(MPI_COMM_WORLD);
		start512 = MPI_Wtime();
		for (i = 0; i < ITERATIONS; i++) {
			MPI_Send(buf, 512, MPI_DOUBLE, 1, 512, MPI_COMM_WORLD);
			MPI_Recv(buf, 512, MPI_DOUBLE, 1, 512, MPI_COMM_WORLD, &status);
			MPI_Send(buf, 512, MPI_DOUBLE, 1, 512, MPI_COMM_WORLD);
			MPI_Recv(buf, 512, MPI_DOUBLE, 1, 512, MPI_COMM_WORLD, &status);
		}
		dur512 = MPI_Wtime() - start512;
		bandwidth512 = 4 * sizeof(double) * 512 / dur512;
		printf("Buffer size 512 bandwidth: %lf MB/s\n", bandwidth512);
		buf = (double*)malloc(1024 * sizeof(double));
		MPI_Barrier(MPI_COMM_WORLD);
		start1024 = MPI_Wtime();
		for (i = 0; i < ITERATIONS; i++) {
			MPI_Send(buf, 1024, MPI_DOUBLE, 1, 1024, MPI_COMM_WORLD);
			MPI_Recv(buf, 1024, MPI_DOUBLE, 1, 1024, MPI_COMM_WORLD, &status);
			MPI_Send(buf, 1024, MPI_DOUBLE, 1, 1024, MPI_COMM_WORLD);
			MPI_Recv(buf, 1024, MPI_DOUBLE, 1, 1024, MPI_COMM_WORLD, &status);
		}
		dur1024 = MPI_Wtime() - start1024;
		bandwidth1024 = 4 * sizeof(double) * 1024 / dur1024;
		printf("Buffer size 1024 bandwidth: %lf MB/s\n", bandwidth1024);
		buf = (double*)malloc(2048 * sizeof(double));
		MPI_Barrier(MPI_COMM_WORLD);
		start2048 = MPI_Wtime();
		for (i = 0; i < ITERATIONS; i++) {
			MPI_Send(buf, 2048, MPI_DOUBLE, 1, 2048, MPI_COMM_WORLD);
			MPI_Recv(buf, 2048, MPI_DOUBLE, 1, 2048, MPI_COMM_WORLD, &status);
			MPI_Send(buf, 2048, MPI_DOUBLE, 1, 2048, MPI_COMM_WORLD);
			MPI_Recv(buf, 2048, MPI_DOUBLE, 1, 2048, MPI_COMM_WORLD, &status);
		}
		dur2048 = MPI_Wtime() - start2048;
		bandwidth2048 = 4 * sizeof(double) * 2048 / dur2048;
		printf("Buffer size 2048 bandwidth: %lf MB/s\n", bandwidth2048);
		MPI_Barrier(MPI_COMM_WORLD);
		printf("Durations: %lf, %lf, %lf, %lf, %lf\n", dur32, dur256, dur512, dur1024, dur2048);
	} else if (rank == 1) {
		// Process 1
		buf = (double*)malloc(32 * sizeof(double));
		MPI_Barrier(MPI_COMM_WORLD);
		for (i = 0; i < ITERATIONS; i++) {
			MPI_Recv(buf, 32, MPI_DOUBLE, 0, 32, MPI_COMM_WORLD, &status);
			MPI_Send(buf, 32, MPI_DOUBLE, 0, 32, MPI_COMM_WORLD);
			MPI_Recv(buf, 32, MPI_DOUBLE, 0, 32, MPI_COMM_WORLD, &status);
			MPI_Send(buf, 32, MPI_DOUBLE, 0, 32, MPI_COMM_WORLD);
		}
		buf = (double*)malloc(256 * sizeof(double));
		MPI_Barrier(MPI_COMM_WORLD);
		for (i = 0; i < ITERATIONS; i++) {
			MPI_Recv(buf, 256, MPI_DOUBLE, 0, 256, MPI_COMM_WORLD, &status);
			MPI_Send(buf, 256, MPI_DOUBLE, 0, 256, MPI_COMM_WORLD);
			MPI_Recv(buf, 256, MPI_DOUBLE, 0, 256, MPI_COMM_WORLD, &status);
			MPI_Send(buf, 256, MPI_DOUBLE, 0, 256, MPI_COMM_WORLD);
		}
		buf = (double*)malloc(512 * sizeof(double));
		MPI_Barrier(MPI_COMM_WORLD);
		for (i = 0; i < ITERATIONS; i++) {
			MPI_Recv(buf, 512, MPI_DOUBLE, 0, 512, MPI_COMM_WORLD, &status);
			MPI_Send(buf, 512, MPI_DOUBLE, 0, 512, MPI_COMM_WORLD);
			MPI_Recv(buf, 512, MPI_DOUBLE, 0, 512, MPI_COMM_WORLD, &status);
			MPI_Send(buf, 512, MPI_DOUBLE, 0, 512, MPI_COMM_WORLD);
		}
		buf = (double*)malloc(1024 * sizeof(double));
		MPI_Barrier(MPI_COMM_WORLD);
		for (i = 0; i < ITERATIONS; i++) {
			MPI_Recv(buf, 1024, MPI_DOUBLE, 0, 1024, MPI_COMM_WORLD, &status);
			MPI_Send(buf, 1024, MPI_DOUBLE, 0, 1024, MPI_COMM_WORLD);
			MPI_Recv(buf, 1024, MPI_DOUBLE, 0, 1024, MPI_COMM_WORLD, &status);
			MPI_Send(buf, 1024, MPI_DOUBLE, 0, 1024, MPI_COMM_WORLD);
		}
		buf = (double*)malloc(2048 * sizeof(double));
		MPI_Barrier(MPI_COMM_WORLD);
		for (i = 0; i < ITERATIONS; i++) {
			MPI_Recv(buf, 2048, MPI_DOUBLE, 0, 2048, MPI_COMM_WORLD, &status);
			MPI_Send(buf, 2048, MPI_DOUBLE, 0, 2048, MPI_COMM_WORLD);
			MPI_Recv(buf, 2048, MPI_DOUBLE, 0, 2048, MPI_COMM_WORLD, &status);
			MPI_Send(buf, 2048, MPI_DOUBLE, 0, 2048, MPI_COMM_WORLD);
		}
		MPI_Barrier(MPI_COMM_WORLD);
	}
	MPI_Finalize();
	return 0;
}
