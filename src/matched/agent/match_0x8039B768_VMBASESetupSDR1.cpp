// 0x8039B768 __VMBASESetupSDR1 (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 27,3; lis 5,-32710; addi 5,5,-18560; rlwinm 5,5,0,1,31; mtspr 26,5; .long 0x4C000064; sync; mtspr 25,4; sync; mfmsr 3; ori 3,3,48; mtspr 27,3; lis 5,-32710; addi 5,5,-18520; mtspr 26,5; .long 0x4C000064; ori 0,0,0"
extern "C" int f_8039B768() {}
