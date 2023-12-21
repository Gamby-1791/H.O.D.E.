#include "GPIOModule.h"

#include "../driver/gpiolib.h"

static PhysLib gpiolib (DEFCPUHZ);

JNIEXPORT void JNICALL Java_GPIOModule_opengpio (JNIEnv *, jclass)
{
    gpiolib.open ();
}

JNIEXPORT jint JNICALL Java_GPIOModule_readgpio (JNIEnv *, jclass)
{
    return gpiolib.readgpio ();
}

JNIEXPORT void JNICALL Java_GPIOModule_writegpio (JNIEnv *, jclass, jboolean wdata, jint valu)
{
    gpiolib.writegpio (wdata, valu);
}
