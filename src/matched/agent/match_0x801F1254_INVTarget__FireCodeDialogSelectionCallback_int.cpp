// 0x801F1254 INVTarget::FireCodeDialogSelectionCallback(int) (536 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 28,0x20(1); stw 0,0x34(1); mr 28,3; addi 11,13,-28700; lwz 9,0x84(28); addi 10,28,216; rlwinm 9,9,2,0,29; lwzx 0,9,11; rlwinm 0,0,2,0,29; lwzx 31,10,0; cmpwi 31,0; beq 8f; mr 3,31; bl _s801F1254_0; cmpwi 3,2; bne 6f; mr 3,31; bl _s801F1254_1; cmpwi 3,3; beq 4f; bgt 0f; cmpwi 3,1; beq 3f; cmpwi 3,2; beq 1f; b 8f; 0:; cmpwi 3,4; beq 2f; cmpwi 3,5; beq 5f; b 8f; 1:; lis 11,-32697; mr 3,31; lwz 9,0x5ea8(11); lwz 30,0x0(9); bl _s801F1254_2; mr 10,3; addi 11,1,8; rlwinm 9,10,2,0,29; mr 3,28; lwzx 0,30,9; mr 4,11; li 5,0; stw 0,0x8(1); stw 10,0x4(11); bl _s801F1254_3; b 8f; 2:; mr 3,28; li 4,0; li 5,0; bl _s801F1254_4; b 8f; 3:; lwz 29,-21508(13); mr 3,31; lwz 30,0x0(29); lha 0,0x78(30); addi 30,30,120; add 29,29,0; bl _s801F1254_5; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; mr 30,3; mr 3,31; bl _s801F1254_6; mr 5,3; mr 4,30; mr 3,28; bl _s801F1254_7; b 8f; 4:; lis 11,-32697; mr 3,31; lwz 9,0x5ea0(11); lwz 30,0x0(9); bl _s801F1254_8; mr 10,3; addi 11,1,16; rlwinm 9,10,2,0,29; mr 3,28; lwzx 0,30,9; mr 4,11; li 5,0; stw 0,0x10(1); stw 10,0x4(11); bl _s801F1254_9; b 8f; 5:; lis 11,-32697; mr 3,31; lwz 9,0x5ea4(11); lwz 30,0x0(9); bl _s801F1254_10; mr 10,3; addi 11,1,24; rlwinm 9,10,2,0,29; mr 3,28; lwzx 0,30,9; mr 4,11; li 5,0; stw 0,0x18(1); stw 10,0x4(11); bl _s801F1254_11; b 8f; 6:; cmpwi 3,1; beq 7f; cmpwi 3,3; bne 8f; 7:; lwz 29,-21508(13); mr 3,31; lwz 30,0x0(29); lha 0,0x78(30); addi 30,30,120; add 29,29,0; bl _s801F1254_12; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; mr 30,3; mr 3,31; bl _s801F1254_13; mr 5,3; mr 4,30; mr 3,28; bl _s801F1254_14; 8:; lwz 0,0x34(1); mtspr 8,0; lmw 28,0x20(1); addi 1,1,48"
extern "C" void _s801F1254_0();
extern "C" void _s801F1254_1();
extern "C" void _s801F1254_2();
extern "C" void _s801F1254_3();
extern "C" void _s801F1254_4();
extern "C" void _s801F1254_5();
extern "C" void _s801F1254_6();
extern "C" void _s801F1254_7();
extern "C" void _s801F1254_8();
extern "C" void _s801F1254_9();
extern "C" void _s801F1254_10();
extern "C" void _s801F1254_11();
extern "C" void _s801F1254_12();
extern "C" void _s801F1254_13();
extern "C" void _s801F1254_14();
extern "C" void f_801F1254() {}
