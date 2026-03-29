typedef void *(*VtableFn)(void *);

struct EGlobalArray {
    char pad_000[0xBC];
    void *m_playerObjects[4];
};

struct VtableEntry2 {
    short delta;
    short pad;
    VtableFn func;
};

extern EGlobalArray _globals;

void Interactor_Update(void *self);
void SAnimator2_GetEngineFormatPos(void *outVec, void *animator);

struct EVec3_U {
    int x;
    int y;
    int z;
};

struct SocialModeInteractor_UPD {
    int m_personID;
    char pad_04[0x04];
    EVec3_U m_pos;
    char pad_14[0x4C];

    void Update(float dt);
};

void SocialModeInteractor_UPD::Update(float dt) {
    Interactor_Update(this);

    int pid = m_personID;
    void *obj = _globals.m_playerObjects[pid];

    VtableEntry2 *vt = *(VtableEntry2 **)((char *)obj + 4);
    VtableFn fn = vt[49].func;
    short delta = vt[49].delta;
    void *result = fn((char *)obj + delta);

    EVec3_U localVec;
    SAnimator2_GetEngineFormatPos(&localVec, result);

    m_pos = localVec;
}
