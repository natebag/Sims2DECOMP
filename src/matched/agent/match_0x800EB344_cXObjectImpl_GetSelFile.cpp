// 0x800EB344 cXObjectImpl::GetSelFile (52b)
void* obj_get_selfile(void*);

void* GetSelFile_test(char* self) {
    char* data = *(char**)(self + 140);
    void* ptr = *(void**)data;
    if (ptr == 0) {
        ptr = (void*)obj_get_selfile(data);
    }
    return ptr;
}
