// 0x8001CAF8 (8 bytes)
class CameraDirector {
public:
    int GetFrameEffectsManager();
};

int CameraDirector::GetFrameEffectsManager() {
    return *(int*)((char*)this + 0x2D0);
}
