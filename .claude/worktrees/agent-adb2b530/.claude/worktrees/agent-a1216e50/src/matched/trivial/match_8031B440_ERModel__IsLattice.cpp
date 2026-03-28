// 0x8031B440 (8 bytes)
class ERModel {
public:
    int IsLattice();
};

int ERModel::IsLattice() {
    return *(int*)((char*)this + 0x34);
}
