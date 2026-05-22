// 0x80307E14 EVibrate::Resume(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 0,0x4(30); cmpwi 0,0; beq 2f; li 0,0; li 31,0; stw 0,0x4(30); 0:; mr 3,30; rlwinm 4,31,0,24,31; bl _s80307E14_0; cmpwi 3,0; beq 1f; lwz 3,-26524(13); mr 4,31; bl _s80307E14_1; mr. 11,3; beq 1f; lwz 9,0x208(11); lha 3,0xa0(9); lwz 0,0xa4(9); add 3,11,3; mtspr 8,0; blrl; 1:; addi 31,31,1; cmpwi 31,4; blt 0b; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80307E14_0();
extern "C" void _s80307E14_1();
extern "C" void f_80307E14() {}
