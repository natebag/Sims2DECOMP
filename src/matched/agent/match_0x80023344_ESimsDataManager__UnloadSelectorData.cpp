// 0x80023344 ESimsDataManager::UnloadSelectorData(ObjSelector*, bool) (128B)

struct ObjSelector {
    char pad[156];
    int m_f156;          // offset 156
    int m_f160;          // offset 160
};

struct ESimsDataManager {
    char pad[3360];
    int m_f3360;          // offset 3360
    char pad2[12];
    ObjSelector* m_f3376; // offset 3376
    void UnloadSelectorData(ObjSelector* sel, bool arg);
};

extern void* g_unloadMgr;  // SDA @ -22652

extern "C" void ESDM_DoUnload(ESimsDataManager* self, ObjSelector* sel);  // 0x800233c4

void ESimsDataManager::UnloadSelectorData(ObjSelector* sel, bool arg) {
    sel->m_f156 = 0;
    if (m_f3360 == 0 && sel->m_f160 == 0) return;
    if (m_f3376 == sel) {
        void* mgr = g_unloadMgr;
        int* vt = *(int**)mgr;
        short adj = *(short*)((char*)vt + 56);
        void (*fn)(void*) = (void (*)(void*))*(void**)((char*)vt + 60);
        fn((char*)mgr + adj);
    }
    ESDM_DoUnload(this, sel);
}
