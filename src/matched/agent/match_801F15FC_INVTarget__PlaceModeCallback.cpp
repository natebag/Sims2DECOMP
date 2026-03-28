namespace InteractorModule {
    class PlaceManipulator {
    public:
        struct CallbackData {
            int field0;
            void* obj;
        };
    };
}

class INVTarget {
public:
    void PlaceModeCallbackImpl(InteractorModule::PlaceManipulator::CallbackData *data);
    static void PlaceModeCallback(InteractorModule::PlaceManipulator::CallbackData *data);
};

void INVTarget::PlaceModeCallback(InteractorModule::PlaceManipulator::CallbackData *data) {
    ((INVTarget*)data->obj)->PlaceModeCallbackImpl(data);
}
