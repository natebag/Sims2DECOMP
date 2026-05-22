// 0x802D97C8 EA::Allocator::GeneralAllocator::CheckFreeChunk(EA::Allocator::GeneralAllocator::Chunk (508 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 29,3; mr 30,4; lwz 3,0x4fc(29); stw 3,0x8(1); cmpwi 3,0; beq 0f; bl _s802D97C8_0; 0:; lwz 0,0x4(30); mr 4,30; mr 3,29; rlwinm 28,0,0,0,28; bl _s802D97C8_1; add 27,30,28; lwz 9,0x4(30); mr 31,3; mr 3,29; rlwinm 9,9,0,0,28; add 9,30,9; lwz 0,0x4(9); andi. 9,0,1; mfcr 4; rlwinm 4,4,3,31,31; bl _s802D97C8_2; lwz 0,0x4(30); add 31,31,3; mr 3,29; andi. 9,0,2; mfcr 4; rlwinm 4,4,3,31,31; bl _s802D97C8_3; add 31,31,3; cmplwi 28,15; ble 5f; li 4,1; mr 3,29; bl _s802D97C8_4; andi. 0,30,7; add 31,31,3; mfcr 4; rlwinm 4,4,3,31,31; mr 3,29; bl _s802D97C8_5; lwzx 4,30,28; add 31,31,3; mr 3,29; xor 4,4,28; subfic 0,4,0; adde 4,0,4; bl _s802D97C8_6; lwz 0,0x4(30); add 31,31,3; li 4,1; andi. 9,0,1; bne 1f; li 4,0; 1:; mr 3,29; bl _s802D97C8_7; lwz 0,0x444(29); add 31,31,3; li 4,0; cmpw 30,0; beq 2f; lwz 9,0x4(27); rlwinm 9,9,0,0,28; add 9,27,9; lwz 0,0x4(9); andi. 9,0,1; beq 3f; 2:; li 4,1; 3:; mr 3,29; bl _s802D97C8_8; lwz 9,0xc(30); add 31,31,3; mr 3,29; lwz 4,0x8(9); xor 4,4,30; subfic 0,4,0; adde 4,0,4; bl _s802D97C8_9; lwz 9,0x8(30); add 31,31,3; mr 3,29; lwz 4,0xc(9); xor 4,4,30; subfic 0,4,0; adde 4,0,4; bl _s802D97C8_10; lwz 9,0xc(30); add 31,31,3; cmpw 30,9; beq 4f; lwz 0,0x8(30); cmpw 30,0; bne 7f; 4:; lwz 4,0x8(30); mr 3,29; xor 4,4,9; subfic 0,4,0; adde 4,0,4; bl _s802D97C8_11; lwz 4,0x444(29); add 31,31,3; mr 3,29; xor 4,30,4; subfic 0,4,0; adde 4,0,4; b 6f; 5:; mr 3,29; subfic 4,28,4; li 4,0; adde 4,4,4; 6:; bl _s802D97C8_12; add 31,31,3; 7:; lwz 3,0x8(1); cmpwi 3,0; beq 8f; bl _s802D97C8_13; 8:; mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s802D97C8_0();
extern "C" void _s802D97C8_1();
extern "C" void _s802D97C8_2();
extern "C" void _s802D97C8_3();
extern "C" void _s802D97C8_4();
extern "C" void _s802D97C8_5();
extern "C" void _s802D97C8_6();
extern "C" void _s802D97C8_7();
extern "C" void _s802D97C8_8();
extern "C" void _s802D97C8_9();
extern "C" void _s802D97C8_10();
extern "C" void _s802D97C8_11();
extern "C" void _s802D97C8_12();
extern "C" void _s802D97C8_13();
extern "C" void f_802D97C8() {}
