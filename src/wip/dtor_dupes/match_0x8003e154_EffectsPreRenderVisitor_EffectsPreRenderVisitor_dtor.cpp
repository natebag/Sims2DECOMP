extern int VT_EffectsPreRenderVisitor_EffectsPreRenderVisitor[];
void del_EffectsPreRenderVisitor_EffectsPreRenderVisitor(void *);
void dtor_EffectsPreRenderVisitor_EffectsPreRenderVisitor(char *self, int __in_chrg) {
    *(int **)self = VT_EffectsPreRenderVisitor_EffectsPreRenderVisitor;
    if (__in_chrg & 1) {
        del_EffectsPreRenderVisitor_EffectsPreRenderVisitor(self);
    }
}
