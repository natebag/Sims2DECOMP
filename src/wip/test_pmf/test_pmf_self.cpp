// Test PMF crack — variant B: static thunk passing obj as arg (self-call)
class ACTTarget;

class CBFunctorBase {
public:
    void (ACTTarget::*m_pmf)(ACTTarget*);
    ACTTarget* m_obj;
};

template <class T, class M>
class CBMemberTranslator0 {
public:
    static void thunk(CBFunctorBase& f);
};

void CBMemberTranslator0<ACTTarget, void (ACTTarget::*)(ACTTarget *)>::thunk(CBFunctorBase& f) {
    (f.m_obj->*f.m_pmf)(f.m_obj);
}
