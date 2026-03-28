/* HouseImpl::GetFurnishingsScoreCurve(void) at 0x800BC994 (8B) */

struct HouseImpl {
    char pad[0x20];
    void* m_furnishingsScoreCurve;

    void* GetFurnishingsScoreCurve(void);
};

void* HouseImpl::GetFurnishingsScoreCurve(void) {
    return m_furnishingsScoreCurve;
}
