// FLAGS: -fno-schedule-insns
// 0x80378ABC AXRegisterAuxACallback (12B)
// stw r3,-22280(r13); stw r4,-22272(r13); blr
extern void* gAuxACallback;
extern void* gAuxAUserdata;
void AXRegisterAuxACallback(void* callback, void* userdata) {
    gAuxACallback = callback;
    gAuxAUserdata = userdata;
}
