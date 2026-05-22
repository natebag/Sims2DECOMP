// 0x802D9D90 EA::Allocator::GeneralAllocator::CheckState(EA::Allocator::GeneralAllocator::HeapValidationLevel) (1628 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; mfcr 12; stmw 21,0x14(1); stw 0,0x44(1); stw 12,0x10(1); mr 29,3; mr 21,4; lwz 3,0x4fc(29); stw 3,0x8(1); cmpwi 3,0; beq 0f; bl _s802D9D90_0; 0:; li 28,0; cmpwi 21,0; ble 43f; mr 3,29; li 4,1; bl _s802D9D90_1; li 23,0; lwz 9,0x444(29); mr 28,3; cmpwi 9,0; beq 50f; addi 0,29,52; mr 24,0; cmpw 9,0; beq 50f; lwz 4,0x4(29); mr 3,29; cmpwi 4,21,1; subfic 4,4,79; li 4,0; adde 4,4,4; bl _s802D9D90_2; add 28,28,3; ble cr4,42f; lis 26,30; li 27,0; addi 22,29,12; ori 26,26,33920; 1:; rlwinm 0,27,2,0,29; addi 25,27,1; lwzx 30,22,0; li 27,0; cmpwi 30,0; beq 5f; 2:; mr 4,30; mr 3,29; bl _s802D9D90_3; cmpwi 3,0; li 4,1; bne 3f; li 4,0; 3:; mr 3,29; bl _s802D9D90_4; lwz 0,0x4(30); add 28,28,3; li 4,1; andi. 9,0,4; bne 4f; li 4,0; 4:; mr 3,29; addi 27,27,1; bl _s802D9D90_5; cmpw 27,26; add 28,28,3; mfcr 31; lwz 30,0xc(30); mfcr 4; rlwinm 4,4,1,31,31; mr 3,29; bl _s802D9D90_6; add 28,28,3; cmpwi 30,0; beq 5f; mtcrf 128,31; blt 2b; 5:; mr 27,25; cmpwi 27,10; blt 1b; ble cr4,42f; li 27,0; 6:; rlwinm 0,27,2,0,29; cmpwi 27,1; mr 30,0; lwzx 31,24,0; bgt 7f; mr 3,29; subfic 0,31,0; adde 4,0,31; bl _s802D9D90_7; addi 25,27,2; b 16f; 7:; li 26,0; li 4,1; cmpwi 31,0; bne 8f; li 4,0; 8:; mr 3,29; bl _s802D9D90_8; lwz 31,0xc(31); addi 0,30,44; add 9,29,0; add 28,28,3; cmpw 31,9; bne 9f; li 26,1; 9:; lwzx 0,24,30; addi 25,27,2; cmpw 31,0; beq 14f; mr 27,9; 10:; cmpw 31,27; bne 11f; addi 26,26,1; b 13f; 11:; mr 4,31; mr 3,29; bl _s802D9D90_9; cmpwi 3,0; li 4,1; bne 12f; li 4,0; 12:; mr 3,29; bl _s802D9D90_10; add 28,28,3; 13:; lwz 31,0xc(31); lwzx 0,24,30; cmpw 31,0; bne 10b; 14:; cmpwi 26,0; li 4,1; bne 15f; li 4,0; 15:; mr 3,29; bl _s802D9D90_11; 16:; add 28,28,3; mr 27,25; cmpwi 27,256; blt 6b; ble cr4,42f; lwz 0,0x4e4(29); lis 4,1; ori 4,4,34463; mr 3,29; subfc 4,0,4; li 4,0; adde 4,4,4; bl _s802D9D90_12; lwz 0,0x4e8(29); add 28,28,3; li 4,1; cmpwi 0,0; bne 17f; li 4,0; 17:; mr 3,29; li 27,0; bl _s802D9D90_13; lwz 9,0x4ec(29); add 28,28,3; mr 3,29; addi 0,9,-1; and. 11,9,0; mfcr 4; rlwinm 4,4,3,31,31; bl _s802D9D90_14; lwz 4,0x4(29); add 28,28,3; mr 3,29; rlwinm 4,4,0,0,30; rlwinm 9,4,29,3,31; subfic 4,4,88; li 4,0; adde 4,4,4; addi 30,9,-2; bl _s802D9D90_15; add 28,28,3; 18:; rlwinm 0,27,2,0,29; cmpw 27,30; lwzx 31,22,0; ble 19f; mr 3,29; subfic 0,31,0; adde 4,0,31; bl _s802D9D90_16; add 28,28,3; 19:; cmpwi 31,0; addi 25,27,1; beq 21f; 20:; lwz 0,0x4(31); mr 3,29; rlwinm 0,0,0,0,28; rlwinm 4,0,29,3,31; add 23,23,0; addi 4,4,-2; xor 4,4,27; subfic 0,4,0; adde 4,0,4; bl _s802D9D90_17; lwz 31,0xc(31); add 28,28,3; cmpwi 31,0; bne 20b; 21:; mr 27,25; cmpwi 27,9; ble 18b; cmpwi 23,0; beq 23f; lwz 0,0x4(29); li 4,1; andi. 9,0,1; bne 22f; li 4,0; 22:; mr 3,29; b 24f; 23:; lwz 0,0x4(29); andi. 9,0,1; bne 25f; mr 3,29; li 4,1; 24:; bl _s802D9D90_18; add 28,28,3; 25:; ble cr4,42f; li 27,1; 26:; rlwinm 9,27,3,0,28; cmpwi 27,1; add 9,9,29; mfcr 24; addi 26,9,44; ble 31f; srawi 9,27,5; addi 10,29,1076; rlwinm 9,9,2,0,29; rlwinm 0,27,0,27,31; lwzx 8,10,9; li 11,1; slw 11,11,0; li 9,1; and. 0,8,11; bne 27f; li 9,0; 27:; lwz 0,0x8(26); li 4,1; cmpw 26,0; bne 28f; li 4,0; 28:; cmpwi 9,0; bne 29f; xori 4,4,1; b 30f; 29:; cmpwi 4,0; beq 31f; mr 4,9; 30:; mr 3,29; bl _s802D9D90_19; add 28,28,3; 31:; lwz 30,0x8(26); addi 25,27,1; cmpw 30,26; beq 41f; 32:; mr 3,29; mr 4,30; bl _s802D9D90_20; lwz 0,0x4(30); add 28,28,3; mtcrf 128,24; rlwinm 31,0,0,0,28; ble 37f; cmplwi 31,511; bgt 33f; rlwinm 4,31,29,3,31; b 34f; 33:; mr 3,31; bl _s802D9D90_21; mr 4,3; 34:; mr 3,29; xor 4,4,27; subfic 0,4,0; adde 4,0,4; bl _s802D9D90_22; add 28,28,3; cmplwi 31,511; ble 37f; lwz 9,0x8(30); li 4,0; cmpw 9,26; beq 35f; lwz 9,0x4(9); lwz 0,0x4(30); rlwinm 9,9,0,0,28; rlwinm 0,0,0,0,28; cmplw 9,0; blt 36f; 35:; li 4,1; 36:; mr 3,29; bl _s802D9D90_23; add 28,28,3; 37:; lwz 0,0x4(30); rlwinm 0,0,0,0,28; add 31,30,0; b 39f; 38:; mr 4,31; mr 3,29; bl _s802D9D90_24; lwz 0,0x4(31); add 28,28,3; rlwinm 0,0,0,0,28; add 31,31,0; 39:; mr 3,29; mr 4,31; bl _s802D9D90_25; cmpwi 3,0; bne 40f; lwz 0,0x4(31); rlwinm 11,0,0,0,28; add 9,31,11; lwz 0,0x4(9); andi. 9,0,1; beq 40f; cmplwi 11,15; bgt 38b; 40:; lwz 30,0x8(30); cmpw 30,26; bne 32b; 41:; mr 27,25; cmpwi 27,127; ble 26b; 42:; lwz 4,0x444(29); mr 3,29; bl _s802D9D90_26; lwz 4,0x498(29); add 28,28,3; mr 3,29; not 4,4; rlwinm 4,4,1,31,31; bl _s802D9D90_27; lwz 9,0x498(29); add 28,28,3; lwz 0,0x4a0(29); mr 3,29; cmpw cr7,9,0; cror 31,30,28; mfcr 4; rlwinm 4,4,0,31,31; bl _s802D9D90_28; add 28,28,3; 43:; cmpwi 21,2; ble 50f; lwz 27,0x470(29); addi 0,29,1100; mr 25,0; cmpw 27,0; beq 50f; 44:; lwz 9,0x4(27); lwz 31,0x0(27); add 9,27,9; addi 26,9,-16; cmplw 31,26; bge 49f; 45:; lwz 9,0x4(31); rlwinm 9,9,0,0,28; add 9,31,9; lwz 0,0x4(9); andi. 30,0,1; beq 46f; mr 3,29; mr 4,31; bl _s802D9D90_29; b 47f; 46:; mr 3,29; mr 4,31; bl _s802D9D90_30; 47:; add 28,28,3; cmpwi 30,0; bne 48f; lwz 0,0xc(31); cmpw 31,0; bne 48f; lwz 4,0x444(29); mr 3,29; xor 4,31,4; subfic 0,4,0; adde 4,0,4; bl _s802D9D90_31; add 28,28,3; b 49f; 48:; lwz 0,0x4(31); rlwinm 0,0,0,0,28; add 31,31,0; cmplw 31,26; blt 45b; 49:; lwz 27,0x24(27); cmpw 27,25; bne 44b; 50:; lwz 3,0x8(1); cmpwi 3,0; beq 51f; bl _s802D9D90_32; 51:; mr 3,28; lwz 0,0x44(1); lwz 12,0x10(1); mtspr 8,0; lmw 21,0x14(1); mtcrf 8,12; addi 1,1,64"
extern "C" void _s802D9D90_0();
extern "C" void _s802D9D90_1();
extern "C" void _s802D9D90_2();
extern "C" void _s802D9D90_3();
extern "C" void _s802D9D90_4();
extern "C" void _s802D9D90_5();
extern "C" void _s802D9D90_6();
extern "C" void _s802D9D90_7();
extern "C" void _s802D9D90_8();
extern "C" void _s802D9D90_9();
extern "C" void _s802D9D90_10();
extern "C" void _s802D9D90_11();
extern "C" void _s802D9D90_12();
extern "C" void _s802D9D90_13();
extern "C" void _s802D9D90_14();
extern "C" void _s802D9D90_15();
extern "C" void _s802D9D90_16();
extern "C" void _s802D9D90_17();
extern "C" void _s802D9D90_18();
extern "C" void _s802D9D90_19();
extern "C" void _s802D9D90_20();
extern "C" void _s802D9D90_21();
extern "C" void _s802D9D90_22();
extern "C" void _s802D9D90_23();
extern "C" void _s802D9D90_24();
extern "C" void _s802D9D90_25();
extern "C" void _s802D9D90_26();
extern "C" void _s802D9D90_27();
extern "C" void _s802D9D90_28();
extern "C" void _s802D9D90_29();
extern "C" void _s802D9D90_30();
extern "C" void _s802D9D90_31();
extern "C" void _s802D9D90_32();
extern "C" void f_802D9D90() {}
