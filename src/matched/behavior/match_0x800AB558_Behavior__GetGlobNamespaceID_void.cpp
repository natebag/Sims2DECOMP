// FLAGS: -fno-schedule-insns
// 0x800AB558 Behavior::GetGlobNamespaceID(void) (8B)
// lwz r3,gGlobNamespaceID(r13); blr  -- ignores this, returns SDA global
extern int gGlobNamespaceID;

struct Behavior {
    int GetGlobNamespaceID();
};

int Behavior::GetGlobNamespaceID() { return gGlobNamespaceID; }
