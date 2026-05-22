// 0x801A4C70 CRDTarget::Update(void) (336 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 30,0x28(1); stw 0,0x34(1); mr 30,3; lwz 0,0x84(30); cmpwi 0,0; beq 4f; lwz 0,0x90(30); cmpwi 0,0; beq 4f; lis 3,-32697; li 4,9; addi 3,3,24012; bl _s801A4C70_0; lwz 0,0xc0(30); mr 31,3; cmpw 31,0; beq 2f; lwz 0,0x98(30); xori 0,0,1; cmpwi 0,0; stw 0,0x98(30); beq 0f; mr 3,30; bl _s801A4C70_1; b 1f; 0:; mr 3,30; bl _s801A4C70_2; 1:; stw 31,0xc0(30); 2:; lwz 0,0x98(30); cmpwi 0,0; beq 4f; lwz 11,0x94(30); lis 7,17200; lis 9,-32705; xoris 0,11,32768; lfd f13,-7840(9); stw 0,0x24(1); lis 9,-32705; lfs f12,-7832(9); lis 8,-32705; stw 7,0x20(1); addi 11,11,1; lfs f11,-7828(8); lfd f0,0x20(1); stw 11,0x94(30); fsub f0,f0,f13; frsp f0,f0; fdivs f10,f0,f12; fcmpu 0,f10,f11; ble 3f; li 0,0; mr 3,30; stw 0,0x98(30); bl _s801A4C70_3; b 4f; 3:; lis 9,-32705; fsubs f0,f11,f10; lis 11,-32705; lfs f13,-7820(9); lfs f11,-7824(11); fmuls f13,f10,f13; addi 3,1,8; fmadds f0,f0,f11,f13; fctiwz f12,f0; stfd f12,0x20(1); lwz 30,0x24(1); bl _s801A4C70_4; lis 4,-32705; addi 3,1,8; addi 4,4,-7852; mr 5,30; li 6,24; li 7,0; bl _s801A4C70_5; addi 3,1,8; li 4,2; bl _s801A4C70_6; 4:; lwz 0,0x34(1); mtspr 8,0; lmw 30,0x28(1); addi 1,1,48"
extern "C" void _s801A4C70_0();
extern "C" void _s801A4C70_1();
extern "C" void _s801A4C70_2();
extern "C" void _s801A4C70_3();
extern "C" void _s801A4C70_4();
extern "C" void _s801A4C70_5();
extern "C" void _s801A4C70_6();
extern "C" void f_801A4C70() {}
