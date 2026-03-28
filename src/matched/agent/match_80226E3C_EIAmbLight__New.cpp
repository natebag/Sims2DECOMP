typedef unsigned int size_t;

void* operator new(size_t);

extern int EIAmbLight_vtable[];

void EILight_ctor(void*);

struct EIAmbLight {
    static EIAmbLight* New();
};

EIAmbLight* EIAmbLight::New() {
    EIAmbLight* p = (EIAmbLight*)operator new(0xAC);
    EILight_ctor(p);
    *(int**)p = EIAmbLight_vtable;
    return p;
}
