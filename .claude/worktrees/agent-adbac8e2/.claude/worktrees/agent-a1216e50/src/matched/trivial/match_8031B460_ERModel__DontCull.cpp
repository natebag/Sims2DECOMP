// 0x8031B460 (8 bytes)
class ERModel {
public:
    int DontCull();
};

int ERModel::DontCull() {
    return *(int*)((char*)this + 0x2C);
}
