// 0x80053E00 (8 bytes)
class ISimsObjectModel {
public:
    int GetDir();
};

int ISimsObjectModel::GetDir() {
    return (int)((char*)this + 0x410);
}
