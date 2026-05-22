// 0x802AB148 AptSeedRand(unsigned (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32694; li 0,0; ori 3,3,1; li 11,623; stw 3,-15936(9); mtspr 9,11; stw 0,-27100(13); addi 9,9,-15936; lis 0,1; addi 9,9,4; ori 0,0,3533; 0:; mullw 3,3,0; stw 3,0x0(9); addi 9,9,4; bdnz 0b"
extern "C" void f_802AB148() {}
