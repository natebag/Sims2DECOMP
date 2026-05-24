// 0x80209378 SpriteSlot::GetOptions(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_802093A4" lines="stw 11,0x34(3)"

struct SpriteSlot {
    void GetOptions();
};

void SpriteSlot::GetOptions() {
}
