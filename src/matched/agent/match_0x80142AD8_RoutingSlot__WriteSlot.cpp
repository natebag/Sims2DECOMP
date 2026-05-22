// 0x80142AD8 RoutingSlot::WriteSlot(SlotDescriptor*) (124B)

struct SlotDescriptor {
    short field_0;
    char pad1[2];
    float field_4;
    float field_8;
    float field_C;
    char pad2[12];
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    float field_3C;
    int field_40;
    int field_44;
};

struct RoutingSlot {
    char pad[4];
    float field_4;
    float field_8;
    float field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    float field_30;
    int field_34;
    int field_38;
    void WriteSlot(SlotDescriptor* dst);
};

void RoutingSlot::WriteSlot(SlotDescriptor* dst) {
    dst->field_0 = 3;
    dst->field_28 = field_1C;
    dst->field_1C = field_10;
    dst->field_20 = field_14;
    dst->field_24 = field_18;
    dst->field_2C = field_20;
    dst->field_30 = field_24;
    dst->field_34 = field_28;
    dst->field_38 = field_2C;
    dst->field_3C = field_30;
    dst->field_40 = field_34;
    dst->field_44 = field_38;
    dst->field_4 = field_4;
    dst->field_8 = field_8;
    dst->field_C = field_C;
}
