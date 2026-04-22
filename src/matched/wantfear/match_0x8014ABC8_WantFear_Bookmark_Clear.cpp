// 0x8014ABC8 WantFear::Bookmark::Clear (28B)
//
// Zero-fill "clear" method over a 3×short + 1×int layout. DOL emits:
//   li r0, 0
//   li r9, 0
//   sth r0, 8(r3)        ; field8 short via r0 (BYTE zero reg)
//   stw r9, 4(r3)        ; field4 int   via r9 (WORD zero reg)
//   sth r0, 0(r3)        ; field0 short via r0
//   sth r0, 2(r3)        ; field2 short via r0
//   blr
//
// Technique #63 source-order rule (stress-test of the signed-off BBI ctor
// technique on a mixed short/word layout): listing the short stores BEFORE
// the word store in source puts GCC into the polarity where r0 holds the
// short-zero and r9 holds the word-zero.

namespace WantFear {

struct Bookmark {
    short field0;
    short field2;
    int field4;
    short field8;
    void Clear();
};

void Bookmark::Clear() {
    field0 = 0;
    field2 = 0;
    field8 = 0;
    field4 = 0;
}

}  // namespace WantFear
