// 0x80053E38 (8 bytes)
class ISimsObjectModel {
public:
    int GetILight();
};

int ISimsObjectModel::GetILight() {
    return *(int*)((char*)this + 0x460);
}
