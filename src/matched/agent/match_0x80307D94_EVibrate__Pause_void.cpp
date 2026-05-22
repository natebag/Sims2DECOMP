// 0x80307D94 EVibrate::Pause(void) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 31,0; 0:; mr 3,30; rlwinm 4,31,0,24,31; bl _s80307D94_0; cmpwi 3,0; beq 1f; lwz 3,-26524(13); mr 4,31; bl _s80307D94_1; mr. 11,3; beq 1f; lwz 9,0x208(11); lha 3,0x98(9); lwz 0,0x9c(9); add 3,11,3; mtspr 8,0; blrl; 1:; addi 31,31,1; cmpwi 31,4; blt 0b; li 0,1; stw 0,0x4(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80307D94_0();
extern "C" void _s80307D94_1();
extern "C" void f_80307D94() {}
