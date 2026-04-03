// 0x8001eb3c (20 bytes) — VERIFIED MATCH
// CameraManager::CameraManager(void) — zeros two fields
struct CameraManager_C { int b; int a; CameraManager_C(); };
CameraManager_C::CameraManager_C() : b(0), a(0) {}
