// 0x8031B428 (8 bytes)
class ERModel {
public:
    int IsHierarchical();
};

int ERModel::IsHierarchical() {
    return *(int*)((char*)this + 0x14);
}
