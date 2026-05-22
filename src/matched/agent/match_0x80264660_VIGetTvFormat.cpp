// 0x80264660 VIGetTvFormat (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); bl _s80264660_0; lwz 5,-23212(13); cmplwi 5,7; bgt 0f; lis 4,-32700; addi 4,4,-11732; rlwinm 0,5,2,0,29; lwzx 0,4,0; mtspr 9,0; bctr; li 31,0; b 0f; li 31,1; b 0f; mr 31,5; 0:; bl _s80264660_1; mr 3,31; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s80264660_0();
extern "C" void _s80264660_1();
extern "C" void f_80264660() {}
