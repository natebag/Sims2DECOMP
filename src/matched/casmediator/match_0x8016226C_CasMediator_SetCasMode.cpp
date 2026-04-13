// FLAGS: -msdata=eabi -G 8
// 0x8016226C CasMediator::SetCasMode (44b)
extern void UIDBSetInt(const char*, int);
extern char g_casModeKey[];

struct CasMediator {
    char pad[44];
    int casMode;
};

void CasMediator_SetCasMode(CasMediator* self, int mode) {
    self->casMode = mode;
    UIDBSetInt(g_casModeKey, mode);
}
