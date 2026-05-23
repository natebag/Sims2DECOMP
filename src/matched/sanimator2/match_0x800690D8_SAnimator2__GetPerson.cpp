/* 0x800690D8 (8 bytes) - SAnimator2::GetPerson(void) */
class cXPerson;
struct SAnimator2 {
    char pad[4];
    cXPerson* m_person;
    cXPerson* GetPerson();
};
cXPerson* SAnimator2::GetPerson() { return m_person; }
