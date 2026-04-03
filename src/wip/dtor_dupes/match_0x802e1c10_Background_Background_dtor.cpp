extern int VT_Background_Background[];
void del_Background_Background(void *);
void dtor_Background_Background(char *self, int __in_chrg) {
    *(int **)self = VT_Background_Background;
    if (__in_chrg & 1) {
        del_Background_Background(self);
    }
}
