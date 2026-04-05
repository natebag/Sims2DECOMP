typedef unsigned char u8;
u8* getItem2(u8*, int, int);
void setItemStyle(u8*, u8*);
void WrapperPaneBase_SetItemStyle(u8* self, int type, int idx, u8* style) {
    u8* item = getItem2(self, type, idx);
    setItemStyle(item, style);
}
