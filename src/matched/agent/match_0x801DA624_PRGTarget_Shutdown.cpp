// 0x801DA624 (76B) PRGTarget::Shutdown(void) — MI-vcall SendCmd("flowGoto", "Pause") on non-SDA singleton
// Secondary vtable at object offset 0x80 (MI), slot 2 = SendCmd(const char*, const char*)

struct FlowDispatcherBase { char pad[128]; };
struct FlowDispatcher : public FlowDispatcherBase {
    virtual void f0() = 0;
    virtual void SendCmd(const char* cmd, const char* arg) = 0;
};

extern char g_flowDispatcher[16];

class PRGTarget {
public:
    void Shutdown(void);
};

void PRGTarget::Shutdown(void) {
    (*(FlowDispatcher**)g_flowDispatcher)->SendCmd("flowGoto", "Pause");
}
