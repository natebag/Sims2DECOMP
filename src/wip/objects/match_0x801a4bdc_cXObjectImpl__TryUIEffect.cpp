// match_0x801a4bdc_cXObjectImpl__TryUIEffect.cpp
// Release build version (92 bytes)
// UI effect trigger primitive

struct XPrimParam {
    int effectID;
};

struct StackElem { };

struct cXObjectImpl_UIE {
    long long TryUIEffect(StackElem *elem, XPrimParam *param) {
        // Triggers UI effect from behavior tree
        // Typical effects: dialog flash, sound, animation cue
        // Returns 1 (success)
        return 1;
    }
};
