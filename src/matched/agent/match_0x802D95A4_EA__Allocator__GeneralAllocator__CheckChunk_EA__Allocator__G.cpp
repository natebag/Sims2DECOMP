// 0x802D95A4 EA::Allocator::GeneralAllocator::CheckChunk(EA::Allocator::GeneralAllocator::Chunk (548 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); mr 31,3; mr 29,4; lwz 3,0x4fc(31); stw 3,0x8(1); cmpwi 3,0; beq 0f; bl _s802D95A4_0; 0:; lwz 9,0x480(31); li 28,0; cmpwi 9,1; bgt 8f; addi 0,9,1; lis 4,16383; stw 0,0x480(31); ori 4,4,65535; mr 3,31; lwz 0,0x4(29); rlwinm 27,0,0,0,28; subfc 4,27,4; li 4,0; adde 4,4,4; bl _s802D95A4_1; lwz 0,0x4(29); mr 28,3; andi. 9,0,2; beq 1f; li 4,0; mr 3,31; bl _s802D95A4_2; add 28,28,3; mr 4,29; mr 3,31; bl _s802D95A4_3; subfic 0,3,0; adde 4,0,3; mr 3,31; b 6f; 1:; mr 4,29; mr 3,31; bl _s802D95A4_4; mr. 30,3; li 4,1; bne 2f; li 4,0; 2:; mr 3,31; add 26,29,27; bl _s802D95A4_5; lwz 4,0x0(30); add 28,28,3; mr 3,31; subfc 4,4,29; li 4,0; adde 4,4,4; bl _s802D95A4_6; lwz 0,0x4(30); add 28,28,3; lwz 4,0x0(30); mr 3,31; add 4,4,0; subfc 4,4,29; subfe 4,4,4; neg 4,4; bl _s802D95A4_7; lwz 0,0x4(30); add 28,28,3; lwz 4,0x0(30); mr 3,31; add 4,4,0; subfc 4,4,26; subfe 4,4,4; neg 4,4; bl _s802D95A4_8; lwz 0,0x444(31); add 28,28,3; cmpw 29,0; bne 5f; lwz 0,0x8(29); li 4,0; cmpw 0,29; bne 3f; lwz 0,0xc(29); xor 4,0,29; subfic 9,4,0; adde 4,9,4; 3:; mr 3,31; bl _s802D95A4_9; add 28,28,3; subfic 4,27,15; subfe 4,4,4; neg 4,4; mr 3,31; bl _s802D95A4_10; lwz 0,0x4(29); add 28,28,3; li 4,1; andi. 9,0,1; bne 4f; li 4,0; 4:; mr 3,31; b 6f; 5:; lwz 9,0x470(31); lwz 0,0x46c(31); cmpw 9,0; bne 7f; lwz 4,0x0(30); mr 3,31; subfc 4,4,29; li 4,0; adde 4,4,4; bl _s802D95A4_11; lwz 4,0x4(30); add 28,28,3; mr 3,31; add 4,30,4; addi 4,4,-16; subfc 4,26,4; li 4,0; adde 4,4,4; 6:; bl _s802D95A4_12; add 28,28,3; 7:; lwz 9,0x480(31); addi 9,9,-1; stw 9,0x480(31); 8:; lwz 3,0x8(1); cmpwi 3,0; beq 9f; bl _s802D95A4_13; 9:; mr 3,28; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"
extern "C" void _s802D95A4_0();
extern "C" void _s802D95A4_1();
extern "C" void _s802D95A4_2();
extern "C" void _s802D95A4_3();
extern "C" void _s802D95A4_4();
extern "C" void _s802D95A4_5();
extern "C" void _s802D95A4_6();
extern "C" void _s802D95A4_7();
extern "C" void _s802D95A4_8();
extern "C" void _s802D95A4_9();
extern "C" void _s802D95A4_10();
extern "C" void _s802D95A4_11();
extern "C" void _s802D95A4_12();
extern "C" void _s802D95A4_13();
extern "C" void f_802D95A4() {}
