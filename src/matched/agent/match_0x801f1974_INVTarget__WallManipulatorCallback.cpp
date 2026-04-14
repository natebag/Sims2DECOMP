// 0x801F1974 INVTarget::WallManipulatorCallback(InteractorModule::WallManipulator::CallbackData *) (40B)

struct InteractorModule_WallManipulator_CallbackData;

struct INVTarget {
    char pad[4];
    INVTarget* m_pImpl;
    void WallManipulatorCallbackImpl(InteractorModule_WallManipulator_CallbackData* data);
    void WallManipulatorCallback(InteractorModule_WallManipulator_CallbackData* data);
};

void INVTarget::WallManipulatorCallback(InteractorModule_WallManipulator_CallbackData* data) {
    m_pImpl->WallManipulatorCallbackImpl((InteractorModule_WallManipulator_CallbackData*)this);
}
