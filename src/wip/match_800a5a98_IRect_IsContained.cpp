// 0x800a5a98 IRect::IsContained (76b)

struct IRect {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    
    bool IsContained(IRect* other) const;
};

bool IRect::IsContained(IRect* other) const {
    if (field_8 <= other->field_8) {
        goto check4_area;
    }
    
    if (field_0 >= other->field_0) {
        if (field_4 >= other->field_4) {
            check4_area:
            return field_C <= other->field_C;
        }
    }
    
    return false;
}
