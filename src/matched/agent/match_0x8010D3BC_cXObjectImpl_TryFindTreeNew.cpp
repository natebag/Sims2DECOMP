/* cXObjectImpl::TryFindTreeNew(StackElem*, FindTreeNewParam*) - 0x8010D3BC - 12 bytes */
/* li r3, 0; li r4, 0; blr - stub returning NULL, 0 */

struct StackElem;
struct FindTreeNewParam;

class cXObjectImpl {
public:
    long long TryFindTreeNew(StackElem* elem, FindTreeNewParam* param);
};

long long cXObjectImpl::TryFindTreeNew(StackElem* elem, FindTreeNewParam* param) {
    return 0;
}
