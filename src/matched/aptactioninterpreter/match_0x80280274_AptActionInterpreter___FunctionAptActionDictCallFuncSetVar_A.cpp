// 0x80280274 AptActionInterpreter::_FunctionAptActionDictCallFuncSetVar(
//                 AptActionInterpreter*, AptActionInterpreter::LocalContextT*) (196 B)
//
// Composite opcode: reads a single-byte dictionary id, pushes that string box onto
// working stack A0 and dispatches its per-type method (vtable+0x08, slot 1), then
// chains the CallFunction and SetVariable opcode handlers, and finally releases the
// GC value vector if it holds values and the operand stack has drained.
//
// AptValueObj box (vptr @ 0x08, two non-virtual head words), m_stringDict @ 0x38,
// m_stackA0 @ 0x00: see include/types/AptValue.h + AptActionInterpreter.h. apt-opcode-
// handler recipe: default scheduling (the DOL hoists the dispatch-arg globals + the
// 138 immediate to the top), single-read stack top, byte cursor walk. No surgery.
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
    unsigned char* cursor;     // 0x00
    void*          m_field04;  // 0x04
    void*          m_field08;  // 0x08
};

struct AptValueVector {
    int  m_field00;  // 0x00
    int  m_count;    // 0x04
    void ReleaseValues();
};

extern AptGlobal gAptDCFGlobalA;
extern AptGlobal gAptDCFGlobalB;
extern AptValueVector* gAptGCVector;

struct AptActionInterpreter {
    AptInterpStack m_stackA0;          // 0x00
    char           _pad[0x38 - 0x0C];  // 0x0C .. 0x38
    AptValueObj**  m_stringDict;       // 0x38
    static void _FunctionAptActionDictCallFuncSetVar(AptActionInterpreter* interp,
                                                     LocalContextT* ctx);
    static void _FunctionAptActionCallFunction(AptActionInterpreter*, LocalContextT*);
    static void _FunctionAptActionSetVariable(AptActionInterpreter*, LocalContextT*);
};

void AptActionInterpreter::_FunctionAptActionDictCallFuncSetVar(AptActionInterpreter* interp,
                                                                LocalContextT* ctx) {
    unsigned char* cur = ctx->cursor;
    unsigned int idx = *cur++;
    ctx->cursor = cur;

    AptValueObj* box = interp->m_stringDict[idx];
    int top = interp->m_stackA0.top;
    interp->m_stackA0.data[top] = box;
    interp->m_stackA0.top = top + 1;
    box->Dispatch(&gAptDCFGlobalA, &gAptDCFGlobalB, 138);

    _FunctionAptActionCallFunction(interp, ctx);
    _FunctionAptActionSetVariable(interp, ctx);

    AptValueVector* vec = gAptGCVector;
    if (vec->m_count != 0 && interp->m_stackA0.top == 0)
        vec->ReleaseValues();
}
