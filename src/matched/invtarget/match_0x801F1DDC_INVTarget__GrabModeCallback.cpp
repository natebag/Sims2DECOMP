// 0x801F1DDC INVTarget::GrabModeCallback (40B)
struct CallbackData { int pad; void* target; };
extern void INVTarget_GrabModeCallbackImpl(void*, CallbackData*);
void INVTarget_GrabModeCallback(CallbackData* data) {
    void* self = data->target;
    INVTarget_GrabModeCallbackImpl(self, data);
}
