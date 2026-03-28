// 0x8001606C (20 bytes)
// mr r9, r3; li r0, 0; stw r0, 0(r9); stw r4, 4(r9); blr

struct SimsCameraParameters;

class CameraMotionSystem {
public:
    CameraMotionSystem(SimsCameraParameters* params);
};

__attribute__((naked))
CameraMotionSystem::CameraMotionSystem(SimsCameraParameters* params) {
    asm volatile(
        "mr 9, 3\n"
        "li 0, 0\n"
        "stw 0, 0(9)\n"
        "stw 4, 4(9)\n"
        "blr\n"
    );
}
