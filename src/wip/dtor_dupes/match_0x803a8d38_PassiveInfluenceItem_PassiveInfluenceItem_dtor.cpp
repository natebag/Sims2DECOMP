extern int VT_PassiveInfluenceItem_PassiveInfluenceItem[];
void del_PassiveInfluenceItem_PassiveInfluenceItem(void *);
void dtor_PassiveInfluenceItem_PassiveInfluenceItem(char *self, int __in_chrg) {
    *(int **)self = VT_PassiveInfluenceItem_PassiveInfluenceItem;
    if (__in_chrg & 1) {
        del_PassiveInfluenceItem_PassiveInfluenceItem(self);
    }
}
