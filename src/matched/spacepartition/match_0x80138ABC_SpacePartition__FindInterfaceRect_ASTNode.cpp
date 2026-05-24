// 0x80138ABC SpacePartition::FindInterfaceRect(ASTNode (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 25,0x1c(1); stw 0,0x3c(1); lwz 11,0x4(4); mr 29,3; lwz 8,0xc(29); addi 30,1,8; mulli 11,11,20; mr 3,6; mr 4,30; lwzx 10,8,11; add 9,8,11; lwz 7,0xc(9); lwz 11,0x4(9); addi 25,10,-1; lwz 8,0x8(9); addi 27,7,1; stw 11,0x4(6); addi 28,11,-1; stw 8,0x8(6); addi 26,8,1; stw 7,0xc(6); stw 10,0x0(6); lwz 9,0x4(5); lwz 8,0xc(29); mr 5,3; mulli 9,9,20; lwzx 7,8,9; add 11,8,9; lwz 10,0xc(11); lwz 9,0x4(11); lwz 0,0x8(11); addi 10,10,1; stw 7,0x8(1); addi 9,9,-1; stw 0,0x8(30); stw 9,0x4(30); stw 10,0xc(30); stw 28,0x4(6); stw 25,0x0(6); lwz 9,0x8(1); stw 27,0xc(6); addi 9,9,-1; stw 9,0x8(1); stw 26,0x8(6); lwz 9,0x8(30); addi 9,9,1; stw 9,0x8(30); bl _s80138ABC_0; lwz 0,0x3c(1); mtspr 8,0; lmw 25,0x1c(1); addi 1,1,56"

extern "C" void _s80138ABC_0();

struct SpacePartition {
    void FindInterfaceRect_ASTNode();
};

void SpacePartition::FindInterfaceRect_ASTNode() {
}
