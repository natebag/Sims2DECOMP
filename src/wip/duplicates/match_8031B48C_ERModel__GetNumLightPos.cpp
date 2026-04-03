// 0x8031B48C (8 bytes)
class ERModel {
public:
    int GetNumLightPos();
};

int ERModel::GetNumLightPos() {
    return *(int*)((char*)this + 0x140);
}
