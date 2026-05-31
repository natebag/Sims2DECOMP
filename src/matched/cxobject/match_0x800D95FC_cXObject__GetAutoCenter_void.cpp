// FLAGS: -fno-schedule-insns
// 0x800D95FC cXObject::GetAutoCenter(void) (8B)
// lwz r3,gAutoCenter(r13); blr  -- ignores this, returns SDA global
extern int gAutoCenter;

struct cXObject {
    int GetAutoCenter();
};

int cXObject::GetAutoCenter() { return gAutoCenter; }
