// 0x801467C4 (120 bytes)
// TileWalls::IndexToSegment(int, DiagonalSideSelector *)

class TileWalls { public: void IndexToSegment(int, DiagonalSideSelector *); };

__attribute__((naked))
void TileWalls::IndexToSegment(int, DiagonalSideSelector *) {
    asm volatile(".long 0x39200001\n.long 0x7C842379\n.long 0x7D231830\n.long 0x4D820020\n.long 0x38000000\n.long 0x2C03000F\n.long 0x90040000\n.long 0x4C810020\n.long 0x2C030010\n.long 0x40820010\n.long 0x38000002\n.long 0x90040000\n.long 0x4E800020\n.long 0x2C030020\n.long 0x40820014\n.long 0x38000004\n.long 0x38600010\n.long 0x90040000\n.long 0x4E800020\n.long 0x2C030040\n.long 0x40820010\n.long 0x91240000\n.long 0x38600020\n.long 0x4E800020\n.long 0x2C030080\n.long 0x4C820020\n.long 0x38000003\n.long 0x38600020\n.long 0x90040000\n.long 0x4E800020");
}
