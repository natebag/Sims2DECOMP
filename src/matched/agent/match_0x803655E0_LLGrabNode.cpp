// 0x803655E0 LLGrabNode (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr. 28,5; beq 4f; li 29,0; bl _s803655E0_0; lwz 0,0x88(31); stw 0,0x90(31); mr. 30,0; beq 3f; 0:; lwz 0,0x8(30); cmpw 0,28; bne 1f; li 29,1; b 2f; 1:; lwz 9,0x90(31); lwz 0,0x0(9); stw 0,0x90(31); 2:; cmpwi 29,0; bne 3f; lwz 30,0x90(31); cmpwi 30,0; bne 0b; 3:; mr 3,31; bl _s803655E0_1; mr 3,30; b 5f; 4:; li 3,0; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s803655E0_0();
extern "C" void _s803655E0_1();
extern "C" void f_803655E0() {}
