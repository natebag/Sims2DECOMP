// PARTIAL-FAKE from full-tree verify sweep 2026-04-21.
// Moved from src/matched/versioninfo/match_0x8024A9B0_TArray_EVec3__op_assign.cpp.
// Declared 9B in file header, map shows 48B — file compiles to 44B,
// SIZE_MISMATCH.
//
// Root cause: wrong LR load shape. DOL uses lis+addi+mtlr sequence; this
// file emits lwz+mtlr (shorter sequence), which misses 4B. Suggests the
// underlying function has an absolute-address helper invocation that was
// modeled as a plain function pointer call instead of the real DOL
// thunk pattern.
//
// The versioninfo/ folder is known-suspect territory per S13 carryover
// audit plan — this fits the pattern.
//
// See OpusReview info board legacy-mislabels audit.

// 0x8024A9B0 match_0x8024A9B0_TArray_EVec3__op_assign (9b)
// TArray<EVec3, TArrayDefaultAllocator>::operator=(TArray<EVec3, TArrayDefaultAllocator> &)
// Address: 0x8024A9B0 | Size: 48 bytes

typedef void* (*FuncPtr)(void*, void*);
extern FuncPtr gTArrayCopyFunc;

char* TArray_EVec3_op_assign(void* self, void* other) {
    char* result = (char*)gTArrayCopyFunc(self, other);
    return result + 8;
}
