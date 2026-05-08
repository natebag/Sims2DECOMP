// 0x8000ACB8 _assertFail (44B)

typedef void (*AptFunc)();
extern AptFunc gAptFuncs[];

extern "C" void _assertFail() {
    gAptFuncs[3]();
}
