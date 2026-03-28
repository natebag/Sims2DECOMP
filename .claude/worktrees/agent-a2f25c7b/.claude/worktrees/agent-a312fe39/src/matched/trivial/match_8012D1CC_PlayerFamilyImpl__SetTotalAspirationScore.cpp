// 0x8012D1CC (8 bytes)
class PlayerFamilyImpl {
public:
    void SetTotalAspirationScore(int p);
};

void PlayerFamilyImpl::SetTotalAspirationScore(int p) {
    *(int*)((char*)this + 0xD60) = p;
}
