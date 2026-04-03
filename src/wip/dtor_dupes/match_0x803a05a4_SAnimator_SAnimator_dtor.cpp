extern int VT_SAnimator_SAnimator[];
void del_SAnimator_SAnimator(void *);
void dtor_SAnimator_SAnimator(char *self, int __in_chrg) {
    *(int **)self = VT_SAnimator_SAnimator;
    if (__in_chrg & 1) {
        del_SAnimator_SAnimator(self);
    }
}
