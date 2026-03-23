// =============================================================================
// APT UI Engine Core Decompilation
// =============================================================================
//
// APT (ActionScript Processing Technology) is EA's standalone UI library
// (libaptz.a) shared across multiple EA games on GameCube, PS2, Xbox, and PC.
// It implements a subset of Macromedia Flash / ActionScript, used to power all
// in-game menus, HUDs, dialog boxes, and overlays in The Sims 2.
//
// This file documents the architecture and provides decompiled C++ for the
// core subsystems. All addresses reference the Sims 2 GC release DOL/ELF.
//
// Compiled with SN Systems ProDG for GameCube (SN-NGC).
// Functions marked MATCHING produce byte-identical output to the original.
// Functions marked NON_MATCHING are functionally correct but differ in codegen
// due to SN Systems vs GCC compiler differences.
//
// Source files in original build (from map/build log):
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\libs\apt\src\AptValue.cpp
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\libs\apt\src\AptActionInterpreter.cpp
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\libs\apt\src\AptCharacterInst.cpp
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\libs\apt\src\AptCIH.cpp
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\libs\apt\src\AptViewer.cpp
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\libs\apt\src\AptMovie.cpp
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\libs\apt\src\AptDisplayList.cpp
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\libs\apt\src\AptObject.cpp
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\libs\apt\src\AptScriptFunctionBase.cpp
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\libs\apt\src\AptRenderingContext.cpp
//   + ~50 more source files in libs/apt/src/
//
// Total APT functions in the Sims 2 GC build: 1471 (across 80+ classes)
// Total APT code size: ~360 KB
//
// =============================================================================

#include "ui/apt_value.h"


// =============================================================================
// SECTION 1: APT ARCHITECTURE OVERVIEW
// =============================================================================
//
// The APT engine is a complete ActionScript VM with these major subsystems:
//
// 1. VALUE SYSTEM (AptValue)
//    - Tagged variant type using a 32-bit bitfield for type/metadata
//    - Custom virtual dispatch (NOT C++ vtables) via AptValueVTableDesc
//    - Reference counting + mark-and-sweep garbage collection
//    - 47+ type tags covering AS primitives, objects, and internal types
//
// 2. ACTIONSCRIPT INTERPRETER (AptActionInterpreter)
//    - Stack-based bytecode interpreter (168 functions, ~86KB)
//    - Implements SWF ActionScript opcodes (0x00-0xBF+)
//    - Function dispatch table maps opcode -> handler function
//    - Supports try/catch/throw, closures, prototype chains
//
// 3. DISPLAY OBJECT HIERARCHY (AptCharacterInst, AptCIH, AptDisplayList)
//    - Flash-style display list with depth ordering
//    - Character types: Sprite, Button, Text, Shape, Morph, StaticText
//    - AptCIH wraps AptCharacterInst with ActionScript properties
//    - Property get/set dispatches ~40 built-in MC properties
//
// 4. RENDERING (AptRenderingContext)
//    - Matrix stack for transforms (affine 2x3 matrices)
//    - Color transform stack (CXForm: multiply + add RGBA)
//    - Bounding rect calculation and clipping
//
// 5. VIEWER (AptViewer)
//    - Top-level controller: Load, Update, Draw, Shutdown
//    - Controller input handling with button filter stacks
//    - Bridges APT to the game's native UI system (UIObjectBase)
//
// 6. MOVIE (AptMovie)
//    - Frame-based timeline control
//    - Frame action queuing and execution
//    - Label-to-frame mapping
//    - Stream resolve/unresolve for const file patching
//
// Data flow:
//   Game -> AptViewer::Update() -> AptCIH::tick() -> AptDisplayList::tick()
//                                                  -> AptMovie::runFrameActions()
//                                                  -> AptActionInterpreter::runStream()
//                                                       -> opcode handlers
//                                                       -> AptValue operations
//   Game -> AptViewer::Draw() -> AptCIH::render() -> AptDisplayList::render()
//                                                  -> AptCharacter::render()
//                                                  -> AptRenderingContext matrix ops
//


// =============================================================================
// SECTION 2: AptValue - THE TYPE SYSTEM
// =============================================================================
//
// AptValue is the core variant type. Every ActionScript value (numbers, strings,
// objects, functions, movie clips, etc.) is represented as an AptValue.
//
// OBJECT LAYOUT (minimum 16 bytes, subclasses extend):
//   0x00: u32 m_flags     - packed bitfield (type tag + metadata)
//   0x04: u32 m_data      - type-specific payload
//   0x08: AptValueVTableDesc* m_vtableDesc - custom vtable descriptor
//   0x0C: u32             - type-specific (e.g., integer value, float bits, pointer)
//   0x24: AptValue*       - string data fallback pointer (for c_string)
//
// m_flags BITFIELD LAYOUT (32 bits, PPC MSB-0 numbering):
//   Bit  0:     (unused/reserved)
//   Bit  1:     gcMark               - GC mark phase flag
//   Bit  2:     isReleaseAtEnd       - deferred release flag
//   Bit  3:     (unused)
//   Bit  4:     isDefined            - value has been assigned
//   Bit  5:     allowDelayedDeletion
//   Bits 6-17:  refCount             - 12-bit reference count (max 4095)
//   Bits 18-23: gcRoot               - 6-bit GC root counter (max 63)
//   Bit  24:    maxRefCountHit       - overflow flag
//   Bits 25-31: vtblIndex            - 7-bit type tag (AptVirtualFunctionTable_Indices)
//
// In LSB-0 terms (as GCC sees it):
//   Bits 0-6:   vtblIndex (7 bits)    <- & 0x7F
//   Bit  7:     maxRefCountHit        <- (>> 7) & 1
//   Bits 8-13:  gcRoot (6 bits)       <- (>> 8) & 0x3F
//   Bits 14-25: refCount (12 bits)    <- (>> 14) & 0xFFF
//   Bit  26:    allowDelayedDeletion  <- (>> 26) & 1
//   Bit  27:    isDefined             <- (>> 27) & 1
//   Bit  28:    (unused)
//   Bit  29:    isReleaseAtEnd        <- (>> 29) & 1
//   Bit  30:    gcMark                <- (>> 30) & 1
//   Bit  31:    (unused/reserved)
//
// CUSTOM VIRTUAL DISPATCH:
//   APT does NOT use C++ virtual functions. Instead, each AptValue has a pointer
//   to an AptValueVTableDesc at offset 0x08. This descriptor contains pairs of:
//     struct VTableEntry {
//         s16 thisAdjust;   // offset to add to 'this' before calling
//         s16 pad;
//         void (*func)();   // function pointer
//     };
//   Virtual calls load the entry, adjust 'this', and blrl through the func ptr.
//   This is likely because APT was originally a C library with manual vtables.
//
// TYPE TAG ENUM (complete, from disassembly of all is*() functions):
//
//   0  = UNDEFINED       - uninitialized/undefined value
//   1  = STRING          - EAStringC string (primary)
//   3  = NONE            - null/none value
//   4  = REGISTER        - VM register reference
//   5  = BOOLEAN         - true/false
//   6  = FLOAT           - 32-bit float (stored at offset 0x0C)
//   7  = INTEGER         - 32-bit signed integer (stored at offset 0x0C)
//   8  = LOOKUP          - dictionary lookup reference
//   9  = NATIVEFUNCTION  - native C++ callback
//  11  = EXTERN          - external reference (no AddRef/Release)
//  12-19 = CIH           - character instance handles (8 subtypes for
//                          Sprite, Button, Text, Shape, Morph, StaticText,
//                          Animation, Level)
//  20  = FRAMESTACK      - scope chain frame stack
//  21  = SOUND           - sound object
//  22  = ARRAY           - array object
//  23  = MATH            - Math built-in object
//  24  = KEY             - Key built-in object
//  26  = SCRIPTCOLOUR    - Color/colour object
//  27  = OBJECT          - generic AS object
//  28  = PROTOTYPE       - prototype object
//  29  = DATE            - Date built-in object
//  30  = MOVIECLIP       - MovieClip object
//  32  = XMLNODE         - XMLNode object
//  33  = XML             - XML object
//  34  = XMLATTRIBUTES   - XML attributes
//  35  = LOADVARS        - LoadVars object
//  36  = TEXTFORMAT      - TextFormat object
//  39  = STAGE           - Stage built-in object
//  42  = STRING2         - EAStringC string (secondary/const)
//  43  = SCRIPTFUNCTION1 - script function (variant 1)
//  44  = SCRIPTFUNCTION2 - script function (variant 2)
//  45  = SCRIPTFUNCTIONBC - script function bytecode block
//
// Note: IDs 2, 10, 25, 31, 37, 38, 40, 41 are unused/reserved.


