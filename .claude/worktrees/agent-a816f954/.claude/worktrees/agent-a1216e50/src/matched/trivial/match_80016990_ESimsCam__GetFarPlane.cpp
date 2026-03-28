// 0x80016990 (8 bytes)
class ESimsCam {
public:
    float GetFarPlane();
};

float ESimsCam::GetFarPlane() {
    return *(float*)((char*)(*(int*)((char*)this + 0x0)) + 0x68);
}
