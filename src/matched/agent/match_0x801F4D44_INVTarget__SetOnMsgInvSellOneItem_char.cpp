// 0x801F4D44 INVTarget::SetOnMsgInvSellOneItem(char (648 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 31,3; mr 3,4; bl _s801F4D44_0; rlwinm 3,3,2,0,29; addi 9,31,216; lwzx 30,9,3; cmpwi 30,0; beq 9f; mr 3,30; li 25,1; bl _s801F4D44_1; mr 28,3; mr 3,30; bl _s801F4D44_2; lwz 9,0x84(31); li 0,1; mr 26,3; stb 0,0x3253(31); cmpwi 9,0; bne 0f; li 25,0; 0:; mr 3,30; li 27,0; bl _s801F4D44_3; cmpwi 3,2; bne 7f; mr 3,30; bl _s801F4D44_4; cmpwi 3,3; beq 4f; bgt 1f; cmpwi 3,1; beq 6f; cmpwi 3,2; beq 3f; b 8f; 1:; cmpwi 3,4; beq 2f; cmpwi 3,5; beq 5f; b 8f; 2:; lbz 5,0x3253(31); li 4,20; li 3,20; bl _s801F4D44_5; mr 27,3; lbz 6,0x3253(31); lwz 3,0x90(31); mr 5,28; li 4,4; bl _s801F4D44_6; b 8f; 3:; lis 9,-32697; rlwinm 8,28,2,0,29; lwz 10,0x5ea8(9); li 4,20; lbz 5,0x3253(31); lwz 9,0x0(10); lwzx 11,9,8; lwz 3,0x4(11); bl _s801F4D44_7; mr 27,3; lbz 6,0x3253(31); lwz 3,0x90(31); mr 5,28; li 4,2; bl _s801F4D44_8; b 8f; 4:; lis 9,-32697; rlwinm 8,28,2,0,29; lwz 10,0x5ea0(9); li 4,20; lbz 5,0x3253(31); lwz 9,0x0(10); lwzx 11,9,8; lwz 3,0x0(11); bl _s801F4D44_9; mr 27,3; lbz 6,0x3253(31); lwz 3,0x90(31); mr 5,28; li 4,3; bl _s801F4D44_10; b 8f; 5:; lis 9,-32697; rlwinm 8,28,2,0,29; lwz 10,0x5ea4(9); li 4,20; lbz 5,0x3253(31); lwz 9,0x0(10); lwzx 11,9,8; lwz 3,0x0(11); bl _s801F4D44_11; mr 27,3; lbz 6,0x3253(31); lwz 3,0x90(31); mr 5,28; li 4,5; bl _s801F4D44_12; b 8f; 6:; lwz 3,-21508(13); mr 4,28; lwz 9,0x0(3); lha 0,0x78(9); lwz 9,0x7c(9); add 3,3,0; mtspr 8,9; blrl; bl _s801F4D44_13; lbz 4,0x3253(31); bl _s801F4D44_14; mr 27,3; lbz 6,0x3253(31); lwz 3,0x90(31); mr 5,28; li 4,1; bl _s801F4D44_15; b 8f; 7:; lwz 11,-21508(13); mr 4,28; lwz 9,0x0(11); lha 3,0x78(9); lwz 0,0x7c(9); add 3,11,3; mtspr 8,0; blrl; bl _s801F4D44_16; lbz 4,0x3253(31); bl _s801F4D44_17; mr 27,3; lwz 29,0x90(31); mr 3,30; lbz 30,0x3253(31); bl _s801F4D44_18; mr 6,3; mr 4,28; mr 3,29; mr 5,30; bl _s801F4D44_19; 8:; lwz 4,0x318c(31); mr 5,25; lwz 11,-21496(13); add 4,4,27; stw 4,0x318c(31); lwz 9,0x0(11); lha 3,0xd0(9); lwz 0,0xd4(9); add 3,11,3; mtspr 8,0; blrl; mr 3,31; mr 4,26; bl _s801F4D44_20; 9:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s801F4D44_0();
extern "C" void _s801F4D44_1();
extern "C" void _s801F4D44_2();
extern "C" void _s801F4D44_3();
extern "C" void _s801F4D44_4();
extern "C" void _s801F4D44_5();
extern "C" void _s801F4D44_6();
extern "C" void _s801F4D44_7();
extern "C" void _s801F4D44_8();
extern "C" void _s801F4D44_9();
extern "C" void _s801F4D44_10();
extern "C" void _s801F4D44_11();
extern "C" void _s801F4D44_12();
extern "C" void _s801F4D44_13();
extern "C" void _s801F4D44_14();
extern "C" void _s801F4D44_15();
extern "C" void _s801F4D44_16();
extern "C" void _s801F4D44_17();
extern "C" void _s801F4D44_18();
extern "C" void _s801F4D44_19();
extern "C" void _s801F4D44_20();
extern "C" void f_801F4D44() {}
