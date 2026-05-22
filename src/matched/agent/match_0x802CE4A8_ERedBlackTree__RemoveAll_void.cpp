// 0x802CE4A8 ERedBlackTree::RemoveAll(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 30,0x4(31); cmpwi 30,0; beq 1f; 0:; mr 3,30; lwz 30,0xc(30); bl _s802CE4A8_0; mr. 30,30; bne 0b; 1:; lis 9,-32700; li 0,0; addi 9,9,-4812; stw 0,0x0(31); stw 9,0x8(31); stw 0,0x4(31); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802CE4A8_0();
extern "C" void f_802CE4A8() {}
