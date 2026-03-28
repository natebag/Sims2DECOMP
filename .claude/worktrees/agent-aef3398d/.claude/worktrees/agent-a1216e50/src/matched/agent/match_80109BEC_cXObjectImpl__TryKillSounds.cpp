// 0x80109BEC (68 bytes)
// cXObjectImpl::TryKillSounds(StackElem *, KillSoundsParam *)

class cXObjectImpl { public: void TryKillSounds(StackElem *, KillSoundsParam *); };

__attribute__((naked))
void cXObjectImpl::TryKillSounds(StackElem *, KillSoundsParam *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0xA8050000\n.long 0x2C000000\n.long 0x4182000C\n.long 0xA8840004\n.long 0x48000008\n.long 0xA8830064\n.long 0x806DAC0C\n.long 0x4BFADF0D\n.long 0x38600000\n.long 0x38800001\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
