/* Interaction::GetPerson(void) const - 0x800C1C7C (8 bytes) */

struct cXObject;

struct Interaction {
    int m_pad0;
    int m_type;
    cXObject *m_person;

    cXObject *GetPerson(void) const;
};

cXObject *Interaction::GetPerson(void) const {
    return m_person;
}
