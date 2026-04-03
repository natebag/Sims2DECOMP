// 0x8022E284 (8 bytes)
class EIStaticModel {
public:
    int GetDrawMatrix();
};

int EIStaticModel::GetDrawMatrix() {
    return (int)((char*)this + 0x80);
}
