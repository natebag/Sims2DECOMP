// 0x8001EA34 (8 bytes)
class ESimsCam {
public:
    int GetTarget();
};

int ESimsCam::GetTarget() {
    return (int)((char*)this + 0x43C);
}
