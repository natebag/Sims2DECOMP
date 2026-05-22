// 0x8034DD3C ENgcShader::SelectForShadowMask(ERC (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,3; lwz 9,0x70(30); li 4,0; li 5,0; lwz 0,0x124(9); lha 3,0x120(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x70(30); li 5,0; mr 4,29; lwz 0,0x33c(9); lha 3,0x338(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x70(30); li 4,16384; lwz 0,0x12c(9); lha 3,0x128(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x70(30); li 4,64; li 5,0; lwz 0,0x144(9); lha 3,0x140(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x70(30); li 4,0; li 5,2; li 6,0; lha 3,0x1c8(9); li 7,0; lwz 0,0x1cc(9); add 3,30,3; mtspr 8,0; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_8034DD3C() {}
