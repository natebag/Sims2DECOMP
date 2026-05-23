// 0x80250BB0 RealMode (24B) — Dolphin SDK OSMemory.o
// ASMPROC_inject_before: before="blr" replace="rfi" lines="clrlwi 3,3,2; mtsrr0 3; mfmsr 3; rlwinm 3,3,0,28,25; mtsrr1 3"
extern "C" void RealMode() {}
