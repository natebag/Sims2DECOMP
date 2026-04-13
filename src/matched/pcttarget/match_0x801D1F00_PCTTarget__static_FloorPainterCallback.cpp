// 0x801D1F00 PCTTarget::static_FloorPainterCallback (48B)
struct CallbackData { int pad; void* target; };
extern void PCTTarget_FloorPainterCallback(void*, CallbackData*);
void PCTTarget_static_FloorPainterCallback(CallbackData* data) {
    void* self = data->target;
    if (self != 0) {
        PCTTarget_FloorPainterCallback(self, data);
    }
}