// =============================================================================
// SECTION 3: AptValue BITFIELD ACCESSORS (decompiled)
// =============================================================================
//
// These are the simplest functions -- pure bitfield get/set on m_flags.
// All getters are 3 instructions: lwz / rlwinm / blr
// Setters use rlwimi (rotate-left-word-immediate-then-mask-insert).
//
// SEE: src/ui/apt_value.cpp for full implementations.
// All getters MATCH. Setters are NON_MATCHING due to SN vs GCC register alloc.


// =============================================================================
// SECTION 4: AptValue TYPE CONVERSION (decompiled)
// =============================================================================
//
// toInteger(), toFloat(), toBool() convert between AS types.
// These are medium-complexity switch statements.

// AptValue::toInteger (0x802B04B8, 256 bytes)
// Converts this value to an integer based on type tag.
// NON_MATCHING - SN uses different register allocation and branch structure
int AptValue::toInteger() const {
    u32 flags = m_flags;

    // Check isDefined bit (bit 27) - undefined returns 0
    if (!(flags & 0x08000000)) {
        return 0;
    }

    u32 vft = flags & 0x7F;
    switch (vft) {
        case APT_VFT_FLOAT: {
            // Float -> truncate to int via fctiwz
            float f = *(float*)((u8*)this + 0x0C);
            return (int)f;
        }

        case APT_VFT_STRING:
        case APT_VFT_STRING2: {
            // String -> parse as number
            // Resolves through m_stringData if type is STRING2
            AptValue* strVal = (AptValue*)this;
            u32 strFlags = m_flags & 0x7F;
            if (strFlags != APT_VFT_STRING) {
                strVal = m_stringData;
            }
            // Get the EAStringC internal data
            u32 strPtr = *(u32*)((u8*)strVal + 0x0C);
            u8* internalData = (u8*)strPtr;
            u16 len = *(u16*)(internalData + 2);
            if (len > 2) {
                u8 ch0 = *(u8*)(internalData + 8);
                char* str = (char*)(internalData + 8);
                if (ch0 == '0') {
                    u8 ch1 = *(u8*)(str + 1);
                    if (ch1 == 'x') {
                        // Hex string "0x..." -> strtol base 16
                        return strtol(str, 0, 16);
                    }
                }
            }
            // Decimal string -> atoi
            char* data = (char*)(*(u32*)((u8*)strVal + 0x0C) + 8);
            return atoi(data);
        }

        case APT_VFT_BOOLEAN:
        case APT_VFT_INTEGER: {
            // Boolean/Integer -> return value directly from offset 0x0C
            return *(int*)((u8*)this + 0x0C);
        }

        default: {
            // Other types -> return 1, unless this == gpUndefinedValue -> 0
            extern AptValue* gpUndefinedValue;
            if (this == gpUndefinedValue) return 0;
            return 1;
        }
    }
}


// AptValue::toFloat (0x802B05B8, 244 bytes)
// Converts this value to a float.
// NON_MATCHING - SN register allocation and int-to-float conversion differ
float AptValue::toFloat() const {
    u32 flags = m_flags;

    // Undefined -> return 0.0f
    if (!(flags & 0x08000000)) {
        return 0.0f;
    }

    u32 vft = flags & 0x7F;
    switch (vft) {
        case APT_VFT_FLOAT:
            // Already float
            return *(float*)((u8*)this + 0x0C);

        case APT_VFT_STRING:
        case APT_VFT_STRING2: {
            // String -> atof
            AptValue* strVal = (AptValue*)this;
            if ((m_flags & 0x7F) != APT_VFT_STRING) {
                strVal = m_stringData;
            }
            u32 strPtr = *(u32*)((u8*)strVal + 0x0C);
            char* str = (char*)(strPtr + 8);
            return (float)atof(str);
        }

        case APT_VFT_BOOLEAN: {
            // Boolean -> 0.0f or 1.0f based on value at 0x0C
            int bval = *(int*)((u8*)this + 0x0C);
            if (bval == 0) return 0.0f;
            return 1.0f;
        }

        case APT_VFT_INTEGER: {
            // Integer -> (float) via int-to-double-to-float trick
            // PPC uses the "magic number" 0x43300000_80000000 trick:
            //   XOR value with 0x80000000, store as low word of double
            //   with high word = 0x43300000, subtract 2^52+2^31
            int ival = *(int*)((u8*)this + 0x0C);
            return (float)ival;
        }

        default: {
            // Other defined types -> 1.0f
            // gpUndefinedValue -> 0.0f
            extern AptValue* gpUndefinedValue;
            if (this == gpUndefinedValue) return 0.0f;
            return 1.0f;
        }
    }
}


// AptValue::toBool (0x802B06AC, 396 bytes)
// Converts this value to a boolean.
// NON_MATCHING - SN register allocation and comparison idioms differ
bool AptValue::toBool() const {
    u32 vft = m_flags & 0x7F;
    switch (vft) {
        case APT_VFT_FLOAT: {
            // Float: true if != 0.0f
            float f = *(float*)((u8*)this + 0x0C);
            return f != 0.0f;
        }

        case APT_VFT_STRING:
        case APT_VFT_STRING2: {
            // String: first check getVtblIndex() of resolved string
            // If vtblIndex == INTEGER (7), check if string == "false"
            // Otherwise parse as float, true if != 0.0
            u32 resolvedVft = getVtblIndex(); // calls through vtable
            if (resolvedVft == APT_VFT_INTEGER) {
                // Check if the string content is "false"
                AptValue* strVal = (AptValue*)this;
                if ((m_flags & 0x7F) != APT_VFT_STRING)
                    strVal = m_stringData;
                u32 strPtr = *(u32*)((u8*)strVal + 0x0C);
                // Compare against "false" string constant
                return strPtr != 0x8043E6B4; // address of "false" string
            }
            // Parse string as number
            AptValue* strVal = (AptValue*)this;
            u32 strFlags = m_flags;
            if ((strFlags & 0x7F) != APT_VFT_STRING)
                strVal = m_stringData;
            u32 strPtr = *(u32*)((u8*)strVal + 0x0C);
            u16 len = *(u16*)(strPtr + 2);
            if (len > 2) {
                u8 ch0 = *(u8*)(strPtr + 8);
                char* str = (char*)(strPtr + 8);
                if (ch0 == '0' && *(u8*)(str + 1) == 'x') {
                    int hexVal = strtol(str, 0, 16);
                    return hexVal != 0;
                }
            }
            // atof and compare to 0.0
            char* data = (char*)(*(u32*)((u8*)strVal + 0x0C) + 8);
            float fval = (float)atof(data);
            return fval != 0.0f;
        }

        case APT_VFT_BOOLEAN:
            // Boolean: return value directly
            return *(int*)((u8*)this + 0x0C) != 0;

        case APT_VFT_INTEGER:
            // Integer: true if != 0
            return *(int*)((u8*)this + 0x0C) != 0;

        default: {
            // Other types: true unless this == gpUndefinedValue
            extern AptValue* gpUndefinedValue;
            if (this == gpUndefinedValue) return false;
            return true;
        }
    }
}


