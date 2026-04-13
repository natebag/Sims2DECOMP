// 0x801D1E40 PCTTarget::static_GrabManipulatorCallback (48B)
struct CallbackData { int pad; void* target; };
extern void PCTTarget_GrabManipulatorCallback(void*, CallbackData*);
void PCTTarget_static_GrabManipulatorCallback(CallbackData* data) {
    void* self = data->target;
    if (self != 0) {
        PCTTarget_GrabManipulatorCallback(self, data);
    }
}
