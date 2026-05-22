// 0x800F1264 ObjectFolderImpl::GetTypeAttrBlock(int) (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x664(3); lwz 9,0x660(3); cmpw 9,0; beq 1f; mr 11,0; 0:; lwz 3,0x0(9); lwz 0,0x0(3); cmpw 0,4; beqlr; addi 9,9,4; cmpw 9,11; bne 0b; 1:; li 3,0"
extern "C" int f_800F1264() {}
