// 0x8012D1BC (8 bytes)
class PlayerFamilyImpl {
public:
    int GetGoalAndUnlockData();
};

int PlayerFamilyImpl::GetGoalAndUnlockData() {
    return (int)((char*)this + 0xCDC);
}
