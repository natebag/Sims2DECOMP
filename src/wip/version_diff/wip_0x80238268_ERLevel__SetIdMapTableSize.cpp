// PARTIAL-FAKE from full-tree verify sweep 2026-04-21.
// Moved from src/matched/er_level/match_0x80238268_ERLevel__SetIdMapTableSize.cpp.
// Declared 8B in file header, map shows 40B — file body does not produce
// byte-match at map size 40B.
//
// Root cause: wrong constant in table-size formula. DOL has `addis r3,r3,3`;
// this file produces `addis r3,r3,4`. Off-by-one in the sub-object offset
// computation or the size-scale factor.
//
// See OpusReview info board legacy-mislabels audit.

// 0x80238268 ERLevel::SetIdMapTableSize (8B)

struct ERLevel;
extern void SetIdMapTableSize_impl(ERLevel* self, int size);

void ERLevel__SetIdMapTableSize(void* self, int size) {
    SetIdMapTableSize_impl((ERLevel*)((char*)self + 0x3A264), size);
}
