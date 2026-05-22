// 0x802401E8 SNInitEXI2TCHandler (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); bl _s802401E8_0; mr 30,3; lis 4,-32732; addi 4,4,172; li 3,16; bl _s802401E8_1; li 3,0; ori 3,3,32768; bl _s802401E8_2; lis 11,-13312; mr 3,30; ori 11,11,26664; lwz 0,0x0(11); ori 0,0,8; stw 0,0x0(11); lwz 9,0x0(11); rlwinm 9,9,0,30,28; stw 9,0x0(11); bl _s802401E8_3; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802401E8_0();
extern "C" void _s802401E8_1();
extern "C" void _s802401E8_2();
extern "C" void _s802401E8_3();
extern "C" void f_802401E8() {}
