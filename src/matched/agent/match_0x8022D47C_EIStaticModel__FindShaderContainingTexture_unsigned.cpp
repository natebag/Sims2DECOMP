// 0x8022D47C EIStaticModel::FindShaderContainingTexture(unsigned (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 27,3; mr 25,4; lwz 9,0x120(27); cmpwi 9,0; bne 1f; b 5f; 0:; lwz 3,0x4(30); b 6f; 1:; lwz 0,0x40(9); li 28,0; lwz 30,0x118(27); cmpw 28,0; bge 5f; li 26,0; 2:; lwz 9,0x120(27); li 31,0; lwz 0,0x3c(9); add 29,0,26; lwz 9,0x4(29); cmpw 31,9; bge 4f; 3:; lwz 3,0x4(30); mr 4,25; bl _s8022D47C_0; cmpwi 3,0; bne 0b; lwz 0,0x4(29); addi 31,31,1; addi 30,30,16; cmpw 31,0; blt 3b; 4:; lwz 9,0x120(27); addi 28,28,1; addi 26,26,24; lwz 0,0x40(9); cmpw 28,0; blt 2b; 5:; li 3,0; 6:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s8022D47C_0();
extern "C" void f_8022D47C() {}
