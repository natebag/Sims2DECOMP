class HouseImpl {
public:
    char pad[0x20];
    void *m_furnishingsScoreCurve;

    void *GetFurnishingsScoreCurve(void);
};

void *HouseImpl::GetFurnishingsScoreCurve(void) {
    return m_furnishingsScoreCurve;
}
