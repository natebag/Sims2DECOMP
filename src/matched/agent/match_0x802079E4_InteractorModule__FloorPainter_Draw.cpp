// FloorPainter_Draw at 0x802079E4 (44B)
// InteractorModule PreDraw/Draw template — matches 10 functions:
// 0x80205014 DirectInteractor::PreDraw
// 0x80205040 DirectInteractor::Draw
// 0x802079b8 FloorPainter::PreDraw
// 0x802079e4 FloorPainter::Draw
// 0x80219488 ObjectManipulator::PreDraw
// 0x802194b4 ObjectManipulator::Draw
// 0x8021e018 SimInteractor::PreDraw
// 0x8021e044 SimInteractor::Draw
// 0x8021f41c SocialModeInteractor::PreDraw
// 0x8021f448 SocialModeInteractor::Draw

struct InteractorModule_InteractorVisualizer;
struct InteractorModule_DirectInteractor;

extern void InteractorVisualizer_Callback(InteractorModule_InteractorVisualizer*, InteractorModule_DirectInteractor*);

void InteractorModule_DirectInteractor_Callback(void* self, InteractorModule_InteractorVisualizer* vis) {
    InteractorVisualizer_Callback(vis, (InteractorModule_DirectInteractor*)self);
}
