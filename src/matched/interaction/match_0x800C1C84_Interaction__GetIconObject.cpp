/* Interaction::GetIconObject(void) const - 0x800C1C84 (8 bytes) */
struct cXObject;
struct Interaction {
    char pad[16];
    cXObject* m_iconObject;
    cXObject* GetIconObject(void) const;
};
cXObject* Interaction::GetIconObject(void) const { return m_iconObject; }
