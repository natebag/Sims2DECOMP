// 0x8036AD78 (8 bytes)
class REffectsEmitter {
public:
    int GetEmitterInitData();
};

int REffectsEmitter::GetEmitterInitData() {
    return *(int*)((char*)this + 0x14);
}
