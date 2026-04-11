// FLAGS: -fno-schedule-insns
class ACTTarget;

class CBFunctorBase {
public:
    char* (ACTTarget::*m_pmf)(char*);
    ACTTarget* m_obj;
};

template <class R, class P1, class T, class M>
class CBMemberTranslator1wRet {
public:
    static char* thunk(CBFunctorBase& f, char* a1);
};

char* CBMemberTranslator1wRet<char*, char*, ACTTarget, char* (ACTTarget::*)(ACTTarget *, char *)>::thunk(CBFunctorBase& f, char* a1) {
    ACTTarget* obj = f.m_obj;
    return (obj->*f.m_pmf)(a1);
}
