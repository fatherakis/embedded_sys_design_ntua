#include <math.h>

#include "calcDist.h"

void calcDistancesHW(float* data_hw, float* dists_hw)
{
	DTYPE1 data_hw_tmp[MOVIES_NUM][USERS_NUM];
	DTYPE1 movie_tmp[USERS_NUM];

	float dists_hw_tmp[MOVIES_NUM];

#pragma HLS array_partition variable=data_hw_tmp block factor=2 dim=2
#pragma HLS array_partition variable=movie_tmp block factor=2 dim=1
#pragma HLS array_partition variable=dists_hw_tmp block factor=2 dim=1

	int i, j;

LOAD_DATA_HW_TMP:
	for (i = 0; i < MOVIES_NUM; i++) {
		for (j = 0; j < USERS_NUM; j++) {
#pragma HLS pipeline II=1
			data_hw_tmp[i][j] = data_hw[i * USERS_NUM + j];
		}
	}

LOAD_MOVIE_TMP:
	for (i = 0; i < USERS_NUM; i++){
#pragma HLS unroll factor=8
#pragma HLS pipeline II=1
		movie_tmp[i] = data_hw_tmp[MOVIE_ID][i];
	}

	DTYPE1 sum, diff;
COMPUTE_DISTS:
	for (i = 0; i < MOVIES_NUM; i++) {
		sum = (DTYPE1)0.0;
		diff = (DTYPE1)0.0;
		for (j = 0; j < USERS_NUM; j++) {
#pragma HLS pipeline II=1
#pragma HLS unroll factor=8
			diff = (data_hw_tmp[i][j] > movie_tmp[j]) ? data_hw_tmp[i][j] - movie_tmp[j] : movie_tmp[j] - data_hw_tmp[i][j];
			sum += diff * diff;
		}
		dists_hw_tmp[i] = sqrt(sum.to_float());
	}

WRITE_DISTS:
	for (i = 0; i < MOVIES_NUM; i++) {
#pragma HLS unroll factor=8
#pragma HLS pipeline II=1
		dists_hw[i] = dists_hw_tmp[i];
	}

}
