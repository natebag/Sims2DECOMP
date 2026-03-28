// 0x8003FA14 (8 bytes) — stw r4, 0xD0(r3); blr

class EGlobal {
public:
    char _pad[0xD0];
    void* m_cam;

    void SetCam(void* cam);
};

void EGlobal::SetCam(void* cam) {
    m_cam = cam;
}
