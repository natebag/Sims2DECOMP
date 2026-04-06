// 0x80188464 HUDTarget::UpdateTutorialLocks (80b)

typedef unsigned int u32;

extern u32 g_tutorialLockValue;

struct HUDTarget {
    u32 field_EC;
    u32 field_F0;

    void UpdateTutorialLocks();
};

void HUDTarget_UpdateLocks(HUDTarget*);

void HUDTarget::UpdateTutorialLocks() {
    u32 newValue = g_tutorialLockValue;
    int shouldUpdate = 1;
    
    if (field_EC == newValue) {
        shouldUpdate = 0;
    }
    
    field_EC = newValue;
    field_F0 = newValue;
    
    if (shouldUpdate && newValue == 1) {
        HUDTarget_UpdateLocks(this);
    }
}