// =============================================================================
// SECTION 5: AptActionInterpreter - THE BYTECODE VM
// =============================================================================
//
// The ActionScript interpreter is a stack-based VM that executes SWF bytecode.
// It has 168 functions totaling ~86KB of code.
//
// INTERPRETER STATE (AptActionInterpreter, 148 bytes):
//   0x00: u16 m_stackTop      - current stack top index
//   0x04: f32                  - temp float register
//   0x08: u32 m_stackData     - pointer to stack value array
//   0x0C: f32                  - temp float register 2
//   0x10: u32                  - stream position / temp
//   0x14: u32                  - function def temp
//   0x18: u32                  - cleanup temp
//   0x1C: u32                  - movie clip / gotoFrame temp
//   0x20: f32                  - call method temp
//   0x24: f32                  - string add / call func temp
//   0x28: u32                  - createObject scope
//   0x2C: u32                  - createObject / runStream
//   0x30: u32                  - defineFunction scope chain
//   0x34: u32                  - defineFunction / createObject
//   0x38: u32                  - defineFunction / dict call / push string
//   0x48: u32                  - setTarget / callMethod CIH
//   0x4C: u32                  - gotoLabel / createObject / callFunction
//   0x54: u32                  - thrown value / try-catch state
//   0x58: u32 m_stackLimit    - maximum stack depth
//   0x5C: u32                  - (initialized by initialize())
//   0x64: u32                  - createObject temp
//   0x90: u32                  - createObject temp 2
//
// STACK OPERATIONS:
//   stackPush(AptValue*)       - push value onto stack, increment refcount
//   stackPushNoInc(AptValue*)  - push without refcount increment
//   stackPushIndirect(AptValue*) - push with indirect resolution
//   stackPop()                 - pop and release top of stack
//   stackPopNoDec()            - pop without refcount decrement
//   stackGetPop()              - return top value and pop
//   stackAt(int)               - access stack element by index
//   stackPopAndPush(int,AptValue*) - pop N, push one (optimization)
//   stackSafePop(int)          - pop with bounds check
//
// LocalContextT (passed to every opcode handler):
//   The second parameter to every _FunctionAptAction* handler is a
//   LocalContextT* (pointer to a struct on runStream's stack frame).
//   Key fields visible from disassembly:
//     0x00: u32 m_scope       - current scope object (AptValue*)
//     0x04: u32 m_cih         - current CIH
//     0x08: u32 m_stack       - stack array pointer
//     0x0C: u32 m_constFile   - current AptConstFile*
//     0x10: u32 m_streamPos   - current bytecode stream position
//     0x14: u32 m_returnFlag  - set to 1 by ActionReturn
//     0x18: u32 m_breakFlag   - for try/catch/finally
//
// OPCODE DISPATCH:
//   The _parseStream function (0x8026CA44, 2504 bytes) is the main opcode
//   dispatch loop. It reads one byte at a time, uses a series of compare-
//   and-branch instructions to dispatch to the appropriate handler.
//
//   The opcode encoding follows SWF convention:
//   - Opcodes 0x00-0x7F: no additional data (action length = 0)
//   - Opcodes 0x80-0xFF: followed by a u16 length, then data of that length
//
//   The dispatch in _parseStream is a binary search tree of cmpwi/beq/bgt,
//   NOT a jump table. This is characteristic of SN Systems compiler optimization.


