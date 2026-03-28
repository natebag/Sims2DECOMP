// 0x80138C20 (116 bytes)
// SpacePartition::SpacePartition(void)

class SpacePartition { public: void SpacePartition(void); };

__attribute__((naked))
void SpacePartition::SpacePartition(void) {
    asm volatile(".long 0x9421FFD0\n.long 0x7C691B78\n.long 0x38000000\n.long 0x9009000C\n.long 0x39690014\n.long 0x90090010\n.long 0x3949001C\n.long 0x900B0004\n.long 0x39090024\n.long 0x9009001C\n.long 0x3969002C\n.long 0x900A0004\n.long 0x38E90034\n.long 0x90080004\n.long 0x38C9003C\n.long 0x9009002C\n.long 0x39490044\n.long 0x900B0004\n.long 0x3909004C\n.long 0x90070004\n.long 0x39690054\n.long 0x9009003C\n.long 0x90060004\n.long 0x900A0004\n.long 0x9009004C\n.long 0x90080004\n.long 0x900B0004\n.long 0x38210030\n.long 0x4E800020");
}
