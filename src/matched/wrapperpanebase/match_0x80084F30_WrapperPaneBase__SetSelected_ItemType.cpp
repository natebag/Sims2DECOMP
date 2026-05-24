// 0x80084F30 WrapperPaneBase::SetSelected(ItemType, (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 9,3,8; lwz 10,0x8(3); lwz 0,0x4(9); li 8,0; cmpw 10,0; beqlr; mr 3,9; 0:; lwz 9,0x0(10); lwz 0,0x0(9); cmpw 0,4; bne 2f; lwz 0,0x4(9); rlwinm 11,0,0,30,28; andi. 7,0,1; stw 11,0x4(9); beq 2f; cmpw 8,5; bne 1f; ori 0,11,4; stw 0,0x4(9); 1:; addi 8,8,1; 2:; lwz 0,0x4(3); addi 10,10,4; cmpw 10,0; bne 0b"

struct WrapperPaneBase {
    void SetSelected_ItemType();
};

void WrapperPaneBase::SetSelected_ItemType() {
}
