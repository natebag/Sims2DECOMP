extern int VT_cSimulator_cSimulator[];
void del_cSimulator_cSimulator(void *);
void dtor_cSimulator_cSimulator(char *self, int __in_chrg) {
    *(int **)self = VT_cSimulator_cSimulator;
    if (__in_chrg & 1) {
        del_cSimulator_cSimulator(self);
    }
}
