// 0x801D1E70 PCTTarget::static_PlaceModeCallback (48B)
struct CallbackData { int pad; void* target; };
extern void PCTTarget_PlaceModeCallback(void*, CallbackData*);
void PCTTarget_static_PlaceModeCallback(CallbackData* data) {
    void* self = data->target;
    if (self != 0) {
        PCTTarget_PlaceModeCallback(self, data);
    }
}
