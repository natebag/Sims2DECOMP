// 0x80053D9C (8 bytes)
class ISimsObjectModel {
public:
    int GetShadow();
};

int ISimsObjectModel::GetShadow() {
    return *(int*)((char*)this + 0x44C);
}
