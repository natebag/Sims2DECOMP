// FLAGS: -fno-elide-constructors
// 0x800DCD70 cXObjectImpl::GetPrevObjectSibling (76b)
void* obj_get_prev(void*);

void* GetPrevObjectSibling_test(char* self) {
    void* link = obj_find_link(self + 40, 14);
    void* ret = 0;
    if (*(short*)link == 0) {
        ret = obj_get_prev(self);
    }
    return ret;
}
