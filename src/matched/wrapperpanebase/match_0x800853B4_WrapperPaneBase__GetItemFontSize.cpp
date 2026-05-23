struct Item { char pad[0x54]; float size; };
extern "C" Item* getItemByType(void* self, int type, int idx);
float WrapperPaneBase_GetItemFontSize(void* self, int type, int idx) {
    return getItemByType(self, type, idx)->size;
}
