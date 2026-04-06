// SNInitInterrupts - Nintendo SDK function
// 72 bytes, 4 bl calls

// External functions
extern "C" void sub_8024F9B4(int);
extern "C" void sub_8024F59C(int, void*);
extern "C" void sub_8024FA3C(int);

// Global at 0x8023F420
extern char gInterruptHandler[4];

extern "C" void SNInitInterrupts() {
    sub_8024F9B4(0x18000);
    sub_8024F9B4(64);
    sub_8024F59C(25, (void*)0x8023F420);
    sub_8024FA3C(64);
}
