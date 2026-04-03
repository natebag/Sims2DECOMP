// 0x8031B494 (8 bytes)
class ERModel {
public:
    int GetLightPos();
};

int ERModel::GetLightPos() {
    return (int)((char*)this + 0x144);
}
