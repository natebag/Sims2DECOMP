extern int VT_EFontCharacter_EFontCharacter[];
void del_EFontCharacter_EFontCharacter(void *);
void dtor_EFontCharacter_EFontCharacter(char *self, int __in_chrg) {
    *(int **)self = VT_EFontCharacter_EFontCharacter;
    if (__in_chrg & 1) {
        del_EFontCharacter_EFontCharacter(self);
    }
}
