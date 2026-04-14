// 0x800EB488 cXObjectImpl::GetBuildModeType (44b)
int obj_get_data(void*);

int GetBuildModeType_test(char* self) {
    void* result = (void*)obj_get_data(*(void**)(self + 140));
    return *(short*)(*(char**)((char*)result + 56) + 138);
}
