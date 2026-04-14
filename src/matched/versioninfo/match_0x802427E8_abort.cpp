// 0x802427E8 abort (24b)
extern "C" void _exit(int, ...);

extern "C" void abort() {
    _exit(1);
}
