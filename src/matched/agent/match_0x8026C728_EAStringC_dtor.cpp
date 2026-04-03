extern void *g_allocator;
void free_8026C728(void *, void *, int);
void del_8026C728(void *);
void EAStringC_dtor_8026C728(char *self, int __in_chrg) {
    char *buf = *(char **)self;
    int val = *(unsigned short *)buf;
    val--;
    *(unsigned short *)buf = val;
    if ((unsigned short)val == 0) {
        unsigned short sz = *(unsigned short *)(buf + 4);
        free_8026C728(g_allocator, buf, sz + 9);
    }
    if (__in_chrg & 1) {
        del_8026C728(self);
    }
}
