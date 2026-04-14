// 0x801F15FC INVTarget::PlaceModeCallback(InteractorModule::PlaceManipulator::CallbackData *) (40B)

struct InteractorModule_PlaceManipulator_CallbackData;

struct INVTarget {
    char pad[4];
    INVTarget* m_pImpl;
    void PlaceModeCallbackImpl(InteractorModule_PlaceManipulator_CallbackData* data);
    void PlaceModeCallback(InteractorModule_PlaceManipulator_CallbackData* data);
};

void INVTarget::PlaceModeCallback(InteractorModule_PlaceManipulator_CallbackData* data) {
    m_pImpl->PlaceModeCallbackImpl((InteractorModule_PlaceManipulator_CallbackData*)this);
}
