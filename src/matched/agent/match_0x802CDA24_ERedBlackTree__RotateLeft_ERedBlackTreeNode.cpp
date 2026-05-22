// 0x802CDA24 ERedBlackTree::RotateLeft(ERedBlackTreeNode (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x4(4); lis 9,-32700; addi 9,9,-4812; lwz 0,0x0(11); stw 0,0x4(4); lwz 10,0x0(11); cmpw 10,9; beq 0f; stw 4,0x8(10); 0:; cmpw 11,9; beq 1f; lwz 0,0x8(4); stw 0,0x8(11); 1:; lwz 9,0x8(4); cmpwi 9,0; beq 3f; lwz 0,0x0(9); cmpw 4,0; bne 2f; stw 11,0x0(9); b 4f; 2:; stw 11,0x4(9); b 4f; 3:; stw 11,0x8(3); 4:; lis 9,-32700; stw 4,0x0(11); addi 9,9,-4812; cmpw 4,9; beqlr; stw 11,0x8(4)"
extern "C" void f_802CDA24() {}
