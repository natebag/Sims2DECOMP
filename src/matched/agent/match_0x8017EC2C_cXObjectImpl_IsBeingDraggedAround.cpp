
int cXObjectImpl_InternalDragCheck(void *);

struct cXObjectImpl {
    int IsBeingDraggedAround(void);
};

int cXObjectImpl::IsBeingDraggedAround(void) {
    return cXObjectImpl_InternalDragCheck(this);
}
