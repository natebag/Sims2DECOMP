/* cXObjectImpl::HandleBreakpoint(StackElem *, BehaviorNode *) - 36 bytes */

struct StackElem;
struct BehaviorNode;

struct cXObjectData {
    void* HandleBreakpoint(StackElem*, BehaviorNode*);
};

class cXObjectImpl {
public:
    cXObjectData* m_data;

    void* HandleBreakpoint(StackElem* elem, BehaviorNode* node);
};

void* cXObjectImpl::HandleBreakpoint(StackElem* elem, BehaviorNode* node) {
    return m_data->HandleBreakpoint(elem, node);
}
