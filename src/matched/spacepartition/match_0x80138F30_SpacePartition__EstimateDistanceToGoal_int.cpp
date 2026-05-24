// 0x80138F30 SpacePartition::EstimateDistanceToGoal(int) (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; cmplwi 4,1; ble 0f; mr 3,30; bl _s80138F30_0; mr. 8,3; beq 0f; lwz 10,0x0(8); cmpwi 10,0; blt 0f; lwz 11,0x0(30); lis 3,-13108; ori 3,3,52429; lwz 9,0x0(11); lwz 12,0x0(9); lwz 0,0x4(9); subf 0,12,0; mullw 0,0,3; srawi 0,0,2; cmplw 10,0; bge 0f; lwz 11,0x4(8); cmpwi 11,0; blt 0f; lwz 9,0xc(30); lwz 0,0x10(30); subf 0,9,0; mullw 0,0,3; srawi 0,0,2; cmplw 11,0; blt 1f; 0:; lis 9,-32706; lfs f1,-11280(9); b 2f; 1:; mulli 10,10,20; lwz 3,0x14(8); lwz 30,0x18(8); lis 4,17200; mr 6,7; lis 5,-32706; add 9,12,10; lwzx 11,12,10; lwz 10,0xc(9); lwz 0,0x4(9); lwz 8,0x8(9); add 0,0,10; lfd f13,-11272(5); rlwinm 9,0,1,31,31; add 11,11,8; add 0,0,9; rlwinm 10,11,1,31,31; srawi 0,0,1; add 11,11,10; subf 0,3,0; srawi 11,11,1; xoris 0,0,32768; subf 11,30,11; stw 0,0xc(1); xoris 11,11,32768; stw 4,0x8(1); lfd f0,0x8(1); stw 11,0xc(1); fsub f0,f0,f13; stw 4,0x8(1); frsp f0,f0; lfd f1,0x8(1); fsub f1,f1,f13; frsp f1,f1; fmuls f1,f1,f1; fmadds f1,f0,f0,f1; bl _s80138F30_1; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"

extern "C" void _s80138F30_0();
extern "C" void _s80138F30_1();

struct SpacePartition {
    void EstimateDistanceToGoal();
};

void SpacePartition::EstimateDistanceToGoal() {
}
