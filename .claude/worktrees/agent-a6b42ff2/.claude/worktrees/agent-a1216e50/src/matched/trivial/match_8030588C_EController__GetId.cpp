// 0x8030588C (8 bytes)
class EController {
public:
    int GetId();
};

int EController::GetId() {
    return *(int*)((char*)this + 0x0);
}
