struct EResource {
    ~EResource();
    static void Destruct(EResource* obj);
};

void EResource::Destruct(EResource* obj) {
    obj->~EResource();
}
