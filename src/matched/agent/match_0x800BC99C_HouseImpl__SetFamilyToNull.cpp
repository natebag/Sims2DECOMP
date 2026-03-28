/* HouseImpl::SetFamilyToNull(void) at 0x800BC99C (12B) */

struct HouseImpl {
    char pad[0x14];
    void* m_family;

    void SetFamilyToNull(void);
};

void HouseImpl::SetFamilyToNull(void) {
    m_family = 0;
}
