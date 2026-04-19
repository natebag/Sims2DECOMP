// 0x800BC984 (8B) HouseImpl::GetFamily(void)
// Getter for field at offset 0x14.

class HouseImpl {
public:
    char pad_000[0x14];
    int m_field_14;
    int GetFamily(void);
};

int HouseImpl::GetFamily(void) {
    return m_field_14;
}
