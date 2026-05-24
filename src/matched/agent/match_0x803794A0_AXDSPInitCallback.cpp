// FLAGS: -fno-schedule-insns
// 0x803794A0 __AXDSPInitCallback (12B)
// li r0,1; stw r0,-22172(r13); blr
extern int gAXDSPInitDone;
void AXDSPInitCallback() {
    gAXDSPInitDone = 1;
}
