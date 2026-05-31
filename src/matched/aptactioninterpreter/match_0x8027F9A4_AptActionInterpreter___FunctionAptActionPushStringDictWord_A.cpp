// 0x8027F9A4 AptActionInterpreter::_FunctionAptActionPushStringDictWord(
//                 AptActionInterpreter*, AptActionInterpreter::LocalContextT*) (140 B)
//
// ActionScript opcode handler (static). Reads a 16-bit big-endian dictionary id
// from the action stream, looks the boxed value up in the interpreter's string
// dictionary, pushes it onto working stack A0, and dispatches a per-type method
// on the boxed value.
//
// Types (see include/types/AptActionInterpreter.h and include/types/AptValue.h):
//   interp->m_stackA0  {top@0x00, cap@0x04, data@0x08}   working operand stack
//   interp->m_stringDict @0x38                            AptValueObj*[] by id
//   ctx->cursor @0x00                                     action-stream byte ptr
//   AptValueObj: 16-byte box; m_vtable @0x08, so it is modeled here as a
//     polymorphic class with two non-virtual head words (m_flags, m_field04)
//     preceding the vptr. The dispatched method is the first virtual (slot 1,
//     vtable+0x08), which SN ProDG calls through its 8-byte vtable entries
//     {s16 adjustor @+0x08, fnptr @+0x0C} — the lha/lwz/add/blrl sequence.
//
// Matching notes (no post-compile surgery; this replaces a forced inject_before):
//   - *cur++ twice gives the DOL's lbz + lbzu pointer-walk read.
//   - idx = lo | (hi<<8) reuses the low byte's register for the `or`, matching
//     the DOL's register flow (vs (hi<<8)|lo which swaps it).
//   - reading top into a local once (not interp->...top++) avoids a reload and
//     keeps top live for both the index and the increment, as in the DOL.
struct AptGlobal { char _r[16]; };

struct AptValueObjHead {
    unsigned int m_flags;    // 0x00
    unsigned int m_field04;  // 0x04
};

struct AptValueObj : public AptValueObjHead {
    virtual void Dispatch(AptGlobal*, AptGlobal*, int) = 0;  // vtable+0x08
};

struct AptInterpStack {
    int           top;   // 0x00
    int           cap;   // 0x04
    AptValueObj** data;  // 0x08
};

struct LocalContextT {
    unsigned char* cursor;  // 0x00
};

extern AptGlobal gAptPushGlobalA;
extern AptGlobal gAptPushGlobalB;

struct AptActionInterpreter {
    AptInterpStack m_stackA0;          // 0x00
    char           _pad[0x38 - 0x0C];  // 0x0C .. 0x38
    AptValueObj**  m_stringDict;       // 0x38
    static void _FunctionAptActionPushStringDictWord(AptActionInterpreter* interp,
                                                      LocalContextT* ctx);
};

void AptActionInterpreter::_FunctionAptActionPushStringDictWord(AptActionInterpreter* interp,
                                                                LocalContextT* ctx) {
    unsigned char* cur = ctx->cursor;
    unsigned int hi = *cur++;
    unsigned int lo = *cur++;
    ctx->cursor = cur;
    unsigned int idx = lo | (hi << 8);

    int top = interp->m_stackA0.top;
    AptValueObj* obj = interp->m_stringDict[idx];
    interp->m_stackA0.data[top] = obj;
    interp->m_stackA0.top = top + 1;

    obj->Dispatch(&gAptPushGlobalA, &gAptPushGlobalB, 138);
}
