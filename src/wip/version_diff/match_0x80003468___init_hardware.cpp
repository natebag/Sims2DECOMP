// __init_hardware - Nintendo SDK hardware initialization
// 36 bytes, 3 bl calls

extern "C" void __OSPSInit();
extern "C" void __OSCacheInit();
extern "C" void __OSSetInterruptHandler();

extern "C" void __init_hardware() {
    __OSPSInit();
    __OSCacheInit();
    __OSSetInterruptHandler();
}
