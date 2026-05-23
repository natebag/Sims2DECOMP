struct Item { char pad[0x20]; void* value; };
extern "C" Item* getItemByType(void* self, int type, int idx);
void* WrapperPaneBase_GetItemText(void* self, int type, int idx) {
    return getItemByType(self, type, idx)->value;
}
