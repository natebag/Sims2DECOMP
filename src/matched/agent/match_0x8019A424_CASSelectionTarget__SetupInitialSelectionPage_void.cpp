// 0x8019A424 CASSelectionTarget::SetupInitialSelectionPage(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; li 0,1; stw 0,0x548(31); bl _s8019A424_0; lwz 5,0x8c(31); cmpwi 5,0; ble 1f; addi 5,5,4; cmpwi 5,15; ble 0f; li 5,15; 0:; mr 3,31; li 4,4; bl _s8019A424_1; 1:; mr 3,31; bl _s8019A424_2; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8019A424_0();
extern "C" void _s8019A424_1();
extern "C" void _s8019A424_2();
extern "C" void f_8019A424() {}
