// 0x800663A0 (72 bytes)
// SAnimator2::triggerCameraBloom(CameraBloomDataElement *)

struct CameraBloomDataElement;
class SAnimator2 { public: void triggerCameraBloom(CameraBloomDataElement *); };

__attribute__((naked))
void SAnimator2::triggerCameraBloom(CameraBloomDataElement *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x816D98E8\n.long 0xC084000C\n.long 0x812B0000\n.long 0xC0240000\n.long 0xA86901A8\n.long 0x800901AC\n.long 0x7C6B1A14\n.long 0xC0440004\n.long 0xC0640008\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
