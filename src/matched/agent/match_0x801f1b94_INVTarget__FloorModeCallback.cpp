// 0x801F1B94 INVTarget::FloorModeCallback(InteractorModule::FloorPainter::CallbackData *) (40B)

struct InteractorModule_FloorPainter_CallbackData;

struct INVTarget {
    char pad[4];
    INVTarget* m_pImpl;
    void FloorModeCallbackImpl(InteractorModule_FloorPainter_CallbackData* data);
    void FloorModeCallback(InteractorModule_FloorPainter_CallbackData* data);
};

void INVTarget::FloorModeCallback(InteractorModule_FloorPainter_CallbackData* data) {
    m_pImpl->FloorModeCallbackImpl((InteractorModule_FloorPainter_CallbackData*)this);
}
