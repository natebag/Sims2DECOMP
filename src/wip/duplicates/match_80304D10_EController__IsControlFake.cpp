// 0x80304D10 (8 bytes)
class EController {
public:
    int IsControlFake();
};

int EController::IsControlFake() {
    return *(int*)((char*)this + 0x1AC);
}
