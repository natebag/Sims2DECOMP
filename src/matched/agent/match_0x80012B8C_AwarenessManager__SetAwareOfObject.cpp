// AwarenessManager::SetAwareOfObject(cXObject*) - 0x80012B8C (68 bytes)
// Tech #73 application — 2-condition predicate guarding a 3-store success block.
// Same shape family as INGTarget::get_current_inginfo / get_current_mix_inginfo.
//
// FLAGS: -msdata=eabi -G 8

class cXObject;

struct AwarenessManager {
    unsigned int m_flags;
    char pad_4[24 - 4];
    int m_field_18;
    cXObject* m_aware_obj;

    int SetAwareOfObject(cXObject* obj);
};

int AwarenessManager::SetAwareOfObject(cXObject* obj) {
    if (m_aware_obj != 0) goto fail;
    if (obj == 0) goto fail;
    m_aware_obj = obj;
    m_field_18 = 1;
    m_flags = (m_flags | 0x20) & ~0x800;
    return 1;
fail:
    return 0;
}
