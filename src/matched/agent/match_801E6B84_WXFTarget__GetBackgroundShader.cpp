// 0x801E6B84 (84 bytes)
// WXFTarget::GetBackgroundShader(tWantType)

class WXFTarget { public: void GetBackgroundShader(tWantType); };

__attribute__((naked))
void WXFTarget::GetBackgroundShader(tWantType) {
    asm volatile(".long 0x38600000\n.long 0x7C842379\n.long 0x40820010\n.long 0x3C60A0D9\n.long 0x60637DCF\n.long 0x4E800020\n.long 0x2C040080\n.long 0x40820010\n.long 0x3C608CA1\n.long 0x6063C6A6\n.long 0x4E800020\n.long 0x2C040004\n.long 0x40820010\n.long 0x3C604364\n.long 0x6063EFB7\n.long 0x4E800020\n.long 0x2C040001\n.long 0x4C820020\n.long 0x3C60087B\n.long 0x606335FB\n.long 0x4E800020");
}
