// 0x80305894 (8 bytes)
class EController {
public:
    int GetStatus();
};

int EController::GetStatus() {
    return *(int*)((char*)this + 0x4);
}
