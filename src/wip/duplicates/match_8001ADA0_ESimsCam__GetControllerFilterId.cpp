// 0x8001ADA0 (8 bytes)
class ESimsCam {
public:
    int GetControllerFilterId();
};

int ESimsCam::GetControllerFilterId() {
    return *(int*)((char*)this + 0x560);
}
