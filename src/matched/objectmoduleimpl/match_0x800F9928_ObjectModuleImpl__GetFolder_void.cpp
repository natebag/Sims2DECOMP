// FLAGS: -fno-schedule-insns
// 0x800F9928 ObjectModuleImpl::GetFolder(void) (8B)
// lwz r3,gObjectFolder(r13); blr  -- ignores this, returns SDA global
extern int gObjectFolder;

struct ObjectModuleImpl {
    int GetFolder();
};

int ObjectModuleImpl::GetFolder() { return gObjectFolder; }
