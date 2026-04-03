// 0x8022F590 (8 bytes)
class EIStaticSubModel {
public:
    int GetModifiableColor();
};

int EIStaticSubModel::GetModifiableColor() {
    return *(int*)((char*)this + 0x94);
}
