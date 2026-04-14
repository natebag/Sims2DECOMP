/* ESimShadow::ESimShadow(cXPerson *) at 0x80034F78 (68B) */

extern int ESimShadow_vtable[];

struct cXPerson;

struct EIStaticModel {
    EIStaticModel();
};

struct ESimShadow : public EIStaticModel {
    char pad_base[0x320 - sizeof(EIStaticModel)];
    cXPerson* m_person;

    ESimShadow(cXPerson*);
};

ESimShadow::ESimShadow(cXPerson* person) : EIStaticModel() {
    m_person = person;
    *(int*)this = (int)ESimShadow_vtable;
}
