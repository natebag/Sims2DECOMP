extern void *g_allocator;
void free_80298E88(void *, void *, int);
void del_80298E88(void *);
void EAStringC_dtor_80298E88(char *self, int __in_chrg) {
    char *buf = *(char **)self;
    int val = *(unsigned short *)buf;
    val--;
    *(unsigned short *)buf = val;
    if ((unsigned short)val == 0) {
        unsigned short sz = *(unsigned short *)(buf + 4);
        free_80298E88(g_allocator, buf, sz + 9);
    }
    if (__in_chrg & 1) {
        del_80298E88(self);
    }
}
