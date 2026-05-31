// FLAGS: -fno-schedule-insns
// 0x800AB540 Behavior::GetNamespaceID(void) (12B)
// lwz r9,4(r3); lwz r3,4(r9); blr  -- this->m_module->m_namespaceID
struct BehaviorModule {
    char pad[4];
    int m_namespaceID;      // 0x4
};

struct Behavior {
    char pad[4];
    BehaviorModule* m_module;   // 0x4
    int GetNamespaceID();
};

int Behavior::GetNamespaceID() { return m_module->m_namespaceID; }
