// 0x8034DC98 ENgcShader::Select(ERC (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 28,3; li 31,0; lbz 0,0x0(28); mr 27,4; mr 26,5; cmpw 31,0; bge 1f; 0:; lwz 29,0x70(27); mr 4,31; mr 3,28; lha 30,0x120(29); addi 29,29,288; add 30,27,30; bl _s8034DC98_0; lwz 0,0x4(29); mr 4,3; mr 5,31; mr 3,30; mtspr 8,0; addi 31,31,1; blrl; lbz 0,0x0(28); cmpw 31,0; blt 0b; 1:; lwz 9,0x70(27); mr 4,28; mr 5,26; lha 3,0x338(9); lwz 0,0x33c(9); add 3,27,3; mtspr 8,0; blrl; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s8034DC98_0();
extern "C" void f_8034DC98() {}
