struct ObjDef { char pad[0x98]; unsigned short flags; };
struct ObjItem { char pad[0x38]; ObjDef* def; };
extern "C" ObjItem* getSelectedItem(void*);
int ObjSelector_GetRuntimeHasShadow(void* self) {
    ObjItem* item = getSelectedItem(self);
    return ((unsigned)(item->def->flags ^ 2)) >> 1 & 1;
}
