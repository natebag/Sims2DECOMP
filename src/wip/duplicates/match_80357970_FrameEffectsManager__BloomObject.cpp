// 0x80357970 (8 bytes)
class FrameEffectsManager {
public:
    int BloomObject();
};

int FrameEffectsManager::BloomObject() {
    return *(int*)((char*)this + 0x4);
}
