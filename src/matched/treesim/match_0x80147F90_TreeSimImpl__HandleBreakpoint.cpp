// 0x80147F90 TreeSimImpl::HandleBreakpoint(StackElem*, BehaviorNode*) (72B)
// TRIAGE

class StackElem {
public:
    void SetBreak(bool b);
};

class BehaviorNode;

class TreeSimImpl {
public:
    void HandleBreakpoint(StackElem* se, BehaviorNode* node);
    void DoNodeAction(StackElem* se);
};

void TreeSimImpl::HandleBreakpoint(StackElem* se, BehaviorNode* /*node*/) {
    if (se != 0) {
        se->SetBreak(false);
    }
    DoNodeAction(se);
}
