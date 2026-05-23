struct Item { char pad[0x6C]; void* value; };
extern "C" Item* getItemByType(void* self, int type, int idx);
void* WrapperPaneBase_GetItemStyle(void* self, int type, int idx) {
    return getItemByType(self, type, idx)->value;
}
