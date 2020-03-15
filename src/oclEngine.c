#include "oclEngine.h"

void initEngine() {
	engine = (oclEngine*)malloc(sizeof(oclEngine));
	info = (oclInfo*)malloc(sizeof(oclInfo));
	status = (oclStatus*)malloc(sizeof(oclStatus));

	engine->platform_id = NULL;
	engine->device_id = NULL;

	status->ret_device_platform = clGetPlatformIDs(1, 
								&engine->platform_id, 
								&info->num_platforms);

	printf("Intializing openCL : PlatformIDs : %d\n", info->num_platforms);

	status->ret_device_id = clGetDeviceIDs(engine->platform_id, 
							CL_DEVICE_TYPE_ALL,
							1, 
							&engine->device_id, 
							&info->num_devices);

	printf("Intializing openCL : numDevices %d\n", info->num_devices);

	engine->context = clCreateContext(NULL, 1, &engine->device_id, 
									NULL, NULL, &status->ret_context);

	engine->command_cue = clCreateCommandQueue(engine->context, engine->device_id, 0, &status->ret_command_cue);

	printf("Engine initialized : %d, %d, %d, %d\n", status->ret_device_platform,
												status->ret_device_id,
												status->ret_context,
												status->ret_command_cue);

}