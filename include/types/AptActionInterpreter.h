/* include/types/AptActionInterpreter.h — canonical class layout for
 * AptActionInterpreter (aptactioninterpreter.obj)
 *
 * S19 TypeArchaeologist proactive deliverable (highest forced-byte density:
 * 130 forced functions / ~82,932 bytes in build/audit/forced.txt — the #1
 * leverage header in the backlog).
 *
 * Provenance: field offsets cross-verified from the ASMPROC inject_before
 * stub asm of four structural methods (initialize, runStream, setVariable,
 * getVariable). Every offset below cites the instruction it came from. This
 * header describes class SHAPE only — no ASMPROC, no inline asm, no byte
 * injection. It exists so matchers redoing these forced functions as clean
 * C++ know the field layout instead of guessing.
 *
 * ============================================================================
 * What this class is
 * ============================================================================
 * AptActionInterpreter is the game's ActionScript (Flash AVM1-style) bytecode
 * interpreter for the APT UI runtime. runStream() (0x802720D0) is the main
 * fetch/dispatch loop: it reads opcode bytes from an action stream and
 * dispatches through a function-pointer table in rodata
 * (lis r9,-32700; addi r9,r9,-11452; lwzx r0,index<<2 — base ~0x8002B584)
 * to the 122 `_FunctionAptAction*` opcode handlers. The 7 `cbCallMethod_*`
 * functions are built-in global callables (setInterval, escape, isNaN, ...).
 *
 * The operand type passed throughout is `AptValue` (348 B by-value in many
 * signatures). AptValue wraps a refcounted heap object: the pervasive idiom
 *   lhz r9,0x0(rX); addi r9,r9,1; sth r9,0x0(rX)         ; ++refcount  (u16 @+0x00)
 *   ... lhz r9,0x0(r4); addi r9,r9,-1; ...; sth; beq <free with size @+0x04>
 * appears in nearly every method. AptValue/AptString get their own header if
 * a matcher files typereq:AptValue.
 *
 * ============================================================================
 * Recovered layout summary
 * ============================================================================
 * The object head is four parallel growable stacks (12 B each: {top, capacity,
 * data}) used as the interpreter's working stacks, followed by the current
 * target/context pointer and a small run-state block.
 *
 *   initialize() (0x8026C8BC) allocates all four:
 *     r30=this; r28=this+0x0C; r27=this+0x18; r26=this+0x24  (stride 0x0C)
 *     pair A (0x00, 0x0C): capacity from AptInitParmsT+0x20
 *     pair B (0x18, 0x24): capacity from AptInitParmsT+0x24
 *     for each block N at base b:
 *       stw <cap>, 0x4(b)            ; capacity @ b+0x04
 *       rlwinm r4,<cap>,2,0,29       ; bytes = cap*4
 *       bl <alloc>; stw r3, 0x8(b)   ; data ptr @ b+0x08
 *     li r0,0; stw r0,0x58(30); stw r0,0x5c(30)   ; run-state cleared
 *
 *   runStream() confirms the runtime push shape for blocks at 0x00 and 0x24:
 *       lwz r9,0x00(this) ; lwz r10,0x08(this) ; stwx <v>,(r9<<2),r10
 *       addi r9,r9,1 ; stw r9,0x00(this)              ; ++top, store value
 *   so b+0x00 is the runtime top index (push pointer), b+0x04 capacity,
 *   b+0x08 the s32/ptr buffer.
 * ============================================================================
 */
#ifndef SIMS2_TYPES_APTACTIONINTERPRETER_H
#define SIMS2_TYPES_APTACTIONINTERPRETER_H

#include "../types.h"

/* Forward decls (operand / context types referenced by signatures) */
struct AptValue;        /* 348 B by-value operand; refcounted-string-backed     */
struct AptCIH;          /* character instance handle (getName/hitTest/cloneSprite) */
struct AptInitParmsT;   /* init parameters; +0x20 / +0x24 are the stack capacities */
struct AptActionStream; /* the bytecode stream object pushed onto the stacks      */

/* ============================================================================
 * AptInterpStack — one of the four 12-byte working stacks at the object head.
 *
 *   top      : runtime push index (0 after init; runStream stwx at top<<2)
 *   capacity : entry count, allocated in initialize() from AptInitParmsT
 *   data     : malloc'd buffer of `capacity` 4-byte slots (s32 or pointer)
 * ========================================================================== */
