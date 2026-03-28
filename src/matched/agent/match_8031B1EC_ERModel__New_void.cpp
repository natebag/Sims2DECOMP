typedef unsigned int size_t;

struct ERModel {
    char pad[384];
    void* operator new(size_t);
    ERModel();
    static ERModel* New();
};

ERModel* ERModel::New() {
    return new ERModel();
}
