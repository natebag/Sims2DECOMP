// 0x800DB9A0 (8 bytes) — stw 3, -31908(13); blr
// cXObject::SetGlobalFreeWillOverride(bool)

class cXObject {
public:
    void SetGlobalFreeWillOverride(bool);
};

__attribute__((naked))
void cXObject::SetGlobalFreeWillOverride(bool) {
    asm volatile(
        "stw 3, -31908(13)\n"
        "blr\n"
    );
}
