// 0x80119E50 ActionQueue::ActionQueue(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; li 30,9; mr 31,29; 0:; mr 3,31; bl _s80119E50_0; addi 31,31,68; cmpwi 30,0; addi 30,30,-1; bne 0b; li 9,0; li 0,1; stw 9,0x2a8(29); mr 3,29; stb 0,0x2b0(29); stw 9,0x2ac(29); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80119E50_0();
extern "C" void f_80119E50() {}
