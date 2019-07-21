//
// Created by wuqi on 19-7-10.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cuda.h"
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "cublas_v2.h"

#define M 6
#define N 5
#define IDX2F(i,j,ld) ((((j)-1)*(ld))+((i)-1))

/*一个把坐标（i, j）转化为cublas数据格式坐标的函数；
假设一个点位于第i行第j列，每一列的长度为ld，
则计算出来的列优先坐标就是 j*ld+i */

static __inline__
void modify(cublasHandle_t handle, float *m, int ldm, int n,
            int p, int q, float alpha, float beta) {
  cublasSscal(handle, n - p + 1, &alpha, &m[IDX2F(p, q, ldm)], ldm);
  cublasSscal(handle, ldm - p + 1, &beta, &m[IDX2F(p, q, ldm)], 1);
}
int main(void) {
  cudaError_t cudaStat;
  cublasStatus_t stat;
  cublasHandle_t handle;
  int i, j;
  float* devPtrA;
  float* a = 0;
  a = (float *)malloc(M * N * sizeof(*a));
  if (!a) {
    printf("host memory allocation failed");
    return EXIT_FAILURE;
  }
  for (j = 1; j <= N; j++) {
    for (i = 1; i <= M; i++) {
      a[IDX2F(i, j, M)] = (float)((i - 1) * M + j);
    }
  }
  cudaStat = cudaMalloc((void**)&devPtrA, M*N*sizeof(*a));
  if (cudaStat != cudaSuccess) {
    printf("device memory allocation failed"); return EXIT_FAILURE;
  }
  stat = cublasCreate(&handle);
  if (stat != CUBLAS_STATUS_SUCCESS) {
    printf("CUBLAS initialization failed\n");
    return EXIT_FAILURE;
  }
  stat = cublasSetMatrix(M, N, sizeof(*a), a, M, devPtrA, M);
  if (stat != CUBLAS_STATUS_SUCCESS) {
    printf("data download failed");
    cudaFree(devPtrA);
    cublasDestroy(handle);
    return EXIT_FAILURE;
  }
  modify(handle, devPtrA, M, N, 2, 3, 16.0f, 12.0f);
  stat = cublasGetMatrix(M, N, sizeof(*a), devPtrA, M, a, M);
  if (stat != CUBLAS_STATUS_SUCCESS) {
    printf("data upload failed");
    cudaFree(devPtrA); cublasDestroy(handle);
    return EXIT_FAILURE;
  }
  cudaFree(devPtrA);
  cublasDestroy(handle);
  for (j = 1; j <= N; j++) {
    for (i = 1; i <= M; i++) {
      printf("%7.0f", a[IDX2F(i, j, M)]);
    }
    printf("\n");
  }
  free(a);
  return EXIT_SUCCESS;
}