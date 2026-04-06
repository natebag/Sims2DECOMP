// 0x801D00C0 O2TTarget::QuitGame (40b)

struct O2TTarget {
    char pad[0x250];
    int quitting;
};

extern void O2TTarget_Shutdown(O2TTarget*);

void O2TTarget_QuitGame(O2TTarget* self, char*, char*) {
    self->quitting = 1;
    O2TTarget_Shutdown(self);
}
