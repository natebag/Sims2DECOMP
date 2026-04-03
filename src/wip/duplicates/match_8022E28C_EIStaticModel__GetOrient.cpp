// 0x8022E28C (8 bytes)
class EIStaticModel {
public:
    int GetOrient();
};

int EIStaticModel::GetOrient() {
    return (int)((char*)this + 0xC0);
}
