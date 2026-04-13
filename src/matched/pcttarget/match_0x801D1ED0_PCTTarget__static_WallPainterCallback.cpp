// 0x801D1ED0 PCTTarget::static_WallPainterCallback (48B)
struct CallbackData { int pad; void* target; };
extern void PCTTarget_WallPainterCallback(void*, CallbackData*);
void PCTTarget_static_WallPainterCallback(CallbackData* data) {
    void* self = data->target;
    if (self != 0) {
        PCTTarget_WallPainterCallback(self, data);
    }
}
