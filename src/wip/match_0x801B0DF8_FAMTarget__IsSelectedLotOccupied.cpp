// 0x801B0DF8 FAMTarget::IsSelectedLotOccupied(void) (116B)

class FAMTarget {
public:
    char pad_000[332];
    int  m_selectedLotIdx;     // 332
    int IsSelectedLotOccupied();
    int ConvertSelectedLotIndexToActualGameIndex(int idx);
    int GetNumberOfFamilyMembers(void* family);
};

class INeighborhood {
public:
    virtual void V0(); virtual void V1(); virtual void V2(); virtual void V3();
    virtual void V4(); virtual void V5(); virtual void V6(); virtual void V7();
    virtual void V8(); virtual void V9(); virtual void V10(); virtual void V11();
    virtual void V12(); virtual void V13(); virtual void V14(); virtual void V15();
    virtual void V16(); virtual void V17(); virtual void V18(); virtual void V19();
    virtual void V20(); virtual void V21(); virtual void V22(); virtual void V23();
    virtual void V24(); virtual void V25(); virtual void V26(); virtual void V27();
    virtual void V28(); virtual void V29(); virtual void V30(); virtual void V31();
    virtual void V32(); virtual void V33(); virtual void V34(); virtual void V35();
    virtual void* GetFamilyAtLot(int idx);  // slot 37 (offset 296)
};

extern INeighborhood** g_neigh;  // SDA -21476

int FAMTarget::IsSelectedLotOccupied() {
    int idx = ConvertSelectedLotIndexToActualGameIndex(m_selectedLotIdx);
    INeighborhood* nb = *g_neigh;
    void* family = nb->GetFamilyAtLot(idx);
    if (family == 0) return 0;
    return GetNumberOfFamilyMembers(family) > 0 ? 1 : 0;
}
