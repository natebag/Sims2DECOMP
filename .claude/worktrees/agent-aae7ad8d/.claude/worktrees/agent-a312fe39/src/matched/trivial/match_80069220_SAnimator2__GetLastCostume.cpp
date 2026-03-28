// 0x80069220 (8 bytes)
class SAnimator2 {
public:
    int GetLastCostume();
};

int SAnimator2::GetLastCostume() {
    return *(int*)((char*)this + 0x130);
}
