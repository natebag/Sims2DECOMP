// 0x80053DD8 (8 bytes)
class ISimsObjectModel {
public:
    int GetPos();
};

int ISimsObjectModel::GetPos() {
    return (int)((char*)this + 0x404);
}
