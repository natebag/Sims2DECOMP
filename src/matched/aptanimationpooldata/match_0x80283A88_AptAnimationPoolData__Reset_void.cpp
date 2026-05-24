// 0x80283A88 AptAnimationPoolData::Reset(void) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-22936(13); li 9,0; stw 9,0x94(3); stw 0,0x60(3); stw 9,0x4(3); stw 9,0x34(3); stw 9,0x64(3); stw 9,0x68(3); stw 9,0x10(3); stw 9,0x6c(3); stw 9,0x70(3); stw 9,0x30(3); stw 0,0x3c(3); stw 0,0x58(3); stw 0,0x5c(3)"

struct AptAnimationPoolData {
    void Reset();
};

void AptAnimationPoolData::Reset() {
}
