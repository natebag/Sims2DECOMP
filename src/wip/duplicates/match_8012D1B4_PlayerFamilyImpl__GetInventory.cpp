// 0x8012D1B4 (8 bytes)
class PlayerFamilyImpl {
public:
    int GetInventory();
};

int PlayerFamilyImpl::GetInventory() {
    return (int)((char*)this + 0x38);
}
