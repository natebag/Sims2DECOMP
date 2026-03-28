namespace InteractorModule {
    class WallPainter {
    public:
        struct CallbackData {
            int field0;
            void* obj;
        };
    };
}

class INVTarget {
public:
    void WallPainterCallbackImpl(InteractorModule::WallPainter::CallbackData *data);
    static void WallPainterCallback(InteractorModule::WallPainter::CallbackData *data);
};

void INVTarget::WallPainterCallback(InteractorModule::WallPainter::CallbackData *data) {
    ((INVTarget*)data->obj)->WallPainterCallbackImpl(data);
}
