// 0x80085034 WrapperPaneBase::GetItem(ItemType, (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0xc(3); li 11,0; lwz 9,0x8(3); cmpw 9,0; beq 2f; mr 10,0; 0:; lwz 3,0x0(9); lwz 0,0x0(3); cmpw 0,4; bne 1f; cmpw 11,5; beqlr; addi 11,11,1; 1:; addi 9,9,4; cmpw 9,10; bne 0b; 2:; li 3,0"
extern "C" int f_80085034() {}
