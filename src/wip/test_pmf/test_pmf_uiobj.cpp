// FLAGS: -fno-schedule-insns
// Test second CBMemberTranslator0 — UIObjectBase variant
class UIObjectBase;
class CASBodyTarget;

class CBFunctorBase {
public:
    void (UIObjectBase::*m_pmf)(UIObjectBase*);
    UIObjectBase* m_obj;
};

template <class T, class M>
class CBMemberTranslator0 {
public:
    static void thunk(CBFunctorBase& f, UIObjectBase* arg);
};

void CBMemberTranslator0<CASBodyTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase& f, UIObjectBase* arg) {
    UIObjectBase* obj = f.m_obj;
    (obj->*f.m_pmf)(arg);
}
