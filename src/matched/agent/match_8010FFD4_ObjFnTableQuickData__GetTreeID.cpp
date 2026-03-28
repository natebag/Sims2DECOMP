// 0x8010FFD4 (68 bytes)
// ObjFnTableQuickData::GetTreeID(ObjEntryPoint)

class ObjFnTableQuickData { public: void GetTreeID(ObjEntryPoint); };

__attribute__((naked))
void ObjFnTableQuickData::GetTreeID(ObjEntryPoint) {
    asm volatile(".long 0x38000000\n.long 0x2804001D\n.long 0x41810034\n.long 0x8123000C\n.long 0x2C090000\n.long 0x41820010\n.long 0x7C042214\n.long 0x39290004\n.long 0x48000018\n.long 0x80630010\n.long 0x2C030000\n.long 0x41820010\n.long 0x7C042214\n.long 0x39230004\n.long 0x7C0902AE\n.long 0x7C030378\n.long 0x4E800020");
}
