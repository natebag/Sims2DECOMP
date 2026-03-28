struct EOrderTableData;

struct ERLevel {
    char pad0[0x2E2EC];
    EOrderTableData *m_dofForegroundList;

    void DrawOrderTableSlot(EOrderTableData *);
    void DrawDOFForegroundObjects(void);
};

void ERLevel::DrawDOFForegroundObjects(void) {
    DrawOrderTableSlot(m_dofForegroundList);
}
