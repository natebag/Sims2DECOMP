// FLAGS: -fno-schedule-insns
// 0x800AB54C Behavior::GetSemiGlobalNamespaceID(void) (12B)
// lwz r9,4(r3); lwz r3,8(r9); blr  -- this->m_module->m_semiGlobalNamespaceID
struct BehaviorModule {
    char pad[8];
    int m_semiGlobalNamespaceID;    // 0x8
};

struct Behavior {
    char pad[4];
    BehaviorModule* m_module;       // 0x4
    int GetSemiGlobalNamespaceID();
};

int Behavior::GetSemiGlobalNamespaceID() { return m_module->m_semiGlobalNamespaceID; }
