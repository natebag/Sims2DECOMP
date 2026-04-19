// 0x801ACA0C (76B) E2ETarget::OnShutdown(void)
// MI-vcall FlowGoto+Pause sibling — identical bytes to PRG/WXF Shutdown family.

struct FlowDispatcherBase { char pad[128]; };
struct FlowDispatcher : public FlowDispatcherBase {
    virtual void f0() = 0;
    virtual void SendCmd(const char* cmd, const char* arg) = 0;
};

extern char g_flowDispatcher[16];

class E2ETarget {
public:
    void OnShutdown(void);
};

void E2ETarget::OnShutdown(void) {
    (*(FlowDispatcher**)g_flowDispatcher)->SendCmd("flowGoto", "Pause");
}
