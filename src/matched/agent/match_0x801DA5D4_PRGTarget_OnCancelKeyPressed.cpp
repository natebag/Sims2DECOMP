// 0x801DA5D4 (76B) PRGTarget::OnCancelKeyPressed(char*, char*) — identical-bytes sibling to PRGTarget::Shutdown
// MI-vcall SendCmd("flowGoto", "Pause") — args a/b are discarded.

struct FlowDispatcherBase { char pad[128]; };
struct FlowDispatcher : public FlowDispatcherBase {
    virtual void f0() = 0;
    virtual void SendCmd(const char* cmd, const char* arg) = 0;
};

extern char g_flowDispatcher[16];

class PRGTarget {
public:
    void OnCancelKeyPressed(char* a, char* b);
};

void PRGTarget::OnCancelKeyPressed(char*, char*) {
    (*(FlowDispatcher**)g_flowDispatcher)->SendCmd("flowGoto", "Pause");
}
