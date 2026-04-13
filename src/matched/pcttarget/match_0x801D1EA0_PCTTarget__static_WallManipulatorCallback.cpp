// 0x801D1EA0 PCTTarget::static_WallManipulatorCallback (48B)
struct CallbackData { int pad; void* target; };
extern void PCTTarget_WallManipulatorCallback(void*, CallbackData*);
void PCTTarget_static_WallManipulatorCallback(CallbackData* data) {
    void* self = data->target;
    if (self != 0) {
        PCTTarget_WallManipulatorCallback(self, data);
    }
}
