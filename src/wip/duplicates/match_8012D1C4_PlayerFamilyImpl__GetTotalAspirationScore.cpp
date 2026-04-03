// 0x8012D1C4 (8 bytes)
class PlayerFamilyImpl {
public:
    int GetTotalAspirationScore();
};

int PlayerFamilyImpl::GetTotalAspirationScore() {
    return *(int*)((char*)this + 0xD60);
}