struct AptInterpStack {
    /* 0x00 */ s32   top;      /* push index / current depth                     */
    /* 0x04 */ s32   capacity; /* slot count (from AptInitParmsT+0x20 or +0x24)  */
    /* 0x08 */ void* data;     /* capacity * 4 bytes; holds s32 or object ptrs   */
};

/* ============================================================================
 * AptActionInterpreter
 *
 * Head = 4 × AptInterpStack (0x00..0x2F), then the target pointer and the
 * run-state block. Offsets 0x34..0x53 are not yet evidenced (the structural
 * methods sampled don't touch them); kept opaque rather than guessed.
 * ========================================================================== */
struct AptActionInterpreter {
    /* 0x00 */ AptInterpStack m_stackA0;  /* pair A — cap from AptInitParmsT+0x20.
                                             runStream pushes onto this one
                                             (the primary value/operand stack). */
    /* 0x0C */ AptInterpStack m_stackA1;  /* pair A companion (cap +0x20).        */
    /* 0x18 */ AptInterpStack m_stackB0;  /* pair B — cap from AptInitParmsT+0x24. */
    /* 0x24 */ AptInterpStack m_stackB1;  /* pair B companion (cap +0x24).
                                             runStream pushes the running
                                             AptActionStream here on entry
                                             (nested-stream / call stack).        */

    /* 0x30 */ void*          m_pTarget;  /* current target/context object
                                             (AptCharacter-like). set/getVariable
                                             read m_pTarget->+0x28 (var-map head),
                                             +0x2C, +0x30, +0x48 (vcall thunk).
                                             NULL until a SetTarget opcode runs.  */

    /* 0x34 */ s32            m_field34;   /* read in callFunction (0x80270070)
                                              alongside m_stringDict; likely the
                                              dictionary count/size. Paired with
                                              0x38. (purpose not fully pinned)     */
    /* 0x38 */ void**         m_stringDict; /* base of the string dictionary: an
                                              array of AptValueObj* indexed by a
                                              dictionary id. PushStringDictWord
                                              (0x8027F9A4): lwz r10,0x38(this);
                                              lwzx <obj>,(id<<2),r10 — then pushes
                                              obj onto m_stackA0. See AptValue.h.  */
    /* 0x3C */ u8             _gap3C[0x18]; /* OPAQUE — 0x3C..0x53 not yet
                                              evidenced. File typereq for a
                                              specific offset to get it named.     */

    /* 0x54 */ s32            m_continue;  /* execution continue flag. runStream
                                              loop: lwz r0,0x54(this); if r0!=0
                                              keep dispatching, if 0 stop. Set by
                                              End/Throw/abort paths.               */
    /* 0x58 */ s32            m_stackBaseMark; /* saved frame base into m_stackA0:
                                              runStream saves old 0x58, sets it to
                                              m_stackA0.top for the current stream,
                                              uses it to unwind leftover pushes on
                                              exit, then restores the old value.   */
    /* 0x5C */ s32            m_field5C;    /* cleared in initialize() alongside
                                              0x58; companion run-state, exact use
                                              not yet evidenced.                    */

    /* 0x60 */ u8             _padTail[0x40]; /* OPAQUE extent — class total size
                                                unverified; additional fields are
                                                read past 0x60 by some handlers.   */
};

/* ============================================================================
 * Function prototypes — matched AptActionInterpreter methods (154 total)
 *
 * Grouped: core interpreter / lifecycle, built-in global callables, and the
 * opcode handler table. Addresses are the DOL entrypoints; the matched files
 * live in src/matched/aptactioninterpreter/. Most are currently FORCED
 * (ASMPROC) — this list is the navigation map for redoing them as clean C++.
 * ========================================================================== */

