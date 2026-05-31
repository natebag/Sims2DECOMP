// FLAGS: -fno-schedule-insns
// 0x8031229C EResource::GetResSize(void) (12B)
// lwz r3,0x10(3); srwi r3,r3,8; blr  -- m_sizeField >> 8
struct EResource {
    char pad[0x10];
    unsigned m_sizeField;   // 0x10
    unsigned GetResSize();
};

unsigned EResource::GetResSize() {
    return m_sizeField >> 8;
}
