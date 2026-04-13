// 0x8001EC94 (12 bytes) — slwi r4, r4, 2; stwx r5, r3, r4; blr
// Array store: this[index] = camera (pointer array indexed by int)

class ESimsCam;

class CameraManager {
public:
    ESimsCam* m_cameras[4];

    void SetCamera(int index, ESimsCam* cam);
};

void CameraManager::SetCamera(int index, ESimsCam* cam) {
    m_cameras[index] = cam;
}
