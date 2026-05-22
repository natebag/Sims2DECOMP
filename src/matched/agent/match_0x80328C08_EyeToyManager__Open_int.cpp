// 0x80328C08 EyeToyManager::Open(int, (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,-26604(13); cmpwi 0,0; bne 0f; stw 4,-26620(13); stw 3,-26616(13); li 0,0; cmpwi 0,0; stw 0,-26604(13); bne 0f; bl _s80328C08_0; 0:; lwz 3,-26604(13); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80328C08_0();
extern "C" void f_80328C08() {}
