// 0x80248CD4 __sseek (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 0,4; mr 31,3; mr 6,5; lwz 3,0x5c(31); lha 4,0xe(31); mr 5,0; bl _s80248CD4_0; cmpwi 3,-1; bne 0f; lhz 0,0xc(31); rlwinm 0,0,0,20,18; b 1f; 0:; lhz 0,0xc(31); stw 3,0x58(31); ori 0,0,4096; 1:; sth 0,0xc(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80248CD4_0();
extern "C" void f_80248CD4() {}
