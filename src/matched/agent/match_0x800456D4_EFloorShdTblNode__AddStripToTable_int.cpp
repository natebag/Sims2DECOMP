// 0x800456D4 EFloorShdTblNode::AddStripToTable(int, (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); lwz 0,0x0(4); lis 9,-32696; addi 9,9,-29668; rlwinm 3,3,4,0,27; add 3,3,9; mr 4,0; stw 0,0x8(1); bl _s800456D4_0; lwz 9,-32496(13); addi 9,9,1; stw 9,-32496(13); lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s800456D4_0();
extern "C" void f_800456D4() {}
