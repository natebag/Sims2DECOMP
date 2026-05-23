// 0x8003FA24 EGlobal::SetCameraDirector(CameraDirector (8 B)
struct EGlobal { char _pad[0xe0]; unsigned m_cameraDirector; void SetCameraDirector(unsigned); };
void EGlobal::SetCameraDirector(unsigned cd) { m_cameraDirector = cd; }
