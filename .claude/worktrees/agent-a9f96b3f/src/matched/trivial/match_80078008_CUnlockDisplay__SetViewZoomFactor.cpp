// 0x80078008 (8 bytes)
class CUnlockDisplay {
public:
    void SetViewZoomFactor(float p);
};

void CUnlockDisplay::SetViewZoomFactor(float p) {
    *(float*)((char*)this + 0x498) = p;
}
