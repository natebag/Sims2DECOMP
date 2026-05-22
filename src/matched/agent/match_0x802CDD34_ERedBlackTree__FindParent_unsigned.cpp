// 0x802CDD34 ERedBlackTree::FindParent(unsigned (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x8(3); lis 9,-32700; addi 9,9,-4812; li 3,0; cmpw 0,9; beqlr; 0:; mr 3,0; lwz 0,0x18(3); cmplw 4,0; bge 1f; lwz 0,0x0(3); b 2f; 1:; lwz 0,0x4(3); 2:; cmpw 0,9; bne 0b"
extern "C" int f_802CDD34() {}
