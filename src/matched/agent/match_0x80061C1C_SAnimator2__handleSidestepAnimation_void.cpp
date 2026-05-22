// 0x80061C1C SAnimator2::handleSidestepAnimation(void) (1168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-288(1); mfspr 0,8; stfd f29,0x108(1); stfd f30,0x110(1); stfd f31,0x118(1); stmw 27,0xf4(1); stw 0,0x124(1); mr 31,3; lwz 0,0x18(31); cmpwi 0,2; bne 21f; lwz 0,0x61c(31); andi. 9,0,2; bne 21f; lwz 4,0x668(31); li 29,0; cmpwi 4,0; beq 0f; lwz 3,0x8(31); lis 11,-32707; lis 9,-32707; lfs f3,0x4934(11); lfs f1,0x4930(9); addi 3,3,820; lfs f2,-32292(13); bl _s80061C1C_0; stw 29,0x668(31); 0:; lis 9,-32707; lfs f13,0x110(31); lfs f0,0x4938(9); addi 30,1,216; addi 5,1,220; li 29,1; fcmpu 0,f13,f0; li 0,1; blt 1f; lis 9,-32707; lfs f0,0x493c(9); fcmpu 0,f13,f0; ble 2f; 1:; li 29,0; 2:; lis 9,-32707; lfs f0,0x4930(9); fcmpu 0,f13,f0; ble 3f; li 0,0; 3:; cmpwi 0,1; bne 5f; lwz 3,0x4(31); li 4,40; bl _s80061C1C_1; cmpwi 29,1; bne 4f; lwz 3,0x4(31); mr 5,30; li 4,42; bl _s80061C1C_2; b 7f; 4:; lwz 3,0x4(31); mr 5,30; li 4,44; bl _s80061C1C_3; b 7f; 5:; lwz 3,0x4(31); li 4,39; bl _s80061C1C_4; cmpwi 29,1; bne 6f; lwz 3,0x4(31); mr 5,30; li 4,41; bl _s80061C1C_5; b 7f; 6:; lwz 3,0x4(31); mr 5,30; li 4,43; bl _s80061C1C_6; 7:; lwz 30,0xd8(1); addi 3,1,24; bl _s80061C1C_7; lwz 0,0x3c(31); andi. 29,0,16; bne 15f; lis 9,-32693; lwz 4,0x0(30); addi 28,9,11064; li 5,0; mr 3,28; li 6,0; bl _s80061C1C_8; mr. 30,3; beq 15f; lwz 11,0x18(30); lis 27,17200; lis 9,-32707; addi 11,11,-1; lfd f30,0x4940(9); xoris 11,11,32768; lfs f11,0x64(30); stw 11,0xec(1); lis 9,-32707; lfs f12,0x4948(9); lis 11,-32707; stw 27,0xe8(1); lis 9,-32707; lfs f29,0x494c(11); lfd f0,0xe8(1); lfs f13,0x4930(9); fsub f0,f0,f30; frsp f0,f0; fdivs f0,f0,f11; fmuls f31,f0,f12; fmuls f31,f31,f29; fcmpu 0,f31,f13; beq 13f; lwz 3,0x94(1); cmpwi 3,0; beq 8f; bl _s80061C1C_9; stw 29,0x94(1); 8:; lwz 3,0x8(31); addi 4,1,24; stw 30,0x94(1); addi 3,3,820; bl _s80061C1C_10; lwz 9,0x34(30); lwz 10,0xb0(1); lwz 9,0x30(9); addi 10,10,32; cmpwi 9,0; beq 11f; ble 9f; lwz 11,0x44(30); rlwinm 9,9,2,0,29; add 10,11,9; lwzx 8,11,9; lwz 7,0x8(10); lwz 0,0x4(10); stw 8,0x8(1); stw 0,0xc(1); stw 7,0x10(1); b 10f; 9:; lwz 9,0x18(30); lwz 4,0x4(10); addi 3,1,200; addi 9,9,-1; xoris 9,9,32768; stw 9,0xec(1); stw 27,0xe8(1); lfd f1,0xe8(1); fsub f1,f1,f30; frsp f1,f1; fmuls f1,f1,f29; bl _s80061C1C_11; lwz 0,0xc8(1); lwz 9,0xcc(1); lwz 11,0xd0(1); stw 0,0x8(1); stw 9,0xc(1); stw 11,0x10(1); 10:; lfs f0,0xc(1); lis 9,-32707; lfs f13,0x4950(9); fabs f12,f0; fcmpu 0,f12,f13; ble 11f; lis 9,-32707; lfs f0,0x4954(9); fmuls f12,f12,f0; fdivs f13,f12,f31; stfs f13,0xa4(31); 11:; lwz 3,0x8(31); addi 4,1,24; li 30,0; addi 3,3,820; bl _s80061C1C_12; lwz 3,0x94(1); cmpwi 3,0; beq 12f; bl _s80061C1C_13; stw 30,0x94(1); 12:; stw 30,0x94(1); b 14f; 13:; mr 3,28; mr 4,30; li 5,1; bl _s80061C1C_14; 14:; lwz 0,0x3c(31); ori 0,0,16; stw 0,0x3c(31); 15:; addi 3,1,164; bl _s80061C1C_15; lwz 3,0x94(1); cmpwi 3,0; beq 16f; bl _s80061C1C_16; li 0,0; stw 0,0x94(1); 16:; lfs f1,0x110(31); bl _s80061C1C_17; lis 9,-32707; fmuls f31,f1,f1; lfs f0,0x4958(9); fcmpu 0,f31,f0; bge 17f; lis 9,-32707; lfs f31,0x4930(9); b 18f; 17:; lis 9,-32707; lfs f0,0x495c(9); fcmpu 0,f31,f0; ble 18f; lis 9,-32707; lfs f31,0x4960(9); 18:; lis 9,-32707; lfs f0,0x4960(9); fcmpu 0,f31,f0; bne 19f; lwz 9,0xdc(1); li 4,64; lwz 3,0x8(31); li 6,2; lwz 5,0x0(9); li 7,0; lfs f1,-32304(13); addi 3,3,820; bl _s80061C1C_18; li 0,0; stb 0,0xd(3); b 20f; 19:; lwz 9,0xdc(1); li 4,64; lwz 3,0x8(31); li 6,2; lwz 5,0x0(9); li 7,0; lfs f1,-32304(13); addi 3,3,820; li 30,0; bl _s80061C1C_19; stw 3,0x668(31); lis 10,-32707; li 4,2; li 6,5; lwz 0,0x30(3); li 7,0; rlwinm 0,0,0,15,13; stw 0,0x30(3); lwz 9,0x668(31); stb 30,0xd(9); lwz 11,0xd8(1); lwz 3,0x8(31); lwz 5,0x0(11); lfs f1,0x4964(10); addi 3,3,820; bl _s80061C1C_20; mr 29,3; lis 9,-32707; stb 30,0xd(29); mr 5,29; lwz 3,0x8(31); lfs f1,0x4930(9); lwz 4,0x668(31); addi 3,3,820; bl _s80061C1C_21; lwz 3,0x8(31); fmr f1,f31; lwz 4,0x668(31); li 5,0; addi 3,3,820; bl _s80061C1C_22; 20:; lis 9,-32707; lfs f1,0xfc(31); lfs f0,0x4968(9); lis 4,1; lfs f13,0xa4(31); fmuls f1,f1,f0; lwz 3,0x8(31); fdivs f1,f1,f13; addi 3,3,820; bl _s80061C1C_23; lwz 0,0x61c(31); ori 0,0,2; stw 0,0x61c(31); 21:; lwz 0,0x124(1); mtspr 8,0; lmw 27,0xf4(1); lfd f29,0x108(1); lfd f30,0x110(1); lfd f31,0x118(1); addi 1,1,288"
extern "C" void _s80061C1C_0();
extern "C" void _s80061C1C_1();
extern "C" void _s80061C1C_2();
extern "C" void _s80061C1C_3();
extern "C" void _s80061C1C_4();
extern "C" void _s80061C1C_5();
extern "C" void _s80061C1C_6();
extern "C" void _s80061C1C_7();
extern "C" void _s80061C1C_8();
extern "C" void _s80061C1C_9();
extern "C" void _s80061C1C_10();
extern "C" void _s80061C1C_11();
extern "C" void _s80061C1C_12();
extern "C" void _s80061C1C_13();
extern "C" void _s80061C1C_14();
extern "C" void _s80061C1C_15();
extern "C" void _s80061C1C_16();
extern "C" void _s80061C1C_17();
extern "C" void _s80061C1C_18();
extern "C" void _s80061C1C_19();
extern "C" void _s80061C1C_20();
extern "C" void _s80061C1C_21();
extern "C" void _s80061C1C_22();
extern "C" void _s80061C1C_23();
extern "C" void f_80061C1C() {}
