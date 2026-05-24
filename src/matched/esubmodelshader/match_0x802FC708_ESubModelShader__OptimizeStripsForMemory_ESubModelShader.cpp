// 0x802FC708 ESubModelShader::OptimizeStripsForMemory(ESubModelShader (1692 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; mfcr 12; stmw 16,0x10(1); stw 0,0x54(1); stw 12,0xc(1); mr 25,5; lwz 9,-26716(13); lwz 0,0x4(25); mr 16,3; lwz 23,0x18(25); addi 9,9,1; mr 18,6; mr 22,7; stw 9,-26716(13); cmpwi 0,0; li 17,1; beq 0f; li 17,2; cmpwi 22,0; beq 0f; li 17,3; 0:; lwz 0,0x8(25); cmpwi 0,0; beq 1f; addi 17,17,1; 1:; lwz 0,0xc(25); cmpwi 0,0; beq 2f; addi 17,17,1; 2:; lwz 0,0x10(4); cmpwi 3,23,254; andi. 9,0,16; beq 46f; lwz 9,-22712(13); lwz 0,0x0(25); addi 9,9,1; stw 9,-22712(13); cmpwi 0,0; beq 15f; bl _s802FC708_0; li 28,0; rlwinm 4,23,3,0,28; li 5,0; bl _s802FC708_1; mr 30,3; bl _s802FC708_2; rlwinm 4,23,1,0,30; li 5,0; bl _s802FC708_3; mr 24,3; lwz 4,0x0(25); li 31,0; cmpw 28,23; bge 12f; 3:; li 3,0; li 27,0; cmpw 3,28; add 29,31,31; addi 26,31,1; bge 9f; rlwinm 6,29,2,0,29; li 5,0; 4:; lhzx 9,5,30; li 7,0; lhzx 0,6,4; li 8,0; add 10,6,4; add 11,5,30; b 6f; 5:; addi 8,8,1; addi 10,10,2; addi 11,11,2; cmpwi 8,3; bgt 7f; lhz 9,0x0(11); lhz 0,0x0(10); 6:; cmpw 9,0; beq 5b; li 7,1; 7:; cmpwi 7,0; bne 8f; li 27,1; b 9f; 8:; addi 3,3,1; addi 5,5,8; cmpw 3,28; blt 4b; 9:; cmpwi 27,0; bne 11f; rlwinm 0,28,3,0,28; rlwinm 9,31,3,0,28; add 11,0,30; add 9,9,4; li 0,4; addi 10,28,1; mtspr 9,0; 10:; lhz 0,0x0(9); addi 9,9,2; sth 0,0x0(11); addi 11,11,2; bdnz 10b; mr 28,10; 11:; mr 31,26; sthx 3,29,24; cmpw 31,23; blt 3b; 12:; lwz 11,0x14(25); cmpwi 18,0; rlwinm 31,28,3,0,28; ble 14f; mtspr 9,18; add 10,17,17; 13:; lhz 0,0x0(11); add 0,0,0; lhzx 9,24,0; sth 9,0x0(11); add 11,11,10; bdnz 13b; 14:; lwz 4,0x0(25); li 5,0; mr 3,16; bl _s802FC708_4; lis 5,-32702; lis 7,-32702; addi 7,7,-2656; li 6,2048; addi 5,5,-2744; mr 4,31; mr 3,16; bl _s802FC708_5; mr 0,3; mr 5,31; stw 0,0x0(25); mr 4,30; bl _s802FC708_6; bl _s802FC708_7; mr 4,24; bl _s802FC708_8; bl _s802FC708_9; mr 4,30; bl _s802FC708_10; lwz 0,0x18(25); lwz 9,-26712(13); subf 0,28,0; rlwinm 0,0,3,0,28; add 9,9,0; stw 9,-26712(13); 15:; lwz 0,0x4(25); cmpwi 0,0; beq 33f; cmpwi 4,22,0; li 31,2; beq cr4,16f; li 31,4; 16:; bl _s802FC708_11; add 30,23,23; mullw 4,31,30; li 5,0; li 22,0; bl _s802FC708_12; mr 26,3; bl _s802FC708_13; mr 4,30; li 5,0; bl _s802FC708_14; mr 24,3; lwz 12,0x4(25); li 3,0; cmpw 22,23; bge 27f; 17:; li 29,0; li 21,0; cmpw 29,22; add 19,3,3; addi 20,3,1; bge 23f; mullw 0,3,31; li 30,0; mr 5,26; add 27,31,31; add 28,0,0; 18:; li 7,0; li 8,0; cmpw 7,31; bge 21f; lhz 9,0x0(5); mr 4,30; lhzx 0,28,12; mullw 6,3,31; cmpw 9,0; b 20f; 19:; addi 8,8,1; cmpw 8,31; bge 21f; add 9,4,8; add 11,6,8; add 9,9,9; add 11,11,11; lhzx 10,9,26; lhzx 0,11,12; cmpw 10,0; 20:; beq 19b; li 7,1; 21:; cmpwi 7,0; bne 22f; li 21,1; b 23f; 22:; addi 29,29,1; add 30,30,31; add 5,5,27; cmpw 29,22; blt 18b; 23:; cmpwi 21,0; bne 26f; cmpwi 31,0; addi 10,22,1; beq 25f; mullw 0,22,31; mtspr 9,31; mullw 9,3,31; add 0,0,0; add 11,0,26; add 9,9,9; add 9,9,12; 24:; lhz 0,0x0(9); addi 9,9,2; sth 0,0x0(11); addi 11,11,2; bdnz 24b; 25:; mr 22,10; 26:; mr 3,20; sthx 29,19,24; cmpw 3,23; blt 17b; 27:; lwz 11,0x14(25); lwz 0,0x8(25); addi 11,11,2; cmpwi 0,0; beq 28f; addi 11,11,2; 28:; lwz 0,0xc(25); cmpwi 0,0; beq 29f; addi 11,11,2; 29:; cmpwi 18,0; mullw 30,22,31; ble 32f; mtspr 9,18; mcrf cr0,cr4; add 10,17,17; 30:; lhz 0,0x0(11); add 0,0,0; lhzx 9,24,0; sth 9,0x0(11); beq 31f; lhz 0,0x2(11); add 0,0,0; lhzx 9,24,0; sth 9,0x2(11); 31:; add 11,11,10; bdnz 30b; 32:; lwz 4,0x4(25); li 5,0; mr 3,16; add 30,30,30; bl _s802FC708_15; lis 5,-32702; lis 7,-32702; addi 7,7,-2568; li 6,2124; addi 5,5,-2744; mr 4,30; mr 3,16; bl _s802FC708_16; mr 0,3; mr 5,30; stw 0,0x4(25); mr 4,26; bl _s802FC708_17; bl _s802FC708_18; mr 4,24; bl _s802FC708_19; bl _s802FC708_20; mr 4,26; bl _s802FC708_21; lwz 0,0x18(25); lwz 9,-26712(13); subf 0,22,0; add 0,0,0; mullw 0,31,0; add 9,9,0; stw 9,-26712(13); 33:; lwz 0,0x8(25); cmpwi 0,0; beq 46f; bl _s802FC708_22; li 27,0; rlwinm 4,23,2,0,29; li 5,0; bl _s802FC708_23; mr 29,3; bl _s802FC708_24; rlwinm 4,23,1,0,30; li 5,0; bl _s802FC708_25; mr 21,3; lwz 31,0x8(25); li 3,0; cmpw 27,23; bge 43f; 34:; li 30,0; li 26,0; cmpw 30,27; rlwinm 28,27,2,0,29; add 22,3,3; addi 24,3,1; bge 40f; rlwinm 0,3,2,0,29; li 4,0; lbzx 12,31,0; mr 5,0; mr 7,29; 35:; lbz 0,0x0(7); li 6,0; li 8,0; addi 7,7,4; cmpw 0,12; b 37f; 36:; addi 8,8,1; cmpwi 8,3; bgt 38f; add 9,4,8; add 11,5,8; lbzx 10,29,9; lbzx 0,31,11; cmpw 10,0; 37:; beq 36b; li 6,1; 38:; cmpwi 6,0; bne 39f; li 26,1; b 40f; 39:; addi 30,30,1; addi 4,4,4; cmpw 30,27; blt 35b; 40:; cmpwi 26,0; bne 42f; li 0,4; rlwinm 5,3,2,0,29; mtspr 9,0; addi 9,27,1; add 4,28,29; add 11,5,31; 41:; lbz 0,0x0(11); addi 11,11,1; stb 0,0x0(4); addi 4,4,1; bdnz 41b; mr 27,9; 42:; mr 3,24; sthx 30,22,21; cmpw 3,23; blt 34b; 43:; lwz 11,0x14(25); cmpwi 18,0; rlwinm 28,27,2,0,29; addi 11,11,2; ble 45f; mtspr 9,18; add 10,17,17; 44:; lhz 0,0x0(11); add 0,0,0; lhzx 9,21,0; sth 9,0x0(11); add 11,11,10; bdnz 44b; 45:; lwz 4,0x8(25); li 5,0; mr 3,16; bl _s802FC708_26; lis 5,-32702; lis 7,-32702; addi 7,7,-2600; li 6,2185; addi 5,5,-2744; mr 4,28; mr 3,16; bl _s802FC708_27; mr 0,3; mr 5,28; stw 0,0x8(25); mr 4,29; crxor 6,6,6; bl _s802FC708_28; bl _s802FC708_29; mr 4,21; bl _s802FC708_30; bl _s802FC708_31; mr 4,29; bl _s802FC708_32; lwz 0,0x18(25); lwz 9,-26712(13); subf 0,27,0; rlwinm 0,0,2,0,29; add 9,9,0; stw 9,-26712(13); 46:; bgt cr3,47f; mullw 0,18,17; lwz 9,-26724(13); lwz 11,-26720(13); addi 9,9,1; stw 9,-26724(13); add 11,11,0; stw 11,-26720(13); 47:; lwz 0,0x54(1); lwz 12,0xc(1); mtspr 8,0; lmw 16,0x10(1); mtcrf 24,12; addi 1,1,80"

