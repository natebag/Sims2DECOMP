// 0x8008395C (8 bytes) — stw 4, 200(3); blr
// MUWrapper::SetBackgroundDrawEnable(bool)

class MUWrapper {
public:
    void SetBackgroundDrawEnable(bool);
};

__attribute__((naked))
void MUWrapper::SetBackgroundDrawEnable(bool) {
    asm volatile(
        "stw 4, 200(3)
"
        "blr
"
    );
}
