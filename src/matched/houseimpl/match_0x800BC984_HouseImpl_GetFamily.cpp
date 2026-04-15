// 0x800BC984 HouseImpl::GetFamily (8B)
struct HouseImpl {
    char pad[20];
    int* m_family;
    int* GetFamily();
};

int* HouseImpl::GetFamily() { return m_family; }
