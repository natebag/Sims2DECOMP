// 0x8021A8D0 (8 bytes)
class InteractorModule {
public:
    class ObjectManipulator {
    public:
        int GetPlacementObject();
    };
};

int InteractorModule::ObjectManipulator::GetPlacementObject() {
    return (int)((char*)this + 0x64);
}
