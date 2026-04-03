extern int VT_FloatConstants_FloatConstants[];
void del_FloatConstants_FloatConstants(void *);
void dtor_FloatConstants_FloatConstants(char *self, int __in_chrg) {
    *(int **)self = VT_FloatConstants_FloatConstants;
    if (__in_chrg & 1) {
        del_FloatConstants_FloatConstants(self);
    }
}
