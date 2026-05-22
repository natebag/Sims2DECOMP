// 0x80080F80 MUWrapper::Update(void) (840 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,3; bl _s80080F80_0; lwz 3,-21500(13); lis 4,19797; ori 4,4,21332; bl _s80080F80_1; lis 9,-32696; mr 29,3; lwz 5,0x58dc(9); mr 3,30; li 4,0; bl _s80080F80_2; lwz 0,0xac(30); mr 31,3; cmpwi 0,7; beq 0f; cmpwi 0,14; bne 1f; 0:; mr 3,30; li 4,0; bl _s80080F80_3; 1:; lwz 9,0xb0(30); addi 9,9,-3; cmplwi 9,1; bgt 3f; lis 9,-32696; li 0,0; lwz 3,0x58d8(9); addi 4,1,8; stw 0,0x8(1); bl _s80080F80_4; lwz 0,0x8(1); cmpwi 0,0; bne 3f; lwz 0,-31536(13); cmpwi 0,0; bne 2f; li 3,120; bl _s80080F80_5; bl _s80080F80_6; stw 3,-31536(13); 2:; lwz 3,-31536(13); lis 4,-12391; ori 4,4,56094; bl _s80080F80_7; mr 3,30; bl _s80080F80_8; mr 3,30; bl _s80080F80_9; mr 3,29; li 4,3; bl _s80080F80_10; 3:; cmpwi 31,0; bge 23f; rlwinm 31,31,0,1,31; cmpwi 31,7; beq 7f; cmplwi 31,7; bgt 4f; cmplwi 31,3; blt 23f; cmplwi 31,4; ble 5f; cmpwi 31,6; beq 15f; b 23f; 4:; cmpwi 31,9; beq 10f; cmplwi 31,9; blt 17f; cmpwi 31,10; beq 15f; cmpwi 31,14; beq 11f; b 23f; 5:; lwz 0,-31536(13); cmpwi 0,0; bne 6f; li 3,120; bl _s80080F80_11; bl _s80080F80_12; stw 3,-31536(13); 6:; lis 4,-31110; lwz 3,-31536(13); ori 4,4,7936; bl _s80080F80_13; b 23f; 7:; lwz 0,0xac(30); cmpwi 0,6; beq 18f; cmpwi 0,9; beq 18f; cmpwi 0,1; beq 18f; cmpwi 0,11; beq 18f; cmpwi 0,10; beq 12f; cmpwi 0,7; beq 8f; cmpwi 0,14; bne 15f; 8:; lwz 3,0xa8(30); bl _s80080F80_14; mr 31,3; lwz 3,0xa8(30); bl _s80080F80_15; cmpwi 3,7; beq 15f; lwz 0,-31536(13); lis 9,-32696; stw 31,0x58d8(9); cmpwi 0,0; bne 9f; li 3,120; bl _s80080F80_16; bl _s80080F80_17; stw 3,-31536(13); 9:; lwz 3,-31536(13); lis 4,-12391; ori 4,4,56094; bl _s80080F80_18; mr 3,30; bl _s80080F80_19; mr 3,30; bl _s80080F80_20; b 20f; 10:; lwz 9,0xac(30); addi 0,9,-1; cmplwi 0,1; ble 12f; cmpwi 9,7; beq 12f; cmpwi 9,14; beq 12f; b 15f; 11:; lwz 0,0xac(30); cmpwi 0,11; bne 14f; 12:; lwz 0,-31536(13); cmpwi 0,0; bne 13f; li 3,120; bl _s80080F80_21; bl _s80080F80_22; stw 3,-31536(13); 13:; lwz 3,-31536(13); lis 4,1162; ori 4,4,59727; bl _s80080F80_23; mr 3,30; bl _s80080F80_24; mr 3,29; li 4,1; bl _s80080F80_25; b 23f; 14:; cmpwi 0,10; beq 18f; 15:; lwz 0,-31536(13); cmpwi 0,0; bne 16f; li 3,120; bl _s80080F80_26; bl _s80080F80_27; stw 3,-31536(13); 16:; lis 4,14340; lwz 3,-31536(13); ori 4,4,8607; bl _s80080F80_28; b 23f; 17:; lwz 0,0xac(30); cmpwi 0,2; bne 21f; 18:; lwz 0,-31536(13); cmpwi 0,0; bne 19f; li 3,120; bl _s80080F80_29; bl _s80080F80_30; stw 3,-31536(13); 19:; lwz 3,-31536(13); lis 4,-12391; ori 4,4,56094; bl _s80080F80_31; mr 3,30; bl _s80080F80_32; 20:; mr 3,29; li 4,2; bl _s80080F80_33; b 23f; 21:; lwz 0,-31536(13); cmpwi 0,0; bne 22f; li 3,120; bl _s80080F80_34; bl _s80080F80_35; stw 3,-31536(13); 22:; lis 4,14340; lwz 3,-31536(13); ori 4,4,8607; bl _s80080F80_36; 23:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s80080F80_0();
extern "C" void _s80080F80_1();
extern "C" void _s80080F80_2();
extern "C" void _s80080F80_3();
extern "C" void _s80080F80_4();
extern "C" void _s80080F80_5();
extern "C" void _s80080F80_6();
extern "C" void _s80080F80_7();
extern "C" void _s80080F80_8();
extern "C" void _s80080F80_9();
extern "C" void _s80080F80_10();
extern "C" void _s80080F80_11();
extern "C" void _s80080F80_12();
extern "C" void _s80080F80_13();
extern "C" void _s80080F80_14();
extern "C" void _s80080F80_15();
extern "C" void _s80080F80_16();
extern "C" void _s80080F80_17();
extern "C" void _s80080F80_18();
extern "C" void _s80080F80_19();
extern "C" void _s80080F80_20();
extern "C" void _s80080F80_21();
extern "C" void _s80080F80_22();
extern "C" void _s80080F80_23();
extern "C" void _s80080F80_24();
extern "C" void _s80080F80_25();
extern "C" void _s80080F80_26();
extern "C" void _s80080F80_27();
extern "C" void _s80080F80_28();
extern "C" void _s80080F80_29();
extern "C" void _s80080F80_30();
extern "C" void _s80080F80_31();
extern "C" void _s80080F80_32();
extern "C" void _s80080F80_33();
extern "C" void _s80080F80_34();
extern "C" void _s80080F80_35();
extern "C" void _s80080F80_36();
extern "C" void f_80080F80() {}
