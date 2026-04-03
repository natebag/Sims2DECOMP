// 0x80318B08 (8 bytes)
class ERModel {
public:
    int GetDummyCount();
};

int ERModel::GetDummyCount() {
    return *(int*)((char*)this + 0x120);
}
