// 0x800BC994 HouseImpl::GetFurnishingsScoreCurve (8B)
struct HouseImpl {
    char pad[32];
    void* m_furnishingsScoreCurve;
    void* GetFurnishingsScoreCurve();
};

void* HouseImpl::GetFurnishingsScoreCurve() { return m_furnishingsScoreCurve; }
