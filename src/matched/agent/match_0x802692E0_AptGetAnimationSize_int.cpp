// 0x802692E0 AptGetAnimationSize(int (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lwz 9,-23008(13); mr 30,3; mr 28,4; cmpwi 9,0; beq 5f; lwz 9,0x28(9); cmpwi 9,0; beq 5f; lwz 9,0x0(9); lwz 31,0x54(9); cmpwi 31,0; beq 2f; mr 3,31; li 29,0; bl _s802692E0_0; cmpwi 3,18; bne 0f; mr 3,31; bl _s802692E0_1; subfic 0,3,0; adde 29,0,3; 0:; cmpwi 29,0; beq 2f; lwz 10,-23008(13); cmpwi 30,0; lwz 9,0x28(10); lwz 11,0x0(9); lwz 10,0x54(11); lwz 11,0x4c(10); beq 1f; lwz 9,0x8(11); lwz 0,0x1c(9); stw 0,0x0(30); 1:; cmpwi 28,0; beq 5f; lwz 9,0x8(11); lwz 0,0x20(9); b 4f; 2:; cmpwi 30,0; beq 3f; li 0,0; stw 0,0x0(30); 3:; cmpwi 28,0; beq 5f; li 0,0; 4:; stw 0,0x0(28); 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802692E0_0();
extern "C" void _s802692E0_1();
extern "C" void f_802692E0() {}
