// 0x801F1B94 INVTarget::FloorModeCallback (40B)
struct CallbackData { int pad; void* target; };
extern void INVTarget_FloorModeCallbackImpl(void*, CallbackData*);
void INVTarget_FloorModeCallback(CallbackData* data) {
    void* self = data->target;
    INVTarget_FloorModeCallbackImpl(self, data);
}
