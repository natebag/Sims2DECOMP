// 0x80177CC8 (68B) UIObjectBase::UIRouter_SetVariable(char* name, char* value)
// MI-vcall forwards both args straight to g_flowDispatcher->SendCmd(name, value)

struct FlowDispatcherBase { char pad[128]; };
struct FlowDispatcher : public FlowDispatcherBase {
    virtual void f0() = 0;
    virtual void SendCmd(const char* name, const char* value) = 0;
};

extern char g_flowDispatcher[16];

namespace UIObjectBase {
    void UIRouter_SetVariable(char* name, char* value) {
        (*(FlowDispatcher**)g_flowDispatcher)->SendCmd(name, value);
    }
}
