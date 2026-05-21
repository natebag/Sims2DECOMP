// 0x801E9648 SetVar_EYE_funframeCurrSel::Handler(char*) (56B)

extern "C" int AtoI(char* s);

class EyeToyClient {
public:
    static void ApplyFunFrame(int idx);
};

extern void* g_eyeToyMgr_SDA;

class SetVar_EYE_funframeCurrSel {
public:
    void Handler(char* val);
};

void SetVar_EYE_funframeCurrSel::Handler(char* val) {
    int n = AtoI(val);
    *(int*)((char*)g_eyeToyMgr_SDA + 148) = n;
    EyeToyClient::ApplyFunFrame(n - 1);
}
