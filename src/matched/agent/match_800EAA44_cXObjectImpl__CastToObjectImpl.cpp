/* cXObjectImpl::CastToObjectImpl(void) - 4 bytes */

class cXObjectImpl {
public:
    cXObjectImpl* CastToObjectImpl(void);
};

cXObjectImpl* cXObjectImpl::CastToObjectImpl(void) {
    return this;
}
