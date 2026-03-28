typedef unsigned char u8;

class cXPerson;

class SAnimator2 {
    u8 _pad0[4];
    cXPerson *m_pPerson;
public:
    cXPerson *GetPerson();
};

cXPerson *SAnimator2::GetPerson() {
    return m_pPerson;
}
