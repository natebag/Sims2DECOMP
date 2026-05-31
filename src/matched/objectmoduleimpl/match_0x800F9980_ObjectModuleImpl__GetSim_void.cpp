// FLAGS: -fno-schedule-insns
// 0x800F9980 ObjectModuleImpl::GetSim(void) (8B)
// lwz r3,gObjectSim(r13); blr  -- ignores this, returns SDA global
extern int gObjectSim;

struct ObjectModuleImpl {
    int GetSim();
};

int ObjectModuleImpl::GetSim() { return gObjectSim; }
