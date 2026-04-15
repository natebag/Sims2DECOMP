/* 0x8012640C cXPersonImpl::GetCurrentInteractionStackObject(void) (92B) */

struct cXObject;

struct Interaction {
    char pad0[12];
    cXObject* m_stackObject;  // +12
    cXObject* GetStackObject(void) const;
};

struct cXPersonImpl_GCISO {
    char pad[0x534];
    int m_flag_1332;

    cXObject* GetCurrentInteractionStackObject(void);
};

cXObject* cXPersonImpl_GCISO::GetCurrentInteractionStackObject(void) {
    if (m_flag_1332 != 0) {
        char* base = (char*)this + 0x130;
        unsigned int curIdx = *(unsigned int*)(base + 0x2a8);
        Interaction* inter = (Interaction*)(base + (curIdx % 10) * 68);
        return inter->GetStackObject();
    }
    return 0;
}
