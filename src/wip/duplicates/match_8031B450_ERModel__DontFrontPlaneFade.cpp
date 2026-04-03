// 0x8031B450 (8 bytes)
class ERModel {
public:
    int DontFrontPlaneFade();
};

int ERModel::DontFrontPlaneFade() {
    return *(int*)((char*)this + 0x24);
}
