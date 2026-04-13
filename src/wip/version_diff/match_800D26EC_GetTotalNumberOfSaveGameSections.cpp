// 0x800D26EC (12 bytes) - GetTotalNumberOfSaveGameSections(void)
// lis r9,upper; lwz r3,lower(r9); blr

struct SaveData_NS { int data[4]; };
extern SaveData_NS g_saveGameSections;

int GetTotalNumberOfSaveGameSections() {
    return g_saveGameSections.data[3];
}
