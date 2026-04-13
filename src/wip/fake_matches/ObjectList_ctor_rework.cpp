// 0x80048570 ObjectList::ObjectList (32b)

struct ObjectList {
    int field_0;
    int field_4;
    int field_8;
    int field_12;
    
    ObjectList();
};

ObjectList::ObjectList() {
    // Pattern Z with pointer aliasing: zero fields at offsets 0, 4, 12
    this->field_0 = 0;
    this->field_4 = 0;
    int* p = (int*)((char*)this + 8);
    p[1] = 0;  // offset 12 via aliased pointer
}
