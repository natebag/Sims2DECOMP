// 0x800B75BC cSoundPlayer::KillAllEvent(void) (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 28,0x28(1); stw 0,0x3c(1); mr 30,3; li 0,1; stw 0,0x14(30); addi 11,30,24; mr 29,11; lis 28,-32692; lwz 9,0x4(11); lwz 0,0x0(9); stw 0,0x8(1); stw 0,0x10(1); b 3f; 0:; lwz 0,0x4(29); li 9,1; cmpw 11,0; stw 0,0x18(1); bne 1f; li 9,0; 1:; cmpwi 9,0; beq 5f; lwz 9,0x10(1); addi 3,28,-14084; lwz 0,0x0(9); stw 0,0x10(1); lwz 4,0xc(11); bl _s800B75BC_0; lwz 3,0x8(1); stw 3,0x20(1); cmpwi 3,0; lwz 31,0x0(3); lwz 9,0x4(3); stw 31,0x0(9); stw 9,0x4(31); beq 2f; li 4,20; bl _s800B75BC_1; 2:; lwz 0,0x10(1); stw 31,0x18(1); stw 0,0x8(1); 3:; lwz 11,0x8(1); li 9,1; lwz 0,0x10(30); cmpw 11,0; bne 4f; li 9,0; 4:; cmpwi 9,0; addi 10,30,24; bne 0b; 5:; lwz 0,0x4(10); stw 0,0x10(30); stw 0,0x18(1); lwz 0,0x3c(1); mtspr 8,0; lmw 28,0x28(1); addi 1,1,56"
extern "C" void _s800B75BC_0();
extern "C" void _s800B75BC_1();
extern "C" void f_800B75BC() {}
