// 0x80293128 AptCIH::tick(void) (544 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; li 29,0; li 31,0; bl _s80293128_0; cmpwi 3,13; bne 0f; mr 3,30; bl _s80293128_1; subfic 0,3,0; adde 31,0,3; 0:; cmpwi 31,0; bne 2f; mr 3,30; li 31,0; bl _s80293128_2; cmpwi 3,18; bne 1f; mr 3,30; bl _s80293128_3; subfic 0,3,0; adde 31,0,3; 1:; cmpwi 31,0; beq 3f; 2:; li 29,1; 3:; cmpwi 29,0; beq 12f; lwz 31,0x4c(30); li 9,0; lwz 0,0x1c(31); stw 9,0x28(31); andi. 11,0,64; beq 7f; lwz 0,0x2c(31); cmpwi 0,1; beq 4f; lwz 9,0x18(31); addi 9,9,1; 4:; stw 9,0x18(31); lwz 0,0x18(31); lwz 3,0x8(31); mr 6,0; cmpwi 0,1; bne 5f; lwz 0,0x8(3); cmpwi 0,1; bne 5f; li 0,0; stw 0,0x18(31); b 7f; 5:; lwz 0,0x8(3); cmpw 6,0; bne 6f; mr 3,30; li 4,0; bl _s80293128_4; b 7f; 6:; lwz 0,0x1c(31); andi. 9,0,64; beq 7f; addi 3,3,8; addi 4,31,36; mr 5,30; bl _s80293128_5; lwz 0,0x1c(31); andi. 9,0,64; beq 7f; lwz 5,0x18(31); mr 4,30; lwz 3,0x8(31); neg 0,5; stw 0,0x28(31); addi 3,3,8; bl _s80293128_6; lwz 0,0x18(31); stw 0,0x28(31); 7:; lwz 0,0x1c(31); andi. 9,0,128; beq 9f; mr 3,30; li 29,0; bl _s80293128_7; cmpwi 3,18; bne 8f; mr 3,30; bl _s80293128_8; subfic 0,3,0; adde 29,0,3; 8:; cmpwi 29,0; beq 10f; 9:; mr 3,30; li 4,2; bl _s80293128_9; cmpwi 3,0; beq 10f; lwz 5,-27612(13); mr 3,30; li 4,2; li 6,1; bl _s80293128_10; 10:; lwz 0,0x1c(31); andi. 9,0,128; beq 11f; lwz 5,-27612(13); mr 3,30; li 4,1; li 6,1; bl _s80293128_11; lwz 0,0x1c(31); rlwinm 0,0,0,25,23; stw 0,0x1c(31); 11:; addi 3,31,36; bl _s80293128_12; b 14f; 12:; mr 3,30; li 31,0; bl _s80293128_13; cmpwi 3,14; bne 13f; mr 3,30; bl _s80293128_14; subfic 0,3,0; adde 31,0,3; 13:; cmpwi 31,0; beq 14f; lwz 3,0x4c(30); addi 3,3,28; bl _s80293128_15; 14:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80293128_0();
extern "C" void _s80293128_1();
extern "C" void _s80293128_2();
extern "C" void _s80293128_3();
extern "C" void _s80293128_4();
extern "C" void _s80293128_5();
extern "C" void _s80293128_6();
extern "C" void _s80293128_7();
extern "C" void _s80293128_8();
extern "C" void _s80293128_9();
extern "C" void _s80293128_10();
extern "C" void _s80293128_11();
extern "C" void _s80293128_12();
extern "C" void _s80293128_13();
extern "C" void _s80293128_14();
extern "C" void _s80293128_15();
extern "C" void f_80293128() {}
