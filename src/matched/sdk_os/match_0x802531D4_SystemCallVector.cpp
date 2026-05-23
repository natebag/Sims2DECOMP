// 0x802531D4 SystemCallVector (32B) — Dolphin SDK OSSync.o
// ASMPROC_inject_before: before="blr" replace="nop" lines="mfspr 9,1008; ori 10,9,8; mtspr 1008,10; isync; sync; mtspr 1008,9; rfi"
extern "C" void SystemCallVector() {}
