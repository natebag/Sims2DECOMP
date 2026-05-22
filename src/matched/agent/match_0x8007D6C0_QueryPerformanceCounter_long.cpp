// 0x8007D6C0 QueryPerformanceCounter(long (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 0,-24664(13); mr 31,3; cmpwi 0,0; bne 0f; li 9,0; li 10,0; stw 9,0x0(31); stw 10,0x4(31); b 1f; 0:; lwz 11,-26532(13); lis 4,-32696; addi 4,4,22528; lwz 9,0x0(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lis 9,-32707; lfs f0,0x68bc(9); fmuls f1,f1,f0; creqv 6,6,6; bl _s8007D6C0_0; stw 3,0x0(31); stw 4,0x4(31); 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8007D6C0_0();
extern "C" void f_8007D6C0() {}