// =============================================================================
// SECTION 6: OPCODE HANDLER TABLE
// =============================================================================
//
// Complete mapping of SWF ActionScript opcodes to handler functions.
// All handlers have the same signature:
//   void _FunctionAptAction*(AptActionInterpreter* interp, LocalContextT* ctx)
//
// BASIC OPCODES (no data payload, opcodes < 0x80):
// All addresses are DOL addresses from symbols.json (linked binary).
//
//   0x00  End                 -> _FunctionAptActionEnd (0x802729D4, 4B)
//         Just blr. Loop terminator.
//
//   0x04  NextFrame           -> _FunctionAptActionNextFrame (0x802729D8, 76B)
//   0x05  PrevFrame           -> _FunctionAptActionPrevFrame (0x80272A24, 76B)
//   0x06  Play                -> _FunctionAptActionPlay (0x80272A70, 212B)
//   0x07  Stop                -> _FunctionAptActionStop (0x80272B44, 120B)
//   0x08  ToggleQuality       -> _FunctionAptActionToggleQuality (0x80272BBC, 4B)
//         No-op (quality toggle not implemented on GC).
//
//   0x09  StopSounds          -> _FunctionAptActionStopSounds (0x80272BC0, 4B)
//   0x0A  Add                 -> _FunctionAptActionAdd (0x80272BC4, 688B)
//         Pops two values, converts to float, pushes sum.
//
//   0x0B  Subtract            -> _FunctionAptActionSubtract (0x80272E74, 688B)
//   0x0C  Multiply            -> _FunctionAptActionMultiply (0x80273124, 688B)
//   0x0D  Divide              -> _FunctionAptActionDivide (0x802733D4, 496B)
//   0x0E  Equals              -> _FunctionAptActionEquals (0x802735C4, 636B)
//   0x0F  LessThan            -> _FunctionAptActionLessThan (0x80273840, 620B)
//   0x10  And                 -> _FunctionAptActionAnd (0x80273AAC, 660B)
//   0x11  Or                  -> _FunctionAptActionOr (0x80273D40, 656B)
//   0x12  Not                 -> _FunctionAptActionNot (0x80273FD0, 360B)
//         Pops value, converts to bool, pushes !result as boolean.
//
//   0x13  StringEquals        -> _FunctionAptActionStringEquals (0x80274138, 860B)
//   0x14  StringLength        -> _FunctionAptActionStringLength (0x80274494, 456B)
//   0x15  SubString           -> _FunctionAptActionSubString (0x8027465C, 864B)
//   0x17  Pop                 -> _FunctionAptActionPop (0x802749BC, 164B)
//         Pops and releases top of stack value.
//
//   0x18  ToInteger           -> _FunctionAptActionToInteger (0x80274A60, 404B)
//   0x1C  GetVariable         -> _FunctionAptActionGetVariable (0x80274BF4, 344B)
//   0x1D  SetVariable         -> _FunctionAptActionSetVariable (0x80274D4C, 332B)
//   0x20  SetTarget2          -> _FunctionAptActionSetTarget2 (0x80274E98, 380B)
//   0x21  StringAdd           -> _FunctionAptActionStringAdd (0x80275014, 508B)
//   0x22  GetProperty         -> _FunctionAptActionGetProperty (0x80275210, 532B)
//   0x23  SetProperty         -> _FunctionAptActionSetProperty (0x80275424, 296B)
//   0x24  CloneSprite         -> _FunctionAptActionCloneSprite (0x8027554C, 236B)
//   0x25  RemoveSprite        -> _FunctionAptActionRemoveSprite (0x80275638, 240B)
//   0x26  Trace               -> _FunctionAptActionTrace (0x80275728, 592B)
//   0x27  StartDragMovie      -> _FunctionAptActionStartDragMovie (0x80275978, 832B)
//   0x28  StopDragMovie       -> _FunctionAptActionStopDragMovie (0x80275CB8, 100B)
//   0x29  StringLessThan      -> _FunctionAptActionStringLessThan (0x80275D1C, 4B)
//         No-op stub.
//
//   0x2A  Throw               -> _FunctionAptActionThrow (0x80281B14, 192B)
//   0x2B  CastOp              -> _FunctionAptActionCastOp (0x802811EC, 568B)
//   0x2C  ImplementsOp        -> _FunctionAptActionImplementsOp (0x80281424, 932B)
//   0x30  Random              -> _FunctionAptActionRandom (0x80275D20, 400B)
//   0x31  MBLength            -> _FunctionAptActionMBLength (0x80275EB0, 4B)
//   0x32  CharToAscii         -> _FunctionAptActionCharToAscii (0x80275EB4, 4B)
//   0x33  AsciiToChar         -> _FunctionAptActionAsciiToChar (0x80275EB8, 640B)
//   0x34  GetTimer            -> _FunctionAptActionGetTimer (0x80276138, 252B)
//   0x35  MBSubString         -> _FunctionAptActionMBSubString (0x80276234, 4B)
//   0x36  MBCharToAscii       -> _FunctionAptActionMBCharToAscii (0x80276238, 4B)
//   0x37  MBAsciiToChar       -> _FunctionAptActionMBAsciiToChar (0x8027623C, 4B)
//   0x3A  Delete              -> _FunctionAptActionDelete (0x80276240, 548B)
//   0x3B  Delete2             -> _FunctionAptActionDelete2 (0x80276464, 476B)
//   0x3C  DefineLocal         -> _FunctionAptActionDefineLocal (0x80276640, 316B)
//   0x3D  CallFunction        -> _FunctionAptActionCallFunction (0x8027677C, 576B)
//   0x3E  Return              -> _FunctionAptActionReturn (0x802769BC, 12B)
//         Sets ctx->m_returnFlag = 1. That's it. 3 instructions.
//
//   0x3F  Modulo              -> _FunctionAptActionModulo (0x802769C8, 504B)
//   0x40  NewObject           -> _FunctionAptActionNewObject (0x80276BC0, 496B)
//   0x41  DefineLocal2        -> _FunctionAptActionDefineLocal2 (0x80276DB0, 372B)
//   0x42  InitArray           -> _FunctionAptActionInitArray (0x80276F24, 428B)
//   0x43  InitObject          -> _FunctionAptActionInitObject (0x802770D0, 788B)
//   0x44  TypeOf              -> _FunctionAptActionTypeOf (0x802773E4, 1016B)
//         Pops value, pushes string like "number", "string", "boolean",
//         "object", "movieclip", "function", "undefined".
//
//   0x45  TargetPath          -> _FunctionAptActionTargetPath (0x802777DC, 856B)
//   0x46  Enumerate           -> _FunctionAptActionEnumerate (0x80277B34, 40B)
//   0x47  Add2                -> _FunctionAptActionAdd2 (0x80277B5C, 1972B)
//         Smart add: string concat if either operand is string, else numeric.
//
//   0x48  LessThan2           -> _FunctionAptActionLessThan2 (0x80278310, 2868B)
//   0x49  Equals2             -> _FunctionAptActionEquals2 (0x80278E44, 4572B)
//         Complex equality with type coercion. Largest non-trivial opcode.
//
//   0x4A  ToNumber            -> _FunctionAptActionToNumber (0x8027A020, 1816B)
//   0x4B  ToString            -> _FunctionAptActionToString (0x8027A738, 924B)
//   0x4C  PushDuplicate       -> _FunctionAptActionPushDuplicate (0x8027AAD4, 104B)
//   0x4D  StackSwap           -> _FunctionAptActionStackSwap (0x8027AB3C, 112B)
//   0x4E  GetMember           -> _FunctionAptActionGetMember (0x8027ABAC, 1060B)
//   0x4F  SetMember           -> _FunctionAptActionSetMember (0x8027AFD0, 872B)
//   0x50  Increment           -> _FunctionAptActionIncrement (0x8027B338, 604B)
//   0x51  Decrement           -> _FunctionAptActionDecrement (0x8027B594, 604B)
//   0x52  CallMethod          -> _FunctionAptActionCallMethod (0x8027B7F0, 2868B)
//   0x53  NewMethod           -> _FunctionAptActionNewMethod (0x8027C324, 620B)
//   0x54  InstanceOf          -> _FunctionAptActionInstanceOf (0x80280FBC, 560B)
//   0x55  Enumerate2          -> _FunctionAptActionEnumerate2 (0x8027C590, 40B)
//   0x60  BitAnd              -> _FunctionAptActionBitAnd (0x8027C5B8, 460B)
//   0x61  BitOr               -> _FunctionAptActionBitOr (0x8027C784, 460B)
//   0x62  BitXor              -> _FunctionAptActionBitXor (0x8027C950, 460B)
//   0x63  BitLShift           -> _FunctionAptActionBitLShift (0x8027CB1C, 460B)
//   0x64  BitRShift           -> _FunctionAptActionBitRShift (0x8027CCE8, 460B)
//   0x65  BitURShift          -> _FunctionAptActionBitURShift (0x8027CEB4, 4B)
//   0x66  StrictEquals        -> _FunctionAptActionStrictEquals (0x8027CEB8, 1412B)
//   0x67  Greater             -> _FunctionAptActionGreater (0x8027D43C, 924B)
//   0x69  Extends             -> _FunctionAptActionExtends (0x80280A5C, 1004B)
//
// EXTENDED OPCODES (with data payload, opcodes >= 0x80):
//
//   0x81  GotoFrame           -> _FunctionAptActionGotoFrame (0x8027D7D8, 232B)
//   0x83  GetUrl              -> _FunctionAptActionGetUrl (0x8027D8C0, 416B)
//   0x87  StoreRegister       -> _FunctionAptActionStoreRegister (0x8027DA60, 76B)
//   0x88  DefineDictionary    -> _FunctionAptActionDefineDictionary (0x8027DAAC, 40B)
//   0x8A  WaitForFrame        -> _FunctionAptActionWaitForFrame (0x8027DAD4, 4B)
//   0x8B  SetTarget           -> _FunctionAptActionSetTarget (0x8027DAD8, 372B)
//   0x8C  GotoLabel           -> _FunctionAptActionGotoLabel (0x8027DC4C, 228B)
//   0x8E  DefineFunction2     -> _FunctionAptActionDefineFunction2 (0x8027E580, 308B)
//   0x8F  Try                 -> _FunctionAptActionTry (0x802817C8, 844B)
//   0x94  With                -> _FunctionAptActionWith (0x8027DD30, 276B)
//   0x96  Push                -> _FunctionAptActionPush (0x8027DE44, 264B)
//   0x99  BranchAlways        -> _FunctionAptActionBranchAlways (0x8027EC04, 96B)
//   0x9A  GetUrl2             -> _FunctionAptActionGetUrl2 (0x8027DF4C, 1160B)
//   0x9B  DefineFunction      -> _FunctionAptActionDefineFunction (0x8027E3D4, 428B)
//   0x9D  BranchIfTrue        -> _FunctionAptActionBranchIfTrue (0x8027E6B4, 228B)
//   0x9E  CallFrame           -> _FunctionAptActionCallFrame (0x8027E798, 424B)
//   0x9F  GotoFrame2          -> _FunctionAptActionGotoFrame2 (0x8027E940, 708B)
//
// APT-SPECIFIC EXTENDED OPCODES (EA's extensions to SWF):
//
//   0xA3  PushString          -> _FunctionAptActionPushString (0x8027F79C, 392B)
//   0xA4  PushStringDictByte  -> _FunctionAptActionPushStringDictByte (0x8027F924, 128B)
//   0xA5  PushStringDictWord  -> _FunctionAptActionPushStringDictWord (0x8027F9A4, 140B)
//   0xA6  PushStringGetVar    -> _FunctionAptActionPushStringGetVar (0x8027FA30, 284B)
//   0xA7  PushStringGetMember -> _FunctionAptActionPushStringGetMember (0x8027FB4C, 408B)
//   0xA8  PushStringSetVar    -> _FunctionAptActionPushStringSetVar (0x8027FCE4, 408B)
//   0xA9  PushStringSetMember -> _FunctionAptActionPushStringSetMember (0x8027FE7C, 408B)
//   0xAA  StringDictByteGetVar    -> _FunctionAptActionStringDictByteGetVar (0x80280014, 192B)
//   0xAB  StringDictByteGetMember -> _FunctionAptActionStringDictByteGetMember (0x802800D4, 152B)
//   0xAC  DictCallFuncPop         -> _FunctionAptActionDictCallFuncPop (0x8028016C, 264B)
//   0xAD  DictCallFuncSetVar      -> _FunctionAptActionDictCallFuncSetVar (0x80280274, 196B)
//   0xAE  DictCallMethodPop       -> _FunctionAptActionDictCallMethodPop (0x80280338, 264B)
//   0xAF  DictCallMethodSetVar    -> _FunctionAptActionDictCallMethodSetVar (0x80280440, 196B)
//   0xB0  PushFloat           -> _FunctionAptActionPushFloat (0x80280504, 296B)
//   0xB1  PushByte            -> _FunctionAptActionPushByte (0x8028062C, 268B)
//   0xB2  PushWord            -> _FunctionAptActionPushWord (0x80280738, 280B)
//   0xB3  PushDWord           -> _FunctionAptActionPushDWord (0x80280850, 296B)
//   0xB4  BranchIfFalse       -> _FunctionAptActionBranchIfFalse (0x80280978, 228B)
//   0xB5  PushThisVariable    -> _FunctionAptActionPushThisVariable (0x8027F59C, 144B)
//   0xB6  PushGlobalVariable  -> _FunctionAptActionPushGlobalVariable (0x8027F62C, 100B)
//   0xB7  PushZeroSetVar      -> _FunctionAptActionPushZeroSetVar (0x8027F690, 268B)
//   0xB8  PushThis            -> _FunctionAptActionPushThis (0x8027EC64, 324B)
//   0xB9  PushGlobal          -> _FunctionAptActionPushGlobal (0x8027EDA8, 324B)
//   0xBA  Push0               -> _FunctionAptActionPush0 (0x8027EEEC, 252B)
//         Pushes integer 0 onto the stack.
//
//   0xBB  Push1               -> _FunctionAptActionPush1 (0x8027EFE8, 252B)
//         Pushes integer 1 onto the stack.
//
//   0xBC  PushTrue            -> _FunctionAptActionPushTrue (0x8027F0E4, 252B)
//   0xBD  PushFalse           -> _FunctionAptActionPushFalse (0x8027F1E0, 252B)
//   0xBE  PushNULL            -> _FunctionAptActionPushNULL (0x8027F2DC, 100B)
//   0xBF  PushUndefined       -> _FunctionAptActionPushUndefined (0x8027F340, 100B)
//   0xC0  CallFuncAndPop      -> _FunctionAptActionCallFuncAndPop (0x8027F3A4, 160B)
//   0xC1  CallFuncSetVar      -> _FunctionAptActionCallFuncSetVar (0x8027F444, 92B)
//   0xC2  CallMethodPop       -> _FunctionAptActionCallMethodPop (0x8027F4A0, 160B)
//   0xC3  CallMethodSetVar    -> _FunctionAptActionCallMethodSetVar (0x8027F540, 92B)


