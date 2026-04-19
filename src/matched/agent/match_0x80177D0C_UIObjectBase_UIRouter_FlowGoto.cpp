// 0x80177D0C (72B) UIObjectBase::UIRouter_FlowGoto(char* dest)
// MI-vcall dispatch: g_flowDispatcher->SendCmd("flowGoto", dest)

struct FlowDispatcherBase { char pad[128]; };
struct FlowDispatcher : public FlowDispatcherBase {
    virtual void f0() = 0;
    virtual void SendCmd(const char* cmd, const char* arg) = 0;
};

extern char g_flowDispatcher[16];

namespace UIObjectBase {
    void UIRouter_FlowGoto(char* dest) {
        (*(FlowDispatcher**)g_flowDispatcher)->SendCmd("flowGoto", dest);
    }
}
