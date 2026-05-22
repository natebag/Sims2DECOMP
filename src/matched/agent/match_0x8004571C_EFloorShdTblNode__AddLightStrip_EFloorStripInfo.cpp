// 0x8004571C EFloorShdTblNode::AddLightStrip(EFloorStripInfo) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); lbz 0,0x0(3); lis 9,-32696; lwz 11,0x0(3); addi 9,9,-28520; mulli 0,0,12; mr 4,11; stw 11,0x8(1); add 3,0,9; bl _s8004571C_0; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s8004571C_0();
extern "C" void f_8004571C() {}
