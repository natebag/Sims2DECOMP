// 0x800BC984 (8 bytes)
class HouseImpl {
public:
    int GetFamily();
};

int HouseImpl::GetFamily() {
    return *(int*)((char*)this + 0x14);
}
