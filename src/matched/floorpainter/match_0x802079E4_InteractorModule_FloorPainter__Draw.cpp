// 0x802079E4 InteractorModule::FloorPainter::Draw(InteractorVisualizer&) (44B)
// Arg-swap thunk
struct FloorPainter;
struct InteractorVisualizer;

extern void FloorPainter__DrawImpl(InteractorVisualizer& vis, FloorPainter* self);

void FloorPainter__Draw(FloorPainter* self, InteractorVisualizer& vis) {
    FloorPainter__DrawImpl(vis, self);
}
