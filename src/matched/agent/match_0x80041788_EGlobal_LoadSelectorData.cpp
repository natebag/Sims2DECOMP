// EGlobal::LoadSelectorData(ObjSelector *, bool)
// Address: 0x80041788 | Size: 40 bytes

struct EGlobal;
extern EGlobal g_eGlobal;  // SDA global at 0x80473968

extern void LoadSelectorData(EGlobal* global);

// Thunk - ignores parameters, uses global
void EGlobal_LoadSelectorData() {
    LoadSelectorData(&g_eGlobal);
}
