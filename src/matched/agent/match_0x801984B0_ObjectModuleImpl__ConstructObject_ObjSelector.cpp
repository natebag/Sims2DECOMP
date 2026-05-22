// 0x801984B0 ObjectModuleImpl::ConstructObject(ObjSelector (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 4,29,172; bl _s801984B0_0; lwz 4,-21168(13); b 1f; cmpwi 0,2; bne 2f; lwz 3,0x2fc(29); cmpwi 3,0; beq 0f; li 4,3; bl _s801984B0_1; 0:; li 0,0; li 3,360; stw 0,0x2fc(29); bl _s801984B0_2; bl _s801984B0_3; mr 30,3; li 5,1; addi 4,29,464; bl _s801984B0_4; lwz 4,-21164(13); 1:; mr 3,30; bl _s801984B0_5; mr 3,30; bl _s801984B0_6; mr 3,30; bl _s801984B0_7; mr 3,30; bl _s801984B0_8; mr 3,30; bl _s801984B0_9; mr 3,30; bl _s801984B0_10; stw 30,0x2fc(29); b 4f; 2:; cmpwi 0,4; bne 4f; lwz 31,0x84(29); addi 30,1,8; addi 28,30,8; mr 27,30; mr 3,31; bl _s801984B0_11; lwz 0,0x2f4(29); lis 9,-32698; mr 29,3; addi 9,9,24616; xori 0,0,1; subfic 11,0,0; adde 0,11,0; mr 3,28; stw 0,0x84(29); stw 9,0x4(30); bl _s801984B0_12; li 0,0; li 9,288; stw 0,0x8(1); 3:; lwz 0,0x0(29); addic. 9,9,-24; stw 0,0x0(28); lwz 0,0x4(29); stw 0,0x4(28); lwz 0,0x8(29); stw 0,0x8(28); lwz 0,0xc(29); stw 0,0xc(28); lwz 0,0x10(29); stw 0,0x10(28); lwz 0,0x14(29); addi 29,29,24; stw 0,0x14(28); addi 28,28,24; bne 3b; lwz 0,0x0(29); mr 3,31; addi 4,1,8; stw 0,0x0(28); bl _s801984B0_13; lis 9,-32698; mr 3,27; addi 9,9,24616; li 4,2; stw 9,0x4(27); bl _s801984B0_14; 4:; lwz 0,0x154(1); mtspr 8,0; lmw 27,0x13c(1); addi 1,1,336"
extern "C" void _s801984B0_0();
extern "C" void _s801984B0_1();
extern "C" void _s801984B0_2();
extern "C" void _s801984B0_3();
extern "C" void _s801984B0_4();
extern "C" void _s801984B0_5();
extern "C" void _s801984B0_6();
extern "C" void _s801984B0_7();
extern "C" void _s801984B0_8();
extern "C" void _s801984B0_9();
extern "C" void _s801984B0_10();
extern "C" void _s801984B0_11();
extern "C" void _s801984B0_12();
extern "C" void _s801984B0_13();
extern "C" void _s801984B0_14();
extern "C" void f_801984B0() {}
