// Test PMF crack — variant C: non-static method, this == &f via inheritance
class ACTTarget;

class CBFunctorBase {
public:
    void (ACTTarget::*m_pmf)(ACTTarget*);
    ACTTarget* m_obj;
};

template <class T, class M>
class CBMemberTranslator0 : public CBFunctorBase {
public:
    void thunk(CBFunctorBase& f);
};

void CBMemberTranslator0<ACTTarget, void (ACTTarget::*)(ACTTarget *)>::thunk(CBFunctorBase& f) {
    (f.m_obj->*f.m_pmf)(f.m_obj);
}
