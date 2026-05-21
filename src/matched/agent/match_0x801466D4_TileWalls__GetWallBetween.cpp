// 0x801466D4 TileWalls::GetWallBetween(TilePtDir) (120B)
//
// 7-case dispatch returning the wall-segment enum that separates two adjacent
// tile positions, given a TilePtDir enum. DOL emits a binary-tree decision
// with cases 6/7 sharing the return-16 path (range check via cmpwi 7;bgt
// default; cmpwi 6;blt default).
//
// Parked by OpusWorker (5 diffs). Resolution = source-only:
//   - OpusWorker's source omitted `case 2: return 1` — DOL emits a
//     `li r3,1` block reachable from the `bgt 0x80146724` after the
//     `cmpwi r3,1` check (i.e. dir > 1 within lower half = dir == 2).
//   - Once case 2 is added, GCC matches DOL's binary-tree layout +
//     trailing-block emission byte-perfect on first compile.
//
// No new mutator, no ASMPROC directives, no flag tweaks. Pure source-coax
// after correcting the missed case. The dispatch shape (cmpwi/bgt/blt
// binary tree + per-case li/blr trailers) is GCC's natural lowering when
// the switch has gaps in the case values (no jump table).

class TileWalls {
public:
    static int GetWallBetween(int dir);
};

int TileWalls::GetWallBetween(int dir) {
    switch (dir) {
        case 0: return 2;
        case 1: return 8;
        case 2: return 1;
        case 3: return 4;
        case 4: return 32;
        case 6:
        case 7: return 16;
        default: return 0;
    }
}
