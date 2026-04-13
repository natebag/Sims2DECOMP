// 0x8001ECA0 (12 bytes) — slwi r4, r4, 2; lwzx r3, r3, r4; blr
// Array load: return this[index] (pointer array indexed by int)

class ESimsCam;

class CameraManager {
public:
    ESimsCam* m_cameras[4];

    ESimsCam* GetCamera(int index);
};

ESimsCam* CameraManager::GetCamera(int index) {
    return m_cameras[index];
}
