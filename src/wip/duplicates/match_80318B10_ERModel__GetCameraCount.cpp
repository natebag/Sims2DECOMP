// 0x80318B10 (8 bytes)
class ERModel {
public:
    int GetCameraCount();
};

int ERModel::GetCameraCount() {
    return *(int*)((char*)this + 0x12C);
}
