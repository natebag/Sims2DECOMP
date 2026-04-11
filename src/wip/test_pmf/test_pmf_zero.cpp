// FLAGS: -fno-schedule-insns
class ACTTarget;

class CBFunctorBase {
public:
    void (ACTTarget::*m_pmf)();
    ACTTarget* m_obj;
};

template <class T, class M>
class CBMemberTranslator0 {
public:
    static void thunk(CBFunctorBase& f);
};

void CBMemberTranslator0<ACTTarget, void (ACTTarget::*)(ACTTarget *)>::thunk(CBFunctorBase& f) {
    ACTTarget* obj = f.m_obj;
    (obj->*f.m_pmf)();
}
