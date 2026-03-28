typedef int eBodyPartS2C;

struct SimModel {
    void TransformModelPartUV(eBodyPartS2C part);
    void TransformAllModelUV();
};

void SimModel::TransformAllModelUV() {
    int i = 0;
    do {
        TransformModelPartUV((eBodyPartS2C)i);
        i++;
    } while (i <= 25);
}
