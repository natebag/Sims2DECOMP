// 0x8036AD90 (8 bytes)
class REffectsEmitter {
public:
    int Refreshed();
};

int REffectsEmitter::Refreshed() {
    return *(int*)((char*)this + 0x20);
}
