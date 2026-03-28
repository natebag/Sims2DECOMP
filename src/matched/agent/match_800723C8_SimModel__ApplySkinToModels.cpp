typedef int eBodyPartS2C;

struct SimModel {
    void ApplySkinToModelPart(eBodyPartS2C part);
    void ApplySkinToModels();
};

void SimModel::ApplySkinToModels() {
    int i = 0;
    do {
        ApplySkinToModelPart((eBodyPartS2C)i);
        i++;
    } while (i <= 25);
}
