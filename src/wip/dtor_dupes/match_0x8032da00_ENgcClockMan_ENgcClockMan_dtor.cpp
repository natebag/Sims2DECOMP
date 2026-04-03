extern int VT_ENgcClockMan_ENgcClockMan[];
void del_ENgcClockMan_ENgcClockMan(void *);
void dtor_ENgcClockMan_ENgcClockMan(char *self, int __in_chrg) {
    *(int **)self = VT_ENgcClockMan_ENgcClockMan;
    if (__in_chrg & 1) {
        del_ENgcClockMan_ENgcClockMan(self);
    }
}
