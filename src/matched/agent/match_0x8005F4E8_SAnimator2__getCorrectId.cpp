typedef unsigned char u8;

struct PropRef {
    int m_field_00;
    int m_field_04;
};

int SAnimator2_getCorrectId(u8* self, PropRef* prop) {
    u8* person = *(u8**)(self + 4);
    u8* vtable = *(u8**)(person + 4);
    short offset = *(short*)(vtable + 0x210);
    int func = *(int*)(vtable + 0x214);
    u8* obj = person + offset;
    int result = ((int (*)(u8*))func)(obj);
    int ret;
    if (result != 0) {
        ret = prop->m_field_00;
    } else if (prop->m_field_04 != 0) {
        ret = prop->m_field_04;
    } else {
        ret = prop->m_field_00;
    }
    return ret;
}
