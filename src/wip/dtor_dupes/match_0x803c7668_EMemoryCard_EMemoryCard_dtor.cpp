extern int VT_EMemoryCard_EMemoryCard[];
void del_EMemoryCard_EMemoryCard(void *);
void dtor_EMemoryCard_EMemoryCard(char *self, int __in_chrg) {
    *(int **)self = VT_EMemoryCard_EMemoryCard;
    if (__in_chrg & 1) {
        del_EMemoryCard_EMemoryCard(self);
    }
}
