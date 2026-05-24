// 0x801397D0 SpacePartition::GetNthSuccessor(int, (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; mr 31,5; bl _s801397D0_0; cmpwi 31,0; blt 0f; cmpw 31,3; bge 0f; mr 4,29; mr 3,30; bl _s801397D0_1; mr. 3,3; bne 1f; 0:; li 3,-1; b 2f; 1:; lwz 9,0xc(3); lwz 11,0x3c(30); add 9,9,31; rlwinm 9,9,2,0,29; lwzx 3,11,9; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s801397D0_0();
extern "C" void _s801397D0_1();

struct SpacePartition {
    void GetNthSuccessor();
};

void SpacePartition::GetNthSuccessor() {
}
