// 0x800DCF84 (52 bytes)
// FLAGS: -fno-elide-constructors

struct cXObjectImpl {
    char pad[0x90];
    int field_90;
    int field_94;
};

int* cXObjectImpl_HierGetSlot(cXObjectImpl* this_, int slot) {
    if (slot < 0) {
        return 0;
    }
    
    if (this_->field_94 > this_->field_90 && slot < this_->field_94) {
        return (int*)((char*)&this_->field_90 + slot * 32);
    }
    
    return 0;
}
