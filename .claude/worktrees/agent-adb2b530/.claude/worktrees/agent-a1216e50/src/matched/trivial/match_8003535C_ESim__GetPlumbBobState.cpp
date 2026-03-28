// 0x8003535C (8 bytes)
class ESim {
public:
    int GetPlumbBobState();
};

int ESim::GetPlumbBobState() {
    return *(int*)((char*)this + 0x3EC);
}
