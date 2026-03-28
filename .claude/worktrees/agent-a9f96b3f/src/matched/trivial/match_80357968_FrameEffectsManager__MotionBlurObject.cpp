// 0x80357968 (8 bytes)
class FrameEffectsManager {
public:
    int MotionBlurObject();
};

int FrameEffectsManager::MotionBlurObject() {
    return *(int*)((char*)this + 0x0);
}
