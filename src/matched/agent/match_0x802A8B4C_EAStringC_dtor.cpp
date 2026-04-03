extern void *g_allocator;
void free_802A8B4C(void *, void *, int);
void del_802A8B4C(void *);
void EAStringC_dtor_802A8B4C(char *self, int __in_chrg) {
    char *buf = *(char **)self;
    int val = *(unsigned short *)buf;
    val--;
    *(unsigned short *)buf = val;
    if ((unsigned short)val == 0) {
        unsigned short sz = *(unsigned short *)(buf + 4);
        free_802A8B4C(g_allocator, buf, sz + 9);
    }
    if (__in_chrg & 1) {
        del_802A8B4C(self);
    }
}
