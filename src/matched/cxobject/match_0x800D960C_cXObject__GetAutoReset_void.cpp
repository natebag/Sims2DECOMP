// FLAGS: -fno-schedule-insns
// 0x800D960C cXObject::GetAutoReset(void) (8B)
// lwz r3,gAutoReset(r13); blr  -- ignores this, returns SDA global
extern int gAutoReset;

struct cXObject {
    int GetAutoReset();
};

int cXObject::GetAutoReset() { return gAutoReset; }
