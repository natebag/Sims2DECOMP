// 0x80012C04 (72 bytes)
// AwarenessManager::ClearAwareOfObject(cXObject *)

class AwarenessManager { public: void ClearAwareOfObject(cXObject *); };

__attribute__((naked))
void AwarenessManager::ClearAwareOfObject(cXObject *) {
    asm volatile(".long 0x8003001C\n.long 0x7C040000\n.long 0x40820038\n.long 0x80030000\n.long 0x70090020\n.long 0x41820024\n.long 0x3D20803D\n.long 0x60000008\n.long 0xC009DCCC\n.long 0x39600000\n.long 0x540006F2\n.long 0x9163001C\n.long 0x90030000\n.long 0xD0030020\n.long 0x38600001\n.long 0x4E800020\n.long 0x38600000\n.long 0x4E800020");
}
