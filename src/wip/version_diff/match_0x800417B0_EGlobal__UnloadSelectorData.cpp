// EGlobal::UnloadSelectorData(ObjSelector *)
// Address: 0x800417B0 | Size: 44 bytes
// FLAGS: -fno-elide-constructors

struct ObjSelector;
struct EGlobal;

extern EGlobal g_eGlobal;
extern void EGlobal_UnloadSelectorData(EGlobal *data, ObjSelector *sel, int flag);

void EGlobal__UnloadSelectorData(ObjSelector *sel) {
    EGlobal_UnloadSelectorData(&g_eGlobal, sel, 1);
}
