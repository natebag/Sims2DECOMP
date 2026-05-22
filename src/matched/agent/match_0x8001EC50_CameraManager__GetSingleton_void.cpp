// 0x8001EC50 CameraManager::GetSingleton(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,-32672(13); cmpwi 0,0; bne 0f; li 3,8; bl _s8001EC50_0; bl _s8001EC50_1; mr 0,3; stw 0,-32672(13); bl _s8001EC50_2; 0:; lwz 3,-32672(13); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8001EC50_0();
extern "C" void _s8001EC50_1();
extern "C" void _s8001EC50_2();
extern "C" void f_8001EC50() {}
