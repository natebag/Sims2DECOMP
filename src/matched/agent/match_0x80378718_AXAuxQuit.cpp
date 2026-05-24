// FLAGS: -fno-schedule-insns
// 0x80378718 __AXAuxQuit (16B)
// li r0,0; stw r0,-22280(r13); stw r0,-22276(r13); blr
extern void* gAuxACallback;
extern void* gAuxBCallback;
void AXAuxQuit() {
    gAuxACallback = 0;
    gAuxBCallback = 0;
}
