// 0x802363E0 ERLevel::InsertInOrderTable(EOrderTableData (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 28,4; mr 30,3; bl _s802363E0_0; addis 30,30,3; lwz 9,0x8(28); mr 29,3; lfs f12,-24028(30); lfs f1,0x4(9); lfs f0,0x0(9); lfs f13,-24032(30); fsubs f1,f1,f12; fmuls f1,f1,f1; fsubs f0,f0,f13; fmadds f1,f0,f0,f1; bl _s802363E0_1; stfs f1,0x2c(29); lis 10,17200; lis 11,-32704; lwz 0,0x4(28); lfd f13,-2736(11); xoris 0,0,32768; stw 0,0xc(1); stw 10,0x8(1); lfd f0,0x8(1); fsub f0,f0,f13; frsp f0,f0; stfs f0,0x30(29); lwz 0,-24192(30); stw 0,0x28(29); stw 29,-24192(30); lwz 9,-24188(30); addi 9,9,1; stw 9,-24188(30); lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"

extern "C" void _s802363E0_0();
extern "C" void _s802363E0_1();

struct ERLevel {
    void InsertInOrderTable_EOrderTableData();
};

void ERLevel::InsertInOrderTable_EOrderTableData() {
}
