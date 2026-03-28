// 0x80116EE8 (104 bytes)
// cHitMan::AddToUpdateList(cTrack *)

class cHitMan { public: void AddToUpdateList(cTrack *); };

__attribute__((naked))
void cHitMan::AddToUpdateList(cTrack *) {
    asm volatile(".long 0x9421FFD8\n.long 0x7C0802A6\n.long 0xBFA1001C\n.long 0x9001002C\n.long 0x7C7E1B78\n.long 0x7C9D2378\n.long 0x48000051\n.long 0x801E0008\n.long 0x3860000C\n.long 0x90010010\n.long 0x482853F5\n.long 0x7C6B1B78\n.long 0x93AB0008\n.long 0x38600001\n.long 0x81210010\n.long 0x81490004\n.long 0x912B0000\n.long 0x914B0004\n.long 0x916A0000\n.long 0x91690004\n.long 0x91610008\n.long 0x8001002C\n.long 0x7C0803A6\n.long 0xBBA1001C\n.long 0x38210028\n.long 0x4E800020");
}
