// 0x802800D4 AptActionInterpreter::_FunctionAptActionStringDictByteGetMember(
//                 AptActionInterpreter*, AptActionInterpreter::LocalContextT*) (152 B)
//
// Composite opcode: push the byte-indexed dictionary string (identical body to
// _FunctionAptActionPushStringDictByte 0x8027F924), then tail into the GetMember
// opcode handler with the same (interp, ctx). The trailing call is what forces
// interp/ctx into callee-saved r30/r29 (the stmw 29 prologue) — it falls out
// naturally from referencing both after the dispatch.
//
// Redone clean from a forced inject_before via the apt-opcode-handler recipe:
// static method, AptValueObj polymorphic (vptr@0x8 -> first virtual = slot 1,
// SN lha/lwz/add/blrl adjustor call), single-read stack top, inline data store,
// DEFAULT scheduling (the forced stub's -fno-schedule-insns flag is wrong here
// and mismatches). No post-compile surgery.
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

extern AptGlobal gAptGMByteGlobalA;
extern AptGlobal gAptGMByteGlobalB;

struct AptActionInterpreter {
    AptInterpStack m_stackA0;          // 0x00
    char           _pad[0x38 - 0x0C];  // 0x0C .. 0x38
    AptValueObj**  m_stringDict;       // 0x38
    static void _FunctionAptActionStringDictByteGetMember(AptActionInterpreter* interp,
                                                          LocalContextT* ctx);
    static void _FunctionAptActionGetMember(AptActionInterpreter* interp,
                                            LocalContextT* ctx);
};

void AptActionInterpreter::_FunctionAptActionStringDictByteGetMember(AptActionInterpreter* interp,
                                                                     LocalContextT* ctx) {
    unsigned char* cur = ctx->cursor;
    unsigned int idx = *cur++;
    ctx->cursor = cur;

    int top = interp->m_stackA0.top;
    AptValueObj* obj = interp->m_stringDict[idx];
    interp->m_stackA0.data[top] = obj;
    interp->m_stackA0.top = top + 1;

    obj->Dispatch(&gAptGMByteGlobalA, &gAptGMByteGlobalB, 138);
    _FunctionAptActionGetMember(interp, ctx);
}
