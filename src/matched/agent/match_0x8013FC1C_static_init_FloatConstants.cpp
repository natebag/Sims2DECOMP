/* __static_initialization_and_destruction_0 - 0x8013FC1C - 84 bytes */

struct FloatConstants {
    FloatConstants(void);
};

void __cxa_atexit(void (*)(void*), void*, void*);
extern FloatConstants gFloatConstants;
extern void* __dso_handle;

void FloatConstants_dtor_wrapper(void*);

void __static_initialization_and_destruction_0(int __initialize_p, unsigned int __priority) {
    if (__priority == 0x0000FFFF) {
        if (__initialize_p) {
            gFloatConstants.FloatConstants::FloatConstants();
        } else {
            __cxa_atexit(FloatConstants_dtor_wrapper, &gFloatConstants, &__dso_handle);
        }
    }
}
