// 0x80329508 ImageProcessingManager::SetStageCallback(int, void (*)(ETexture *)) (20B)

struct ETexture;

struct ImageProcessingStageEntry {
    int field00;
    void (*callback)(ETexture*);
    int pad[7];
};

extern ImageProcessingStageEntry* g_stages;

class ImageProcessingManager {
public:
    static void SetStageCallback(int idx, void (*cb)(ETexture*));
};

void ImageProcessingManager::SetStageCallback(int idx, void (*cb)(ETexture*)) {
    g_stages[idx].callback = cb;
}
