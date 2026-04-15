/* Interaction::SetUniqueID(void) - 0x800C189C (20 bytes) */
extern int g_InteractionUniqueIDCounter;
struct Interaction {
    char pad[56];
    int m_id;
    void SetUniqueID(void);
};
void Interaction::SetUniqueID(void) {
    int next = g_InteractionUniqueIDCounter + 1;
    g_InteractionUniqueIDCounter = next;
    m_id = next;
}
