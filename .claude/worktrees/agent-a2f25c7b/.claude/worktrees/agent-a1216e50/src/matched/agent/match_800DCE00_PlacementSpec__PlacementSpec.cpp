// 0x800DCE00 (68 bytes)
// PlacementSpec::PlacementSpec(FTilePt &, int, cXObjectImpl *, int)

class PlacementSpec { public: void PlacementSpec(FTilePt &, int, cXObjectImpl *, int); };

__attribute__((naked))
void PlacementSpec::PlacementSpec(FTilePt &, int, cXObjectImpl *, int) {
    asm volatile(".long 0x38000001\n.long 0x7CC63379\n.long 0x90030000\n.long 0x41820008\n.long 0x38860068\n.long 0x81240000\n.long 0x81440004\n.long 0x90C3000C\n.long 0x91230004\n.long 0x91430008\n.long 0x4182000C\n.long 0x90E30010\n.long 0x4800000C\n.long 0x3800FFFF\n.long 0x90030010\n.long 0x90A30014\n.long 0x4E800020");
}
