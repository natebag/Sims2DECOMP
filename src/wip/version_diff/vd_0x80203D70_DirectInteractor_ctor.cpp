struct Interactor {
    char pad[92];
    void* field_5C;
    
    Interactor();
};

struct DirectInteractor : public Interactor {
    char pad0[4];
    int field_64;
    char pad1[8];
    int field_70;
    float field_74;
    int field_78;
    int field_7C;
    int field_80;
    
    DirectInteractor();
};

extern float gDirectInteractorFloat;

DirectInteractor::DirectInteractor() : Interactor() {
    field_5C = (void*)0x804680A0;
    field_64 = 1;
    field_74 = gDirectInteractorFloat;
    field_80 = 0;
    field_70 = 0;
    field_78 = 0;
    field_7C = 0;
}
