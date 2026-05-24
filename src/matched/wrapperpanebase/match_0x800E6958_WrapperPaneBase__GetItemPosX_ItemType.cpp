// 0x800E6958 WrapperPaneBase::GetItemPosX(ItemType, (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_800E7748" lines="addi 3,3,-20132; bl _s800E6958_0; bl _s800E6958_1; rlwinm 11,0,29,3,29; li 10,1; lwzx 9,28,11; rlwinm 0,0,0,27,31; slw 0,10,0; or 9,9,0; stwx 9,28,11; stw 28,0x48(1); lwz 0,0x0(25); stw 29,0x4c(1); stw 0,0x50(1); stw 24,0x54(1); stw 10,0x58(1); stw 28,0x60(1); stw 29,0x64(1); stw 0,0x68(1); stw 24,0x6c(1); lwz 9,0x4(20); lwz 0,0x48(1); lwz 11,0x8(20); lwz 10,0xc(20); stw 9,0x4(18); stw 0,0x8(1); stw 11,0x8(18); stw 10,0xc(18); lwz 0,0x10(20); stw 0,0x10(18)"

extern "C" void _s800E6958_0();
extern "C" void _s800E6958_1();

struct WrapperPaneBase {
    void GetItemPosX_ItemType();
};

void WrapperPaneBase::GetItemPosX_ItemType() {
}
