// 0x801E9648 (56B) SetVar_EYE_funframeCurrSel::Handler(char *)
// AtoI(arg); save to g_pEyeToy->funframeCurrSel (+148); ApplyFunFrame(val-1).

extern "C" int AtoI(char* s);

class EyeToyClient {
public:
    static void ApplyFunFrame(int v);
};

struct EyeToyData {
    char _pad[148];
    int funframeCurrSel;
};

extern EyeToyData* g_pEyeToy;

class SetVar_EYE_funframeCurrSel {
public:
    void Handler(char* arg);
};

void SetVar_EYE_funframeCurrSel::Handler(char* arg)
{
    int v = AtoI(arg);
    g_pEyeToy->funframeCurrSel = v;
    EyeToyClient::ApplyFunFrame(v - 1);
}
