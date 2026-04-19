/* EIStaticModel::Construct(EIStaticModel *) at 0x8022DFE0 (44B) */

struct EIStaticModel_C {
    char m_pad[800];
    static void* operator new(unsigned int size, void* ptr);
    EIStaticModel_C();
    static EIStaticModel_C* Construct(EIStaticModel_C* buf);
};

EIStaticModel_C* EIStaticModel_C::Construct(EIStaticModel_C* buf) {
    return new (buf) EIStaticModel_C();
}
