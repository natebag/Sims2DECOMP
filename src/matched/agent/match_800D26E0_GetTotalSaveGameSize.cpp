// 0x800D26E0 (12 bytes) - GetTotalSaveGameSize(void)
// lis r9,upper; lwz r3,lower(r9); blr

struct SaveData_SZ { int data[4]; };
extern SaveData_SZ g_saveGameSize;

int GetTotalSaveGameSize() {
    return g_saveGameSize.data[3];
}
