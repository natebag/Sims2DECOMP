// 0x802F249C (8 bytes)
class EMirrorPortal {
public:
    void SetNumCorners(int p);
};

void EMirrorPortal::SetNumCorners(int p) {
    *(int*)((char*)this + 0x38) = p;
}
