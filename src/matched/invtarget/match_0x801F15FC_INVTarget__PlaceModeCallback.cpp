// 0x801F15FC INVTarget::PlaceModeCallback (40B)
struct CallbackData { int pad; void* target; };
extern void INVTarget_PlaceModeCallbackImpl(void*, CallbackData*);
void INVTarget_PlaceModeCallback(CallbackData* data) {
    void* self = data->target;
    INVTarget_PlaceModeCallbackImpl(self, data);
}
