// 0x80012258 (88 bytes)
// AwarenessManager::AwarenessAutoRunCheck(float)

class AwarenessManager { public: void AwarenessAutoRunCheck(float); };

__attribute__((naked))
void AwarenessManager::AwarenessAutoRunCheck(float) {
    asm volatile(".long 0x80030000\n.long 0xFC000890\n.long 0x38600000\n.long 0x70090001\n.long 0x41820020\n.long 0x3D20803D\n.long 0xC029DC84\n.long 0xFC000800\n.long 0x4C620B82\n.long 0x4C830020\n.long 0x38600001\n.long 0x4E800020\n.long 0x800D8048\n.long 0x2C000001\n.long 0x4C820020\n.long 0x3D20803D\n.long 0xC029DC88\n.long 0xFC000800\n.long 0x4C620B82\n.long 0x4C830020\n.long 0x38600001\n.long 0x4E800020");
}
