/* Behavior::GetNamespaceID(void) at 0x800AB540 (12B) */

struct BehaviorData {
    int pad;
    int m_namespaceID;
};

struct Behavior {
    char pad[0x04];
    BehaviorData* m_data;

    int GetNamespaceID(void);
};

int Behavior::GetNamespaceID(void) {
    return m_data->m_namespaceID;
}
