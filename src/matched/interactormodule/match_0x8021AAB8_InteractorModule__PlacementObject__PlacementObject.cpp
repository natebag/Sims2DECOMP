// 0x8021AAB8 (56B) InteractorModule::PlacementObject::PlacementObject(void)
// Phantom 32B stack frame: volatile int _dummy[6] forces stwu r1,-32(r1) without LR save.
// Same pattern as InstanceData::InstanceData @ 0x802096F8.
// Sub-struct pointers: r10=this+0x14 (pa), r11=this+0x1c (pb=&m_sub.nested).

namespace InteractorModule {

struct NestedSub {
    int field_0;
    int field_4;
};

struct Sub_at_14 {
    int field_0;
    int field_4;
    NestedSub nested;
    char field_10;
};

class PlacementObject {
public:
    int field_00;
    int field_04;
    char pad1[0x0c];
    Sub_at_14 m_sub;
    int field_28;

    PlacementObject();
};

PlacementObject::PlacementObject() {
    volatile int _dummy[6];
    field_00 = 0;
    Sub_at_14* pa = &m_sub;
    field_04 = 0;
    NestedSub* pb = &m_sub.nested;
    m_sub.field_0 = 0;
    pa->field_4 = 0;
    pb->field_4 = 0;
    pa->field_10 = 0;
    field_28 = 0;
}

}
