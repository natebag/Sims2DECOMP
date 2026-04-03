// 0x802274FC (8 bytes)
class EIDirLight {
public:
    int GetDir();
};

int EIDirLight::GetDir() {
    return (int)((char*)this + 0xAC);
}
