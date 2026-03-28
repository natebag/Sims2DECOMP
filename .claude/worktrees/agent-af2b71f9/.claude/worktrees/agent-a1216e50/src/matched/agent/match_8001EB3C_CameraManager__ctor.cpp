// 0x8001EB3C (20 bytes)
// mr r9, r3; li r0, 0; stw r0, 4(r9); stw r0, 0(r9); blr

class CameraManager {
public:
    CameraManager();
};

__attribute__((naked))
CameraManager::CameraManager() {
    asm volatile(
        "mr 9, 3\n"
        "li 0, 0\n"
        "stw 0, 4(9)\n"
        "stw 0, 0(9)\n"
        "blr\n"
    );
}
