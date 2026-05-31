// FLAGS: -fno-schedule-insns
// 0x80329508 ImageProcessingManager::SetStageCallback(int, void(*)(ETexture*)) (20B)
// mulli r3,r3,36; lwz r0,gImageStageBase(13); add r3,r3,r0; stw r4,4(r3); blr
//   gImageStageBase[idx].callback = cb  (36B stride, callback @+4)
class ETexture;
extern char* gImageStageBase;

class ImageProcessingManager {
public:
    static void SetStageCallback(int idx, void (*cb)(ETexture*));
};

void ImageProcessingManager::SetStageCallback(int idx, void (*cb)(ETexture*)) {
    char* p = (char*)((unsigned)(idx * 36) + (unsigned)gImageStageBase);
    *(void**)(p + 4) = (void*)cb;
}
