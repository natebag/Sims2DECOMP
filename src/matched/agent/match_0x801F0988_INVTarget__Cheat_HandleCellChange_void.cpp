// 0x801F0988 INVTarget::Cheat_HandleCellChange(void) (888 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lbz 0,0x138(31); cmpwi 0,0; beq 13f; cmpwi 0,1; bne 19f; lbz 0,0x3251(31); mr 9,0; rlwinm 0,0,0,24,31; cmpwi 0,10; beq 7f; bgt 0f; cmpwi 0,0; blt 19f; cmpwi 0,8; ble 1f; b 3f; 0:; cmpwi 0,11; beq 9f; cmpwi 0,13; bgt 19f; 1:; rlwinm 0,9,2,0,29; addi 9,31,320; lwzx 11,9,0; lwz 0,0x4(11); lwz 7,0x0(11); cmpw 7,0; beq 10f; lbz 10,0x189(31); subf 11,7,0; lwz 9,0x84(31); addi 8,13,-28700; mulli 10,10,12; srawi 11,11,2; rlwinm 9,9,2,0,29; lwzx 0,9,8; add 9,10,0; cmplw 9,11; blt 2f; lis 3,-32704; addi 3,3,-26048; bl _s801F0988_0; bl _s801F0988_1; 2:; rlwinm 9,9,2,0,29; mr 3,31; lwzx 4,7,9; bl _s801F0988_2; b 19f; 3:; rlwinm 0,9,2,22,29; addi 9,31,320; lwzx 10,9,0; lwz 11,0x0(10); lwz 0,0x4(10); cmpw 11,0; beq 10f; lwz 0,0x84(31); addi 11,13,-28700; lbz 9,0x189(31); li 6,1; mr 8,0; rlwinm 0,0,2,0,29; mr 7,9; lwzx 0,11,0; cmpwi 9,0; bne 4f; cmpwi 0,0; bne 4f; li 6,0; 4:; cmpwi 6,0; beq 6f; mulli 9,7,12; lwz 0,0x4(10); lwz 7,0x0(10); rlwinm 8,8,2,0,29; addi 11,13,-28700; lwzx 10,8,11; subf 0,7,0; addi 9,9,-1; srawi 0,0,3; add 4,9,10; cmplw 4,0; blt 5f; lis 3,-32704; addi 3,3,-26048; bl _s801F0988_3; bl _s801F0988_4; 5:; rlwinm 4,4,3,0,28; mr 3,31; add 4,7,4; bl _s801F0988_5; b 19f; 6:; mr 3,31; bl _s801F0988_6; b 19f; 7:; lwz 9,0x168(31); lwz 11,0x4(9); lwz 7,0x0(9); cmpw 7,11; beq 10f; lbz 10,0x189(31); addi 8,13,-28700; lwz 9,0x84(31); subf 11,7,11; mulli 10,10,12; srawi 11,11,3; rlwinm 9,9,2,0,29; lwzx 0,9,8; add 4,10,0; cmplw 4,11; blt 8f; lis 3,-32704; addi 3,3,-26048; bl _s801F0988_7; bl _s801F0988_8; 8:; rlwinm 4,4,3,0,28; mr 3,31; add 4,7,4; bl _s801F0988_9; b 19f; 9:; lwz 9,0x16c(31); lwz 11,0x4(9); lwz 7,0x0(9); cmpw 7,11; bne 11f; 10:; lwz 0,0x84(31); addi 11,13,-28700; li 9,0; mr 3,31; rlwinm 0,0,2,0,29; stwx 9,11,0; bl _s801F0988_10; b 19f; 11:; lbz 10,0x189(31); addi 8,13,-28700; lwz 9,0x84(31); subf 11,7,11; mulli 10,10,12; srawi 11,11,3; rlwinm 9,9,2,0,29; lwzx 0,9,8; add 4,10,0; cmplw 4,11; blt 12f; lis 3,-32704; addi 3,3,-26048; bl _s801F0988_11; bl _s801F0988_12; 12:; rlwinm 4,4,3,0,28; mr 3,31; add 4,7,4; bl _s801F0988_13; b 19f; 13:; lbz 0,0x189(31); cmpwi 0,0; bne 16f; lwz 0,0x84(31); addi 9,13,-28700; rlwinm 0,0,2,0,29; lwzx 9,9,0; cmpwi 9,8; bgt 14f; rlwinm 0,9,4,0,27; lis 6,-32704; subf 0,9,0; addi 6,6,-14608; add 6,0,6; mr 3,31; addi 4,31,395; li 5,2048; bl _s801F0988_14; b 15f; 14:; mr 3,31; bl _s801F0988_15; 15:; mr 3,31; addi 4,31,2443; li 5,2048; bl _s801F0988_16; lwz 9,0x84(31); addi 11,13,-28700; rlwinm 9,9,2,0,29; add 9,9,11; lbz 0,0x3(9); stb 0,0x3251(31); b 19f; 16:; lwz 0,0x84(31); addi 9,13,-28700; rlwinm 0,0,2,0,29; lwzx 9,9,0; cmpwi 9,4; bgt 17f; rlwinm 0,9,4,0,27; lis 6,-32704; subf 0,9,0; addi 6,6,-14473; add 6,0,6; mr 3,31; addi 4,31,395; li 5,2048; bl _s801F0988_17; b 18f; 17:; mr 3,31; bl _s801F0988_18; 18:; mr 3,31; addi 4,31,2443; li 5,2048; bl _s801F0988_19; lwz 9,0x84(31); addi 0,13,-28700; rlwinm 9,9,2,0,29; add 9,9,0; lbz 11,0x3(9); addi 11,11,9; stb 11,0x3251(31); 19:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801F0988_0();
extern "C" void _s801F0988_1();
extern "C" void _s801F0988_2();
extern "C" void _s801F0988_3();
extern "C" void _s801F0988_4();
extern "C" void _s801F0988_5();
extern "C" void _s801F0988_6();
extern "C" void _s801F0988_7();
extern "C" void _s801F0988_8();
extern "C" void _s801F0988_9();
extern "C" void _s801F0988_10();
extern "C" void _s801F0988_11();
extern "C" void _s801F0988_12();
extern "C" void _s801F0988_13();
extern "C" void _s801F0988_14();
extern "C" void _s801F0988_15();
extern "C" void _s801F0988_16();
extern "C" void _s801F0988_17();
extern "C" void _s801F0988_18();
extern "C" void _s801F0988_19();
extern "C" void f_801F0988() {}
