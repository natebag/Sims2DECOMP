// 0x80304D20 (8 bytes)
class EController {
public:
    void SetFakeButtons(int p);
};

void EController::SetFakeButtons(int p) {
    *(int*)((char*)this + 0x1B0) = p;
}
