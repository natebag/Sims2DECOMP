// 0x801F2370 INVTarget::InstallBldVariables() (64B)

class CBFunctor;

class GetVariableCommandTable {
public:
    void InstallCommand(char* name, CBFunctor& cb);
};

extern char fmt_InstallBld_803F97C8[16];

class INVTarget {
public:
    void* m_0;
    GetVariableCommandTable* m_4;
    char pad8[32];
    int m_40_dummy;
    void InstallBldVariables();
};

void INVTarget::InstallBldVariables() {
    char* fmt = fmt_InstallBld_803F97C8;
    if (m_0 == 0) return;
    m_4->InstallCommand(fmt, *(CBFunctor*)((char*)this + 40));
}
