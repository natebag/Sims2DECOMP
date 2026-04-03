// 0x8012D1AC (8 bytes)
class PlayerFamilyImpl {
public:
    int GetClothingUnlocks();
};

int PlayerFamilyImpl::GetClothingUnlocks() {
    return (int)((char*)this + 0xC8);
}
