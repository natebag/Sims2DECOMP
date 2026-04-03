// 0x80318B00 (8 bytes)
class ERModel {
public:
    int GetLatticeCount();
};

int ERModel::GetLatticeCount() {
    return *(int*)((char*)this + 0x114);
}
