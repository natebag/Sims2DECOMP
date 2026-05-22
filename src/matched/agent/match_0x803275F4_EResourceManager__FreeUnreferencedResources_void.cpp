// 0x803275F4 EResourceManager::FreeUnreferencedResources(void) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 4,127; addi 3,3,88; ori 4,4,65535; bl _s803275F4_0; cmpwi 3,0; li 3,1; bne 0f; li 3,0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s803275F4_0();
extern "C" void f_803275F4() {}
