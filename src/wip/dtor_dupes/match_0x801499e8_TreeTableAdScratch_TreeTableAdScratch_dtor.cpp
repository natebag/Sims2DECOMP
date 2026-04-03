extern int VT_TreeTableAdScratch_TreeTableAdScratch[];
void del_TreeTableAdScratch_TreeTableAdScratch(void *);
void dtor_TreeTableAdScratch_TreeTableAdScratch(char *self, int __in_chrg) {
    *(int **)self = VT_TreeTableAdScratch_TreeTableAdScratch;
    if (__in_chrg & 1) {
        del_TreeTableAdScratch_TreeTableAdScratch(self);
    }
}
