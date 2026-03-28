/* HouseImpl::GetFamily(void) at 0x800BC984 (8B) */

struct HouseImpl {
    char pad[0x14];
    void* m_family;

    void* GetFamily(void);
};

void* HouseImpl::GetFamily(void) {
    return m_family;
}
