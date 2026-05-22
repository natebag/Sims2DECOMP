// 0x802DC744 EA::Allocator::GeneralAllocator::ExtendCoreInternal(unsigned (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 31,4; lwz 0,0x4c4(29); li 11,0; li 30,0; li 9,0; cmpwi 0,0; bne 0f; bl _s802DC744_0; mr 30,3; li 5,1; mr 3,29; mr 4,30; bl _s802DC744_1; lwz 0,0x4(30); li 11,1; rlwinm 9,0,0,0,28; 0:; cmpwi 30,0; beq 2f; cmplw 9,31; ble 2f; ori 0,31,1; subf 9,31,9; stw 0,0x4(30); add 4,30,31; stwx 31,30,31; cmpwi 11,0; stw 9,0x4(4); stwx 9,4,9; beq 1f; mr 3,29; li 5,0; bl _s802DC744_2; b 2f; 1:; addi 9,29,52; lwz 11,0xc(9); stw 9,0x8(4); stw 11,0xc(4); stw 4,0xc(9); stw 4,0x8(11); 2:; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802DC744_0();
extern "C" void _s802DC744_1();
extern "C" void _s802DC744_2();
extern "C" void f_802DC744() {}
