// __static_initialization_and_destruction_0_5
// 36B, uses SDA (r13) with offset -21480

extern char gInitGuard[4];  // at r13 - 21480

extern "C" void __static_initialization_and_destruction_0_5(int param) {
    if (param == 0) {
        return;
    }
    // Store 1 to guard variable
    *(int*)gInitGuard = 1;
}
