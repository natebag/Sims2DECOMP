extern void *g_allocator;
void free_802A1DCC(void *, void *, int);
void del_802A1DCC(void *);
void EAStringC_dtor_802A1DCC(char *self, int __in_chrg) {
    char *buf = *(char **)self;
    int val = *(unsigned short *)buf;
    val--;
    *(unsigned short *)buf = val;
    if ((unsigned short)val == 0) {
        unsigned short sz = *(unsigned short *)(buf + 4);
        free_802A1DCC(g_allocator, buf, sz + 9);
    }
    if (__in_chrg & 1) {
        del_802A1DCC(self);
    }
}
