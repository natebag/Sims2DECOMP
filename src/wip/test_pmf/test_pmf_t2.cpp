// FLAGS: -fno-schedule-insns
class ACTTarget;

class CBFunctorBase {
public:
    void (ACTTarget::*m_pmf)(char*, char*);
    ACTTarget* m_obj;
};

template <class P1, class P2, class T, class M>
class CBMemberTranslator2 {
public:
    static void thunk(CBFunctorBase& f, char* a1, char* a2);
};

void CBMemberTranslator2<char*, char*, ACTTarget, void (ACTTarget::*)(ACTTarget *, char *, char *)>::thunk(CBFunctorBase& f, char* a1, char* a2) {
    ACTTarget* obj = f.m_obj;
    (obj->*f.m_pmf)(a1, a2);
}
