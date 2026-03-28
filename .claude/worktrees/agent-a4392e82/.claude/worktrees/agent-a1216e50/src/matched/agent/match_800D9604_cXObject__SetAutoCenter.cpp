// 0x800D9604 (8 bytes) — stw 3, -31904(13); blr
// cXObject::SetAutoCenter(bool)

class cXObject {
public:
    void SetAutoCenter(bool);
};

__attribute__((naked))
void cXObject::SetAutoCenter(bool) {
    asm volatile(
        "stw 3, -31904(13)\n"
        "blr\n"
    );
}
