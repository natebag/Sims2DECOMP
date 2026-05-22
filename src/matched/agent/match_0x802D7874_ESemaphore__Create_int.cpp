// 0x802D7874 ESemaphore::Create(int, (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; cmpwi 5,-1; bne 0f; mr 5,29; 0:; addi 30,31,12; mr 4,5; mr 3,30; bl _s802D7874_0; stw 29,0x8(31); li 3,1; stw 30,0x4(31); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802D7874_0();
extern "C" void f_802D7874() {}
