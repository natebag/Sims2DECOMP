// 0x8036C308 (8 bytes)
class RParticle {
public:
    int GetData();
};

int RParticle::GetData() {
    return *(int*)((char*)this + 0x14);
}
