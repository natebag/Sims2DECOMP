/* Interaction::SetIconObject(cXObject*) - 0x800C1C8C (8 bytes) */
struct cXObject;
struct Interaction {
    char pad[16];
    cXObject* m_iconObject;
    void SetIconObject(cXObject* o);
};
void Interaction::SetIconObject(cXObject* o) { m_iconObject = o; }
