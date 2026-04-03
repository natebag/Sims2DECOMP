// 0x80053E30 (8 bytes)
class ISimsObjectModel {
public:
    void SetRot(float p);
};

void ISimsObjectModel::SetRot(float p) {
    *(float*)((char*)this + 0x3F0) = p;
}
