// 0x801E629C (76B) WXFTarget::Shutdown(void) — MI-vcall SendCmd("flowGoto", "Pause") on non-SDA singleton
// Identical bytes to PRGTarget::Shutdown / OnCancelKeyPressed family.

struct FlowDispatcherBase { char pad[128]; };
struct FlowDispatcher : public FlowDispatcherBase {
    virtual void f0() = 0;
    virtual void SendCmd(const char* cmd, const char* arg) = 0;
};

extern char g_flowDispatcher[16];

class WXFTarget {
public:
    void Shutdown(void);
};

void WXFTarget::Shutdown(void) {
    (*(FlowDispatcher**)g_flowDispatcher)->SendCmd("flowGoto", "Pause");
}
