// 0x8031B430 (8 bytes)
class ERModel {
public:
    int IsWeldable();
};

int ERModel::IsWeldable() {
    return *(int*)((char*)this + 0x20);
}
