// 0x8021A03C (8 bytes)
class InteractorModule {
public:
    class ObjectManipulator {
    public:
        int GetIsCursorModelEnabled();
    };
};

int InteractorModule::ObjectManipulator::GetIsCursorModelEnabled() {
    return *(int*)((char*)this + 0xA8);
}
