typedef unsigned char u8;
u8* getItem(u8*, int, int);
void setItemProp(u8*, u8*);
void WrapperPaneBase_SetItemText(u8* self, int type, int idx, u8* text) {
    u8* item = getItem(self, type, idx);
    setItemProp(item, text);
}
