// FLAGS: -fno-schedule-insns
// 0x80378AC8 AXRegisterAuxBCallback (12B)
// stw r3,-22276(r13); stw r4,-22268(r13); blr
extern void* gAuxBCallback;
extern void* gAuxBUserdata;
void AXRegisterAuxBCallback(void* callback, void* userdata) {
    gAuxBCallback = callback;
    gAuxBUserdata = userdata;
}
