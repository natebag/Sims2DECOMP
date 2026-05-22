// 0x80008300 allocateString(AptAllocateStringParameters (1176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stfd f31,0x50(1); stmw 28,0x40(1); stw 0,0x5c(1); lis 9,-32697; mr 28,3; addi 9,9,3472; li 11,0; li 30,0; 0:; lwz 0,0x0(9); cmpwi 0,0; bne 1f; li 30,1; b 2f; 1:; addi 9,9,40; addi 11,11,1; 2:; cmpwi 7,30,0; bne cr7,3f; cmpwi 11,249; ble 0b; 3:; mulli 0,11,40; lis 9,-32697; addi 9,9,3472; add 31,0,9; bne cr7,6f; lis 9,-32697; lwz 0,0x34a0(9); addi 31,9,13472; cmpwi 0,0; beq 5f; lwz 3,0x20(31); stw 30,0x34a0(9); cmpwi 3,0; beq 4f; lis 9,-32694; lwz 0,-16284(9); mtspr 8,0; blrl; stw 30,0x20(31); 4:; lwz 11,0x24(31); cmpwi 11,0; beq 5f; lwz 9,0x34(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; stw 30,0x24(31); 5:; lis 9,-32697; addi 31,9,13472; 6:; li 0,1; li 11,0; stw 0,0x0(31); lfs f0,0x4(28); stfs f0,0x8(31); lfs f13,0x8(28); stfs f13,0xc(31); lfs f0,0xc(28); stfs f0,0x10(31); lfs f13,0x10(28); stfs f13,0x14(31); lwz 0,0x14(28); stw 0,0x18(31); lwz 9,0x2c(28); stw 9,0x4(31); lfs f0,0x48(28); stfs f0,0x1c(31); lwz 3,0x54(28); cmpwi 3,0; beq 7f; bl _s80008300_0; mr 11,3; 7:; cmpwi 11,0; beq 8f; lis 9,-32694; addi 3,11,1; lwz 0,-16288(9); mtspr 8,0; blrl; stw 3,0x20(31); lwz 4,0x54(28); bl _s80008300_1; b 9f; 8:; lis 9,-32707; addi 30,1,48; lhz 0,-11240(9); mr 3,30; sth 0,0x30(1); bl _s80008300_2; lis 9,-32694; addi 3,3,1; lwz 0,-16288(9); mtspr 8,0; blrl; mr 0,3; mr 4,30; stw 0,0x20(31); bl _s80008300_3; 9:; lwz 30,0x24(31); cmpwi 30,0; bne 17f; bl _s80008300_4; li 4,8192; li 5,0; bl _s80008300_5; mr 29,3; li 5,3; sth 30,0x0(29); lis 3,-32707; addi 3,3,-11236; lwz 4,0x20(31); bl _s80008300_6; cmpwi 3,0; bne 10f; lwz 3,0x20(31); bl _s80008300_7; mr. 3,3; beq 14f; mr 4,3; mr 3,29; bl _s80008300_8; mr 3,29; bl _s80008300_9; b 14f; 10:; lis 3,-32707; lwz 4,0x20(31); addi 3,3,-11232; li 5,7; bl _s80008300_10; cmpwi 3,0; bne 11f; lwz 3,0x20(31); addi 3,3,7; bl _s80008300_11; mr 4,3; mr 3,29; bl _s80008300_12; b 14f; 11:; lis 3,-32707; lwz 4,0x20(31); addi 3,3,-11224; li 5,7; bl _s80008300_13; cmpwi 3,0; bne 13f; lwz 0,-31524(13); cmpwi 0,0; bne 12f; li 3,16; bl _s80008300_14; bl _s80008300_15; stw 3,-31524(13); 12:; lwz 4,0x20(31); lwz 3,-31524(13); addi 4,4,7; mr 5,4; bl _s80008300_16; mr. 30,3; beq 14f; mr 3,29; mr 4,30; bl _s80008300_17; mr 3,30; bl _s80008300_18; b 14f; 13:; lwz 30,0x20(31); cmpwi 30,0; beq 14f; mr 3,30; bl _s80008300_19; addi 4,3,1; mr 5,29; mr 3,30; bl _s80008300_20; mr 3,29; bl _s80008300_21; 14:; lwz 10,0x4(31); lis 6,17200; mr 8,11; rlwinm 0,10,16,24,31; rlwinm 30,10,24,24,31; stw 0,0x3c(1); mr 7,11; rlwinm 10,10,0,24,31; lis 4,-32707; stw 6,0x38(1); lis 9,-32707; lfs f0,-11204(4); lis 5,-32707; lfd f12,0x38(1); li 3,56; stw 30,0x3c(1); stfs f0,0x14(1); stw 6,0x38(1); lfd f11,-11216(9); lfd f13,0x38(1); stw 10,0x3c(1); fsub f12,f12,f11; lfs f10,-11208(5); fsub f13,f13,f11; stw 6,0x38(1); frsp f12,f12; frsp f13,f13; lfd f0,0x38(1); fdivs f13,f13,f10; fsub f0,f0,f11; stfs f13,0xc(1); frsp f0,f0; fdivs f0,f0,f10; fdivs f12,f12,f10; stfs f0,0x10(1); stfs f12,0x8(1); lfs f0,0x8(31); lfs f13,0xc(31); stfs f0,0x18(1); stfs f13,0x1c(1); lfs f13,0x14(31); lfs f0,0x10(31); stfs f13,0x24(1); stfs f0,0x20(1); bl _s80008300_22; lis 9,-32707; lis 11,-32707; lfs f0,-11200(9); lis 10,-32698; lfs f31,-11196(11); mr 30,3; stfs f0,0x2c(1); addi 10,10,-21552; stfs f0,0x28(1); li 8,0; lwz 7,0x2c(1); lwz 11,0x28(1); stfs f31,0x28(1); stfs f31,0x2c(1); lwz 0,0x28(1); lwz 9,0x2c(1); stw 10,0x34(30); stw 9,0x30(30); stw 11,0x4(30); stw 0,0x2c(30); stw 8,0x0(30); stw 7,0x8(30); bl _s80008300_23; li 4,16; li 5,16; li 6,0; li 7,0; bl _s80008300_24; stw 3,0xc(30); addi 4,1,24; stfs f31,0x24(30); mr 8,29; addi 5,1,32; addi 6,1,8; lfs f1,0x1c(31); mr 3,30; lwz 7,0x18(31); bl _s80008300_25; stw 30,0x24(31); bl _s80008300_26; mr 4,29; bl _s80008300_27; lwz 30,0x0(30); li 9,0; cmpwi 30,0; beq 16f; 15:; lwz 30,0x0(30); addi 9,9,1; cmpwi 30,0; bne 15b; 16:; stw 9,0x1c(28); lis 11,-32707; lis 9,-32707; lfs f12,-11188(11); lfs f13,-11192(9); lwz 9,0x24(31); lfs f0,0x2c(9); fdivs f0,f0,f13; stfs f0,0x40(28); lwz 9,0x24(31); lfs f0,0x30(9); fdivs f0,f0,f12; stfs f0,0x44(28); 17:; mr 3,31; lwz 0,0x5c(1); mtspr 8,0; lmw 28,0x40(1); lfd f31,0x50(1); addi 1,1,88"
extern "C" void _s80008300_0();
extern "C" void _s80008300_1();
extern "C" void _s80008300_2();
extern "C" void _s80008300_3();
extern "C" void _s80008300_4();
extern "C" void _s80008300_5();
extern "C" void _s80008300_6();
extern "C" void _s80008300_7();
extern "C" void _s80008300_8();
extern "C" void _s80008300_9();
extern "C" void _s80008300_10();
extern "C" void _s80008300_11();
extern "C" void _s80008300_12();
extern "C" void _s80008300_13();
extern "C" void _s80008300_14();
extern "C" void _s80008300_15();
extern "C" void _s80008300_16();
extern "C" void _s80008300_17();
extern "C" void _s80008300_18();
extern "C" void _s80008300_19();
extern "C" void _s80008300_20();
extern "C" void _s80008300_21();
extern "C" void _s80008300_22();
extern "C" void _s80008300_23();
extern "C" void _s80008300_24();
extern "C" void _s80008300_25();
extern "C" void _s80008300_26();
extern "C" void _s80008300_27();
extern "C" void f_80008300() {}
