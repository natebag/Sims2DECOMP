// 0x801CA44C MODTarget::SetMeterValue(float, (508 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f31,0x28(1); stmw 28,0x18(1); stw 0,0x34(1); mr 28,3; mr 30,4; lwz 0,0x84(28); cmpwi 0,0; beq 9f; fmr f0,f1; fctiwz f13,f0; stfd f13,0x10(1); lwz 31,0x14(1); cmpwi 31,10; bne 0f; li 31,16; b 1f; 0:; cmpwi 31,0; beq 1f; lis 9,-32705; lis 11,-32705; lfs f31,0x323c(9); lfs f0,0x3240(11); fdivs f31,f1,f31; fmuls f31,f31,f0; fmr f1,f31; bl _s801CA44C_0; fctiwz f0,f1; mr 9,8; stfd f0,0x10(1); lis 7,17200; lis 11,-32705; lis 10,-32705; lwz 8,0x14(1); lfd f13,0x3248(11); xoris 0,8,32768; lfs f12,0x3250(10); stw 0,0x14(1); addi 31,8,1; stw 7,0x10(1); lfd f0,0x10(1); fsub f0,f0,f13; frsp f0,f0; fsubs f31,f31,f0; fcmpu 0,f31,f12; bge 1f; mr 31,8; 1:; lwz 0,0xdc(28); cmpw cr7,31,0; beq cr7,9f; lwz 0,0xa4(28); cmpwi 0,0; bgt 8f; cmpwi 30,0; beq 8f; cmpwi 31,16; beq 7f; cmpwi 31,0; bgt 3f; lwz 0,-31536(13); cmpwi 0,0; bne 2f; li 3,120; bl _s801CA44C_1; bl _s801CA44C_2; stw 3,-31536(13); 2:; lis 4,-26996; lwz 3,-31536(13); ori 4,4,2582; bl _s801CA44C_3; b 7f; 3:; bge cr7,5f; lwz 0,-31536(13); cmpwi 0,0; bne 4f; li 3,120; bl _s801CA44C_4; bl _s801CA44C_5; stw 3,-31536(13); 4:; lis 4,29328; lwz 3,-31536(13); ori 4,4,37550; bl _s801CA44C_6; b 7f; 5:; lwz 0,-31536(13); cmpwi 0,0; bne 6f; li 3,120; bl _s801CA44C_7; bl _s801CA44C_8; stw 3,-31536(13); 6:; lis 4,-25408; lwz 3,-31536(13); ori 4,4,19670; bl _s801CA44C_9; 7:; li 0,10; stw 0,0xa4(28); 8:; addi 30,28,200; addi 29,1,8; mr 3,30; bl _s801CA44C_10; lwz 5,0x94(28); lis 4,-32705; addi 4,4,12844; mr 3,30; bl _s801CA44C_11; li 0,97; lis 4,-32705; stb 0,0x8(1); mr 5,31; addi 3,1,9; addi 4,4,-5236; crxor 6,6,6; bl _s801CA44C_12; mr 4,29; mr 3,30; bl _s801CA44C_13; mr 3,30; bl _s801CA44C_14; stw 31,0xdc(28); 9:; lwz 0,0x34(1); mtspr 8,0; lmw 28,0x18(1); lfd f31,0x28(1); addi 1,1,48"
extern "C" void _s801CA44C_0();
extern "C" void _s801CA44C_1();
extern "C" void _s801CA44C_2();
extern "C" void _s801CA44C_3();
extern "C" void _s801CA44C_4();
extern "C" void _s801CA44C_5();
extern "C" void _s801CA44C_6();
extern "C" void _s801CA44C_7();
extern "C" void _s801CA44C_8();
extern "C" void _s801CA44C_9();
extern "C" void _s801CA44C_10();
extern "C" void _s801CA44C_11();
extern "C" void _s801CA44C_12();
extern "C" void _s801CA44C_13();
extern "C" void _s801CA44C_14();
extern "C" void f_801CA44C() {}
