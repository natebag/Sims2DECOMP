// 0x802F2550 (8 bytes)
class EMirrorPortal {
public:
    void SetFieldOfView(float p);
};

void EMirrorPortal::SetFieldOfView(float p) {
    *(float*)((char*)this + 0x0) = p;
}
