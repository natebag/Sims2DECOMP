// 0x800C1C8C (8 bytes) — stw 4, 16(3); blr
// Interaction::SetIconObject(cXObject *)

class cXObject;

class Interaction {
public:
    void SetIconObject(cXObject *);
};

__attribute__((naked))
void Interaction::SetIconObject(cXObject *) {
    asm volatile(
        "stw 4, 16(3)\n"
        "blr\n"
    );
}
