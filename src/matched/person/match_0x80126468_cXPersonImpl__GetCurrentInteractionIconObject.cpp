/* 0x80126468 cXPersonImpl::GetCurrentInteractionIconObject(void) (92B) */

struct cXObject;

struct Interaction {
    char pad0[16];
    cXObject* m_iconObject;  // +16
    cXObject* GetIconObject(void) const;
};

struct cXPersonImpl_GCIIO {
    char pad[0x534];
    int m_flag_1332;

    cXObject* GetCurrentInteractionIconObject(void);
};

cXObject* cXPersonImpl_GCIIO::GetCurrentInteractionIconObject(void) {
    if (m_flag_1332 != 0) {
        char* base = (char*)this + 0x130;
        unsigned int curIdx = *(unsigned int*)(base + 0x2a8);
        Interaction* inter = (Interaction*)(base + (curIdx % 10) * 68);
        return inter->GetIconObject();
    }
    return 0;
}
