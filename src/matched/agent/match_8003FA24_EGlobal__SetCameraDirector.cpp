// 0x8003FA24 (8 bytes) — stw 4, 224(3); blr
// EGlobal::SetCameraDirector(CameraDirector *)

class CameraDirector;

class EGlobal {
public:
    void SetCameraDirector(CameraDirector *);
};

__attribute__((naked))
void EGlobal::SetCameraDirector(CameraDirector *) {
    asm volatile(
        "stw 4, 224(3)\n"
        "blr\n"
    );
}
