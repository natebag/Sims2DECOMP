typedef unsigned int size_t;
void* operator new(size_t, void*);

struct ERModel {
    char pad[384];
    ERModel();
    static void Construct(ERModel* obj);
};

void ERModel::Construct(ERModel* obj) {
    new (obj) ERModel();
}
