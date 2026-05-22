// 0x80327444 EResourceManager::IsValid(unsigned (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s80327444_0; cmpwi 3,0; li 3,1; bne 0f; li 3,0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80327444_0();
extern "C" void f_80327444() {}
