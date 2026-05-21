// 0x8016EEE0 CasSimRenderer::CasSimRenderer(void) (88B)
// TRIAGE

extern int CasSimRenderer_vt[];

extern void SimModel_ctor(void* self);
extern void EAnimController_ctor(void* self);
extern void CasSimRenderer_Init(void* self);

char* CasSimRenderer_ctor(char* self) {
    *(int*)(self + 0) = 0;
    *(int**)(self + 4) = CasSimRenderer_vt;
    SimModel_ctor(self + 8);
    EAnimController_ctor(self + 372);
    CasSimRenderer_Init(self);
    return self;
}
