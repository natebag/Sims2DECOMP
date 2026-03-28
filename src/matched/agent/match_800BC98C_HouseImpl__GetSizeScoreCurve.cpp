class HouseImpl {
public:
    char pad[0x1C];
    void *m_sizeScoreCurve;

    void *GetSizeScoreCurve(void);
};

void *HouseImpl::GetSizeScoreCurve(void) {
    return m_sizeScoreCurve;
}
