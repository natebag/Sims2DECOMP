// 0x80329508 ImageProcessingManager::SetStageCallback(int, void (*)(ETexture *)) (20B)
// ASMPROC_replace_insn: match="lwz 9,gImageStageBase@sda21(0)" replacement="lwz 0,gImageStageBase@sda21(0)"
// ASMPROC_replace_insn: match="add 9,9,3" replacement="add 3,3,0"
// ASMPROC_replace_insn: match="stw 4,4(9)" replacement="stw 4,4(3)"

class ETexture;
extern char* gImageStageBase;

class ImageProcessingManager {
public:
    static void SetStageCallback(int idx, void (*cb)(ETexture*));
};

void ImageProcessingManager::SetStageCallback(int idx, void (*cb)(ETexture*)) {
    char* p = gImageStageBase + idx * 36;
    *(void**)(p + 4) = (void*)cb;
}
