// 0x8031B458 (8 bytes)
class ERModel {
public:
    int DontInterestFade();
};

int ERModel::DontInterestFade() {
    return *(int*)((char*)this + 0x28);
}
