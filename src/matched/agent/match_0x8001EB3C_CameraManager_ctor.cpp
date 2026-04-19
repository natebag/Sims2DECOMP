// 0x8001EB3C (20B) CameraManager::CameraManager(void)
// Zero-init 8B via volatile int* to force `mr r9, r3` save.

class CameraManager {
public:
    int m_field_0;
    int m_field_4;
    CameraManager(void);
};

CameraManager::CameraManager(void) {
    volatile int* p = (volatile int*)this;
    p[1] = 0;
    p[0] = 0;
}
