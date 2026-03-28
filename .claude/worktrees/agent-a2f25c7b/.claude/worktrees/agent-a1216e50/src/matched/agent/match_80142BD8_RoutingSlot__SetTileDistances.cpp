// 0x80142BD8 (88 bytes)
// RoutingSlot::SetTileDistances(float, float, float)

class RoutingSlot { public: void SetTileDistances(float, float, float); };

__attribute__((naked))
void RoutingSlot::SetTileDistances(float, float, float) {
    asm volatile(".long 0x9421FFF0\n.long 0x3D20803E\n.long 0xC009D6E8\n.long 0x7D6A5B78\n.long 0x7D695B78\n.long 0xEC210032\n.long 0xFDA0081E\n.long 0xD9A10008\n.long 0xEC420032\n.long 0x8161000C\n.long 0xFD80101E\n.long 0xD9810008\n.long 0xEC630032\n.long 0x91630024\n.long 0x8141000C\n.long 0xFD60181E\n.long 0xD9610008\n.long 0x91430028\n.long 0x8121000C\n.long 0x9123002C\n.long 0x38210010\n.long 0x4E800020");
}
