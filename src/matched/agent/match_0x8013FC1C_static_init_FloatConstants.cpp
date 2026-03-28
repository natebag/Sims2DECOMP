/* __static_initialization_and_destruction_0 - 0x8013FC1C - 84 bytes */

void FloatConstants_ctor(void*);
void __atexit_func(void*, int);

extern char gFloatConstants[];

void __static_initialization_and_destruction_0(int __initialize_p, unsigned int __priority) {
    if (__priority == 0x0000FFFF) {
        if (__initialize_p != 0) {
            FloatConstants_ctor(gFloatConstants);
        } else {
            __atexit_func(gFloatConstants, 2);
        }
    }
}
