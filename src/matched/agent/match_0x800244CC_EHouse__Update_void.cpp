// 0x800244CC EHouse::Update(void) (548 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-144(1); mfspr 0,8; stmw 26,0x78(1); stw 0,0x94(1); lwz 30,-26524(13); mr 31,3; li 4,0; mr 3,30; bl _s800244CC_0; mr 4,3; mr 3,30; bl _s800244CC_1; mr 30,3; li 4,0; bl _s800244CC_2; mr 4,3; li 5,0; mr 3,30; li 6,512; bl _s800244CC_3; cmpwi 3,0; beq 0f; mr 3,31; bl _s800244CC_4; 0:; lwz 11,-21496(13); li 4,0; lwz 9,0x0(11); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21496(13); mr 27,3; li 4,5; lwz 9,0x0(11); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21496(13); mr 28,3; li 4,6; lwz 9,0x0(11); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,11,3; blrl; mulli 0,27,60; lis 10,17200; lfs f12,0x40(31); lis 9,-32707; mr 26,3; lfd f13,0x970(9); add 0,0,28; stw 0,0x74(1); stw 10,0x70(1); lfd f0,0x70(1); fsub f0,f0,f13; frsp f13,f0; fcmpu 0,f13,f12; bge 1f; lis 9,-32707; lfs f0,0x978(9); fsubs f0,f0,f12; fadds f0,f0,f13; b 2f; 1:; fsubs f0,f13,f12; 2:; stfs f0,0x44(31); lis 30,17200; stw 0,0x74(1); lis 9,-32707; lfd f13,0x970(9); li 0,1; stw 30,0x70(1); mr 3,31; stw 0,0xc(31); addi 29,1,8; lfd f0,0x70(1); fsub f0,f0,f13; frsp f0,f0; stfs f0,0x40(31); bl _s800244CC_5; xoris 0,27,32768; stw 0,0x74(1); mr 10,11; xoris 6,28,32768; mr 8,11; stw 30,0x70(1); xoris 0,26,32768; lis 9,-32707; lis 7,-32707; lfd f12,0x70(1); stw 6,0x74(1); lfd f11,0x980(9); stw 30,0x70(1); lis 9,-32707; lfs f10,0x988(7); fsub f12,f12,f11; lfd f13,0x70(1); frsp f12,f12; stw 0,0x74(1); fsub f13,f13,f11; lfs f9,0x98c(9); stw 30,0x70(1); frsp f13,f13; fdivs f13,f13,f10; lwz 3,0x1c(31); lfd f0,0x70(1); cmpwi 3,0; fsub f0,f0,f11; frsp f0,f0; fdivs f0,f0,f9; fadds f12,f12,f13; fadds f1,f12,f0; stfs f1,0x48(31); beq 3f; mr 4,29; bl _s800244CC_6; 3:; mr 4,29; mr 3,31; bl _s800244CC_7; mr 3,31; bl _s800244CC_8; lwz 3,0x1c(31); cmpwi 3,0; beq 4f; bl _s800244CC_9; 4:; li 0,0; stw 0,0xc(31); lwz 0,0x94(1); mtspr 8,0; lmw 26,0x78(1); addi 1,1,144"
extern "C" void _s800244CC_0();
extern "C" void _s800244CC_1();
extern "C" void _s800244CC_2();
extern "C" void _s800244CC_3();
extern "C" void _s800244CC_4();
extern "C" void _s800244CC_5();
extern "C" void _s800244CC_6();
extern "C" void _s800244CC_7();
extern "C" void _s800244CC_8();
extern "C" void _s800244CC_9();
extern "C" void f_800244CC() {}
