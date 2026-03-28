/* cXObjectImpl::GetObjectImplementation(void) - 4 bytes */

class cXObjectImpl {
public:
    cXObjectImpl* GetObjectImplementation(void);
};

cXObjectImpl* cXObjectImpl::GetObjectImplementation(void) {
    return this;
}
