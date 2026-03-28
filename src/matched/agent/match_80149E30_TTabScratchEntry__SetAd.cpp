// 0x80149E30 (72 bytes)
// TTabScratchEntry::SetAd(int, ITreeTableAd &)

class TTabScratchEntry { public: void SetAd(int, ITreeTableAd &); };

__attribute__((naked))
void TTabScratchEntry::SetAd(int, ITreeTableAd &) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x54842036\n.long 0x7D241A14\n.long 0x81690008\n.long 0x38840008\n.long 0x7C632214\n.long 0xA80B0020\n.long 0x7CA42B78\n.long 0x812B0024\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
