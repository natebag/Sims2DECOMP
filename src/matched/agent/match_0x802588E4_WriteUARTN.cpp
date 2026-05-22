// 0x802588E4 WriteUARTN (512 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-48(1); stmw 26,0x18(1); addi 30,3,0; addi 31,4,0; lwz 5,-23552(13); addis 0,5,23041; cmplwi 0,90; beq 0f; li 3,2; b 19f; 0:; lwz 3,-23560(13); li 5,0; lwz 4,-23556(13); bl _s802588E4_0; cmpwi 3,0; bne 1f; li 3,0; b 19f; 1:; addi 4,30,0; li 3,13; b 4f; 2:; lbz 0,0x0(4); cmpwi 0,10; bne 3f; stb 3,0x0(4); 3:; addi 4,4,1; 4:; subf 0,30,4; cmplw 0,31; blt 2b; lis 0,-24575; stw 0,0x14(1); li 26,0; lis 29,8193; b 17f; 5:; lwz 3,-23560(13); li 5,3; lwz 4,-23556(13); bl _s802588E4_1; cmpwi 3,0; bne 6f; li 0,-1; b 7f; 6:; stw 29,0x10(1); addi 4,1,16; lwz 3,-23560(13); li 5,4; li 6,1; li 7,0; bl _s802588E4_2; lwz 3,-23560(13); bl _s802588E4_3; lwz 3,-23560(13); addi 4,1,16; li 5,1; li 6,0; li 7,0; bl _s802588E4_4; lwz 3,-23560(13); bl _s802588E4_5; lwz 3,-23560(13); bl _s802588E4_6; lwz 0,0x10(1); rlwinm 0,0,8,24,31; subfic 0,0,16; 7:; cmpwi 0,0; mr 27,0; bge 8f; li 26,3; b 18f; 8:; cmpwi 0,12; bge 9f; cmplw 0,31; blt 17f; 9:; lwz 3,-23560(13); li 5,3; lwz 4,-23556(13); bl _s802588E4_7; cmpwi 3,0; bne 10f; li 26,3; b 18f; 10:; lwz 3,-23560(13); addi 4,1,20; li 5,4; li 6,1; li 7,0; bl _s802588E4_8; lwz 3,-23560(13); bl _s802588E4_9; b 15f; 11:; cmpwi 27,4; bge 12f; cmplw 27,31; blt 16f; 12:; cmplwi 31,4; bge 13f; mr 28,31; b 14f; 13:; li 28,4; 14:; lwz 3,-23560(13); mr 5,28; addi 4,30,0; li 6,1; li 7,0; bl _s802588E4_10; lwz 3,-23560(13); add 30,30,28; subf 31,28,31; subf 27,28,27; bl _s802588E4_11; 15:; cmpwi 27,0; beq 16f; cmplwi 31,0; bne 11b; 16:; lwz 3,-23560(13); bl _s802588E4_12; 17:; cmplwi 31,0; bne 5b; 18:; lwz 3,-23560(13); bl _s802588E4_13; mr 3,26; 19:; lmw 26,0x18(1); lwz 0,0x34(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s802588E4_0();
extern "C" void _s802588E4_1();
extern "C" void _s802588E4_2();
extern "C" void _s802588E4_3();
extern "C" void _s802588E4_4();
extern "C" void _s802588E4_5();
extern "C" void _s802588E4_6();
extern "C" void _s802588E4_7();
extern "C" void _s802588E4_8();
extern "C" void _s802588E4_9();
extern "C" void _s802588E4_10();
extern "C" void _s802588E4_11();
extern "C" void _s802588E4_12();
extern "C" void _s802588E4_13();
extern "C" void f_802588E4() {}