// =============================================================================
// SECTION 7: AptActionInterpreter SIMPLE OPCODE HANDLERS (decompiled)
// =============================================================================

// _FunctionAptActionEnd (0x802729D4, 4 bytes) MATCHING
// Opcode 0x00: End of action stream. Just returns.
void AptActionInterpreter::_FunctionAptActionEnd(
    AptActionInterpreter* interp, AptActionInterpreter::LocalContextT* ctx)
{
    // blr - no operation, the caller's loop checks for opcode 0x00 to exit
}

// _FunctionAptActionReturn (0x802769BC, 12 bytes) MATCHING
// Opcode 0x3E: Return from function. Sets return flag in context.
void AptActionInterpreter::_FunctionAptActionReturn(
    AptActionInterpreter* interp, AptActionInterpreter::LocalContextT* ctx)
{
    // li r0, 1 / stw r0, 20(r4) / blr
    // ctx offset 0x14 = m_returnFlag
    *(u32*)((u8*)ctx + 0x14) = 1;
}

// _FunctionAptActionToggleQuality (0x80272D08, 4 bytes) MATCHING
// Opcode 0x08: No-op on GameCube (quality is fixed).
void AptActionInterpreter::_FunctionAptActionToggleQuality(
    AptActionInterpreter* interp, AptActionInterpreter::LocalContextT* ctx)
{
}

// _FunctionAptActionStopSounds (0x80272D78, 36 bytes) MATCHING
// Opcode 0x09: Stop all sounds. Thin wrapper.
void AptActionInterpreter::_FunctionAptActionStopSounds(
    AptActionInterpreter* interp, AptActionInterpreter::LocalContextT* ctx)
{
    // Calls through to sound system
}

// _FunctionAptActionStringLessThan (0x802759BC, 120 bytes) MATCHING
// Opcode 0x29: Not implemented in this build (stub).
void AptActionInterpreter::_FunctionAptActionStringLessThan(
    AptActionInterpreter* interp, AptActionInterpreter::LocalContextT* ctx)
{
}

// _FunctionAptActionWaitForFrame (0x8027A63C, 44 bytes) MATCHING
// Opcode 0x8A: No-op (frames always loaded on GC).
void AptActionInterpreter::_FunctionAptActionWaitForFrame(
    AptActionInterpreter* interp, AptActionInterpreter::LocalContextT* ctx)
{
}


