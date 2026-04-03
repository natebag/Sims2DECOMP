extern int VT_SpriteSlot_SpriteSlot[];
void del_SpriteSlot_SpriteSlot(void *);
void dtor_SpriteSlot_SpriteSlot(char *self, int __in_chrg) {
    *(int **)self = VT_SpriteSlot_SpriteSlot;
    if (__in_chrg & 1) {
        del_SpriteSlot_SpriteSlot(self);
    }
}
