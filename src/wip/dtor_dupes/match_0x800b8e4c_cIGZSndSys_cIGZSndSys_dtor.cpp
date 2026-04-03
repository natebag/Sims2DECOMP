extern int VT_cIGZSndSys_cIGZSndSys[];
void del_cIGZSndSys_cIGZSndSys(void *);
void dtor_cIGZSndSys_cIGZSndSys(char *self, int __in_chrg) {
    *(int **)self = VT_cIGZSndSys_cIGZSndSys;
    if (__in_chrg & 1) {
        del_cIGZSndSys_cIGZSndSys(self);
    }
}
