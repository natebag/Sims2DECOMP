#ifndef UICORE_H
#define UICORE_H

#include "types.h"

// Forward declarations
class ERC;
class ERShader;
class AptViewer;

// ECTRL_CMD is an enum/int used by the controller system
typedef int ECTRL_CMD;

// ============================================================================
// CBFunctor types - minimal declarations for matching
// ============================================================================

// CBFunctorBase - base class for all callback functors
// The thunk pointer at offset 0x00 is the function pointer used for dispatch
class CBFunctorBase {
public:
    void* m_thunk;   // 0x00 - thunk function pointer
    u8 _pad[0x0C];   // 0x04 - member data
};

// CBFunctor1wRet<P1, Ret> - functor with 1 param and return
template<typename P1, typename Ret>
class CBFunctor1wRet : public CBFunctorBase {};

// CBFunctor2<P1, P2> - functor with 2 params, no return
template<typename P1, typename P2>
class CBFunctor2 : public CBFunctorBase {};

// CBFunctor1<P1> - functor with 1 param, no return
template<typename P1>
class CBFunctor1 : public CBFunctorBase {};

// CBFunctor0 - functor with no params, no return
class CBFunctor0 : public CBFunctorBase {};

// ============================================================================
// UIObjectBase - base class for UI objects
// ============================================================================
class UIObjectBase {
public:
    void pushAptButtonFilter(int player, char* name);
    void popAptButtonFilter(int player, unsigned int id);
    void addCmdToAptButtonFilter(int player, unsigned int id, ECTRL_CMD cmd);
    void removeCmdFromAptButtonFilter(int player, unsigned int id, ECTRL_CMD cmd);
    void pushAptButtonFilterALL(int player, char* name);
    void makeNumberString(int number, unsigned short* outStr);
    void makeMoneyString(int amount, unsigned short* outStr, bool addSign);
    static void doUIQDStringSubstitution(unsigned short* str);
    void UIRouter_SetVariable(char* name, char* value);
    void UIRouter_FlowGoto(char* target);
    void AptViewer_CallFunction(char* funcName, char* param1, char* param2, int numArgs, char** args);
};

// ============================================================================
// GetVariableCommandTable - singleton command table for getVariable callbacks
// Maps string names to CBFunctor1wRet<char*, char*> callbacks
// ============================================================================
class GetVariableCommandTable {
public:
    struct GetVariableCommandTableRecord;

    // Linked list head pointer
    GetVariableCommandTableRecord* m_head; // 0x00
    u8 _pad[0x0C];                         // 0x04

    GetVariableCommandTable();
    ~GetVariableCommandTable();

    void AddRecord(char* name, CBFunctor1wRet<char*, char*>& functor);
    void RemoveRecord(GetVariableCommandTableRecord* record);
    void InstallCommand(char* name, CBFunctor1wRet<char*, char*>& functor);
    void UnInstallCommand(char* name);
    void UnInstallAllCommands(CBFunctor1wRet<char*, char*>& functor);
    int ContainsCommand(char* name);
    char* ExecuteCommand(char* name, char* param);

    static GetVariableCommandTable* Instance();
    static void Shutdown();

    static GetVariableCommandTable* s_pInstance;
};

// ============================================================================
// SetVariableCommandTable - singleton command table for setVariable callbacks
// Maps string names to CBFunctor2<char*, char*> callbacks
// ============================================================================
class SetVariableCommandTable {
public:
    struct SetVariableCommandTableRecord;

    SetVariableCommandTableRecord* m_head; // 0x00
    u8 _pad[0x0C];                         // 0x04

    SetVariableCommandTable();
    ~SetVariableCommandTable();

    void AddRecord(char* name, CBFunctor2<char*, char*>& functor);
    void RemoveRecord(SetVariableCommandTableRecord* record);
    void InstallCommand(char* name, CBFunctor2<char*, char*>& functor);
    void UnInstallCommand(char* name);
    void UnInstallAllCommands(CBFunctor2<char*, char*>& functor);
    int ContainsCommand(char* name);
    void ExecuteCommand(char* name, char* param1, char* param2);

    static SetVariableCommandTable* Instance();
    static void Shutdown();

    static SetVariableCommandTable* s_pInstance;
};

// ============================================================================
// GetLocalizableCommandTable - singleton command table for localizable string callbacks
// Maps string names to CBFunctor1wRet<char*, wchar_t*> callbacks
// Note: wchar_t is unsigned short with -fshort-wchar
// ============================================================================
class GetLocalizableCommandTable {
public:
    struct GetLocalizableCommandTableRecord;

    GetLocalizableCommandTableRecord* m_head; // 0x00
    u8 _pad[0x0C];                             // 0x04

    GetLocalizableCommandTable();
    ~GetLocalizableCommandTable();

