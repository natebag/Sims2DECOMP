/* cXObjectImpl::TryUIEffect(StackElem *, XPrimParam *) - 12 bytes */

struct StackElem;
struct XPrimParam;

class cXObjectImpl {
public:
    long long TryUIEffect(StackElem* elem, XPrimParam* param);
};

long long cXObjectImpl::TryUIEffect(StackElem* elem, XPrimParam* param) {
    return 1;
}
