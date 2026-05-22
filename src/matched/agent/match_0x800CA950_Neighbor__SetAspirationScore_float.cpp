// 0x800CA950 Neighbor::SetAspirationScore(float) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32706; lis 11,-32706; lfs f13,-22832(9); lis 10,-32706; lfs f12,-22828(11); fdivs f1,f1,f13; lfs f0,-22824(10); fmsubs f1,f1,f12,f0; stfs f1,0x110(3)"
extern "C" void f_800CA950() {}
