// 0x80016044 (40 bytes) — Clamp and copy camera parameters

struct SimsCameraParameters {
    void Validate();
};

__attribute__((naked))
void SimsCameraParameters::Validate() {
    asm volatile(
        "lfs 13, 0x28(3)\n"
        "lfs 0, 0x2C(3)\n"
        "fcmpu 0, 0, 13\n"
        "bge 1f\n"
        "stfs 13, 0x2C(3)\n"
        "1:\n"
        "lfs 0, 0x38(3)\n"
        "lfs 13, 0x28(3)\n"
        "stfs 0, 0xB4(3)\n"
        "stfs 13, 0xB8(3)\n"
        "blr\n"
    );
}
