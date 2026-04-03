// 0x8021A034 (8 bytes)
class InteractorModule {
public:
    class ObjectManipulator {
    public:
        void SetIsCursorModelEnabled(int p);
    };
};

void InteractorModule::ObjectManipulator::SetIsCursorModelEnabled(int p) {
    *(int*)((char*)this + 0xA8) = p;
}
