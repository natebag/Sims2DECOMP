// 0x80265D7C PADRead (768 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-64(1); stmw 22,0x18(1); mr 23,3; bl _s80265D7C_0; li 25,0; mulli 5,25,12; lis 4,-32694; addi 0,4,-16400; add 28,0,5; lis 4,-32730; lis 5,-32730; addi 26,3,0; addi 22,4,21496; addi 31,5,22728; li 24,0; lis 30,-32768; 0:; lwz 0,-23160(13); srw 27,30,25; and. 0,0,27; beq 1f; li 3,0; bl _s80265D7C_1; li 0,-2; stb 0,0xa(23); addi 3,23,0; li 4,0; li 5,10; bl _s80265D7C_2; b 12f; 1:; lwz 0,-23176(13); and. 0,0,27; bne 2f; lwz 0,-27652(13); cmpw 0,25; bne 3f; 2:; li 0,-2; stb 0,0xa(23); addi 3,23,0; li 4,0; li 5,10; bl _s80265D7C_3; b 12f; 3:; lwz 0,-23180(13); and. 0,0,27; bne 4f; li 0,-1; stb 0,0xa(23); addi 3,23,0; li 4,0; li 5,10; bl _s80265D7C_4; b 12f; 4:; mr 3,25; bl _s80265D7C_5; cmpwi 3,0; beq 5f; li 0,-3; stb 0,0xa(23); addi 3,23,0; li 4,0; li 5,10; bl _s80265D7C_6; b 12f; 5:; mr 3,25; bl _s80265D7C_7; rlwinm. 0,3,0,28,28; beq 7f; addi 3,25,0; addi 4,1,16; bl _s80265D7C_8; lwz 0,-23168(13); and. 0,0,27; beq 6f; li 0,0; stb 0,0xa(23); addi 3,23,0; li 4,0; li 5,10; bl _s80265D7C_9; lwz 3,-23164(13); and. 0,3,27; bne 12f; or 0,3,27; stw 0,-23164(13); addi 3,25,0; addi 4,31,0; bl _s80265D7C_10; b 12f; 6:; bl _s80265D7C_11; addi 29,3,0; addi 3,27,0; bl _s80265D7C_12; lwz 0,-23180(13); not 9,27; lwz 6,-23168(13); mr 3,25; lwz 5,-23164(13); lwz 4,-23160(13); and 8,0,9; lwz 0,-23156(13); and 7,6,9; and 6,5,9; and 5,4,9; stw 8,-23180(13); and 0,0,9; stw 7,-23168(13); li 4,0; stw 6,-23164(13); stw 5,-23160(13); stw 0,-23156(13); bl _s80265D7C_13; mr 3,29; bl _s80265D7C_14; li 0,-1; stb 0,0xa(23); addi 3,23,0; li 4,0; li 5,10; bl _s80265D7C_15; b 12f; 7:; mr 3,25; bl _s80265D7C_16; rlwinm. 0,3,0,2,2; bne 8f; or 24,24,27; 8:; addi 3,25,0; addi 4,1,16; bl _s80265D7C_17; cmpwi 3,0; bne 9f; li 0,-3; stb 0,0xa(23); addi 3,23,0; li 4,0; li 5,10; bl _s80265D7C_18; b 12f; 9:; lwz 0,0x10(1); rlwinm. 0,0,0,0,0; beq 10f; li 0,-3; stb 0,0xa(23); addi 3,23,0; li 4,0; li 5,10; bl _s80265D7C_19; b 12f; 10:; lwz 12,-27636(13); addi 3,25,0; addi 4,23,0; mtspr 8,12; addi 5,1,16; blrl; lhz 0,0x0(23); rlwinm. 0,0,0,18,18; beq 11f; li 0,-3; stb 0,0xa(23); addi 3,23,0; li 4,0; li 5,10; bl _s80265D7C_20; addi 3,25,0; addi 6,28,0; addi 8,22,0; addi 4,13,-27632; li 5,1; li 7,10; li 10,0; li 9,0; bl _s80265D7C_21; b 12f; 11:; li 0,0; stb 0,0xa(23); lhz 0,0x0(23); rlwinm 0,0,0,25,23; sth 0,0x0(23); 12:; addi 25,25,1; cmpwi 25,4; addi 28,28,12; addi 23,23,12; blt 0b; mr 3,26; bl _s80265D7C_22; mr 3,24; lmw 22,0x18(1); lwz 0,0x44(1); addi 1,1,64; mtspr 8,0"
extern "C" void _s80265D7C_0();
extern "C" void _s80265D7C_1();
extern "C" void _s80265D7C_2();
extern "C" void _s80265D7C_3();
extern "C" void _s80265D7C_4();
extern "C" void _s80265D7C_5();
extern "C" void _s80265D7C_6();
extern "C" void _s80265D7C_7();
extern "C" void _s80265D7C_8();
extern "C" void _s80265D7C_9();
extern "C" void _s80265D7C_10();
extern "C" void _s80265D7C_11();
extern "C" void _s80265D7C_12();
extern "C" void _s80265D7C_13();
extern "C" void _s80265D7C_14();
extern "C" void _s80265D7C_15();
extern "C" void _s80265D7C_16();
extern "C" void _s80265D7C_17();
extern "C" void _s80265D7C_18();
extern "C" void _s80265D7C_19();
extern "C" void _s80265D7C_20();
extern "C" void _s80265D7C_21();
extern "C" void _s80265D7C_22();
extern "C" void f_80265D7C() {}
