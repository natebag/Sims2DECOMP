// 0x80164FDC CasNpcEditor::GetCostume (80b)

struct Costume;
extern Costume* g_costumes;

struct CasNpcEditor {
    Costume* GetCostume(unsigned int index);
};

Costume* GetCostumeByIndex(Costume* base, int category, int index);

Costume* CasNpcEditor::GetCostume(unsigned int index) {
    if (index < 0xA1) {
        int category = 1;
        int adjustedIndex = index;
        if (index >= 0x50) {
            adjustedIndex = index - 0x51;
            category = 0;
        }
        return GetCostumeByIndex(g_costumes, category, adjustedIndex);
    }
    return 0;
}
