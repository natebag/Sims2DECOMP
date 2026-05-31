// FLAGS: -fno-schedule-insns
// 0x800D95F4 cXObject::GetFreeWill(void) (8B)
// lwz r3,gFreeWill(r13); blr  -- ignores this, returns SDA global
extern int gFreeWill;

struct cXObject {
    int GetFreeWill();
};

int cXObject::GetFreeWill() { return gFreeWill; }
