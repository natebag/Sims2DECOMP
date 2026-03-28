namespace InteractorModule {
    class WallManipulator {
    public:
        struct CallbackData {
            int field0;
            void* obj;
        };
    };
}

class INVTarget {
public:
    void WallManipulatorCallbackImpl(InteractorModule::WallManipulator::CallbackData *data);
    static void WallManipulatorCallback(InteractorModule::WallManipulator::CallbackData *data);
};

void INVTarget::WallManipulatorCallback(InteractorModule::WallManipulator::CallbackData *data) {
    ((INVTarget*)data->obj)->WallManipulatorCallbackImpl(data);
}
