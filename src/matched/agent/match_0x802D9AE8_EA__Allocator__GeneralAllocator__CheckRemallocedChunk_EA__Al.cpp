// 0x802D9AE8 EA::Allocator::GeneralAllocator::CheckRemallocedChunk(EA::Allocator::GeneralAllocator::Chunk (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 29,3; mr 28,4; lwz 3,0x4fc(29); mr 27,5; stw 3,0x8(1); cmpwi 3,0; beq 0f; bl _s802D9AE8_0; 0:; lwz 30,0x4(28); mr 4,28; mr 3,29; rlwinm 30,30,0,0,28; bl _s802D9AE8_1; mr 31,3; li 4,1; mr 3,29; bl _s802D9AE8_2; add 31,31,3; subfic 4,30,15; subfe 4,4,4; neg 4,4; mr 3,29; bl _s802D9AE8_3; andi. 0,28,7; add 31,31,3; mfcr 4; rlwinm 4,4,3,31,31; mr 3,29; bl _s802D9AE8_4; add 31,31,3; subfic 4,30,7; subfe 4,4,4; neg 4,4; mr 3,29; bl _s802D9AE8_5; add 31,31,3; addi 4,27,16; subfc 4,4,30; subfe 4,4,4; neg 4,4; mr 3,29; bl _s802D9AE8_6; lwz 0,0x8(1); add 31,31,3; cmpwi 0,0; beq 1f; mr 3,0; bl _s802D9AE8_7; 1:; mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s802D9AE8_0();
extern "C" void _s802D9AE8_1();
extern "C" void _s802D9AE8_2();
extern "C" void _s802D9AE8_3();
extern "C" void _s802D9AE8_4();
extern "C" void _s802D9AE8_5();
extern "C" void _s802D9AE8_6();
extern "C" void _s802D9AE8_7();
extern "C" void f_802D9AE8() {}
