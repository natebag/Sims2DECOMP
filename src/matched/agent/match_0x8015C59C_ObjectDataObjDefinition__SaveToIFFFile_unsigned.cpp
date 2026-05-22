// 0x8015C59C ObjectDataObjDefinition::SaveToIFFFile(unsigned (348 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); lwz 11,-21508(13); mr 29,3; mr 26,6; mr 27,5; lwz 9,0x0(11); li 30,196; lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; mr 31,3; bl _s8015C59C_0; li 4,12; li 5,0; bl _s8015C59C_1; mr 28,3; stw 30,0x0(28); bl _s8015C59C_2; li 4,196; li 5,0; bl _s8015C59C_3; li 0,1; stw 3,0x4(28); stw 0,0x8(28); mr 11,3; li 10,192; lwz 9,0x1c(29); 0:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 0b; lwz 0,0x0(9); lis 5,20290; mr 6,27; mr 7,26; stw 0,0x0(11); mr 4,28; ori 5,5,19012; li 8,0; lwz 9,0xc(31); lha 3,0xf8(9); lwz 0,0xfc(9); add 3,31,3; mtspr 8,0; blrl; mr 3,31; bl _s8015C59C_4; cmpwi 3,0; bne 1f; lwz 9,0xc(31); mr 4,28; lwz 0,0x10c(9); lha 3,0x108(9); mtspr 8,0; add 3,31,3; blrl; mr 3,31; bl _s8015C59C_5; lwz 9,0xc(31); lha 3,0x48(9); lwz 0,0x4c(9); add 3,31,3; mtspr 8,0; blrl; 1:; li 3,1; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s8015C59C_0();
extern "C" void _s8015C59C_1();
extern "C" void _s8015C59C_2();
extern "C" void _s8015C59C_3();
extern "C" void _s8015C59C_4();
extern "C" void _s8015C59C_5();
extern "C" void f_8015C59C() {}
