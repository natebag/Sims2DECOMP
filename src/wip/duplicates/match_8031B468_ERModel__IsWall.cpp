// 0x8031B468 (8 bytes)
class ERModel {
public:
    int IsWall();
};

int ERModel::IsWall() {
    return *(int*)((char*)this + 0x30);
}
