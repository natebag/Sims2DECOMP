// 0x801F1DDC INVTarget::GrabModeCallback(InteractorModule::GrabManipulator::CallbackData *) (40B)

struct InteractorModule_GrabManipulator_CallbackData;

struct INVTarget {
    char pad[4];
    INVTarget* m_pImpl;
    void GrabModeCallbackImpl(InteractorModule_GrabManipulator_CallbackData* data);
    void GrabModeCallback(InteractorModule_GrabManipulator_CallbackData* data);
};

void INVTarget::GrabModeCallback(InteractorModule_GrabManipulator_CallbackData* data) {
    m_pImpl->GrabModeCallbackImpl((InteractorModule_GrabManipulator_CallbackData*)this);
}
