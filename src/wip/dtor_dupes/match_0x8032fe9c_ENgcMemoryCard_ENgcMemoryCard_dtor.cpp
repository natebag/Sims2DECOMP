extern int VT_ENgcMemoryCard_ENgcMemoryCard[];
void del_ENgcMemoryCard_ENgcMemoryCard(void *);
void dtor_ENgcMemoryCard_ENgcMemoryCard(char *self, int __in_chrg) {
    *(int **)self = VT_ENgcMemoryCard_ENgcMemoryCard;
    if (__in_chrg & 1) {
        del_ENgcMemoryCard_ENgcMemoryCard(self);
    }
}
