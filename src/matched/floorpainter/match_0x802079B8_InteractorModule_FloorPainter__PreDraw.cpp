// 0x802079B8 InteractorModule::FloorPainter::PreDraw(InteractorVisualizer&) (44B)
// Arg-swap thunk
struct FloorPainter;
struct InteractorVisualizer;

extern void FloorPainter__PreDrawImpl(InteractorVisualizer& vis, FloorPainter* self);

void FloorPainter__PreDraw(FloorPainter* self, InteractorVisualizer& vis) {
    FloorPainter__PreDrawImpl(vis, self);
}
