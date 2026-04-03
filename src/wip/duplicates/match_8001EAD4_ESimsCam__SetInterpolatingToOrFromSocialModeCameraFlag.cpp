// 0x8001EAD4 (8 bytes)
class ESimsCam {
public:
    void SetInterpolatingToOrFromSocialModeCameraFlag(int p);
};

void ESimsCam::SetInterpolatingToOrFromSocialModeCameraFlag(int p) {
    *(int*)((char*)this + 0x564) = p;
}
