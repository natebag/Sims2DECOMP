// 0x802CDCEC ERedBlackTree::FindKeyOrParent(unsigned (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x8(3); lis 9,-32700; addi 9,9,-4812; li 11,0; 0:; cmpw 3,9; beq 2f; lwz 0,0x18(3); cmpw 4,0; beqlr; mr 11,3; cmplw 4,0; bge 1f; lwz 3,0x0(11); b 0b; 1:; lwz 3,0x4(11); b 0b; 2:; mr 3,11"
extern "C" int f_802CDCEC() {}
