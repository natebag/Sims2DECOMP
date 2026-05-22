// 0x802D9CA0 EA::Allocator::GeneralAllocator::CheckMMappedChunk(EA::Allocator::GeneralAllocator::Chunk (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,3; mr 31,4; lwz 3,0x4fc(30); stw 3,0x8(1); cmpwi 3,0; beq 0f; bl _s802D9CA0_0; 0:; mr 4,31; mr 3,30; bl _s802D9CA0_1; lwz 0,0x4(31); mr 29,3; li 4,1; andi. 9,0,2; bne 1f; li 4,0; 1:; mr 3,30; bl _s802D9CA0_2; lwz 11,0x4b8(30); addi 0,30,1196; mr 8,0; add 29,29,3; cmpw 11,0; beq 3f; lwz 0,0x0(11); lwz 9,0x0(31); subf 0,0,11; subf 4,9,31; cmpw 0,4; beq 3f; mr 10,8; 2:; lwz 11,0xc(11); cmpw 11,10; beq 3f; lwz 0,0x0(11); subf 0,0,11; cmpw 0,4; bne 2b; 3:; cmpw 11,8; li 4,1; bne 4f; li 4,0; 4:; mr 3,30; bl _s802D9CA0_3; lwz 0,0x8(1); add 29,29,3; cmpwi 0,0; beq 5f; mr 3,0; bl _s802D9CA0_4; 5:; mr 3,29; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s802D9CA0_0();
extern "C" void _s802D9CA0_1();
extern "C" void _s802D9CA0_2();
extern "C" void _s802D9CA0_3();
extern "C" void _s802D9CA0_4();
extern "C" void f_802D9CA0() {}
