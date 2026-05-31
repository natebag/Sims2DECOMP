// 0x8027F924 AptActionInterpreter::_FunctionAptActionPushStringDictByte(
//                 AptActionInterpreter*, AptActionInterpreter::LocalContextT*) (128 B)
//
// Byte-index sibling of _FunctionAptActionPushStringDictWord (0x8027F9A4): reads a
// single-byte dictionary id from the action stream, looks the boxed value up in the
// interpreter's string dictionary, pushes it onto working stack A0, and dispatches a
// per-type method on the boxed value.
//
// Was a forced match (3 force_reg directives papering over an slwi r0-vs-r11 /
// commutative-stwx register-allocator difference). Redone clean with the
// AptActionInterpreter opcode-handler recipe: static method, AptValueObj modeled
// polymorphic with two non-virtual head words (vptr@0x8 -> first virtual = slot 1,
// vtable+0x08, SN's lha/lwz/add/blrl adjustor call), single-read stack top, inline
// data store, default scheduling. No post-compile surgery.
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

extern AptGlobal gAptDictByteGlobalA;
extern AptGlobal gAptDictByteGlobalB;

struct AptActionInterpreter {
    AptInterpStack m_stackA0;          // 0x00
    char           _pad[0x38 - 0x0C];  // 0x0C .. 0x38
    AptValueObj**  m_stringDict;       // 0x38
    static void _FunctionAptActionPushStringDictByte(AptActionInterpreter* interp,
                                                     LocalContextT* ctx);
};

void AptActionInterpreter::_FunctionAptActionPushStringDictByte(AptActionInterpreter* interp,
                                                                LocalContextT* ctx) {
    unsigned char* cur = ctx->cursor;
    unsigned int idx = *cur++;
    ctx->cursor = cur;

    int top = interp->m_stackA0.top;
    AptValueObj* obj = interp->m_stringDict[idx];
    interp->m_stackA0.data[top] = obj;
    interp->m_stackA0.top = top + 1;

    obj->Dispatch(&gAptDictByteGlobalA, &gAptDictByteGlobalB, 138);
}
