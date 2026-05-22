// 0x8031C6DC ERShader::ERShader(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s8031C6DC_0; lis 9,-32697; li 0,0; addi 9,9,-18824; li 11,-1; stw 9,0x0(31); lis 10,-32702; stw 11,0x3c(31); addi 9,31,60; stw 0,0x14(31); li 7,2; stw 0,0x18(31); mtspr 9,7; stw 0,0x1c(31); li 8,0; stw 0,0x30(31); addi 11,31,40; stw 0,0x34(31); stw 0,0x38(31); lfs f0,0xa24(10); stw 0,0x10(9); stfs f0,0x4(9); stb 0,0x8(9); stw 0,0xc(9); stfs f0,0x60(31); stw 0,0x68(31); stb 0,0x50(31); stw 0,0x54(31); stw 0,0x58(31); stw 0,0x5c(31); stb 0,0x64(31); stb 0,0x65(31); stb 0,0x66(31); stb 0,0x67(31); 0:; stw 8,-8(11); stw 8,0x0(11); addi 11,11,4; bdnz 0b; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8031C6DC_0();
extern "C" void f_8031C6DC() {}
