// FLAGS: -fno-schedule-insns
extern int VT[];
void del_fn(void *);
void d_SetVar_EYE_state_SetVar_EYE_state(char *self, int __in_chrg) {
    *(int **)(self + 8) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
