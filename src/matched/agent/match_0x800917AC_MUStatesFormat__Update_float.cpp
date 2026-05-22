// 0x800917AC MUStatesFormat::Update(float) (720 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; lwz 3,0x8(31); lwz 30,0x90(3); cmpwi 30,0; bne 1f; lis 9,-32696; stw 30,0x8(1); lwz 3,0x58d8(9); addi 4,1,8; bl _s800917AC_0; lwz 0,0x8(1); cmpwi 0,0; bne 0f; lwz 3,0x8(31); b 9f; 0:; lwz 0,0x1c(31); cmpwi 0,1; beq 14f; lwz 11,0x8(31); li 0,4; li 4,10; lwz 9,0x98(11); stw 0,0xac(9); lwz 11,0x8(31); lwz 3,0x98(11); bl _s800917AC_1; mr 3,31; li 4,14; bl _s800917AC_2; li 0,2; stw 30,0x20(31); stw 0,0x1c(31); b 14f; 1:; cmpwi 30,1; bne 3f; lwz 9,0x1c(31); addi 0,9,-1; cmplwi 0,1; bgt 2f; lwz 9,0x98(3); li 30,3; li 4,6; stw 30,0xac(9); lwz 11,0x8(31); lwz 3,0x98(11); bl _s800917AC_3; mr 3,31; li 4,14; bl _s800917AC_4; stw 30,0x1c(31); b 14f; 2:; cmpwi 9,3; bne 14f; li 0,0; b 13f; 3:; cmpwi 30,2; bne 12f; lwz 0,0x1c(31); cmpwi 0,1; bne 4f; lwz 11,0x98(3); li 0,4; li 4,10; stw 0,0xac(11); lwz 9,0x8(31); lwz 3,0x98(9); bl _s800917AC_5; mr 3,31; li 4,14; bl _s800917AC_6; li 0,0; stw 30,0x1c(31); stw 0,0x20(31); b 14f; 4:; cmpwi 0,2; bne 5f; lwz 11,0x98(3); li 0,8; li 4,4; stw 0,0xac(11); lwz 9,0x8(31); lwz 3,0x98(9); bl _s800917AC_7; lwz 9,0x8(31); lwz 3,0x98(9); bl _s800917AC_8; li 9,1; li 0,6; stw 0,0x1c(31); stw 9,0x20(31); b 14f; 5:; cmpwi 0,6; bne 8f; bl _s800917AC_9; lis 9,-32706; lfs f0,-32064(9); fcmpu 0,f1,f0; blt 14f; lis 29,-32696; li 30,0; lwz 3,0x58d8(29); bl _s800917AC_10; cmpwi 3,1; bne 6f; li 0,0; lwz 3,0x58d8(29); stw 0,0xc(1); addi 4,1,12; bl _s800917AC_11; li 30,1; lwz 0,0xc(1); cmpwi 0,0; bne 6f; li 30,0; 6:; li 0,0; cmpwi 30,0; stw 0,0x20(31); beq 7f; lwz 11,0x8(31); li 0,6; li 4,4; lwz 9,0x98(11); stw 0,0xac(9); lwz 11,0x8(31); lwz 3,0x98(11); bl _s800917AC_12; mr 3,31; li 4,14; bl _s800917AC_13; li 0,5; stw 0,0x1c(31); b 14f; 7:; lwz 11,0x8(31); li 0,6; li 4,3; lwz 9,0x98(11); stw 0,0xac(9); lwz 11,0x8(31); lwz 3,0x98(11); bl _s800917AC_14; mr 3,31; li 4,14; bl _s800917AC_15; li 0,4; stw 0,0x1c(31); b 14f; 8:; cmpwi 0,3; beq 9f; cmpwi 0,7; bne 10f; 9:; li 4,1; bl _s800917AC_16; b 14f; 10:; cmpwi 0,5; bne 11f; li 4,2; bl _s800917AC_17; b 14f; 11:; cmpwi 0,4; bne 14f; li 4,1; bl _s800917AC_18; lwz 9,0x8(31); li 0,0; stw 0,0x90(9); b 14f; 12:; cmpwi 30,3; bne 14f; li 0,0; stw 0,0x1c(31); 13:; stw 0,0x90(3); 14:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s800917AC_0();
extern "C" void _s800917AC_1();
extern "C" void _s800917AC_2();
extern "C" void _s800917AC_3();
extern "C" void _s800917AC_4();
extern "C" void _s800917AC_5();
extern "C" void _s800917AC_6();
extern "C" void _s800917AC_7();
extern "C" void _s800917AC_8();
extern "C" void _s800917AC_9();
extern "C" void _s800917AC_10();
extern "C" void _s800917AC_11();
extern "C" void _s800917AC_12();
extern "C" void _s800917AC_13();
extern "C" void _s800917AC_14();
extern "C" void _s800917AC_15();
extern "C" void _s800917AC_16();
extern "C" void _s800917AC_17();
extern "C" void _s800917AC_18();
extern "C" void f_800917AC() {}
