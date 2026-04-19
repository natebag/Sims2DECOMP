// 0x801CEAC0 (108B) O2TTarget::Shutdown(char*, char*)
// Guarded FlowGoto+Pause: skips unless both m_90 and m_248 are 0, then sets m_254=1 and dispatches.

struct FlowDispatcherBase { char pad[128]; };
struct FlowDispatcher : public FlowDispatcherBase {
    virtual void f0() = 0;
    virtual void SendCmd(const char* cmd, const char* arg) = 0;
};

extern char g_flowDispatcher[16];

class O2TTarget {
public:
    char pad_000[0x90];
    int m_field_090;
    char pad_094[0x248 - 0x94];
    int m_field_248;
    char pad_24c[0x254 - 0x24c];
    int m_field_254;

    void Shutdown(char* a, char* b);
};

void O2TTarget::Shutdown(char*, char*) {
    if (m_field_090 != 0) return;
    if (m_field_248 != 0) return;
    m_field_254 = 1;
    (*(FlowDispatcher**)g_flowDispatcher)->SendCmd("flowGoto", "Pause");
}
