// 0x800B7204 (8 bytes) — li 3, 0; blr
// FloatConstantsQuickData::LoadOnlyNameAndIDFromIndex(unsigned int, int)

class FloatConstantsQuickData {
public:
    void LoadOnlyNameAndIDFromIndex(unsigned int, int);
};

__attribute__((naked))
void FloatConstantsQuickData::LoadOnlyNameAndIDFromIndex(unsigned int, int) {
    asm volatile(
        "li 3, 0
"
        "blr
"
    );
}
