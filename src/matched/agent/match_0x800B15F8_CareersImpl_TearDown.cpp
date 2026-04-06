// FLAGS: -fno-schedule-insns
// 0x800B15F8 CareersImpl::TearDown (76b)
void careers_free(void*);

void TearDown_test(char* self) {
    void* data = *(void**)(self + 4);
    if (data != 0) {
        careers_free(data);
    }
    *(int*)(self + 16) = 0;
    *(int*)(self + 4) = 0;
    *(int*)(self + 8) = 0;
    *(int*)(self + 12) = 0;
}
