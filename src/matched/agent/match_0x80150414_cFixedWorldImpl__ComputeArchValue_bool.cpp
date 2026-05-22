// 0x80150414 cFixedWorldImpl::ComputeArchValue(bool (836 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 22,0x48(1); stw 0,0x74(1); mr 25,4; li 0,0; stw 0,0x0(25); mr 28,3; addi 3,1,8; li 4,0; lwz 9,-21432(13); li 5,0; li 6,1; li 27,0; lwz 26,0xd4(9); li 24,0; lwz 23,0xd8(9); li 22,0; bl _s80150414_0; 0:; lwz 9,0x0(28); addi 4,1,8; lwz 0,0xfc(9); lha 3,0xf8(9); mtspr 8,0; add 3,28,3; blrl; andi. 0,3,32; bne 18f; lwz 9,0x0(28); addi 3,1,16; addi 5,1,8; mr 29,3; lwz 0,0xac(9); li 31,0; lha 4,0xa8(9); mtspr 8,0; add 4,28,4; blrl; lwz 0,0x0(25); cmpwi 0,0; bne 1f; mr 3,29; bl _s80150414_1; cmpwi 3,0; beq 2f; 1:; li 31,1; 2:; stw 31,0x0(25); mr 3,29; bl _s80150414_2; mr. 31,3; beq 8f; 3:; mr 4,31; mr 3,29; bl _s80150414_3; mr 30,3; bl _s80150414_4; add 24,24,3; cmpwi 30,1; beq 4f; cmpwi 30,7; beq 4f; cmpwi 30,8; beq 4f; cmpwi 30,9; bne 5f; 4:; li 0,1; b 6f; 5:; li 0,0; 6:; cmpwi 0,0; beq 7f; mr 3,29; mr 4,31; li 5,0; bl _s80150414_5; lwz 11,0x0(23); rlwinm 3,3,2,0,29; lwzx 9,11,3; lwz 0,0x0(9); add 27,27,0; 7:; mr 4,31; mr 3,29; bl _s80150414_6; mr. 31,3; bne 3b; 8:; lwz 9,0x0(28); addi 4,1,8; lha 3,0x88(9); lwz 0,0x8c(9); add 3,28,3; mtspr 8,0; blrl; mr. 30,3; beq 15f; cmpwi 30,255; beq 9f; lwz 10,0x0(26); rlwinm 9,30,2,0,29; lwzx 11,10,9; lwz 0,0x0(11); b 14f; 9:; mr 3,29; li 4,16; bl _s80150414_7; cmpwi 3,0; beq 11f; mr 3,29; li 4,2; bl _s80150414_8; mr. 30,3; beq 10f; lwz 10,0x0(26); rlwinm 9,30,2,0,29; lwzx 11,10,9; lwz 0,0x0(11); rlwinm 0,0,31,1,31; add 27,27,0; 10:; mr 3,29; li 4,4; b 13f; 11:; mr 3,29; li 4,32; bl _s80150414_9; cmpwi 3,0; beq 15f; mr 3,29; li 4,1; bl _s80150414_10; mr. 30,3; beq 12f; lwz 10,0x0(26); rlwinm 9,30,2,0,29; lwzx 11,10,9; lwz 0,0x0(11); rlwinm 0,0,31,1,31; add 27,27,0; 12:; mr 3,29; li 4,3; 13:; bl _s80150414_11; mr. 30,3; beq 15f; lwz 10,0x0(26); rlwinm 9,30,2,0,29; lwzx 11,10,9; lwz 0,0x0(11); rlwinm 0,0,31,1,31; 14:; add 27,27,0; 15:; lwz 0,0x0(25); li 9,0; cmpwi 0,0; bne 16f; cmpwi 30,0; beq 17f; 16:; li 9,1; 17:; stw 9,0x0(25); mr 3,29; li 4,2; bl _s80150414_12; 18:; addi 3,1,8; bl _s80150414_13; addi 4,3,1; addi 3,1,8; bl _s80150414_14; addi 3,1,8; bl _s80150414_15; lwz 0,0x14(28); cmpw 3,0; blt 20f; addi 3,1,8; li 4,0; bl _s80150414_16; addi 3,1,8; bl _s80150414_17; addi 4,3,1; addi 3,1,8; bl _s80150414_18; addi 3,1,8; bl _s80150414_19; lwz 0,0x18(28); cmpw 3,0; blt 20f; li 4,0; addi 3,1,8; bl _s80150414_20; addi 3,1,8; bl _s80150414_21; cmpwi 3,1; bne 19f; li 22,1; b 20f; 19:; addi 3,1,8; bl _s80150414_22; addi 4,3,1; addi 3,1,8; bl _s80150414_23; 20:; cmpwi 22,0; beq 0b; rlwinm 30,24,1,31,31; addi 3,1,8; add 30,24,30; li 4,2; srawi 30,30,1; add 30,27,30; bl _s80150414_24; mr 3,30; lwz 0,0x74(1); mtspr 8,0; lmw 22,0x48(1); addi 1,1,112"
extern "C" void _s80150414_0();
extern "C" void _s80150414_1();
extern "C" void _s80150414_2();
extern "C" void _s80150414_3();
extern "C" void _s80150414_4();
extern "C" void _s80150414_5();
extern "C" void _s80150414_6();
extern "C" void _s80150414_7();
extern "C" void _s80150414_8();
extern "C" void _s80150414_9();
extern "C" void _s80150414_10();
extern "C" void _s80150414_11();
extern "C" void _s80150414_12();
extern "C" void _s80150414_13();
extern "C" void _s80150414_14();
extern "C" void _s80150414_15();
extern "C" void _s80150414_16();
extern "C" void _s80150414_17();
extern "C" void _s80150414_18();
extern "C" void _s80150414_19();
extern "C" void _s80150414_20();
extern "C" void _s80150414_21();
extern "C" void _s80150414_22();
extern "C" void _s80150414_23();
extern "C" void _s80150414_24();
extern "C" void f_80150414() {}
