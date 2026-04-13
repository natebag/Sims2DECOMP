/* Interaction::SetIconObject(cXObject *) - 0x800C1C8C (8 bytes) */

struct cXObject;

struct Interaction {
    int m_pad0;
    int m_type;
    cXObject *m_person;
    cXObject *m_stackObject;
    cXObject *m_iconObject;

    void SetIconObject(cXObject *obj);
};

void Interaction::SetIconObject(cXObject *obj) {
    m_iconObject = obj;
}
