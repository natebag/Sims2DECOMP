// 0x800901A4 LoadingScreenWaitingForLoadState::Update(float) (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 31,0x1c(1); stw 0,0x24(1); mr 31,3; lwz 3,0x8(31); bl _s800901A4_0; lis 0,17200; stw 3,0x14(1); lis 9,-32707; lfd f13,0x7fc0(9); lis 10,-32707; stw 0,0x10(1); lfs f12,0x7fc8(10); lfd f0,0x10(1); fsub f0,f0,f13; frsp f0,f0; fcmpu 0,f0,f12; beq 1f; lis 9,-32707; lwz 11,-32160(13); lfs f13,0x7fcc(9); lwz 9,0x98(11); cmpwi 9,0; beq 0f; lwz 0,0x354(9); cmpwi 0,0; bne 0f; lis 9,-32707; lfs f13,0x7fd0(9); 0:; lwz 10,0x8(31); li 0,16; lis 8,-32707; lis 9,-32707; addi 11,10,168; lfs f1,0x7fc8(9); stw 0,0xc(11); mr 3,31; stfs f13,0x8(11); li 4,1; stfs f13,0xa8(10); lfs f0,0x7fd4(8); lwz 0,0xc(11); fdivs f0,f0,f13; rlwinm 0,0,0,31,27; ori 0,0,1; stw 0,0xc(11); stfs f0,0x4(11); bl _s800901A4_1; 1:; lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32"
extern "C" void _s800901A4_0();
extern "C" void _s800901A4_1();
extern "C" void f_800901A4() {}
