// 0x80014FF8 __static_initialization_and_destruction_0 (36b)

extern char gInitGuard[4];  // at r13 - 21480

extern "C" void __static_initialization_and_destruction_0_5(int initialize_p, int priority) {
    if (priority != 65535) return;
    if (initialize_p == 0) return;
    *(int*)gInitGuard = 1;
}
