namespace InteractorModule {
    class GrabManipulator {
    public:
        struct CallbackData {
            int field0;
            void* obj;
        };
    };
}

class INVTarget {
public:
    void GrabModeCallbackImpl(InteractorModule::GrabManipulator::CallbackData *data);
    static void GrabModeCallback(InteractorModule::GrabManipulator::CallbackData *data);
};

void INVTarget::GrabModeCallback(InteractorModule::GrabManipulator::CallbackData *data) {
    ((INVTarget*)data->obj)->GrabModeCallbackImpl(data);
}
