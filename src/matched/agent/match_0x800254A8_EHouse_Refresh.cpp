// 0x800254A8 (40B) EHouse::Refresh(void)
// Thin wrapper: call EResourceManager::MakeSpace on global mgr.
// Member function (this unused).

extern char gEResourceManager[];

struct EResourceManager_EH {
    void MakeSpace();
};

struct EHouse_R {
    void Refresh();
};

void EHouse_R::Refresh() {
    ((EResourceManager_EH*)gEResourceManager)->MakeSpace();
}
