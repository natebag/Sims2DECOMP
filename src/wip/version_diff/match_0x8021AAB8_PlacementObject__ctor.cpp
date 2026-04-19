// VERSION_DIFF: phantom 32-byte stack frame (stwu r1,-32(r1); no lr save; addi r1,r1,32)
// 12/14 instructions match; same phantom frame as InstanceData ctor. Body is fully correct.
// 0x8021AAB8 (56B) PlacementObject::PlacementObject(void)
// mr r9, r3 — compiler copies this to r9 for register allocation
// Sub-object pointers: r10=this+0x14, r11=this+0x1c (inner struct at sub+8)
// Stores: 0x00, 0x04, 0x14, 0x18, 0x20, 0x24(byte), 0x28

struct NestedSub {
    int field_0;    // NOT initialized
    int field_4;    // 0x1c+4 = outer+0x20
};

struct Sub_at_14 {
    int field_0;      // 0x14+0  = outer+0x14
    int field_4;      // 0x14+4  = outer+0x18
    NestedSub nested; // 0x14+8  = outer+0x1c (8 bytes)
    char field_10;    // 0x14+0x10 = outer+0x24
};  // total 17 bytes, padded to 20

struct PlacementObject {
    int field_00;       // 0x00
    int field_04;       // 0x04
    char pad1[0x0c];    // 0x08-0x13
    Sub_at_14 m_sub;    // 0x14 (20 bytes, ends at 0x27)
    int field_28;       // 0x28
    PlacementObject();
};

PlacementObject::PlacementObject() {
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
