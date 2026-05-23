// 0x8021E8A8 (64B) InteractorModule::SimInteractor::GetSelectionRadius(void)
// extern char[] SDA trick: *(float*)0x803fdd1c generates lis+ori+lfs (3-insn, 68B);
// extern char kDefaultSelRadius[] emits lis r9,@ha; lfs f1,@l(r9) (2-insn, 64B). Matches!

namespace InteractorModule {

extern float base_GetSelectionRadius();
extern char kDefaultSelRadius[]; // 0x803fdd1c

struct SimInteractor {
    char pad[0x214];
    int m_field_214;
    float GetSelectionRadius();
};

float SimInteractor::GetSelectionRadius() {
    float result = base_GetSelectionRadius();
    if (m_field_214 == 0) {
        result = *(float*)kDefaultSelRadius;
    }
    return result;
}

} // namespace InteractorModule
