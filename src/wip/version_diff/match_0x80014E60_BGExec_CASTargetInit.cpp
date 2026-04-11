extern int gCASTargetInitDone;
extern int gSomeContext;

struct ESimsAppData {
    char pad[0x3C];
    void* m_casTarget;
};

extern ESimsAppData gAppData;

void* SimsAlloc(int size);
void* CASTargetInit(void* mem, int ctx);

void BGExec_CASTargetInit() {
    if (gAppData.m_casTarget == 0) {
        void* mem = SimsAlloc(5688);
        gAppData.m_casTarget = CASTargetInit(mem, gSomeContext);
    }
    gCASTargetInitDone = 1;
}
