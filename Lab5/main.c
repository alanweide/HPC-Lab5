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

int main(int argc, char * argv[]) {
	if (argc == 2) {
		int rank;
		int iterations = atoi(argv[1]);
		double *buf32;
		double *buf256;
		double *buf512;
		double *buf1024;
		double *buf2048;
		MPI_Status status;
		MPI_Init(&argc, &argv);
		MPI_Comm_rank(MPI_COMM_WORLD, &rank);
		if (rank == 0) {
			buf32 = (double*)malloc(32 * sizeof(double));
			buf256 = (double*)malloc(256 * sizeof(double));
			buf512 = (double*)malloc(512 * sizeof(double));
			buf1024 = (double*)malloc(1024 * sizeof(double));
			buf2048 = (double*)malloc(2048 * sizeof(double));
			for (int i = 0; i < iterations; i++) {
				MPI_Send(&buf32, 32, MPI_DOUBLE, 1, 32, MPI_COMM_WORLD);
				MPI_Recv(&buf32, 32, MPI_DOUBLE, 1, 32, MPI_COMM_WORLD, &status);
				MPI_Send(&buf32, 32, MPI_DOUBLE, 1, 32, MPI_COMM_WORLD);
				MPI_Recv(&buf32, 32, MPI_DOUBLE, 1, 32, MPI_COMM_WORLD, &status);
			}
			for (int i = 0; i < iterations; i++) {
				MPI_Send(&buf256, 256, MPI_DOUBLE, 1, 256, MPI_COMM_WORLD);
				MPI_Recv(&buf256, 256, MPI_DOUBLE, 1, 256, MPI_COMM_WORLD, &status);
				MPI_Send(&buf256, 256, MPI_DOUBLE, 1, 256, MPI_COMM_WORLD);
				MPI_Recv(&buf256, 256, MPI_DOUBLE, 1, 256, MPI_COMM_WORLD, &status);
			}
			for (int i = 0; i < iterations; i++) {
				MPI_Send(&buf512, 512, MPI_DOUBLE, 1, 512, MPI_COMM_WORLD);
				MPI_Recv(&buf512, 512, MPI_DOUBLE, 1, 512, MPI_COMM_WORLD, &status);
				MPI_Send(&buf512, 512, MPI_DOUBLE, 1, 512, MPI_COMM_WORLD);
				MPI_Recv(&buf512, 512, MPI_DOUBLE, 1, 512, MPI_COMM_WORLD, &status);
			}
			for (int i = 0; i < iterations; i++) {
				MPI_Send(&buf1024, 1024, MPI_DOUBLE, 1, 1024, MPI_COMM_WORLD);
				MPI_Recv(&buf1024, 1024, MPI_DOUBLE, 1, 1024, MPI_COMM_WORLD, &status);
				MPI_Send(&buf1024, 1024, MPI_DOUBLE, 1, 1024, MPI_COMM_WORLD);
				MPI_Recv(&buf1024, 1024, MPI_DOUBLE, 1, 1024, MPI_COMM_WORLD, &status);
			}
			for (int i = 0; i < iterations; i++) {
				MPI_Send(&buf2048, 2048, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD);
				MPI_Recv(&buf2048, 2048, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD, &status);
				MPI_Send(&buf2048, 2048, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD);
				MPI_Recv(&buf2048, 2048, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD, &status);
			}
		} else if (rank == 1) {
			for (int i = 0; i < iterations; i++) {
				MPI_Recv(&buf32, 32, MPI_DOUBLE, 0, 32, MPI_COMM_WORLD, &status);
				MPI_Send(&buf32, 32, MPI_DOUBLE, 0, 32, MPI_COMM_WORLD);
				MPI_Recv(&buf32, 32, MPI_DOUBLE, 0, 32, MPI_COMM_WORLD, &status);
				MPI_Send(&buf32, 32, MPI_DOUBLE, 0, 32, MPI_COMM_WORLD);
			}
			for (int i = 0; i < iterations; i++) {
				MPI_Recv(&buf256, 256, MPI_DOUBLE, 0, 256, MPI_COMM_WORLD, &status);
				MPI_Send(&buf256, 256, MPI_DOUBLE, 0, 256, MPI_COMM_WORLD);
				MPI_Recv(&buf256, 256, MPI_DOUBLE, 0, 256, MPI_COMM_WORLD, &status);
				MPI_Send(&buf256, 256, MPI_DOUBLE, 0, 256, MPI_COMM_WORLD);
			}
			for (int i = 0; i < iterations; i++) {
				MPI_Recv(&buf512, 512, MPI_DOUBLE, 0, 512, MPI_COMM_WORLD, &status);
				MPI_Send(&buf512, 512, MPI_DOUBLE, 0, 512, MPI_COMM_WORLD);
				MPI_Recv(&buf512, 512, MPI_DOUBLE, 0, 512, MPI_COMM_WORLD, &status);
				MPI_Send(&buf512, 512, MPI_DOUBLE, 0, 512, MPI_COMM_WORLD);
			}
			for (int i = 0; i < iterations; i++) {
				MPI_Recv(&buf1024, 1024, MPI_DOUBLE, 0, 1024, MPI_COMM_WORLD, &status);
				MPI_Send(&buf1024, 1024, MPI_DOUBLE, 0, 1024, MPI_COMM_WORLD);
				MPI_Recv(&buf1024, 1024, MPI_DOUBLE, 0, 1024, MPI_COMM_WORLD, &status);
				MPI_Send(&buf1024, 1024, MPI_DOUBLE, 0, 1024, MPI_COMM_WORLD);
			}
			for (int i = 0; i < iterations; i++) {
				MPI_Recv(&buf2048, 2048, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, &status);
				MPI_Send(&buf2048, 2048, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
				MPI_Recv(&buf2048, 2048, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, &status);
				MPI_Send(&buf2048, 2048, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
			}
		}
		MPI_Finalize();
		return 0;
	} else {
		printf("Usage: mpirun -np [np] a.out [iterations]\n");
		return -1;
	}
}
