// 0x800C6AD0 (64B) cXMTObjectImpl::IsPartOfMe(cXObject *)

struct cXObject;
struct cXMTObjectImpl {
    int IsPartOfMe(cXObject* target);
};

int cXMTObjectImpl::IsPartOfMe(cXObject* target) {
    cXMTObjectImpl* node = this;
    void* head = *(void**)((char*)this + 0x0C);
    if (head != 0) node = (cXMTObjectImpl*)head;
    while (node != 0) {
        void* p = *(void**)((char*)node + 4);
        if (*(void**)p == target) return 1;
        node = *(cXMTObjectImpl**)((char*)node + 8);
    }
    return 0;
}
