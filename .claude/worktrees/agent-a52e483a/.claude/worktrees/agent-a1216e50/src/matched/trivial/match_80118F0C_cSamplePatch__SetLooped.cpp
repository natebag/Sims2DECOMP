// 0x80118F0C (8 bytes)
class cSamplePatch {
public:
    void SetLooped(int p);
};

void cSamplePatch::SetLooped(int p) {
    *(int*)((char*)this + 0x10) = p;
}
