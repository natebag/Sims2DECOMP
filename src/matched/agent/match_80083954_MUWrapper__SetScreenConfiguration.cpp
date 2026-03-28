// 0x80083954 (8 bytes) — stw 4, 172(3); blr
// MUWrapper::SetScreenConfiguration(MUWrapper::eMUScreenConfiguration)

class MUWrapper {
public:
    void SetScreenConfiguration(MUWrapper::eMUScreenConfiguration);
};

__attribute__((naked))
void MUWrapper::SetScreenConfiguration(MUWrapper::eMUScreenConfiguration) {
    asm volatile(
        "stw 4, 172(3)
"
        "blr
"
    );
}
