// FLAGS: -fno-schedule-insns
extern int VT[];
void del_fn(void *);
void d_InteractorModule_GrabManipulator_GrabManipulatorParams_GrabManipulatorParams(char *self, int __in_chrg) {
    *(int **)(self + 16) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
