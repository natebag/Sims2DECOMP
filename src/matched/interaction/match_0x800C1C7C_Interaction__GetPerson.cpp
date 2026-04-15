/* Interaction::GetPerson(void) const - 0x800C1C7C (8 bytes) */
struct cXPerson;
struct Interaction {
    char pad[8];
    cXPerson* m_person;
    cXPerson* GetPerson(void) const;
};
cXPerson* Interaction::GetPerson(void) const { return m_person; }
