// FLAGS: -fno-schedule-insns
class UIObjectBase;
class ACTTarget;
class ERC;

// Use single-arg PMF type — same 8B layout, GCC generates same dispatch
class CBFunctorBase {
public:
    void (UIObjectBase::*m_pmf)(ERC*);
    UIObjectBase* m_obj;
};

template <class P1, class T, class M>
class CBMemberTranslator1 {
public:
    static void thunk(CBFunctorBase& f, ERC* arg);
};

void CBMemberTranslator1<ERC*, ACTTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase& f, ERC* arg) {
    UIObjectBase* obj = f.m_obj;
    (obj->*f.m_pmf)(arg);
}
