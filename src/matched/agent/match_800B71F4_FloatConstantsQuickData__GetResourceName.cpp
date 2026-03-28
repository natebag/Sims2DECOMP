// 0x800B71F4 (8 bytes) — li 3, 0; blr
// FloatConstantsQuickData::GetResourceName(StringBuffer &) const

class StringBuffer;

class FloatConstantsQuickData {
public:
    void GetResourceName(StringBuffer &) const;
};

__attribute__((naked))
void FloatConstantsQuickData::GetResourceName(StringBuffer &) const {
    asm volatile(
        "li 3, 0\n"
        "blr\n"
    );
}
