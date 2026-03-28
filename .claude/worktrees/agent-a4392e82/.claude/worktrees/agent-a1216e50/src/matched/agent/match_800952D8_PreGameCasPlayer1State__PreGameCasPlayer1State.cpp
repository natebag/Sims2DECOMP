// 0x800952D8 (76 bytes)
// PreGameCasPlayer1State::PreGameCasPlayer1State(int)

class PreGameCasPlayer1State { public: void PreGameCasPlayer1State(int); };

__attribute__((naked))
void PreGameCasPlayer1State::PreGameCasPlayer1State(int) {
    asm volatile(".long 0x3D608046\n.long 0x7C691B78\n.long 0x38000000\n.long 0x3900FFFF\n.long 0x396BDFE0\n.long 0x39400001\n.long 0x90890000\n.long 0x9109000C\n.long 0x91490014\n.long 0x9009002C\n.long 0x91690018\n.long 0x91090004\n.long 0x90090008\n.long 0x90090010\n.long 0x9009001C\n.long 0x90090020\n.long 0x90090024\n.long 0x90090028\n.long 0x4E800020");
}
