// 0x801C10C8 (64 bytes)
// M2MTarget::OnGetNumItems(M2MTarget::ResultStruct &)

class M2MTarget { public: void OnGetNumItems(M2MTarget::ResultStruct &); };

__attribute__((naked))
void M2MTarget::OnGetNumItems(M2MTarget::ResultStruct &) {
    asm volatile(".long 0x80040000\n.long 0x38600000\n.long 0x2C0000FF\n.long 0x4082000C\n.long 0x38600002\n.long 0x4E800020\n.long 0x80040004\n.long 0x2C0000FF\n.long 0x4082000C\n.long 0x38600008\n.long 0x4E800020\n.long 0x80040008\n.long 0x2C000000\n.long 0x4C820020\n.long 0x38600004\n.long 0x4E800020");
}
