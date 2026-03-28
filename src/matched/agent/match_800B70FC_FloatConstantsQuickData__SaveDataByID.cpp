// 0x800B70FC (8 bytes) — li 3, 0; blr
// FloatConstantsQuickData::SaveDataByID(ObjectDataID &)

class FloatConstantsQuickData {
public:
    void SaveDataByID(ObjectDataID &);
};

__attribute__((naked))
void FloatConstantsQuickData::SaveDataByID(ObjectDataID &) {
    asm volatile(
        "li 3, 0
"
        "blr
"
    );
}
