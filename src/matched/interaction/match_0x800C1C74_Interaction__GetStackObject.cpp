/* Interaction::GetStackObject(void) const - 0x800C1C74 (8 bytes) */
struct cXObject;
struct Interaction {
    char pad[12];
    cXObject* m_stackObject;
    cXObject* GetStackObject(void) const;
};
cXObject* Interaction::GetStackObject(void) const { return m_stackObject; }
