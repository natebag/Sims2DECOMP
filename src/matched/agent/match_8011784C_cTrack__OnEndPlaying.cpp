// 0x8011784C (84 bytes)
// cTrack::OnEndPlaying(void)

class cTrack { public: void OnEndPlaying(void); };

__attribute__((naked))
void cTrack::OnEndPlaying(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x813F0000\n.long 0x8809001C\n.long 0x70090001\n.long 0x41820010\n.long 0x38800011\n.long 0x38A00000\n.long 0x48000685\n.long 0x813F0000\n.long 0x8869001B\n.long 0x20030000\n.long 0x7C601914\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
