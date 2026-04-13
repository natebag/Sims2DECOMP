// 0x800DCD4C cXObjectImpl::GetNextObjectSibling (36B)

extern void* cXObjectImpl_GetSibling(void* self, int dir);

struct cXObjGNOS {
    void* GetNextObjectSibling();
};

void* cXObjGNOS::GetNextObjectSibling() {
    return cXObjectImpl_GetSibling(this, 0);
}
