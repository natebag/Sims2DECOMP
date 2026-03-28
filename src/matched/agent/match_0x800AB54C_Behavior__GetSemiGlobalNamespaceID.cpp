/* Behavior::GetSemiGlobalNamespaceID(void) at 0x800AB54C (12B) */

struct BehaviorData {
    int pad;
    int m_namespaceID;
    int m_semiGlobalNamespaceID;
};

struct Behavior {
    char pad[0x04];
    BehaviorData* m_data;

    int GetSemiGlobalNamespaceID(void);
};

int Behavior::GetSemiGlobalNamespaceID(void) {
    return m_data->m_semiGlobalNamespaceID;
}
