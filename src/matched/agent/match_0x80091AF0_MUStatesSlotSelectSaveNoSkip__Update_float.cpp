// 0x80091AF0 MUStatesSlotSelectSaveNoSkip::Update(float) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0x8(31); lwz 0,0x90(3); cmpwi 0,0; bne 0f; lwz 11,0x98(3); li 0,7; li 4,9; stw 0,0xac(11); lwz 9,0x8(31); lwz 3,0x98(9); bl _s80091AF0_0; mr 3,31; li 4,14; bl _s80091AF0_1; b 2f; 0:; cmpwi 0,1; bne 1f; li 4,1; bl _s80091AF0_2; b 2f; 1:; cmpwi 0,2; bne 2f; li 4,2; bl _s80091AF0_3; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80091AF0_0();
extern "C" void _s80091AF0_1();
extern "C" void _s80091AF0_2();
extern "C" void _s80091AF0_3();
extern "C" void f_80091AF0() {}
