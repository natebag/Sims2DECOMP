// 0x80304294 (8 bytes)
class EController {
public:
    void OverrideStatus(int p);
};

void EController::OverrideStatus(int p) {
    *(int*)((char*)this + 0x4) = p;
}