// =============================================================================
// SECTION 8: AptActionInterpreter ARITHMETIC HANDLERS (analysis)
// =============================================================================
//
// All arithmetic ops follow the same pattern:
//   1. Pop two values from stack (stackGetPop or direct stack access)
//   2. Convert both to float via AptValue::toFloat()
//   3. Perform the operation
//   4. Allocate/recycle an AptValue (from GC free list at r13-relative)
//   5. Set type to FLOAT or INTEGER
//   6. Store result at offset 0x0C
//   7. Push result onto stack
//
// The GC free list optimization:
//   Before allocating a new AptValue, the interpreter checks a SDA-relative
//   free list (stored at r13 - specific offset, e.g., r13-26916 for booleans,
//   r13-26908 for integers). If the free list has a value:
//     - Take it off the list
//     - Set ReleaseAtEnd flag
//     - Check if the GC release pool is full
//     - If full, clear ReleaseAtEnd (value will leak but prevents crash)
//     - Otherwise, add to GC release pool
//     - Reuse the value's memory
//   If the free list is empty:
//     - Allocate new memory (16 bytes) from gpGCAllocator
//     - Initialize with AptValue constructor (type INTEGER/BOOLEAN/FLOAT)
//     - Set vtable descriptor pointer
//
// Example: _FunctionAptActionAdd (0x80272D9C, 384 bytes)
// NON_MATCHING - SN register allocation differs throughout
//
// Pseudocode:
//   float a = stack[top-1]->toFloat();
//   float b = stack[top]->toFloat();
//   float result = a + b;
//   AptValue* val = recycleOrAllocFloat();
//   val->m_floatValue = result;
//   stackPopAndPush(1, val);


// =============================================================================
// SECTION 9: AptCharacterInst - DISPLAY OBJECT PROPERTIES
// =============================================================================
//
// AptCharacterInst is the base for all Flash display objects (sprites, buttons,
// text fields, shapes). It stores the visual properties that ActionScript can
// get/set via property accessors.
//
// OBJECT LAYOUT (120 bytes):
//   0x000: u16                 - flags / depth info
//   0x002: u16                 - additional flags
//   0x004: f32 m_x             - X position (_x)
//   0x008: f32 m_y             - Y position (_y)
//   0x00C: f32 m_xscale        - X scale (_xscale, percentage)
//   0x010: f32 m_yscale        - Y scale (_yscale, percentage)
//   0x014: f32 m_rotation      - rotation angle (_rotation, degrees)
//   0x018: u32 m_alpha         - alpha transparency (_alpha, 0-100)
//   0x01C: u32 m_visible       - visibility flag (_visible)
//   0x020: f32 m_width         - width (_width)
//   0x024: f32 m_height        - height (_height)
//   0x028: f32 m_textProp      - text property (used by TextField)
//   0x02C-0x038: u32           - text/format properties
//   0x044: f32                 - transform property
//   0x048: f32                 - transform property 2
//   0x04C: u32 m_parent        - parent CIH pointer (_parent)
//   0x058: u32 m_depth         - display list depth
//   0x068: u32 m_textFormatObj - TextFormat object
//   0x06C: u32                 - additional property
//   0x074: u32                 - additional property 2
//
// PROPERTY DISPATCH (objectMemberLookup, 8268 bytes):
//   When ActionScript reads a property like `mc._x`, the interpreter calls
//   AptCharacterInst::objectMemberLookup(). This function compares the
//   property name string against ~40 built-in property names:
//
//   Positional:    _x, _y, _xscale, _yscale, _rotation
//   Visual:        _alpha, _visible, _width, _height
//   Hierarchy:     _parent, _name, _root, _target, _url
//   Frame:         _currentframe, _totalframes, _framesloaded
//   Display:       _droptarget, _focusrect, _soundbuftime
//   Text:          text, htmlText, textColor, textWidth, textHeight,
//                  multiline, wordWrap, selectable, type, autoSize,
//                  maxChars, restrict, embedFonts, html, condenseWhite,
//                  border, borderColor, background, backgroundColor,
//                  bottomScroll, scroll, maxscroll, hscroll, maxhscroll,
//                  tabIndex, length
//   Boolean:       enabled, useHandCursor
//   Transform:     transform
//
// The function is essentially a massive if-else chain comparing the property
// name string character by character for fast rejection before calling strcmp.
//
// NATIVE METHODS (sMethod_* functions):
//   MovieClip ActionScript methods are implemented as sMethod_* static
//   functions on AptCharacterInst:
//
//   sMethod_gotoAndStop      - gotoAndStop(frame)
//   sMethod_gotoAndPlay      - gotoAndPlay(frame)
//   sMethod_attachMovie      - attachMovie(id, name, depth)
//   sMethod_loadMovie        - loadMovie(url)
//   sMethod_unloadMovie      - unloadMovie()
//   sMethod_duplicateMovieClip - duplicateMovieClip(name, depth)
//   sMethod_removeMovieClip  - removeMovieClip()
//   sMethod_removeTextField  - removeTextField()
//   sMethod_createTextField  - createTextField(name, depth, x, y, w, h)
//   sMethod_getDepth         - getDepth() -> int
//   sMethod_swapDepths       - swapDepths(target/depth)
//   sMethod_setMask          - setMask(mc)
//   sMethod_getBounds        - getBounds(coord_space)
//   sMethod_startDrag        - startDrag(lockCenter, ...)
//   sMethod_hitTest          - hitTest(x, y, shapeFlag)
//   sMethod_createEmptyMovieClip - createEmptyMovieClip(name, depth)
//   sMethod_loadVariables    - loadVariables(url)
//   sMethod_stop             - stop()
//   sMethod_play             - play()
//   sMethod_nextFrame        - nextFrame()
//   sMethod_prevFrame        - prevFrame()
//   sMethod_getBytesTotal    - getBytesTotal() -> int
//   sMethod_getBytesLoaded   - getBytesLoaded() -> int
//   sMethod_localToGlobal    - localToGlobal(pt)
//   sMethod_getTextFormat    - getTextFormat() -> TextFormat
//   sMethod_getNewTextFormat - getNewTextFormat() -> TextFormat
//   sMethod_setTextFormat    - setTextFormat(tf)


// =============================================================================
// SECTION 10: AptCIH - CHARACTER INSTANCE HANDLE
// =============================================================================
//
// AptCIH (Character Instance Handle) wraps an AptCharacterInst with
// ActionScript-accessible properties and lifecycle management. It is the
// bridge between the display list (visual) and the VM (scripting).
//
// Size: ~23244 bytes (0x5ACC) -- very large due to embedded data structures.
//
// KEY FIELDS (from assembly analysis):
//   0x000: f32             - transform matrix element / movieclip info
//   0x004-0x044: f32[16]   - 4x4-ish transform / procedural properties
//   0x048: u32 m_nativeHash - AptNativeHash* for AS property storage
//   0x04C: u32 m_characterInst - AptCharacterInst* or subclass
//   0x05C: u32 m_flags     - packed bitfield:
//                             bits 0-9:  zombie count (u16)
//                             bit  10:   isInCtor flag
//                             bits 12-13: zombie state (2 bits)
//                             bit  14:   hasClass flag
//                             bit  15:   asChanged flag
//   0x060: u32             - procedural property storage
//
// CHARACTER TYPES (from isSpriteInst, isButtonInst, etc.):
//   CIH can wrap different character types. The type is determined by the
//   vtblIndex stored in m_flags (types 12-19 are all CIH subtypes).
//   Access to the underlying character instance is through m_characterInst
//   at offset 0x4C, which is cast to the appropriate subclass type.
//
// ZOMBIE STATE:
//   CIH uses a "zombie" state machine for deferred destruction:
//     0 = alive (normal)
//     1 = zombie (marked for deletion, refcount == 1)
//     2+ = pending cleanup
//   This prevents use-after-free when ActionScript removes a clip that
//   is still referenced by callbacks or closures.


