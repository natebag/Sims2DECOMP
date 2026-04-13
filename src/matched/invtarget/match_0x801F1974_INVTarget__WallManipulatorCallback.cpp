// 0x801F1974 INVTarget::WallManipulatorCallback (40B)
struct CallbackData { int pad; void* target; };
extern void INVTarget_WallManipulatorCallbackImpl(void*, CallbackData*);
void INVTarget_WallManipulatorCallback(CallbackData* data) {
    void* self = data->target;
    INVTarget_WallManipulatorCallbackImpl(self, data);
}
