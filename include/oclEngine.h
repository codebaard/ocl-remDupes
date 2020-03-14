//This deals with all the openCL stuff
#include<stdio.h>
#include<stdlib.h>

//get ocl headers
#include <CL/cl.h>

typedef struct oclEngine {
	cl_platform_id platform_id;
	cl_device_id device_id;
	cl_context context;
	cl_command_queue command_cue;
} oclEngine ;
 
typedef struct oclInfo {
	cl_uint num_devices;
	cl_uint num_platforms;

} oclInfo;

typedef struct oclMemoryObj {
	cl_mem input_buffer;
	cl_mem output_buffer;
} oclMemoryObj;

typedef struct oclKernelObj {
	cl_program program;
	cl_kernel kernel;
} oclKernelObj;

typedef struct oclStatus {
	cl_int ret_device_platform;
	cl_int ret_device_id;
} oclStatus ;

oclEngine *engine;
oclInfo *info;
oclStatus *status;

void initEngine() //add params later for platform switching