extern "C" void _s802FC708_0();
extern "C" void _s802FC708_1();
extern "C" void _s802FC708_2();
extern "C" void _s802FC708_3();
extern "C" void _s802FC708_4();
extern "C" void _s802FC708_5();
extern "C" void _s802FC708_6();
extern "C" void _s802FC708_7();
extern "C" void _s802FC708_8();
extern "C" void _s802FC708_9();
extern "C" void _s802FC708_10();
extern "C" void _s802FC708_11();
extern "C" void _s802FC708_12();
extern "C" void _s802FC708_13();
extern "C" void _s802FC708_14();
extern "C" void _s802FC708_15();
extern "C" void _s802FC708_16();
extern "C" void _s802FC708_17();
extern "C" void _s802FC708_18();
extern "C" void _s802FC708_19();
extern "C" void _s802FC708_20();
extern "C" void _s802FC708_21();
extern "C" void _s802FC708_22();
extern "C" void _s802FC708_23();
extern "C" void _s802FC708_24();
extern "C" void _s802FC708_25();
extern "C" void _s802FC708_26();
extern "C" void _s802FC708_27();
extern "C" void _s802FC708_28();
extern "C" void _s802FC708_29();
extern "C" void _s802FC708_30();
extern "C" void _s802FC708_31();
extern "C" void _s802FC708_32();

struct ESubModelShader {
    void OptimizeStripsForMemory_ESubModelShader();
};

void ESubModelShader::OptimizeStripsForMemory_ESubModelShader() {
}
