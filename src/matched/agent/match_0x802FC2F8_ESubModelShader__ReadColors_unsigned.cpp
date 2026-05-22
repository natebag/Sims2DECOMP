// 0x802FC2F8 ESubModelShader::ReadColors(unsigned (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 0,0x10(3); mr 30,4; mr 29,30; mr 31,5; andi. 9,0,4; beq 2f; lwz 4,0x18(31); lis 5,-32702; lis 7,-32702; addi 5,5,-2744; addi 7,7,-2616; rlwinm 4,4,2,0,29; li 6,1786; bl _s802FC2F8_0; lwz 0,0x18(31); mr 9,3; mr 4,30; rlwinm 0,0,2,0,29; stw 9,0xc(31); mr 5,0; add 30,30,0; bl _s802FC2F8_1; lwz 0,0x18(31); li 11,0; lwz 9,0xc(31); cmpw 11,0; bge 1f; li 10,255; 0:; stb 10,0x3(9); addi 11,11,1; addi 9,9,4; lwz 0,0x18(31); cmpw 11,0; blt 0b; 1:; lwz 4,0x18(31); lwz 3,0xc(31); rlwinm 4,4,2,0,29; bl _s802FC2F8_2; 2:; subf 3,29,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802FC2F8_0();
extern "C" void _s802FC2F8_1();
extern "C" void _s802FC2F8_2();
extern "C" void f_802FC2F8() {}
