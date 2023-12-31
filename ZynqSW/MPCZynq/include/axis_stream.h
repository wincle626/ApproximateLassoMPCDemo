/*
 * axis_stream.hpp
 *
 *  Created on: 28 Sep 2022
 *      Author: vv_fa
 */

#ifndef SRC_AXIS_STREAM_H_
#define SRC_AXIS_STREAM_H_

#include <stdio.h>
#include <getopt.h>
#include <sys/mman.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <math.h>


#include "xaxidma.h"
#include "xparameters.h"
#include "xdebug.h"

typedef float T;

#define DIM 256
#define SIZE 16

#define IN_LEN 40
#define OUT_LEN 40

int axis_stream(float in_stream[IN_LEN], float out_stream[OUT_LEN],
		float output_ref[OUT_LEN]);


#endif /* SRC_AXIS_STREAM_H_ */
