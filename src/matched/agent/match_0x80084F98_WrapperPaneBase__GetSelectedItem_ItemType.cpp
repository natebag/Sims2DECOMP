// 0x80084F98 WrapperPaneBase::GetSelectedItem(ItemType) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0xc(3); lwz 9,0x8(3); cmpw 9,0; beq 2f; mr 11,0; 0:; lwz 3,0x0(9); lwz 0,0x0(3); cmpw 0,4; bne 1f; lwz 0,0x4(3); andi. 10,0,4; bnelr; 1:; addi 9,9,4; cmpw 9,11; bne 0b; 2:; li 3,0"
extern "C" int f_80084F98() {}
