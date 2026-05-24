// FLAGS: -fno-schedule-insns
// 0x803778AC __ARQInitTempQueue (16B)
// li r0,0; stw r0,-22320(r13); stw r0,-22316(r13); blr
extern int gARQTempHead;
extern int gARQTempTail;
void ARQInitTempQueue() {
    gARQTempHead = 0;
    gARQTempTail = 0;
}
