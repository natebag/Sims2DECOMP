// 0x800B15F8 CareersImpl::TearDown (76b)
// FLAGS: -fno-schedule-insns

extern void FreeResource(void*);

struct CareersImpl {
    int pad;
    void* data;
    int field_8;
    int field_C;
    int field_10;
};

void CareersImpl_TearDown(CareersImpl* self) {
    if (self->data != 0) {
        FreeResource(self->data);
        self->field_10 = 0;
        self->data = 0;
        self->field_8 = 0;
        self->field_C = 0;
    }
}
