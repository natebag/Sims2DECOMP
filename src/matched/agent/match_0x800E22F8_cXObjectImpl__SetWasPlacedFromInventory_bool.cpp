// 0x800E22F8 cXObjectImpl::SetWasPlacedFromInventory(bool) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; addi 31,3,40; mr 3,31; li 4,8; bl _s800E22F8_0; lha 5,0x0(3); cmpwi 30,0; beq 0f; mr 3,31; ori 5,5,16384; li 4,8; bl _s800E22F8_1; b 1f; 0:; mr 3,31; li 4,8; rlwinm 5,5,0,18,16; bl _s800E22F8_2; 1:; li 3,1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800E22F8_0();
extern "C" void _s800E22F8_1();
extern "C" void _s800E22F8_2();
extern "C" void f_800E22F8() {}
