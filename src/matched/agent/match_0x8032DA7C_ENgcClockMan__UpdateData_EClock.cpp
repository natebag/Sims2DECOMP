// 0x8032DA7C ENgcClockMan::UpdateData(EClock (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,4; bl _s8032DA7C_0; lis 9,-32768; lis 0,4194; lwz 10,0xf8(9); ori 0,0,19923; lwz 8,0x4(30); mulhwu 10,10,0; lis 9,-32702; subf 8,8,4; lfd f12,0x1578(9); lis 0,17200; lis 11,-32702; lfs f11,0x1580(11); rlwinm 10,10,24,8,31; lfs f13,0x8(30); divwu 8,8,10; stw 3,0x0(30); stw 4,0x4(30); stw 8,0xc(1); stw 0,0x8(1); lfd f0,0x8(1); fsub f0,f0,f12; frsp f0,f0; fdivs f0,f0,f11; fadds f13,f13,f0; stfs f13,0x8(30); lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8032DA7C_0();
extern "C" void f_8032DA7C() {}
