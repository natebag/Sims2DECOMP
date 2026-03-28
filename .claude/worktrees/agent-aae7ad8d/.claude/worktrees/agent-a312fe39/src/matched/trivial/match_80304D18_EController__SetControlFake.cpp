// 0x80304D18 (8 bytes)
class EController {
public:
    void SetControlFake(int p);
};

void EController::SetControlFake(int p) {
    *(int*)((char*)this + 0x1AC) = p;
}
