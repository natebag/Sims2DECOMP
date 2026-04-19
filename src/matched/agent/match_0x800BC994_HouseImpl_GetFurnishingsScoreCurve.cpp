// 0x800BC994 (8B) HouseImpl::GetFurnishingsScoreCurve(void)
// Getter for field at offset 0x20.

class HouseImpl {
public:
    char pad_000[0x20];
    int m_field_20;
    int GetFurnishingsScoreCurve(void);
};

int HouseImpl::GetFurnishingsScoreCurve(void) {
    return m_field_20;
}
