extern int VT_EClockMan_EClockMan[];
void del_EClockMan_EClockMan(void *);
void dtor_EClockMan_EClockMan(char *self, int __in_chrg) {
    *(int **)self = VT_EClockMan_EClockMan;
    if (__in_chrg & 1) {
        del_EClockMan_EClockMan(self);
    }
}
