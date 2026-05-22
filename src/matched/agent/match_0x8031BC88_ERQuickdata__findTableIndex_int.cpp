// 0x8031BC88 ERQuickdata::findTableIndex(int, (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,3; mr 30,4; mr 29,5; mr 27,6; 0:; subf. 9,30,29; blt 2f; bne 3f; mulli 0,30,20; lwz 3,0x14(28); addi 9,3,28; lwzx 10,9,0; cmpwi 10,0; beq 2f; cmplw 27,10; blt 2f; addi 9,3,40; lwzx 11,9,0; cmpwi 11,0; bne 1f; li 11,1; 1:; addi 9,3,36; lwzx 0,9,0; mr 3,30; mullw 0,11,0; add 0,10,0; cmplw 27,0; blt 7f; 2:; li 3,-1; b 7f; 3:; rlwinm 0,9,1,31,31; mr 3,28; add 0,9,0; srawi 0,0,1; add 31,30,0; mr 4,31; bl _s8031BC88_0; cmplw 27,3; bge 4f; addi 29,31,-1; b 0b; 4:; mulli 0,31,20; lwz 10,0x14(28); addi 9,10,40; lwzx 11,9,0; cmpwi 11,0; bne 5f; li 11,1; 5:; addi 9,10,36; lwzx 0,9,0; mullw 0,11,0; add 0,3,0; cmplw 27,0; blt 6f; addi 30,31,1; b 0b; 6:; mr 3,31; 7:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8031BC88_0();
extern "C" void f_8031BC88() {}
