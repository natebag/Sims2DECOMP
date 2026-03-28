#ifndef APT_ACTION_H
#define APT_ACTION_H

#include "types.h"
#include "ui/apt_value.h"

// Forward declarations
class AptConstFile;
struct AptActionSetup;
struct AptInitParmsT;

// ============================================================================
// AptActionInterpreter - ActionScript bytecode interpreter
// ============================================================================
class AptActionInterpreter {
public:
    struct LocalContextT {
        u32 m_streamPos;     // 0x00 - current stream position
        u32 m_stack;         // 0x04 - stack pointer
        u32 m_scope;         // 0x08 - scope chain
        u32 m_pad0C;         // 0x0C
        u32 m_pad10;         // 0x10
        u32 m_returnFlag;    // 0x14 - set to 1 for return
    };

    // Offset 0x34: dictionary data
    u8 m_pad[0x34];
    u32 m_dictCount;     // 0x34
    u32 m_dictSize;      // 0x38

    void initialize(AptInitParmsT& parms);
    void shutdown();

    void _parseStream(u8* stream, u8* end, AptConstFile* constFile, int* offset);

    // Stream resolution
    void unresolveStream(u8* stream, u8* end, int* offset);
    void resolveStream(u8* stream, u8* end, AptConstFile* constFile, int* offset);

    // Execution preparation
    void PrepareForExecution(char* name);
    void PrepareForExecution(AptActionSetup* setup);

    // Variable loading
    void loadVariables(AptValue* context, AptValue* scope, EAStringC* url);

    // Variable/object access
    void setVariable(AptValue* context, AptValue* scope, EAStringC* name, AptValue* value, int a, int b, int c);
    void getObject(AptValue* context, AptValue* scope, EAStringC* name);
    void getContext(AptValue* context, AptValue* scope, EAStringC* name, AptValue** out, EAStringC& outName);
    void getContext(AptValue* context, AptValue* scope, EAStringC* name, AptValue** out, char* outName);

    // Method callbacks
    static AptValue* cbCallMethod_ASSetPropFlags(AptValue* thisObj, int argc);
    static AptValue* cbCallMethod_setInterval(AptValue* thisObj, int argc);
    static AptValue* cbCallMethod_clearInterval(AptValue* thisObj, int argc);
    static AptValue* cbCallMethod_hitTest(AptCIH* thisObj, int argc);
    static AptValue* cbCallMethod_isNaN(AptValue* thisObj, int argc);
    static AptValue* cbCallMethod_unescape(AptValue* thisObj, int argc);
    static AptValue* cbCallMethod_escape(AptValue* thisObj, int argc);

    // URL operations
    void urlDecode(char* url, EAStringC& key, EAStringC& val);

    // Enumerate support
    void _doEnumerate(AptValue* stack, AptValue* scope);

    // ActionScript bytecode function handlers (static function table entries)
    static void _FunctionAptActionEnd(AptActionInterpreter* interp, LocalContextT* ctx);
    static void _FunctionAptActionToggleQuality(AptActionInterpreter* interp, LocalContextT* ctx);
    static void _FunctionAptActionStopSounds(AptActionInterpreter* interp, LocalContextT* ctx);
    static void _FunctionAptActionStringLessThan(AptActionInterpreter* interp, LocalContextT* ctx);
    static void _FunctionAptActionMBLength(AptActionInterpreter* interp, LocalContextT* ctx);
    static void _FunctionAptActionCharToAscii(AptActionInterpreter* interp, LocalContextT* ctx);
    static void _FunctionAptActionMBSubString(AptActionInterpreter* interp, LocalContextT* ctx);
    static void _FunctionAptActionMBCharToAscii(AptActionInterpreter* interp, LocalContextT* ctx);
    static void _FunctionAptActionMBAsciiToChar(AptActionInterpreter* interp, LocalContextT* ctx);
    static void _FunctionAptActionReturn(AptActionInterpreter* interp, LocalContextT* ctx);
    static void _FunctionAptActionEnumerate(AptActionInterpreter* interp, LocalContextT* ctx);
    static void _FunctionAptActionEnumerate2(AptActionInterpreter* interp, LocalContextT* ctx);
    static void _FunctionAptActionBitURShift(AptActionInterpreter* interp, LocalContextT* ctx);
    static void _FunctionAptActionDefineDictionary(AptActionInterpreter* interp, LocalContextT* ctx);
    static void _FunctionAptActionWaitForFrame(AptActionInterpreter* interp, LocalContextT* ctx);
};

// AptScriptFunctionBase
class AptScriptFunctionBase {
public:
    static void PushStaticData();
};

#endif // APT_ACTION_H
