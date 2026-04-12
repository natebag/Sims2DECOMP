/* ObjectList::ObjectList(void) at 0x80048570 (32B) */

struct ObjectList {
    int field_0;    // 0x00
    int field_4;    // 0x04
    int field_8;    // 0x08
    
    ObjectList(void);
};

ObjectList::ObjectList(void) {
    ObjectList* p = this;
    *(volatile int*)&p->field_0 = 0;
    *(volatile int*)&p->field_4 = 0;
    *(volatile int*)&p->field_8 = 0;
}
