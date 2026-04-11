// global_destructors keyed to gRebootTimer
// Address: 0x800063CC | Size: 44 bytes

// Internal cleanup function at 0x800062FC
extern void cleanup_func(int a, unsigned short b);

void global_destructors_gRebootTimer() {
    cleanup_func(0, 0xFFFF);
}
