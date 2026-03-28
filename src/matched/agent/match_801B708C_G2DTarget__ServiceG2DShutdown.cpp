// 0x801B708C (116 bytes)
// G2DTarget::ServiceG2DShutdown(void)

class G2DTarget { public: void ServiceG2DShutdown(void); };

__attribute__((naked))
void G2DTarget::ServiceG2DShutdown(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x801F0134\n.long 0x38600000\n.long 0x2C000002\n.long 0x41810010\n.long 0x2C000001\n.long 0x40800024\n.long 0x48000024\n.long 0x2C000003\n.long 0x40820010\n.long 0x7FE3FB78\n.long 0x4BFFE8F9\n.long 0x4800000C\n.long 0x2C000006\n.long 0x41810008\n.long 0x38600001\n.long 0x801F0098\n.long 0x2C000000\n.long 0x41820008\n.long 0x38600001\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
