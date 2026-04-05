typedef unsigned char u8;

void addInteraction(u8*, u8*, int);
void updateAction(u8*);

void cXPersonImpl_SetCurrentAction(u8* self, u8* interaction) {
    *(int*)(self + 0x534) = 1;
    addInteraction(self + 0x130, interaction, 0);
    updateAction(self);
}
