// 0x801E6524 (76B) WXFTarget::OnCancelKeyPressed(char*, char*) — identical-bytes sibling
// MI-vcall SendCmd("flowGoto", "Pause")

struct FlowDispatcherBase { char pad[128]; };
struct FlowDispatcher : public FlowDispatcherBase {
    virtual void f0() = 0;
    virtual void SendCmd(const char* cmd, const char* arg) = 0;
};

extern char g_flowDispatcher[16];

class WXFTarget {
public:
    void OnCancelKeyPressed(char* a, char* b);
};

void WXFTarget::OnCancelKeyPressed(char*, char*) {
    (*(FlowDispatcher**)g_flowDispatcher)->SendCmd("flowGoto", "Pause");
}
