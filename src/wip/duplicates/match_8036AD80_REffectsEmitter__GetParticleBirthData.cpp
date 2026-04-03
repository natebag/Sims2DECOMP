// 0x8036AD80 (8 bytes)
class REffectsEmitter {
public:
    int GetParticleBirthData();
};

int REffectsEmitter::GetParticleBirthData() {
    return *(int*)((char*)this + 0x18);
}
