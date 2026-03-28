// 0x8005634C (8 bytes) — stw 4, 808(3); blr
// ISimInstance::SetXOb(cXObject *)

class ISimInstance {
public:
    void SetXOb(cXObject *);
};

__attribute__((naked))
void ISimInstance::SetXOb(cXObject *) {
    asm volatile(
        "stw 4, 808(3)\n"
        "blr\n"
    );
}
