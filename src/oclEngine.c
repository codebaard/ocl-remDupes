#include "oclEngine.h"

void initEngine() {
	engine = (oclEngine*)malloc(sizeof(oclEngine));
	info = (oclInfo*)malloc(sizeof(oclInfo));
	status = (oclStatus*)malloc(sizeof(oclStatus));

	status->ret_device_platform = clGetPlatformIDs(1, &engine->platform_id, &info->num_platforms);

}