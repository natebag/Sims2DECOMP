// FLAGS: -msdata=eabi -G 8
// 0x802ED7EC EAnimController::SetTrackAnim (84b)
extern unsigned int CalcId(const char*);
extern void SetTrackAnimFull(void*, int, unsigned int, float, int, int);
extern char g_defaultBlend[];

void EAnimController_SetTrackAnim(void* self, int track, const char* name) {
    unsigned int id = CalcId(name);
    SetTrackAnimFull(self, track, id, *(float*)g_defaultBlend, -1, 0);
}
