extern void *g_allocator;
void free_802B936C(void *, void *, int);
void del_802B936C(void *);
void EAStringC_dtor_802B936C(char *self, int __in_chrg) {
    char *buf = *(char **)self;
    int val = *(unsigned short *)buf;
    val--;
    *(unsigned short *)buf = val;
    if ((unsigned short)val == 0) {
        unsigned short sz = *(unsigned short *)(buf + 4);
        free_802B936C(g_allocator, buf, sz + 9);
    }
    if (__in_chrg & 1) {
        del_802B936C(self);
    }
}