/* ---- core interpreter / lifecycle (25) ---- */
extern "C" void f_8026C8BC(void); /* initialize(AptInitParmsT)               */
extern "C" void f_8026C968(void); /* shutdown()                              */
extern "C" void f_8026CA44(void); /* _parseStream(unsigned)                  */
extern "C" void f_8026D454(void); /* loadVariables(AptValue)                 */
extern "C" void f_8026D6C0(void); /* getObject(AptValue)                     */
extern "C" void f_8026D7FC(void); /* getContext(AptValue)                    */
extern "C" void f_8026D958(void); /* getContext(AptValue) [overload]         */
extern "C" void f_8026DB60(void); /* setVariable(AptValue)                   */
extern "C" void f_8026F6DC(void); /* getName2(AptCIH)                        */
extern "C" void f_8026F824(void); /* getName(AptCIH)                         */
extern "C" void f_8026F8DC(void); /* _doCloneSprite(AptCIH)                  */
extern "C" void f_8026FB50(void); /* getVariable(AptValue)                   */
extern "C" void f_8026FF94(void); /* valueToObject(AptValue)                 */
extern "C" void f_80270070(void); /* callFunction(AptValue)                  */
extern "C" void f_80270788(void); /* CleanupAfterExecution(char)             */
extern "C" void f_8027085C(void); /* CleanupAfterExecution()                 */
extern "C" void f_80270930(void); /* _createObject(AptValue)                 */
extern "C" void f_80271BB8(void); /* _doEnumerate(AptValue)                  */
extern "C" void f_802720D0(void); /* runStream(unsigned) — main dispatch loop */
extern "C" void f_802727F4(void); /* urlDecode(char)                         */
extern "C" void f_80272984(void); /* doFSCommand(char)                       */
extern "C" void f_8027AB3C(void); /* StackSwap                               */
extern "C" void f_8027F444(void); /* CallFuncSetVar                          */
extern "C" void f_8027F540(void); /* CallMethodSetVar                        */
extern "C" void f_80280E48(void); /* isObjectOfType(AptValue)                */

/* ---- built-in global callables (7) ---- */
extern "C" void f_8026E048(void); /* cbCallMethod_setInterval(AptValue)      */
extern "C" void f_8026E3E4(void); /* cbCallMethod_clearInterval(AptValue)    */
extern "C" void f_8026E518(void); /* cbCallMethod_hitTest(AptCIH)            */
extern "C" void f_8026E69C(void); /* cbCallMethod_isNaN(AptValue)            */
extern "C" void f_8026EB48(void); /* cbCallMethod_unescape(AptValue)         */
extern "C" void f_8026ECE8(void); /* cbCallMethod_escape(AptValue)           */
extern "C" void f_8026EE5C(void); /* cbCallMethod_boolean(AptValue)          */

