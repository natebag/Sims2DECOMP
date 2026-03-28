/* Interaction::GetIconObject(void) const - 0x800C1C84 (8 bytes) */

struct cXObject;

struct Interaction {
    int m_pad0;
    int m_type;
    cXObject *m_person;
    cXObject *m_stackObject;
    cXObject *m_iconObject;

    cXObject *GetIconObject(void) const;
};

cXObject *Interaction::GetIconObject(void) const {
    return m_iconObject;
}
