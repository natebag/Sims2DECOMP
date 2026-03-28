// 0x8010D3BC (12 bytes)
// cXObjectImpl::TryFindTreeNew(StackElem *, FindTreeNewParam *)
// li r3, 0; li r4, 0; blr
class StackElem;
class FindTreeNewParam;
class cXObjectImpl {
public:
    long long TryFindTreeNew(StackElem* elem, FindTreeNewParam* param);
};

long long cXObjectImpl::TryFindTreeNew(StackElem* elem, FindTreeNewParam* param) {
    return 0;
}