/* ---- opcode handlers (122) — dispatched by runStream via the rodata table -- */
extern "C" void f_802729D4(void); /* _FunctionAptActionEnd                   */
extern "C" void f_80272A70(void); /* _FunctionAptActionPlay                  */
extern "C" void f_80272BBC(void); /* _FunctionAptActionToggleQuality         */
extern "C" void f_80272BC0(void); /* _FunctionAptActionStopSounds            */
extern "C" void f_80272BC4(void); /* _FunctionAptActionAdd                   */
extern "C" void f_80272E74(void); /* _FunctionAptActionSubtract              */
extern "C" void f_80273124(void); /* _FunctionAptActionMultiply              */
extern "C" void f_802733D4(void); /* _FunctionAptActionDivide                */
extern "C" void f_802735C4(void); /* _FunctionAptActionEquals                */
extern "C" void f_80273840(void); /* _FunctionAptActionLessThan              */
extern "C" void f_80273AAC(void); /* _FunctionAptActionAnd                   */
extern "C" void f_80273D40(void); /* _FunctionAptActionOr                    */
extern "C" void f_80273FD0(void); /* _FunctionAptActionNot                   */
extern "C" void f_80274138(void); /* _FunctionAptActionStringEquals          */
extern "C" void f_80274494(void); /* _FunctionAptActionStringLength          */
extern "C" void f_8027465C(void); /* _FunctionAptActionSubString             */
extern "C" void f_802749BC(void); /* FunctionAptActionPop                    */
extern "C" void f_80274A60(void); /* _FunctionAptActionToInteger             */
extern "C" void f_80274BF4(void); /* _FunctionAptActionGetVariable           */
extern "C" void f_80274D4C(void); /* _FunctionAptActionSetVariable           */
extern "C" void f_80274E98(void); /* _FunctionAptActionSetTarget2            */
extern "C" void f_80275014(void); /* _FunctionAptActionStringAdd             */
extern "C" void f_80275210(void); /* _FunctionAptActionGetProperty           */
extern "C" void f_80275424(void); /* _FunctionAptActionSetProperty           */
extern "C" void f_8027554C(void); /* _FunctionAptActionCloneSprite           */
extern "C" void f_80275638(void); /* _FunctionAptActionRemoveSprite          */
extern "C" void f_80275728(void); /* _FunctionAptActionTrace                 */
extern "C" void f_80275978(void); /* _FunctionAptActionStartDragMovie        */
extern "C" void f_80275CB8(void); /* FunctionAptActionStopDragMovie          */
extern "C" void f_80275D1C(void); /* _FunctionAptActionStringLessThan        */
extern "C" void f_80275D20(void); /* _FunctionAptActionRandom                */
extern "C" void f_80275EB0(void); /* _FunctionAptActionMBLength              */
extern "C" void f_80275EB4(void); /* _FunctionAptActionCharToAscii           */
extern "C" void f_80275EB8(void); /* _FunctionAptActionAsciiToChar           */
extern "C" void f_80276138(void); /* _FunctionAptActionGetTimer              */
extern "C" void f_80276234(void); /* _FunctionAptActionMBSubString           */
extern "C" void f_80276238(void); /* _FunctionAptActionMBCharToAscii         */
extern "C" void f_8027623C(void); /* _FunctionAptActionMBAsciiToChar         */
extern "C" void f_80276240(void); /* _FunctionAptActionDelete                */
extern "C" void f_80276464(void); /* _FunctionAptActionDelete2               */
extern "C" void f_80276640(void); /* _FunctionAptActionDefineLocal           */
extern "C" void f_8027677C(void); /* _FunctionAptActionCallFunction          */
extern "C" void f_802769C8(void); /* _FunctionAptActionModulo                */
extern "C" void f_80276BC0(void); /* _FunctionAptActionNewObject             */
extern "C" void f_80276DB0(void); /* _FunctionAptActionDefineLocal2          */
extern "C" void f_80276F24(void); /* _FunctionAptActionInitArray             */
extern "C" void f_802770D0(void); /* _FunctionAptActionInitObject            */
extern "C" void f_802773E4(void); /* _FunctionAptActionTypeOf                */
extern "C" void f_802777DC(void); /* _FunctionAptActionTargetPath            */
extern "C" void f_80277B5C(void); /* _FunctionAptActionAdd2                  */
extern "C" void f_80278310(void); /* _FunctionAptActionLessThan2             */
extern "C" void f_80278E44(void); /* _FunctionAptActionEquals2               */
extern "C" void f_8027A020(void); /* _FunctionAptActionToNumber              */
extern "C" void f_8027A738(void); /* _FunctionAptActionToString              */
extern "C" void f_8027AAD4(void); /* FunctionAptActionPushDuplicate          */
extern "C" void f_8027ABAC(void); /* _FunctionAptActionGetMember             */
extern "C" void f_8027AFD0(void); /* _FunctionAptActionSetMember             */
extern "C" void f_8027B338(void); /* _FunctionAptActionIncrement             */
extern "C" void f_8027B594(void); /* _FunctionAptActionDecrement             */
extern "C" void f_8027B7F0(void); /* _FunctionAptActionCallMethod            */
extern "C" void f_8027C324(void); /* _FunctionAptActionNewMethod             */
extern "C" void f_8027C5B8(void); /* _FunctionAptActionBitAnd                */
extern "C" void f_8027C784(void); /* _FunctionAptActionBitOr                 */
extern "C" void f_8027C950(void); /* _FunctionAptActionBitXor                */
extern "C" void f_8027CB1C(void); /* _FunctionAptActionBitLShift             */
extern "C" void f_8027CCE8(void); /* _FunctionAptActionBitRShift             */
extern "C" void f_8027CEB4(void); /* _FunctionAptActionBitURShift            */
extern "C" void f_8027CEB8(void); /* _FunctionAptActionStrictEquals          */
extern "C" void f_8027D43C(void); /* _FunctionAptActionGreater               */
extern "C" void f_8027D7D8(void); /* _FunctionAptActionGotoFrame             */
extern "C" void f_8027D8C0(void); /* _FunctionAptActionGetUrl                */
extern "C" void f_8027DA60(void); /* FunctionAptActionStoreRegister          */
extern "C" void f_8027DAAC(void); /* FunctionAptActionDefineDictionary       */
extern "C" void f_8027DAD4(void); /* _FunctionAptActionWaitForFrame          */
extern "C" void f_8027DAD8(void); /* _FunctionAptActionSetTarget             */
extern "C" void f_8027DC4C(void); /* _FunctionAptActionGotoLabel             */
extern "C" void f_8027DD30(void); /* _FunctionAptActionWith                  */
extern "C" void f_8027DE44(void); /* _FunctionAptActionPush                  */
extern "C" void f_8027DF4C(void); /* _FunctionAptActionGetUrl2               */
extern "C" void f_8027E3D4(void); /* _FunctionAptActionDefineFunction        */
extern "C" void f_8027E580(void); /* _FunctionAptActionDefineFunction2       */
extern "C" void f_8027E6B4(void); /* _FunctionAptActionBranchIfTrue          */
extern "C" void f_8027E798(void); /* _FunctionAptActionCallFrame             */
extern "C" void f_8027E940(void); /* _FunctionAptActionGotoFrame2            */
extern "C" void f_8027EC04(void); /* FunctionAptActionBranchAlways           */
extern "C" void f_8027EC64(void); /* _FunctionAptActionPushThis              */
extern "C" void f_8027EDA8(void); /* _FunctionAptActionPushGlobal            */
extern "C" void f_8027EEEC(void); /* _FunctionAptActionPush0                 */
extern "C" void f_8027EFE8(void); /* _FunctionAptActionPush1                 */
extern "C" void f_8027F0E4(void); /* _FunctionAptActionPushTrue              */
extern "C" void f_8027F1E0(void); /* _FunctionAptActionPushFalse             */
extern "C" void f_8027F2DC(void); /* FunctionAptActionPushNULL               */
extern "C" void f_8027F340(void); /* FunctionAptActionPushUndefined          */
extern "C" void f_8027F3A4(void); /* FunctionAptActionCallFuncAndPop         */
extern "C" void f_8027F4A0(void); /* FunctionAptActionCallMethodPop          */
extern "C" void f_8027F59C(void); /* FunctionAptActionPushThisVariable       */
extern "C" void f_8027F62C(void); /* FunctionAptActionPushGlobalVariable     */
extern "C" void f_8027F690(void); /* _FunctionAptActionPushZeroSetVar        */
extern "C" void f_8027F79C(void); /* _FunctionAptActionPushString            */
extern "C" void f_8027F924(void); /* FunctionAptActionPushStringDictByte     */
extern "C" void f_8027F9A4(void); /* _FunctionAptActionPushStringDictWord    */
extern "C" void f_8027FA30(void); /* _FunctionAptActionPushStringGetVar      */
extern "C" void f_8027FB4C(void); /* _FunctionAptActionPushStringGetMember   */
extern "C" void f_8027FCE4(void); /* _FunctionAptActionPushStringSetVar      */
extern "C" void f_8027FE7C(void); /* _FunctionAptActionPushStringSetMember   */
extern "C" void f_80280014(void); /* _FunctionAptActionStringDictByteGetVar  */
extern "C" void f_802800D4(void); /* _FunctionAptActionStringDictByteGetMem  */
extern "C" void f_8028016C(void); /* _FunctionAptActionDictCallFuncPop       */
extern "C" void f_80280274(void); /* _FunctionAptActionDictCallFuncSetVar    */
extern "C" void f_80280338(void); /* _FunctionAptActionDictCallMethodPop     */
extern "C" void f_80280440(void); /* _FunctionAptActionDictCallMethodSetVar  */
extern "C" void f_80280504(void); /* _FunctionAptActionPushFloat             */
extern "C" void f_8028062C(void); /* _FunctionAptActionPushByte              */
extern "C" void f_80280738(void); /* _FunctionAptActionPushWord              */
extern "C" void f_80280850(void); /* _FunctionAptActionPushDWord             */
extern "C" void f_80280978(void); /* _FunctionAptActionBranchIfFalse         */
extern "C" void f_80280A5C(void); /* _FunctionAptActionExtends               */
extern "C" void f_80280FBC(void); /* _FunctionAptActionInstanceOf            */
extern "C" void f_802811EC(void); /* _FunctionAptActionCastOp                */
extern "C" void f_80281424(void); /* _FunctionAptActionImplementsOp          */
extern "C" void f_802817C8(void); /* _FunctionAptActionTry                   */
extern "C" void f_80281B14(void); /* _FunctionAptActionThrow                 */

#endif /* SIMS2_TYPES_APTACTIONINTERPRETER_H */
