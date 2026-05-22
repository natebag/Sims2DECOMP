// 0x801BFEE8 M2MTarget::GetVariable(char (440 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 31,4; mr 29,3; lbz 3,0x0(31); extsb 3,3; bl _s801BFEE8_0; cmpwi 3,0; beq 0f; addi 31,31,1; 0:; li 3,128; bl _s801BFEE8_1; mr 30,3; li 0,0; lis 3,-32705; stb 0,0x0(30); addi 3,3,8440; mr 4,31; bl _s801BFEE8_2; cmpwi 3,0; bne 1f; lis 9,-32705; addi 11,9,-8792; lwz 10,-8792(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(30); sth 0,0x4(30); stb 8,0x6(30); b 4f; 1:; lis 3,-32705; mr 4,31; addi 3,3,8452; bl _s801BFEE8_3; cmpwi 3,0; bne 2f; lis 4,-32705; mr 3,30; addi 4,4,-5236; li 5,432; crxor 6,6,6; bl _s801BFEE8_4; b 4f; 2:; lis 3,-32705; mr 4,31; addi 3,3,8472; bl _s801BFEE8_5; cmpwi 3,0; bne 3f; lwz 0,0x160(29); lis 8,17200; lis 11,-32705; stw 0,0x14(1); lis 10,-32705; lfd f13,0x2140(11); mr 5,9; stw 8,0x10(1); lis 4,-32705; lfs f11,0x2148(10); addi 4,4,-5236; lfd f0,0x10(1); mr 3,30; fsub f0,f0,f13; frsp f0,f0; fadds f0,f0,f11; fmr f13,f0; fctiwz f12,f13; stfd f12,0x10(1); lwz 5,0x14(1); crxor 6,6,6; bl _s801BFEE8_6; b 4f; 3:; lis 3,-32705; mr 4,31; addi 3,3,8492; bl _s801BFEE8_7; cmpwi 3,0; bne 4f; lwz 0,0x164(29); lis 8,17200; lis 11,-32705; stw 0,0x14(1); lis 10,-32705; lfd f13,0x2140(11); mr 5,9; stw 8,0x10(1); lis 4,-32705; lfs f11,0x2148(10); addi 4,4,-5236; lfd f0,0x10(1); mr 3,30; fsub f0,f0,f13; frsp f0,f0; fadds f0,f0,f11; fmr f13,f0; fctiwz f12,f13; stfd f12,0x10(1); lwz 5,0x14(1); crxor 6,6,6; bl _s801BFEE8_8; 4:; mr 3,30; bl _s801BFEE8_9; mr 3,30; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s801BFEE8_0();
extern "C" void _s801BFEE8_1();
extern "C" void _s801BFEE8_2();
extern "C" void _s801BFEE8_3();
extern "C" void _s801BFEE8_4();
extern "C" void _s801BFEE8_5();
extern "C" void _s801BFEE8_6();
extern "C" void _s801BFEE8_7();
extern "C" void _s801BFEE8_8();
extern "C" void _s801BFEE8_9();
extern "C" void f_801BFEE8() {}
