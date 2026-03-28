// 0x80228198 (8 bytes)
class EILight {
public:
    void Enable(int p);
};

void EILight::Enable(int p) {
    *(int*)((char*)this + 0x88) = p;
}
