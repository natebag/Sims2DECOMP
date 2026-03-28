struct BehaviorData {
    int pad_00;
    int m_namespaceID;
    int m_semiGlobalNamespaceID;
};

class Behavior {
public:
    void *vtable;
    BehaviorData *m_data;

    int GetSemiGlobalNamespaceID(void);
};

int Behavior::GetSemiGlobalNamespaceID(void) {
    return m_data->m_semiGlobalNamespaceID;
}
