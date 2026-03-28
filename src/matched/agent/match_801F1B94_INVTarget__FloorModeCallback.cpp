namespace InteractorModule {
    class FloorPainter {
    public:
        struct CallbackData {
            int field0;
            void* obj;
        };
    };
}

class INVTarget {
public:
    void FloorModeCallbackImpl(InteractorModule::FloorPainter::CallbackData *data);
    static void FloorModeCallback(InteractorModule::FloorPainter::CallbackData *data);
};

void INVTarget::FloorModeCallback(InteractorModule::FloorPainter::CallbackData *data) {
    ((INVTarget*)data->obj)->FloorModeCallbackImpl(data);
}
