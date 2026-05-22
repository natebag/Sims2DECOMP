// 0x802DC5D8 EA::Allocator::GeneralAllocator::AddCore(void (364 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 25,0x14(1); stw 0,0x34(1); mr 29,3; mr 31,4; lwz 3,0x4fc(29); mr 30,5; mr 28,6; mr 27,7; mr 26,8; mr 25,9; stw 3,0x8(1); cmpwi 3,0; beq 0f; bl _s802DC5D8_0; 0:; cmpwi 31,0; beq 4f; cmplwi 30,63; ble 7f; lwz 9,0x4ec(29); divwu 0,30,9; mullw 0,0,9; cmpw 30,0; beq 1f; neg 0,9; and 30,30,0; 1:; addi 0,31,47; li 9,0; rlwinm 0,0,0,0,28; stw 28,0x10(31); stw 27,0x14(31); mr 4,31; stw 26,0x18(31); mr 3,29; stw 25,0x1c(31); addi 5,29,1100; stw 30,0x4(31); stw 30,0x8(31); stw 0,0x0(31); stw 9,0xc(31); bl _s802DC5D8_1; lwz 3,0x0(31); li 5,1; subf 4,31,3; subf 4,4,30; bl _s802DC5D8_2; lwz 9,0x444(29); addi 0,29,52; mr 4,3; li 5,1; cmpw 9,0; bne 2f; li 5,0; 2:; mr 3,29; bl _s802DC5D8_3; lwz 3,0x8(1); cmpwi 3,0; beq 3f; bl _s802DC5D8_4; 3:; li 3,1; b 9f; 4:; cmpwi 30,0; beq 7f; lwz 4,0x4ec(29); addi 0,30,-1; mr 3,29; li 31,1; add 0,0,4; neg 4,4; and 4,0,4; bl _s802DC5D8_5; cmpwi 3,0; bne 5f; li 31,0; 5:; lwz 3,0x8(1); cmpwi 3,0; beq 6f; bl _s802DC5D8_6; 6:; mr 3,31; b 9f; 7:; lwz 3,0x8(1); cmpwi 3,0; beq 8f; bl _s802DC5D8_7; 8:; li 3,0; 9:; lwz 0,0x34(1); mtspr 8,0; lmw 25,0x14(1); addi 1,1,48"
extern "C" void _s802DC5D8_0();
extern "C" void _s802DC5D8_1();
extern "C" void _s802DC5D8_2();
extern "C" void _s802DC5D8_3();
extern "C" void _s802DC5D8_4();
extern "C" void _s802DC5D8_5();
extern "C" void _s802DC5D8_6();
extern "C" void _s802DC5D8_7();
extern "C" void f_802DC5D8() {}
