/* cXObjectImpl::GetNextObjectSibling(void) - 0x800DCD4C (36 bytes) */

struct cXObject;

struct cXObjectImpl {
    cXObject *HierGetChild(int);
    cXObject *GetNextObjectSibling(void);
};

cXObject *cXObjectImpl::GetNextObjectSibling(void) {
    return HierGetChild(0);
}
