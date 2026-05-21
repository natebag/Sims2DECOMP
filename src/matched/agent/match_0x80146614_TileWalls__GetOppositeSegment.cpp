// 0x80146614 TileWalls::GetOppositeSegment(TileWallsSegment) (108B)
//
// 6-way switch returning the "opposite" of a wall-segment enum. Two of the
// cases (16, 32) return the same value as the case label — DOL exploits this
// with a `beqlr` self-return idiom (the switch argument is already in r3,
// so no `li r3, K; blr` block is needed).
//
// WALL CLASS: self-return idiom — DOL's `cmpwi rA, K; beqlr` collapses
// GCC's `cmpwi rA, K; beq .case_K; ...; .case_K: li rA, K; blr`. Same
// semantics, 2 fewer instructions per applicable case.
//
// Recipe (2 self_return_blr directives, new mutator):
//   1. self_return_blr value=16    (collapses case-16 block)
//   2. self_return_blr value=32    (collapses case-32 block)
//
// Each directive: finds the `cmpwi 0,3,K` line whose immediate matches
// `value`, confirms the next line is the corresponding `beq .L_case_K`,
// finds the .L_case_K block with `li 3,K; blr`, and rewrites the beq to
// `bclr 12,2,0` (= beqlr) + deletes the now-orphaned case block.
//
// Parked by OpusWorker 2026-05-21 — same family blast as TileWalls walls.
//
// ASMPROC_self_return_blr: value=16
// ASMPROC_self_return_blr: value=32

class TileWalls {
public:
    static int GetOppositeSegment(int seg);
};

int TileWalls::GetOppositeSegment(int seg) {
    switch (seg) {
        case 1: return 4;
        case 2: return 8;
        case 4: return 1;
        case 8: return 2;
        case 16: return seg;
        case 32: return seg;
        default: return 0;
    }
}
