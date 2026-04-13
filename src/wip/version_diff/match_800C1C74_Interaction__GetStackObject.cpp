/* Interaction::GetStackObject(void) const - 0x800C1C74 (8 bytes) */

struct cXObject;

struct Interaction {
    int m_pad0;
    int m_type;
    cXObject *m_person;
    cXObject *m_stackObject;
    cXObject *m_iconObject;

    cXObject *GetStackObject(void) const;
};

cXObject *Interaction::GetStackObject(void) const {
    return m_stackObject;
}
