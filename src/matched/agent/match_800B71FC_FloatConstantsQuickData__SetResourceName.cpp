// 0x800B71FC (8 bytes) — li 3, 0; blr
// FloatConstantsQuickData::SetResourceName(StringBuffer &)

class FloatConstantsQuickData {
public:
    void SetResourceName(StringBuffer &);
};

__attribute__((naked))
void FloatConstantsQuickData::SetResourceName(StringBuffer &) {
    asm volatile(
        "li 3, 0
"
        "blr
"
    );
}
