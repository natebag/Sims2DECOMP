// 0x801701DC (64 bytes)
// CasSimRendererDynamic::IsShirtIdleAnim(unsigned int)

class CasSimRendererDynamic { public: void IsShirtIdleAnim(unsigned int); };

__attribute__((naked))
void CasSimRendererDynamic::IsShirtIdleAnim(unsigned int) {
    asm volatile(".long 0x81230224\n.long 0x38600000\n.long 0x80090028\n.long 0x7C040000\n.long 0x41820028\n.long 0x80090060\n.long 0x7C040000\n.long 0x4182001C\n.long 0x8009002C\n.long 0x7C040000\n.long 0x41820010\n.long 0x80090030\n.long 0x7C040000\n.long 0x4C820020\n.long 0x38600001\n.long 0x4E800020");
}
