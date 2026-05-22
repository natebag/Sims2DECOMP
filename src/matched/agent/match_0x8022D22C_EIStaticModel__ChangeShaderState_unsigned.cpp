// 0x8022D22C EIStaticModel::ChangeShaderState(unsigned (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 27,3; mr 26,4; lwz 9,0x120(27); cmpwi 9,0; beq 3f; lwz 0,0x40(9); li 8,0; lwz 30,0x118(27); cmpw 8,0; bge 3f; 0:; lwz 11,0x120(27); mulli 10,8,24; li 31,0; lwz 9,0x3c(11); addi 28,8,1; add 29,9,10; b 2f; 1:; lwz 3,0x4(30); rlwinm 4,26,0,24,31; addi 31,31,1; addi 30,30,16; bl _s8022D22C_0; 2:; lwz 0,0x4(29); cmpw 31,0; blt 1b; lwz 9,0x120(27); mr 8,28; lwz 0,0x40(9); cmpw 8,0; blt 0b; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s8022D22C_0();
extern "C" void f_8022D22C() {}
