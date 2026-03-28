// 0x800B7174 (8 bytes) — li 3, 1; blr
// FloatConstantsQuickData::GetDataSourceType(void) const

class FloatConstantsQuickData {
public:
    void GetDataSourceType(void) const;
};

__attribute__((naked))
void FloatConstantsQuickData::GetDataSourceType(void) const {
    asm volatile(
        "li 3, 1\n"
        "blr\n"
    );
}
