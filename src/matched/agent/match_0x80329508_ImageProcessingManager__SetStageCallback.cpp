// 0x80329508 ImageProcessingManager::SetStageCallback(int, void (*)(ETexture*)) (20B)
//
// Static method writing a callback ptr into a stage-indexed slot of the
// global gImageStageBase array (36-byte stride, callback at +4).
//
// WALL CLASS: register-allocation 3-way relabel
//   DOL uses r0 for the SDA base load + r3 as the result accumulator
//   (add r3, r3, r0; stw r4, 4(r3)). GCC uses r9 for both (lwz r9, ...;
//   add r9, r9, r3; stw r4, 4(r9)). Three insns differ, all rewriteable
//   via direct substring substitution.
//
// Recipe (3 replace_insn directives, no new mutator):
//   1. lwz 9,gImageStageBase@sda21(0) -> lwz 0,...      (dest r9 -> r0)
//   2. add 9,9,3 -> add 3,3,0                            (whole-line operand rewrite)
//   3. stw 4,4(9) -> stw 4,4(3)                          (base r9 -> r3)
//
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
