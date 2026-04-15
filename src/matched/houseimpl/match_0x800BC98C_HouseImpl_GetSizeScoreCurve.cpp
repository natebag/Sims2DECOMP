// 0x800BC98C HouseImpl::GetSizeScoreCurve (8B)
struct HouseImpl {
    char pad[28];
    void* m_sizeScoreCurve;
    void* GetSizeScoreCurve();
};

void* HouseImpl::GetSizeScoreCurve() { return m_sizeScoreCurve; }
