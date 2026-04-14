// 0x801F1B6C INVTarget::WallPainterCallback(InteractorModule::WallPainter::CallbackData *) (40B)

struct InteractorModule_WallPainter_CallbackData;

struct INVTarget {
    char pad[4];
    INVTarget* m_pImpl;
    void WallPainterCallbackImpl(InteractorModule_WallPainter_CallbackData* data);
    void WallPainterCallback(InteractorModule_WallPainter_CallbackData* data);
};

void INVTarget::WallPainterCallback(InteractorModule_WallPainter_CallbackData* data) {
    m_pImpl->WallPainterCallbackImpl((InteractorModule_WallPainter_CallbackData*)this);
}
