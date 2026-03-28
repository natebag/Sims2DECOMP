struct BehaviorData {
    int pad_00;
    int m_namespaceID;
};

class Behavior {
public:
    void *vtable;
    BehaviorData *m_data;

    int GetNamespaceID(void);
};

int Behavior::GetNamespaceID(void) {
    return m_data->m_namespaceID;
}