    void AddRecord(char* name, CBFunctor1wRet<char*, wchar_t*>& functor);
    void RemoveRecord(GetLocalizableCommandTableRecord* record);
    void InstallCommand(char* name, CBFunctor1wRet<char*, wchar_t*>& functor);
    void UnInstallCommand(char* name);
    void UnInstallAllCommands(CBFunctor1wRet<char*, wchar_t*>& functor);
    int ContainsCommand(char* name);
    wchar_t* ExecuteCommand(char* name, char* param);

    static GetLocalizableCommandTable* Instance();
    static void Shutdown();

    static GetLocalizableCommandTable* s_pInstance;
};

// ============================================================================
// UI2D - singleton managing 2D UI shader entries
// ============================================================================
class UI2D {
public:
    struct UI2DRecord;

    u8 _pad[0x10]; // 0x00 - internal data (linked list, etc.)

    UI2D();
    ~UI2D();

    void AddEntry(char* name, unsigned int hashId, ERShader* shader, char* group, int flags);
    void RemoveEntry(UI2DRecord* record);
    void InstallEntry(char* name, unsigned int hashId, char* group, int flags);
    void InstallEntry(char* name, ERShader* shader, char* group, int flags);
    UI2DRecord* FindEntry(char* name);
    void UnInstallEntry(char* name);
    void UnInstallAllEntries(char* group);
    int ContainsEntry(char* name);
    ERShader* GetShader(char* name);

    static UI2D* Instance();
    static void Shutdown();

    static UI2D* s_pInstance;
};

// ============================================================================
// UI3D - singleton managing 3D UI display objects
// ============================================================================
class UI3D {
public:
    struct UI3DRecord {
        u8 _pad[0x1C];
        void* m_displayObject; // 0x1C
    };

    u8 _pad[0x20]; // 0x00 - internal data

    UI3D();
    ~UI3D();

    void AddEntry(char* name, unsigned int param1, unsigned int param2, unsigned int param3, int param4, char* group);
    void RemoveEntry(UI3DRecord* record);
    void InstallEntry(char* name, unsigned int param1, unsigned int param2, unsigned int param3, char* group, int flags);
    UI3DRecord* FindEntry(char* name);
    void UnInstallEntry(char* name);
    void UnInstallAllEntries(char* group);
    int ContainsEntry(char* name);
    void Update3D();
    void* GetDisplayObject(char* name);

    static UI3D* Instance();
    static void Shutdown();

    static UI3D* s_pInstance;
};

// ============================================================================
// FlowGotoTarget - UI flow state management
// ============================================================================
class FlowGotoTarget {
public:
    enum eFlashState {};

    u8 _pad[0x84];
    int m_stateRequest;       // 0x84
    int m_pendingState;       // 0x88

    FlowGotoTarget();
    ~FlowGotoTarget();

    void SetVariable(char* name, char* value);
    char* GetVariable(char* name);
    int IsStateRequestPending();
    int GetStateRequest();
    void SetPendingStateCurrent();
};

// ============================================================================
// UIButtonImages - singleton managing button image shaders
// Note: SN Systems places vtable at offset 0xB0, not offset 0x00
// We do NOT use virtual here since GCC would put vtable at 0x00
// ============================================================================
class UIButtonImages {
public:
    u8 _pad[0x70];
    float m_buttonMinSizes[10]; // 0x70 - array of min sizes per button ID
    u8 _pad2[0x18];
    void* m_vtable;             // 0xB0 - vtable pointer (SN Systems layout)
    u8 _pad3[0x04];

    UIButtonImages();
    ~UIButtonImages();

    static void Startup();
    static void Shutdown();
    void DefineIDs();
    void AddRefAll();
    void DelRefAll();
    ERShader* GetButtonShader(int buttonId);
    static float GetButtonMinSize(int buttonId);
    void LocalizeXBoxImages();

    static UIButtonImages* instance;
};

// ============================================================================
// WidgetScreenFormat - widget screen layout management
// ============================================================================
class WidgetScreenFormat {
public:
    enum IterationType {};

    int m_field00;    // 0x00
    int m_field04;    // 0x04
    u8 _pad[0x08];
    int m_field10;    // 0x10
    u8 _pad2[0x08];
    int m_field1c;    // 0x1C

    WidgetScreenFormat();
    ~WidgetScreenFormat();

    void LaunchWidgetScreenLayout(char** layout, int numItems, int flags);
    void IterateScreenLayout(char** layout, IterationType type);
    void IterateTags(IterationType type);
    void GetNextTag(IterationType type);
    int IsValidTag(char* tag);
    int IsDataValid(char* data);
    int IsPlayerSpecificTag(char* tag);
};

// ============================================================================
// UIQDTarget - QD substitution strings (external function reference)
// ============================================================================
extern void UIQDTarget_UIQDSubstitutionStrings(unsigned short* str);

#endif // UICORE_H
