// 0x801194F0 (64 bytes)
// cSoundCache::onTrackDelete(cTrack *)

class cSoundCache { public: void onTrackDelete(cTrack *); };

__attribute__((naked))
void cSoundCache::onTrackDelete(cTrack *) {
    asm volatile(".long 0x39600000\n.long 0x7C03582E\n.long 0x7C002000\n.long 0x4082000C\n.long 0x7D63592E\n.long 0x4E800020\n.long 0x396B0001\n.long 0x2C0B003F\n.long 0x4D810020\n.long 0x5569103A\n.long 0x7C03482E\n.long 0x7C002000\n.long 0x4082FFE8\n.long 0x38000000\n.long 0x7C03492E\n.long 0x4E800020");
}
