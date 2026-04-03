extern int VT_Effects_EffectsVisitor_EffectsVisitor[];
void del_Effects_EffectsVisitor_EffectsVisitor(void *);
void dtor_Effects_EffectsVisitor_EffectsVisitor(char *self, int __in_chrg) {
    *(int **)self = VT_Effects_EffectsVisitor_EffectsVisitor;
    if (__in_chrg & 1) {
        del_Effects_EffectsVisitor_EffectsVisitor(self);
    }
}
