// FLAGS: -fno-schedule-insns
// 0x800D95EC cXObject::GetPersonWidth(void) (8B)
// lwz r3,gPersonWidth(r13); blr  -- ignores this, returns SDA global
extern int gPersonWidth;

struct cXObject {
    int GetPersonWidth();
};

int cXObject::GetPersonWidth() { return gPersonWidth; }