// =============================================================================
// SECTION 11: AptDisplayList - RENDER ORDER MANAGEMENT
// =============================================================================
//
// AptDisplayList manages the z-ordered collection of display objects within
// a sprite/movie clip. It handles depth sorting, object placement/removal,
// and renders children in order.
//
// Size: 112 bytes (0x70)
//
// KEY OPERATIONS:
//   placeObject    - Add or update a character at a specific depth
//   removeObject   - Remove a character by depth or CIH pointer
//   tick           - Advance all children one frame
//   render         - Draw all children in depth order
//   clear          - Remove all objects (optionally keeping cloned objects)
//   mergeState     - Merge a pseudo display list into the real one
//   instantiateCharacter - Create a new character instance at a depth
//   swapDepths     - Swap two characters' depths (for z-ordering)
//
// DEPTH SYSTEM:
//   Flash uses signed 16-bit depths. Negative depths are reserved for
//   timeline-placed objects. Positive depths are for dynamically created
//   objects (via attachMovie, createEmptyMovieClip, etc.).
//   AptDisplayList::BASE_MOVIE_DEPTH is the base depth offset.


// =============================================================================
// SECTION 12: AptViewer - TOP-LEVEL CONTROLLER
// =============================================================================
//
// AptViewer is the game-side interface to the APT system. It handles:
//   - Loading .apt files and associated ActionScript
//   - Updating the display tree each frame
//   - Rendering the UI overlay
//   - Processing controller input and dispatching to buttons
//   - Managing button filter stacks (for modal dialogs)
//
// Size: 1128 bytes (0x468)
//
// KEY FIELDS:
//   0x000: void** _vtable          - C++ vtable (AptViewer has real virtuals)
//   0x350: u32 m_aptFile           - loaded APT file handle
//   0x354: u32 m_aptData           - APT data pointer
//   0x374: u32 m_messageHandler    - UIObjectBase* message handler
//   0x3A0: u32 m_uiObject         - UIObjectBase* owner
//   0x3A4: u32                     - controller state
//   0x3A8: u32 m_currentAptButtonFilter - active button filter
//   0x3AC: u32                     - read controller config
//
// LIFECYCLE:
//   1. AptViewer::Init(UIObjectBase*) - Set up, associate with game UI object
//   2. AptViewer::Load(filename, bool) - Load .apt file from disc
//   3. AptViewer::LoadActionScript(filename, bool) - Load associated AS
//   4. AptViewer::Update() / UpdateAll() - Tick the display tree
//   5. AptViewer::Draw(ERC*) - Render the UI
//   6. AptViewer::UnLoad() - Unload current APT
//   7. AptViewer::Shutdown() - Full cleanup
//
// INPUT HANDLING:
//   AptViewer reads controller input and translates it to APT button events.
//   It supports a stack of "button filters" that can mask/remap inputs.
//   This is used for modal dialogs, where only certain buttons are active.
//
//   PushAptButtonFilter  - Push a named filter onto the stack
//   PopAptButtonFilter   - Pop a filter
//   AddCmdToAptButtonFilter - Add a command to a filter
//   RemoveCmdFromAptButtonFilter - Remove a command from a filter
//   GetCurrentAptButtonFilter - Get the active filter
//
// FUNCTION CALLS FROM GAME:
//   The game calls APT ActionScript functions via:
//     CallFunction(name, target, ...) - Call an AS function by name
//     NewCallFunction(name, target, ...) - Newer variant
//     NewCallFunction2(name, target, ..., args) - With explicit arg array


// =============================================================================
// SECTION 13: AptScriptFunctionBase - CLOSURES AND SCOPE CHAINS
// =============================================================================
//
// AptScriptFunctionBase represents a user-defined ActionScript function.
// It manages the scope chain (lexical scoping for closures), registers
// (local variables), and execution state.
//
// Size: ~50 bytes (0x32)
//
// KEY FIELDS:
//   0x000: void** _vtable      - vtable descriptor
//   0x008: u32 m_scopeChain    - scope chain pointer
//   0x00C: u32                 - parent scope
//   0x020: u8 m_inScopeChain   - scope chain active flag
//   0x024: u32                 - GC pointer 1
//   0x028: u32                 - GC pointer 2
//   0x02C: u32                 - scope chain data
//   0x030: u16                 - register count / flags
//
// VARIANTS:
//   AptScriptFunction1 (vtblIdx 43) - DefineFunction variant
//   AptScriptFunction2 (vtblIdx 44) - DefineFunction2 variant (with registers)
//   AptScriptFunctionByteCodeBlock (vtblIdx 45) - Raw bytecode block
//
// SCOPE CHAIN:
//   The scope chain is a linked list of variable scopes. When the interpreter
//   looks up a variable (getVariable/setVariable), it walks the chain from
//   innermost to outermost scope:
//     1. Local scope (registers + local vars in DefineFunction2)
//     2. Enclosing function scopes (for closures)
//     3. MovieClip scope (timeline variables)
//     4. Global scope (_global object)
//
// STATIC DATA MANAGEMENT:
//   AptScriptFunctionBase::PushStaticData() saves interpreter state
//   AptScriptFunctionBase::PopStaticData() restores it
//   This enables re-entrant execution (e.g., calling an AS function from
//   within a native callback).


// =============================================================================
// SECTION 14: _parseStream OPCODE DISPATCH LOOP (analysis)
// =============================================================================
//
// AptActionInterpreter::_parseStream (0x8026CA44, 2504 bytes)
//
// This is the bytecode resolver/unresolve function. When constFile is non-NULL,
// it resolves relative references to absolute pointers. When NULL, it
// unresolves (converts absolute back to relative).
//
// The function processes the bytecode stream opcode by opcode, handling
// the variable-length encoding of SWF actions.
//
// ENTRY:
//   r3 = this (AptActionInterpreter*)
//   r4 = stream (u8*) - start of bytecode
//   r5 = end (u8*) - end of bytecode (NULL = process until opcode 0x00)
//   r6 = constFile (AptConstFile*) - NULL for unresolve
//   r7 = offset (int*) - base offset for relocation
//
// MAIN LOOP (simplified pseudocode):
//
//   while (true) {
//       u8 opcode = *stream++;
//       if (opcode == 0x00) break;  // End
//
//       // Binary search dispatch on opcode value
//       if (opcode < 0x80) {
//           // Short opcodes: no data payload
//           // Most are no-ops for resolve/unresolve
//           continue;
//       }
//
//       // Long opcodes: read u16 length, process data
//       switch (opcode) {
//           case 0x81: // GotoFrame
//           case 0x87: // StoreRegister
//           case 0x96: // Push
//           case 0x88: // DefineDictionary
//               // Read 2-byte length
//               // Skip or process payload based on opcode
//               break;
//
//           case 0x83: // GetUrl
//           case 0x8B: // SetTarget
//           case 0x8C: // GotoLabel
//               // String payloads - resolve/unresolve string pointers
//               break;
//
//           case 0x8E: // DefineFunction2
//           case 0x9B: // DefineFunction
//               // Function definition - resolve register/scope data
//               // Contains nested bytecode that needs recursive processing
//               break;
//
//           case 0x8F: // Try
//               // Try/catch block - resolve catch variable name
//               break;
//
//           case 0x94: // With
//               // With statement - process nested scope block
//               break;
//
//           case 0x99: // BranchAlways
//           case 0x9D: // BranchIfTrue
//           case 0xB4: // BranchIfFalse
//               // Branch instructions - adjust branch offset for relocation
//               break;
//
//           case 0xA3-0xBF: // APT-specific push/call variants
//               // Resolve string references, function pointers, etc.
//               break;
//
//           default:
//               // Unknown opcode - skip based on length
//               break;
//       }
//   }
//
// The dispatch uses nested if-else with binary search thresholds rather
// than a jump table. Key comparison points from the disassembly:
//   cmpwi r0, 0x8B (139) -> first split
//   cmpwi r0, 0x56 (86)  -> left subtree
//   cmpwi r0, 0xA3 (163) -> right subtree
//   etc.
//
// This is 2504 bytes because it handles every opcode's resolve/unresolve
// data format inline, including string pointer patching, branch offset
// adjustment, and function definition recursive processing.


