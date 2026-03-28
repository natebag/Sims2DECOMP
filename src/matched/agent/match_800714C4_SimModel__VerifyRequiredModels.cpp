// 0x800714C4 (8 bytes) — li 3, 1; blr
// SimModel::VerifyRequiredModels(void) const

class SimModel {
public:
    void VerifyRequiredModels(void) const;
};

__attribute__((naked))
void SimModel::VerifyRequiredModels(void) const {
    asm volatile(
        "li 3, 1
"
        "blr
"
    );
}
