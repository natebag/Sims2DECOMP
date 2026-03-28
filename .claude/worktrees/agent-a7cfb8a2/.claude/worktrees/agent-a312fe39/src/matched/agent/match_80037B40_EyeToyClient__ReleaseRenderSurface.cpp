// 0x80037B40 (64 bytes)
// EyeToyClient::ReleaseRenderSurface(ERenderSurface *)

class EyeToyClient { public: void ReleaseRenderSurface(ERenderSurface *); };

__attribute__((naked))
void EyeToyClient::ReleaseRenderSurface(ERenderSurface *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C641B79\n.long 0x41820020\n.long 0x806D98E8\n.long 0x81230000\n.long 0xA80900D8\n.long 0x812900DC\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
