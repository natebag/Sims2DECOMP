#ifndef INTERACTION_H
#define INTERACTION_H

#include "types.h"

// Forward declarations
class cXPerson;
class cXObject;
class BString2;
class ReconBuffer;
class EActionIcon;
class StringBuffer;

// ============================================================================
// Interaction - Represents a sim's queued action/interaction
//
// Object file: interaction.obj
// Vtable at 0x8045F718 (size 0x28)
//
// Layout (0x40 bytes total):
//   +0x00: vtable pointer
//   +0x04: m_type (int)
//   +0x08: m_pPerson (cXPerson*)
//   +0x0C: m_pStackObject (cXObject*)
//   +0x10: m_pIconObject (cXObject*)
//   +0x14: m_treeTabEntryIndex (int)
//   +0x18: m_stackVars[4] (short[4])
//   +0x20: m_localVarsCount (int)
//   +0x24: m_pLocalVars (short*)
//   +0x28: m_priority (int)
//   +0x2C: m_treeID (short) + padding
//   +0x30: m_attenuation (float)
//   +0x34: m_name (BString2 - 4 bytes inline)
//   +0x38: m_uniqueID (int)
//   +0x3C: m_flags (int - bitfield)
// ============================================================================
class Interaction {
public:
    // TextColor enum - stored in bits 12-14 of m_flags
    enum tColor {
        COLOR_0 = 0,
        COLOR_1 = 1,
        COLOR_2 = 2,
        COLOR_3 = 3,
        COLOR_4 = 4,
        COLOR_5 = 5,
        COLOR_6 = 6,
        COLOR_7 = 7
    };

    // Flag bit positions in m_flags
    enum {
        FLAG_AUTO_FIRST_SELECT = 0x0001,  // bit 0
        FLAG_CONTINUATION      = 0x0002,  // bit 1
        FLAG_CHECKED           = 0x0004,  // bit 2
        FLAG_AVAILABLE         = 0x0008,  // bit 3
        FLAG_HIDDEN            = 0x0010,  // bit 4
        FLAG_PUSH_TO_HEAD      = 0x0020,  // bit 5
        FLAG_CARRY_NAME_OVER   = 0x0040,  // bit 6
        FLAG_NAME_CHANGED      = 0x0080,  // bit 7
        FLAG_CANCELLED         = 0x0100,  // bit 8
        FLAG_DEBUG_OVERRIDE    = 0x0200,  // bit 9
        FLAG_MUST_RUN          = 0x0400,  // bit 10
        FLAG_DISABLED          = 0x0800,  // bit 11
        FLAG_TEXT_COLOR_MASK   = 0x7000,  // bits 12-14
        FLAG_TEXT_COLOR_SHIFT  = 12,
        FLAG_RUN_AS_SUB        = 0x8000,  // bit 15
    };

    // Constructors / Destructor
    Interaction();
    Interaction(Interaction& other);
    Interaction(cXPerson* person, cXObject* obj, int type);
    Interaction(cXPerson* person, cXPerson* other);
    Interaction(cXPerson* person, cXObject* obj, int type, int param);
    virtual ~Interaction();

    // Operators
    Interaction& operator=(Interaction& other);

    // Virtuals (from vtable)
    virtual int GetCTilePt() const;          // vtable+0x14
    virtual int SetShader(EActionIcon* icon) const; // vtable+0x1C

    // Stack/Local variables
    void SetStackVars(short* vars);
    void SetLocalVars(short* vars, int count);
    short* GetStackVars();
    short* GetLocalVars();
    int GetLocalVarsCount();

    // Name
    void SetName(BString2& name);
    void SetName(int param1, int param2);
    int GetName() const;

    // Entry
    int GetEntry() const;

    // Unique ID
    void SetUniqueID();
    bool HasID() const;
    int GetID() const;
    void SetID(int id);

    // Type
    int GetType();

    // Objects
    cXObject* GetStackObject() const;
    cXPerson* GetPerson() const;
    cXObject* GetIconObject() const;
    void SetIconObject(cXObject* obj);

    // Tree
    short GetTreeID() const;
    int GetTreeTabEntryIndex() const;

    // Priority
    int GetPriority() const;
    void SetPriority(int priority);

    // Attenuation
    float GetAttenuation() const;

    // Text color
    tColor GetTextColor() const;
    void SetTextColor(tColor color);

    // Flag accessors
    bool GetAutoFirstSelect() const;
    void SetAutoFirstSelect(bool val);
    bool GetContinuation() const;
    void SetContinuation(bool val);
    bool GetChecked() const;
    void SetChecked(bool val);
    bool GetAvailable() const;
    void SetAvailable(bool val);
    bool GetHidden() const;
    void SetHidden(bool val);
    bool GetPushToHead() const;
    void SetPushToHead(bool val);
    bool GetCarryNameOver() const;
    void SetCarryNameOver(bool val);
    bool GetNameChanged() const;
    void SetNameChanged(bool val);
    bool GetCancelled() const;
    void SetCancelled(bool val);
    bool GetDebugOverride() const;
    void SetDebugOverride(bool val);
    bool GetMustRun() const;
    void SetMustRun(bool val);
    bool GetDisabled() const;
    void SetDisabled(bool val);
    bool GetRunAsSub() const;
    void SetRunAsSub(bool val);
    int GetFlags() const;
    void SetFlags(int flags);

    // Serialization
    void DoStream(ReconBuffer* buf, int dir);

    // Static
    static int sLastUniqueID;

private:
    int m_type;                 // +0x04
    cXPerson* m_pPerson;        // +0x08
    cXObject* m_pStackObject;   // +0x0C
    cXObject* m_pIconObject;    // +0x10
    int m_treeTabEntryIndex;    // +0x14
    short m_stackVars[4];       // +0x18
    int m_localVarsCount;       // +0x20
    short* m_pLocalVars;        // +0x24
    int m_priority;             // +0x28
    short m_treeID;             // +0x2C
    short m_pad2E;              // +0x2E
    float m_attenuation;        // +0x30
    char m_name[4];             // +0x34 (BString2 inline)
    int m_uniqueID;             // +0x38
    int m_flags;                // +0x3C
};

#endif // INTERACTION_H
