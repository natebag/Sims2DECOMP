// 0x8009526C (72 bytes)
// PreGameState::PreGameState(int)

class PreGameState { public: void PreGameState(int); };

__attribute__((naked))
void PreGameState::PreGameState(int) {
    asm volatile(".long 0x3D608046\n.long 0x7C691B78\n.long 0x38000000\n.long 0x3940FFFF\n.long 0x39000001\n.long 0x396BE028\n.long 0x90890000\n.long 0x9149000C\n.long 0x91690018\n.long 0x90090028\n.long 0x9109002C\n.long 0x91490004\n.long 0x90090008\n.long 0x90090010\n.long 0x91090014\n.long 0x9009001C\n.long 0x90090024\n.long 0x4E800020");
}
