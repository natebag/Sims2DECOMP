// AwarenessManager::ClearAwareOfObject(cXObject*) - 0x80012C04 (72 bytes)
// Sibling of SetAwareOfObject. Single early-exit + conditional body + return 1.
// Goto-fail used to force bne+merged-tail (Tech #74-shape: explicit goto needed
// for predicate-with-trailing-conditional-body to keep source polarity).
//
// FLAGS: -fno-schedule-insns -msdata=eabi -G 8

class cXObject;

extern char g_clearAwareFloatConst[16];

struct AwarenessManager {
    unsigned int m_flags;
    char pad_4[24 - 4];
    int m_field_18;
    cXObject* m_aware_obj;
    float m_field_20;

    int ClearAwareOfObject(cXObject* obj);
};

int AwarenessManager::ClearAwareOfObject(cXObject* obj) {
    if (obj != m_aware_obj) goto fail;
    if (m_flags & 0x20) {
        float k = *(float*)g_clearAwareFloatConst;
        m_aware_obj = 0;
        m_flags = (m_flags | 8) & ~0x20;
        m_field_20 = k;
    }
    return 1;
fail:
    return 0;
}
