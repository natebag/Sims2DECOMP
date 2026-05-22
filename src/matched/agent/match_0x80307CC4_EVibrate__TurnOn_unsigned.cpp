// 0x80307CC4 EVibrate::TurnOn(unsigned (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 31,4; lwz 3,-26524(13); bl _s80307CC4_0; mr. 11,3; beq 0f; lwz 9,0x208(11); lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,11,3; blrl; mulli 0,31,68; addi 9,30,56; mr 10,9; stwx 3,9,0; b 1f; 0:; mulli 0,31,68; addi 9,30,56; mr 10,9; stwx 11,9,0; 1:; lwzx 3,10,0; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80307CC4_0();
extern "C" void f_80307CC4() {}
