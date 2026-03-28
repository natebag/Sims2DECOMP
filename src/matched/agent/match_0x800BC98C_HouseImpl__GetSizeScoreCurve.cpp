/* HouseImpl::GetSizeScoreCurve(void) at 0x800BC98C (8B) */

struct HouseImpl {
    char pad[0x1C];
    void* m_sizeScoreCurve;

    void* GetSizeScoreCurve(void);
};

void* HouseImpl::GetSizeScoreCurve(void) {
    return m_sizeScoreCurve;
}
