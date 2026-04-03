// 0x80053E28 (8 bytes)
class ISimsObjectModel {
public:
    float GetRot();
};

float ISimsObjectModel::GetRot() {
    return *(float*)((char*)this + 0x3F0);
}
