// 0x8022DAE8 (8 bytes)
class EIStaticModel {
public:
    int GetModifiableColor();
};

int EIStaticModel::GetModifiableColor() {
    return *(int*)((char*)this + 0x114);
}
