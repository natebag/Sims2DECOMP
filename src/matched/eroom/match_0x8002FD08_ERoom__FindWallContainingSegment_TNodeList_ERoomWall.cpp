// 0x8002FD08 ERoom::FindWallContainingSegment(TNodeList<ERoomWall (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lwz 31,0x0(4); mr 27,5; mr 28,6; mr 29,7; cmpwi 31,0; beq 2f; 0:; lwz 30,0x0(31); mr 4,27; mr 5,28; mr 6,29; mr 3,30; bl _s8002FD08_0; cmpwi 3,0; beq 1f; mr 3,30; b 3f; 1:; lwz 31,0x8(31); cmpwi 31,0; bne 0b; 2:; li 3,0; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s8002FD08_0();

struct ERoom {
    void FindWallContainingSegment_TNodeList_ERoomWall();
};

void ERoom::FindWallContainingSegment_TNodeList_ERoomWall() {
}
