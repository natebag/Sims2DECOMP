// 0x8032471C (8 bytes)
class EDatasetManager {
public:
    float GetLoadProgress();
};

float EDatasetManager::GetLoadProgress() {
    return *(float*)((char*)this + 0xD20);
}
