// 0x80324780 (8 bytes)
class EDatasetManager {
public:
    void SetLoadProgress(float p);
};

void EDatasetManager::SetLoadProgress(float p) {
    *(float*)((char*)this + 0xD20) = p;
}
