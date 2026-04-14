// 0x80070808 SimModel::DeallocateAllModels(void) (68B)
// Pattern: 26-iteration loop calling DeallocateModel(i) — UNSIGNED counter (cmplwi)
struct SimModel {
    void DeallocateModel(int idx);
    void DeallocateAllModels();
};

void SimModel::DeallocateAllModels() {
    unsigned int i = 0;
    do {
        DeallocateModel(i);
        i++;
    } while (i <= 25u);
}
