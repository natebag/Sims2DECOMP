/* 0x8005F4E8 (96 bytes) - SAnimator2::getCorrectId(PropRef *) */
struct PropRef {
    int m_field_00;
    int m_field_04;
};

struct SAnimator2 {
    char pad[4];
    unsigned char* m_pPerson;
    int getCorrectId(PropRef* prop);
};

int SAnimator2::getCorrectId(PropRef* prop) {
    unsigned char* person = m_pPerson;
    unsigned char* vtable = *(unsigned char**)(person + 4);
    short offset = *(short*)(vtable + 0x210);
    int func = *(int*)(vtable + 0x214);
    unsigned char* obj = person + offset;
    int result = ((int (*)(unsigned char*))func)(obj);
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
