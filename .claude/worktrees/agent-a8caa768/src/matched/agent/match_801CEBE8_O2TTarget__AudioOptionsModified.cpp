// 0x801CEBE8 (84 bytes)
// O2TTarget::AudioOptionsModified(void)

class O2TTarget { public: void AudioOptionsModified(void); };

__attribute__((naked))
void O2TTarget::AudioOptionsModified(void) {
    asm volatile(".long 0x3D208047\n.long 0x896D8BD4\n.long 0x81495F14\n.long 0x880A001C\n.long 0x7C005800\n.long 0x40820038\n.long 0x892A001D\n.long 0x880D8BD5\n.long 0x7C090000\n.long 0x40820028\n.long 0x892A0029\n.long 0x880D8BD6\n.long 0x7C090000\n.long 0x40820018\n.long 0x892A0028\n.long 0x38600000\n.long 0x880D8BD7\n.long 0x7C090000\n.long 0x4D820020\n.long 0x38600001\n.long 0x4E800020");
}
