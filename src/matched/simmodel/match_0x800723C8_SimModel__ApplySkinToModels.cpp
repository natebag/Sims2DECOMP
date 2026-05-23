// 0x800723C8 SimModel::ApplySkinToModels(void) (68B)
// Pattern: 26-iteration loop calling ApplySkinModel(i) — SIGNED counter (cmpwi)
struct SimModel {
    void ApplySkinModel(int idx);
    void ApplySkinToModels();
};

void SimModel::ApplySkinToModels() {
    int i = 0;
    do {
        ApplySkinModel(i);
        i++;
    } while (i <= 25);
}
