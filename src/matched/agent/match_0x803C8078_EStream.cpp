// 0x803C8078 EStream (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 29,3; mr 28,4; lwz 9,0x18(29); addi 4,1,8; li 5,4; li 30,0; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,29,3; blrl; lwz 4,0x8(1); mr 3,28; li 5,0; bl _s803C8078_0; lwz 0,0x8(1); cmpw 30,0; bge 1f; li 31,0; 0:; lwz 4,0x0(28); mr 3,29; addi 30,30,1; add 4,4,31; bl _s803C8078_1; addi 31,31,4; lwz 0,0x8(1); cmpw 30,0; blt 0b; 1:; mr 3,29; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s803C8078_0();
extern "C" void _s803C8078_1();
extern "C" void f_803C8078() {}
