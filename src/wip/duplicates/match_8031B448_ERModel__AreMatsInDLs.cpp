// 0x8031B448 (8 bytes)
class ERModel {
public:
    int AreMatsInDLs();
};

int ERModel::AreMatsInDLs() {
    return *(int*)((char*)this + 0x8C);
}
