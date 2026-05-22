// 0x8024E304 __OSUnhandledException (744 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 8,-32694; stw 0,0x4(1); lis 7,-32700; stwu 1,-64(1); stmw 22,0x18(1); addi 24,3,0; addi 25,4,0; addi 26,5,0; addi 27,6,0; addi 30,8,-24784; addi 31,7,-19512; bl _s8024E304_0; lwz 5,0x19c(25); addi 28,4,0; addi 29,3,0; rlwinm. 0,5,0,30,30; bne 0f; addi 3,31,92; crxor 6,6,6; rlwinm 4,24,0,24,31; bl _s8024E304_1; b 7f; 0:; rlwinm 0,24,0,24,31; cmplwi 0,6; bne 4f; rlwinm. 0,5,0,11,11; beq 4f; lwz 0,0x40(30); cmplwi 0,0; beq 4f; li 24,16; bl _s8024E304_2; addi 23,3,0; ori 3,23,8192; bl _s8024E304_3; lis 3,-32768; lwz 3,0xd8(3); cmplwi 3,0; beq 1f; bl _s8024E304_4; 1:; bl _s8024E304_5; lis 4,24582; addi 22,4,-1793; and 3,3,22; bl _s8024E304_6; mr 3,23; bl _s8024E304_7; lis 23,-32768; lwz 0,0xd8(23); cmplw 0,25; bne 2f; bl _s8024E304_8; lwz 12,0x40(30); addi 4,25,0; addi 5,26,0; crxor 6,6,6; mtspr 8,12; addi 6,27,0; li 3,16; blrl; lwz 3,0x19c(25); li 0,0; rlwinm 3,3,0,19,17; stw 3,0x19c(25); stw 0,0xd8(23); lwz 0,0x194(25); and 0,0,22; stw 0,0x194(25); bl _s8024E304_9; bl _s8024E304_10; b 3f; 2:; lwz 3,0x19c(25); li 0,0; rlwinm 3,3,0,19,17; stw 3,0x19c(25); stw 0,0xd8(23); 3:; mr 3,25; bl _s8024E304_11; 4:; rlwinm 23,24,0,24,31; rlwinm 0,24,2,22,29; add 22,30,0; lwz 0,0x0(22); cmplwi 0,0; beq 5f; bl _s8024E304_12; lwz 12,0x0(22); addi 3,23,0; addi 4,25,0; crxor 6,6,6; mtspr 8,12; addi 5,26,0; addi 6,27,0; blrl; bl _s8024E304_13; bl _s8024E304_14; mr 3,25; bl _s8024E304_15; 5:; rlwinm 0,24,0,24,31; cmplwi 0,8; bne 6f; mr 3,25; bl _s8024E304_16; 6:; addi 3,31,124; crxor 6,6,6; rlwinm 4,24,0,24,31; bl _s8024E304_17; 7:; addi 3,13,-27908; crxor 6,6,6; bl _s8024E304_18; mr 3,25; bl _s8024E304_19; addi 4,26,0; crxor 6,6,6; addi 5,27,0; addi 3,31,148; bl _s8024E304_20; addi 6,28,0; crxor 6,6,6; addi 5,29,0; addi 3,31,200; bl _s8024E304_21; rlwinm 0,24,0,24,31; cmplwi 0,15; bgt 8f; lis 3,-32700; addi 3,3,-18780; rlwinm 0,0,2,0,29; lwzx 0,3,0; mtspr 9,0; bctr; lwz 4,0x198(25); addi 5,27,0; addi 3,31,216; crxor 6,6,6; bl _s8024E304_22; b 8f; lwz 4,0x198(25); addi 3,31,312; crxor 6,6,6; bl _s8024E304_23; b 8f; lwz 4,0x198(25); addi 5,27,0; addi 3,31,388; crxor 6,6,6; bl _s8024E304_24; b 8f; lwz 4,0x198(25); addi 5,27,0; addi 3,31,488; crxor 6,6,6; bl _s8024E304_25; b 8f; addi 3,13,-27908; crxor 6,6,6; bl _s8024E304_26; lis 25,-13312; crxor 6,6,6; addi 24,25,20480; lhz 4,0x5030(25); addi 3,31,584; lhz 5,0x5032(25); bl _s8024E304_27; lhz 4,0x20(24); addi 3,31,616; lhz 5,0x22(24); crxor 6,6,6; bl _s8024E304_28; lwz 4,0x6014(25); crxor 6,6,6; addi 3,31,648; bl _s8024E304_29; 8:; lha 4,-23656(13); addi 3,31,676; crxor 6,6,6; lwz 5,-23660(13); lwz 7,-23648(13); lwz 8,-23644(13); bl _s8024E304_30; bl _s8024E304_31; lmw 22,0x18(1); lwz 0,0x44(1); addi 1,1,64; mtspr 8,0"
extern "C" void _s8024E304_0();
extern "C" void _s8024E304_1();
extern "C" void _s8024E304_2();
extern "C" void _s8024E304_3();
extern "C" void _s8024E304_4();
extern "C" void _s8024E304_5();
extern "C" void _s8024E304_6();
extern "C" void _s8024E304_7();
extern "C" void _s8024E304_8();
extern "C" void _s8024E304_9();
extern "C" void _s8024E304_10();
extern "C" void _s8024E304_11();
extern "C" void _s8024E304_12();
extern "C" void _s8024E304_13();
extern "C" void _s8024E304_14();
extern "C" void _s8024E304_15();
extern "C" void _s8024E304_16();
extern "C" void _s8024E304_17();
extern "C" void _s8024E304_18();
extern "C" void _s8024E304_19();
extern "C" void _s8024E304_20();
extern "C" void _s8024E304_21();
extern "C" void _s8024E304_22();
extern "C" void _s8024E304_23();
extern "C" void _s8024E304_24();
extern "C" void _s8024E304_25();
extern "C" void _s8024E304_26();
extern "C" void _s8024E304_27();
extern "C" void _s8024E304_28();
extern "C" void _s8024E304_29();
extern "C" void _s8024E304_30();
extern "C" void _s8024E304_31();
extern "C" void f_8024E304() {}
