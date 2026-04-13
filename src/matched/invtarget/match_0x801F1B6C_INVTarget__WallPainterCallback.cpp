// 0x801F1B6C INVTarget::WallPainterCallback (40B)
struct CallbackData { int pad; void* target; };
extern void INVTarget_WallPainterCallbackImpl(void*, CallbackData*);
void INVTarget_WallPainterCallback(CallbackData* data) {
    void* self = data->target;
    INVTarget_WallPainterCallbackImpl(self, data);
}
