// 0x80037A5C (64 bytes)
// EyeToyClient::ReleaseTexture(ETexture *)

class EyeToyClient { public: void ReleaseTexture(ETexture *); };

__attribute__((naked))
void EyeToyClient::ReleaseTexture(ETexture *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C641B79\n.long 0x41820020\n.long 0x806D98E8\n.long 0x81230000\n.long 0xA80900C0\n.long 0x812900C4\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
