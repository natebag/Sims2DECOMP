// FLAGS: -fno-schedule-insns
class UIObjectBase;
class ACTTarget;
class ERC;

class CBFunctorBase {
public:
    void (UIObjectBase::*m_pmf)();
    UIObjectBase* m_obj;
};

template <class P1, class T, class M>
class CBMemberTranslator1 {
public:
    static void thunk(CBFunctorBase& f);
};

void CBMemberTranslator1<ERC*, ACTTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase& f) {
    UIObjectBase* obj = f.m_obj;
    (obj->*f.m_pmf)();
}
