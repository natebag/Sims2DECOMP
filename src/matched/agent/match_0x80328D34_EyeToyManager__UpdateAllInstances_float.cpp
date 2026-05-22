// 0x80328D34 EyeToyManager::UpdateAllInstances(float) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-26600(13); cmpwi 0,0; bnelr; lwz 0,-26612(13); li 9,0; cmplw 9,0; bgelr; 0:; addi 9,9,1; cmplw 9,0; blt 0b"
extern "C" int f_80328D34() {}
