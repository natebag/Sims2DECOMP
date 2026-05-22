// 0x803C3FF8 EStream (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; mr 28,4; lwz 9,0x18(31); addi 4,1,8; li 5,4; li 29,0; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,31,3; blrl; lwz 4,0x8(1); mr 3,28; li 5,0; bl _s803C3FF8_0; lwz 0,0x8(1); cmpw 29,0; bge 1f; li 30,0; 0:; lwz 9,0x18(31); li 5,4; lwz 4,0x0(28); addi 29,29,1; lwz 0,0x34(9); lha 3,0x30(9); add 4,4,30; mtspr 8,0; addi 30,30,4; add 3,31,3; blrl; lwz 0,0x8(1); cmpw 29,0; blt 0b; 1:; mr 3,31; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s803C3FF8_0();
extern "C" void f_803C3FF8() {}
