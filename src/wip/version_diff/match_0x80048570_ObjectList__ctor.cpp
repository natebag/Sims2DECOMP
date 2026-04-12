// 0x80048570 ObjectList::ObjectList (32b)
// Note: DOL has stack frame, we don't - VERSION_DIFF

struct ObjectList {
    int field_0;
    int field_4;
    int field_8;
    
    ObjectList();
};

ObjectList::ObjectList() {
    field_0 = 0;
    field_4 = 0;
    field_8 = 0;
}
