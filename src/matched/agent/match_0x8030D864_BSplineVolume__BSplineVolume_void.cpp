// 0x8030D864 BSplineVolume::BSplineVolume(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; li 29,0; lis 9,-32697; li 0,1; addi 9,9,-20720; stw 29,0x9c(30); stw 9,0xdc(30); li 4,0; stw 0,0xa0(30); li 5,148; bl _s8030D864_0; lis 9,-32702; lis 11,-32702; stw 29,0x98(30); addi 3,30,204; lfs f1,0x2a4(9); addi 4,30,208; lfs f2,0x2a8(11); stw 29,0xa4(30); stw 29,0x94(30); bl _s8030D864_1; lfs f0,0xcc(30); mr 3,30; lfs f13,0xd0(30); fsubs f12,f13,f0; fsubs f0,f0,f13; stfs f12,0xd8(30); stfs f0,0xd4(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8030D864_0();
extern "C" void _s8030D864_1();
extern "C" void f_8030D864() {}
