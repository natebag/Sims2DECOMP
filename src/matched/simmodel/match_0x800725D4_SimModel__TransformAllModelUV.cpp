// 0x800725D4 SimModel::TransformAllModelUV(void) (68B)
// Pattern: 26-iteration loop (signed cmpwi) — family match with ApplySkinToModels
struct SimModel {
    void TransformModelUV(int idx);
    void TransformAllModelUV();
};

void SimModel::TransformAllModelUV() {
    int i = 0;
    do {
        TransformModelUV(i);
        i++;
    } while (i <= 25);
}
