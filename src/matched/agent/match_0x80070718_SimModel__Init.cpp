// 0x80070718 SimModel::Init(CasSimDescriptionS2C*, bool) (100B)
// Pattern: chained calls — Reset + Verify + operator new + ctor + SetHighRes + SetSimDescription
extern "C" void* __builtin_new(unsigned int size);

struct CasSimDescriptionS2C {
    void Verify();
};

struct CasSimPartsS2C {};
extern "C" void* CasSimPartsS2C_ctor(CasSimPartsS2C* self);

struct SimModel {
    char pad[312];
    CasSimPartsS2C* m_parts;
    void Reset();
    void SetHighResolution(bool b);
    void SetSimDescription(CasSimDescriptionS2C* d);
    void Init(CasSimDescriptionS2C* d, bool b);
};

void SimModel::Init(CasSimDescriptionS2C* d, bool b) {
    Reset();
    d->Verify();
    m_parts = (CasSimPartsS2C*)CasSimPartsS2C_ctor((CasSimPartsS2C*)__builtin_new(16));
    SetHighResolution(b);
    SetSimDescription(d);
}
