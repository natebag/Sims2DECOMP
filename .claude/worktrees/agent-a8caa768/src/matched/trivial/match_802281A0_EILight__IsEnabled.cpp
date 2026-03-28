// 0x802281A0 (8 bytes)
class EILight {
public:
    int IsEnabled();
};

int EILight::IsEnabled() {
    return *(int*)((char*)this + 0x88);
}
