// 0x8024CCC0 __LCEnable (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfmsr 5; ori 5,5,4096; mtmsr 5; lis 3,-32768; li 4,1024; mtspr 9,4; 0:; dcbt 0,3; dcbst 0,3; addi 3,3,32; bdnz 0b; mfspr 4,920; oris 4,4,4111; mtspr 920,4; ori 0,0,0; ori 0,0,0; ori 0,0,0; ori 0,0,0; ori 0,0,0; ori 0,0,0; ori 0,0,0; ori 0,0,0; ori 0,0,0; ori 0,0,0; ori 0,0,0; ori 0,0,0; lis 3,-8192; ori 3,3,2; mtspr 543,3; ori 3,3,510; mtspr 542,3; isync; lis 3,-8192; li 6,512; mtspr 9,6; li 6,0; 1:; .long 0x10061FEC; addi 3,3,32; bdnz 1b; ori 0,0,0; ori 0,0,0; ori 0,0,0; ori 0,0,0; ori 0,0,0; ori 0,0,0; ori 0,0,0; ori 0,0,0; ori 0,0,0; ori 0,0,0; ori 0,0,0; ori 0,0,0"
extern "C" int f_8024CCC0() {}
