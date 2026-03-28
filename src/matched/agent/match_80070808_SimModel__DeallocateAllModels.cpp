typedef int eBodyPartS2C;

struct SimModel {
    void DeallocateModelPart(eBodyPartS2C part);
    void DeallocateAllModels();
};

void SimModel::DeallocateAllModels() {
    unsigned int i = 0;
    do {
        DeallocateModelPart((eBodyPartS2C)i);
        i++;
    } while (i <= 25);
}