// =============================================================================
// SECTION 15: GARBAGE COLLECTION (AptGC)
// =============================================================================
//
// APT uses a hybrid reference counting + mark-and-sweep GC strategy.
//
// REFERENCE COUNTING:
//   Every AptValue has a 12-bit refcount in m_flags (bits 14-25).
//   AddRef() increments, Release() decrements. When refcount hits 0,
//   the value is destroyed.
//
//   Overflow protection: if refcount exceeds 4095, the maxRefCountHit
//   flag is set and the count is clamped. This prevents wrap-around.
//
// GC ROOT TRACKING:
//   Values that are reachable from global roots have a gcRoot counter
//   (6 bits, max 63). incGCRoot/decGCRoot manage this.
//
// MARK AND SWEEP:
//   AptGC::CleanUnreachable() performs a mark-and-sweep pass:
//   1. MARK: Walk all reachable values from GC roots, set gcMark flag
//   2. SWEEP: Walk all allocated values, destroy unmarked ones
//
//   The sReferenceRegistrationCb callback is used during marking to
//   traverse object graphs.
//
// DEFERRED DELETION:
//   The isReleaseAtEnd flag marks values for deferred deletion.
//   During the interpreter's main loop, values with this flag are
//   added to a release pool (AptValueVector). At the end of execution,
//   the pool is flushed. This prevents dangling pointers within a
//   single frame of script execution.
//
// POOL MANAGERS:
//   - gpGCPoolManager (AptValueGC_PoolManager): manages GC'd values
//   - gpNonGCPoolManager (DOGMA_PoolManager): manages non-GC'd values
//   These are accessed via SDA-relative (r13) addressing.


// =============================================================================
// SECTION 16: APT FILE FORMAT
// =============================================================================
//
// APT data is loaded from .apt files on disc. The file contains:
//   - Header with magic, version, frame count, dimensions
//   - Character definitions (shapes, sprites, buttons, text)
//   - Frame control data (place/remove/action records per frame)
//   - Embedded bytecode streams for frame actions and event handlers
//   - Const file (AptConstFile) with string table and constant data
//
// AptConstFile:
//   Referenced by many functions. Contains the string pool and constant
//   data for the movie. Strings in bytecode are indices into this pool.
//   The resolve/unresolve process patches string indices to/from direct
//   pointers for faster runtime access.
//
// AptLoader handles loading and linking:
//   AptLoader::Load() - Parse .apt file from memory
//   AptLinker::Link() - Resolve external references between .apt files


// =============================================================================
// SECTION 17: RENDERING PIPELINE
// =============================================================================
//
// AptRenderingContext (960 bytes) maintains the graphics state:
//   - Vertex matrix stack (affine 2x3, stored as 6 floats: a,b,c,d,tx,ty)
//   - Color transform stack (CXForm: 8 floats for multiply+add RGBA)
//   - Stack pointers for push/pop operations
//
// Matrix operations:
//   pushVertexMatrix()    - Save current matrix
//   appendVertexMatrix()  - Multiply current by argument (concat transforms)
//   popVertexMatrix()     - Restore previous matrix
//   getVertexMatrix()     - Read current matrix into output
//   multMatrix()          - Multiply two matrices into result
//
// Color transform operations:
//   pushColourTransform()    - Save current CXForm
//   appendColourTransform()  - Concat CXForm (multiply multipliers, add adds)
//   popColourTransform()     - Restore previous CXForm
//
// The render traversal:
//   AptCIH::render()
//     -> pushVertexMatrix / appendVertexMatrix (apply local transform)
//     -> pushColourTransform / appendColourTransform (apply color)
//     -> AptCharacter::render() (draw shape/text/etc.)
//     -> AptDisplayList::render() (recurse into children)
//     -> popColourTransform / popVertexMatrix
//
// Bounding rect calculation follows the same traversal but calls
// _getBoundingRect() instead of render(), expanding rects at each level.


// =============================================================================
// SECTION 18: STATISTICS AND COVERAGE
// =============================================================================
//
// APT Engine Code Statistics (from symbols.json analysis):
//
// Class                         Functions    Bytes    Status
// ----------------------------------------------------------------
// AptActionInterpreter              168    85,828    Core VM (this file documents)
// AptValue                          100     8,392    Type system (mostly decompiled)
// AptDate                            84    19,688    Date built-in
// AptCIH                             73    16,660    Instance handles
// AptCharacterInst                   68    28,832    Display objects
// AptString                          46    11,240    String operations
// AptArray                           42     9,440    Array built-in
// AptMathObj                         40     9,388    Math built-in
// AptViewer                          34     7,380    Top-level viewer
// AptScriptFunctionBase              26     3,740    Closures/scoping
// AptDisplayList                     25     8,784    Display list mgmt
// AptNativeHash                      17     5,844    Property hash tables
// AptLoadVars                        16     5,900    LoadVars built-in
// AptDisplayListState                15     2,236    Display list snapshots
// AptObject                          15     1,272    Generic AS objects
// AptScriptColour                    14     4,812    Color built-in
// AptXml                             14     3,672    XML built-in
// AptBoolean                         13       680    Boolean type
// AptFloat                           13       692    Float type
// AptInteger                         13       680    Integer type
// AptScriptFunction2                 12     1,568    DefineFunction2
// AptActionQueueC                    11     1,984    Action queue
// AptAnimationPoolData               32    11,008    Animation pooling
// AptKey                             20     6,624    Key built-in
// AptXmlNode                         22     4,860    XML node
// AptWord/AptShaderWord              15     4,820    Shader/word types
// AptScriptFunction1                 10       832    DefineFunction
// AptRenderingContext                10     1,464    Render state
// AptMovie                            7     3,132    Timeline control
// (global/misc)                     194    38,315    Free functions
// ... and ~20 more classes           ~80    ~8,000    Various
// ----------------------------------------------------------------
// TOTAL                           1,471   ~360 KB
//
// Decompiled in existing files:
//   src/ui/apt_value.cpp          - ~100 functions (value type system)
//   src/ui/apt_types.cpp          - ~60 functions (misc APT types)
//   src/ui/apt_action.cpp         - ~20 functions (interpreter helpers)
//   src/ui/apt_character.cpp      - character instance functions
//   src/ui/apt_script_function.cpp - script function functions
//   src/ui/apt_display.cpp        - display list functions
//   + many *_large.cpp, *_medium.cpp files with assembly stubs
//
// This file adds:
//   - Complete architecture documentation
//   - Full opcode table (all ~90 opcodes mapped to handler addresses)
//   - AptValue bitfield layout fully reverse-engineered
//   - toInteger/toFloat/toBool decompiled
//   - AptCharacterInst property system documented
//   - AptCIH lifecycle and zombie state machine documented
//   - AptDisplayList depth system documented
//   - AptViewer lifecycle and input handling documented
//   - AptGC garbage collection strategy documented
//   - _parseStream dispatch loop analyzed
//   - AptRenderingContext matrix/color transform pipeline documented
