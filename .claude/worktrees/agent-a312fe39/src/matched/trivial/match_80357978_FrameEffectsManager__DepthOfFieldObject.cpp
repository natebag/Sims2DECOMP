// 0x80357978 (8 bytes)
class FrameEffectsManager {
public:
    int DepthOfFieldObject();
};

int FrameEffectsManager::DepthOfFieldObject() {
    return *(int*)((char*)this + 0x8);
}
