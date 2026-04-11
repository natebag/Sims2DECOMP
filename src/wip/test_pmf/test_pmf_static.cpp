// Test PMF crack — variant A: static thunk passing arg
class ACTTarget;

class CBFunctorBase {
public:
    void (ACTTarget::*m_pmf)(ACTTarget*);
    ACTTarget* m_obj;
};

template <class T, class M>
class CBMemberTranslator0 {
public:
    static void thunk(CBFunctorBase& f, T* arg);
};

void CBMemberTranslator0<ACTTarget, void (ACTTarget::*)(ACTTarget *)>::thunk(CBFunctorBase& f, ACTTarget* arg) {
    (f.m_obj->*f.m_pmf)(arg);
}
