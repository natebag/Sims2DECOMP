// 0x80010DAC AptViewer::RepeatCheck(int, (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); lfs f1,-32700(13); lis 9,-32707; lfs f13,-32704(13); lfs f0,-9788(9); mr 29,4; fadds f1,f1,f13; lis 9,-32707; fdivs f0,f1,f0; lfs f2,-9784(9); mr 30,5; stfs f1,-32700(13); li 28,0; fctiwz f12,f0; stfd f12,0x8(1); lwz 31,0xc(1); bl _s80010DAC_0; stfs f1,-32700(13); cmpwi 31,4; ble 0f; li 31,4; 0:; rlwinm 11,30,2,0,29; rlwinm 0,29,4,0,27; add 4,11,0; lis 9,-32702; addi 10,9,13904; lis 11,-32702; lwzx 0,10,4; addi 11,11,13872; lwzx 9,11,4; add 0,0,31; cmpw 0,9; stwx 0,10,4; blt 1f; li 0,0; addi 9,9,-3; stwx 0,10,4; cmpwi 9,11; li 28,1; stwx 9,11,4; bgt 1f; li 0,12; stwx 0,11,4; 1:; mr 3,28; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s80010DAC_0();
extern "C" void f_80010DAC() {}
