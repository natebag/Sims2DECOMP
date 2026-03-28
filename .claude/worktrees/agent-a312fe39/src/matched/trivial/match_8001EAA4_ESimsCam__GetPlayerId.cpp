// 0x8001EAA4 (8 bytes)
class ESimsCam {
public:
    int GetPlayerId();
};

int ESimsCam::GetPlayerId() {
    return *(int*)((char*)this + 0x4);
}
