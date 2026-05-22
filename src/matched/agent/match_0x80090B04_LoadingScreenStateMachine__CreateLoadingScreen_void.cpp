// 0x80090B04 LoadingScreenStateMachine::CreateLoadingScreen(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x98(31); cmpwi 0,0; bne 0f; bl _s80090B04_0; li 5,16; li 6,0; li 7,0; li 4,920; bl _s80090B04_1; lwz 4,0x9c(31); bl _s80090B04_2; stw 3,0x98(31); 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80090B04_0();
extern "C" void _s80090B04_1();
extern "C" void _s80090B04_2();
extern "C" void f_80090B04() {}
