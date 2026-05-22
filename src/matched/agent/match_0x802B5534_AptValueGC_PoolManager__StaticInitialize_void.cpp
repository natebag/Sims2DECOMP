// 0x802B5534 AptValueGC_PoolManager::StaticInitialize(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,4; li 9,0; stb 0,-21328(13); li 11,8; li 0,46; stb 9,-21327(13); mtspr 9,0; lis 10,15; stb 11,-21336(13); lis 9,-32704; addi 9,9,3732; li 8,0; ori 10,10,16960; li 11,1; 0:; lbzx 0,9,11; cmplw 0,8; ble 1f; mr 8,0; 1:; cmplw 0,10; bge 2f; mr 10,0; 2:; addi 11,11,1; bdnz 0b; li 0,0; cmplwi 10,11; stw 0,-21332(13); bgt 3f; li 10,12; 3:; stb 10,-21335(13)"
extern "C" void f_802B5534() {}
