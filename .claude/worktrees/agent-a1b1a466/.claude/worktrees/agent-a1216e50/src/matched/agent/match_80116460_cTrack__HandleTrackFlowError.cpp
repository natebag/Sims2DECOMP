// 0x80116460 (68 bytes)
// cTrack::HandleTrackFlowError(char *)

class cTrack { public: void HandleTrackFlowError(char *); };

__attribute__((naked))
void cTrack::HandleTrackFlowError(char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x801F0000\n.long 0x2C000000\n.long 0x4182000C\n.long 0x387F002C\n.long 0x4BFFFFD9\n.long 0x7FE3FB78\n.long 0x480018F9\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
