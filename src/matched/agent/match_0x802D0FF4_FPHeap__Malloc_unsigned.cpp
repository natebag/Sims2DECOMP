// 0x802D0FF4 FPHeap::Malloc(unsigned (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,5; mr. 31,4; beq 0f; lwz 3,-21320(13); mr 4,31; li 5,8; bl _s802D0FF4_0; mr. 3,3; bne 1f; mr 3,30; mr 4,31; mr 5,29; bl _s802D0FF4_1; b 1f; 0:; li 3,0; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802D0FF4_0();
extern "C" void _s802D0FF4_1();
extern "C" void f_802D0FF4() {}
