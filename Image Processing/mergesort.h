#pragma once

#include <stdio.h>
#include <stdlib.h>
#define LENGTH  100

int* slice(int *arr, int start, int end);
void merge(int *result, int *left, int *right, int leftLen, int rightLen);
void mergeSort(int *arr, int len);
//void printArray(int* arr, int len);
