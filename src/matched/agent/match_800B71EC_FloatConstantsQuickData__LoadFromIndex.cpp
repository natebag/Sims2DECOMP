// 0x800B71EC (8 bytes) — li 3, 0; blr
// FloatConstantsQuickData::LoadFromIndex(unsigned int, int)

class FloatConstantsQuickData {
public:
    void LoadFromIndex(unsigned int, int);
};

__attribute__((naked))
void FloatConstantsQuickData::LoadFromIndex(unsigned int, int) {
    asm volatile(
        "li 3, 0
"
        "blr
"
    );
}
