// 0x801E9680 (56B) SetVar_EYE_filterCurrSel::Handler(char *)
// AtoI(arg); save to g_pEyeToy->filterCurrSel (+144); ApplyPresetFilter(val-1).

extern "C" int AtoI(char* s);

class EyeToyClient {
public:
    static void ApplyPresetFilter(int v);
};

struct EyeToyData2 {
    char _pad[144];
    int filterCurrSel;
};

extern EyeToyData2* g_pEyeToy2;

class SetVar_EYE_filterCurrSel {
public:
    void Handler(char* arg);
};

void SetVar_EYE_filterCurrSel::Handler(char* arg)
{
    int v = AtoI(arg);
    g_pEyeToy2->filterCurrSel = v;
    EyeToyClient::ApplyPresetFilter(v - 1);
}
