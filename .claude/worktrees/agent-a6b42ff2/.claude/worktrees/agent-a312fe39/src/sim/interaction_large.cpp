// interaction_large.cpp - Large functions (257-1024 bytes) from interaction.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\interaction.obj
//
// 3 large functions decompiled from interaction.obj
//
// NON_MATCHING causes:
//   - GCC virtual dispatch (bctr vs blrl)
//   - GCC register allocation differences
//   - GCC constructor ABI (stmw vs individual stw)
//   - SDA-relative addressing for static sLastUniqueID

#include "types.h"
#include "stub_classes.h"

// Forward declarations
class Interaction;
class cXPerson;
class cXObject;
class cXObjectImpl;
class ReconBuffer;
class BString2;

// External functions
extern void* operator_new(unsigned int size);
extern void operator_delete(void* ptr);
extern void BString2_ctor(void* str);
extern void BString2_dtor(void* str, int);
extern void BString2_copy(void* dst, void* src);
extern void memcpy(void* dst, const void* src, unsigned int size);

#if 0  // Reference decompilation - not compiled

// ============================================================================
// Interaction::Interaction(cXPerson *, cXPerson *)
// Address: 0x800C12F8 | Size: 636 bytes
// NON_MATCHING - GCC constructor ABI, virtual dispatch chain
//
// Constructs a social interaction between two persons. Gets the target
// person's object impl via virtual dispatch chain, finds the social
// interaction module, then looks up the interaction definition.
// Initializes all fields and copies stack variables from the found entry.
//
// Assembly analysis:
//   - Sets vtable at +0x40 (this is offset from base, vtable at 0x8045F718)
//   - Constructs BString2 at +0x34
//   - Virtual dispatch chain: person->impl->getObject->getTreeTab->findEntry
//   - Sets m_type=1, m_pPerson=person, m_priority=50 (0x32)
//   - Clears FLAG_AUTO_FIRST_SELECT in m_flags
// ============================================================================
Interaction::Interaction(cXPerson* person, cXPerson* other) {
    // Set vtable
    *(void**)((char*)this + 0x40) = (void*)0x8045F718;

    // Construct name BString2 at +0x34
    BString2_ctor((char*)this + 0x34);

    // Get other's object impl through virtual dispatch
    int* vtbl = *(int**)other;
    int* vtbl2 = *(int**)((char*)other + *(short*)((char*)vtbl + 0xE8));
    void* otherImpl = ((void*(*)(void*))*(void**)((char*)vtbl2 + 0xEC))
                       ((char*)other + *(short*)((char*)vtbl + 0xE8));

    // Initialize to default interaction with other person
    void* defaultInit = (void*)0x800C1068;  // Interaction::InitDefault
    ((void(*)(Interaction*, void*))defaultInit)(this, otherImpl);

    // Set fields
    m_type = 1;         // Social interaction type
    m_pPerson = person;
    m_priority = 50;    // Default priority
    m_flags &= ~FLAG_AUTO_FIRST_SELECT;

    // If other person has an object...
    cXObject* stackObj = m_pStackObject;
    if (stackObj != 0) {
        // Get the sim description from other person's impl
        int* implVtbl = *(int**)stackObj;
        void* simDesc = ((void*(*)(void*))*(void**)((char*)implVtbl + 0x360))
                         ((char*)stackObj + *(short*)((char*)implVtbl + 0x35C));
        void* treeTab = (void*)simDesc;

        if (treeTab != 0) {
            // Find social interaction definition
            void* interDef = FindSocialInteraction(treeTab, other);
            if (interDef != 0) {
                // Copy interaction data from definition
                short treeID = *(short*)((char*)interDef + 0x00);
                int priority = *(int*)((char*)interDef + 0x04);
                m_treeID = treeID;
                m_priority = priority;

                // Copy stack vars if present
                short* srcVars = (short*)((char*)interDef + 0x08);
                m_stackVars[0] = srcVars[0];
                m_stackVars[1] = srcVars[1];
                m_stackVars[2] = srcVars[2];
                m_stackVars[3] = srcVars[3];

                // Copy name
                BString2_copy((char*)this + 0x34, (char*)interDef + 0x10);

                // Set flags from definition
                int defFlags = *(int*)((char*)interDef + 0x14);
                m_flags |= defFlags;
            }
        }
    }

    // Generate unique ID
    m_uniqueID = ++sLastUniqueID;
}

// ============================================================================
// Interaction::Interaction(cXPerson *, cXObject *, int, int)
// Address: 0x800C1574 | Size: 424 bytes
// NON_MATCHING - GCC constructor ABI, virtual dispatch
//
// Constructs an object interaction. Similar to the person-person constructor
// but targets an object instead. Looks up the tree tab entry by the given
// type and parameter indices.
//
// Assembly analysis:
//   - Sets vtable at offset (0x8045F718)
//   - Constructs BString2 at +0x34
//   - Gets object's impl, retrieves tree tab, looks up entry by type+param
//   - Sets m_type, m_pPerson, m_pStackObject
//   - Copies tree ID, priority, stack vars from found entry
// ============================================================================
Interaction::Interaction(cXPerson* person, cXObject* obj, int type, int param) {
    // Set vtable
    *(void**)((char*)this + 0x40) = (void*)0x8045F718;

    // Construct name BString2 at +0x34
    BString2_ctor((char*)this + 0x34);

    // Initialize base fields
    m_type = type;
    m_pPerson = person;
    m_pStackObject = obj;
    m_pIconObject = 0;
    m_treeTabEntryIndex = -1;
    m_stackVars[0] = 0;
    m_stackVars[1] = 0;
    m_stackVars[2] = 0;
    m_stackVars[3] = 0;
    m_localVarsCount = 0;
    m_pLocalVars = 0;
    m_priority = 50;
    m_treeID = -1;
    m_attenuation = 1.0f;
    m_uniqueID = 0;
    m_flags = 0;

    if (obj == 0) {
        return;
    }

    // Get object's tree tab through virtual dispatch
    int* vtbl = *(int**)obj;
    void* impl = ((void*(*)(void*))*(void**)((char*)vtbl + 0x04))((char*)obj);
    if (impl == 0) {
        return;
    }

    // Get tree tab
    int* implVtbl = *(int**)impl;
    void* treeTab = ((void*(*)(void*))*(void**)((char*)implVtbl + 0x88))((char*)impl);
    if (treeTab == 0) {
        return;
    }

    // Look up entry by type and param
    void* entry = FindTreeTabEntry(treeTab, type, param);
    if (entry == 0) {
        return;
    }

    // Copy from entry
    m_treeTabEntryIndex = *(int*)((char*)entry + 0x00);
    m_treeID = *(short*)((char*)entry + 0x04);
    m_priority = *(int*)((char*)entry + 0x08);
    m_attenuation = *(float*)((char*)entry + 0x0C);

    // Copy stack vars
    short* srcVars = (short*)((char*)entry + 0x10);
    m_stackVars[0] = srcVars[0];
    m_stackVars[1] = srcVars[1];
    m_stackVars[2] = srcVars[2];
    m_stackVars[3] = srcVars[3];

    // Copy name
    BString2_copy((char*)this + 0x34, (char*)entry + 0x18);

    // Set flags
    int entryFlags = *(int*)((char*)entry + 0x1C);
    m_flags = entryFlags;

    // Set icon object (may be same as stack object)
    m_pIconObject = obj;

    // Generate unique ID
    m_uniqueID = ++sLastUniqueID;
}

// ============================================================================
// Interaction::DoStream(ReconBuffer *, int)
// Address: 0x800C1A68 | Size: 524 bytes
// NON_MATCHING - GCC register alloc, serialization codegen
//
// Serializes/deserializes all interaction fields to/from a ReconBuffer.
// Handles both read and write directions. Streams the vtable-independent
// data fields, stack vars, local vars (with dynamic allocation on read),
// BString2 name, and flags.
// ============================================================================
void Interaction::DoStream(ReconBuffer* buf, int dir) {
    if (buf == 0) {
        return;
    }

    // Stream basic fields
    ReconBuffer_StreamInt(buf, &m_type);

    // Stream person/object as IDs (not pointers)
    short personID = 0;
    short stackObjID = 0;
    short iconObjID = 0;

    if (dir == 1) {
        // Writing - convert pointers to IDs
        if (m_pPerson != 0) {
            personID = GetObjectID(m_pPerson);
        }
        if (m_pStackObject != 0) {
            stackObjID = GetObjectID(m_pStackObject);
        }
        if (m_pIconObject != 0) {
            iconObjID = GetObjectID(m_pIconObject);
        }
    }

    ReconBuffer_StreamShort(buf, &personID);
    ReconBuffer_StreamShort(buf, &stackObjID);
    ReconBuffer_StreamShort(buf, &iconObjID);

    if (dir == 0) {
        // Reading - convert IDs to pointers
        m_pPerson = (cXPerson*)FindObjectByID(personID);
        m_pStackObject = FindObjectByID(stackObjID);
        m_pIconObject = FindObjectByID(iconObjID);
    }

    // Stream tree tab entry
    ReconBuffer_StreamInt(buf, &m_treeTabEntryIndex);

    // Stream stack vars (4 shorts)
    ReconBuffer_StreamShort(buf, &m_stackVars[0]);
    ReconBuffer_StreamShort(buf, &m_stackVars[1]);
    ReconBuffer_StreamShort(buf, &m_stackVars[2]);
    ReconBuffer_StreamShort(buf, &m_stackVars[3]);

    // Stream local vars
    ReconBuffer_StreamInt(buf, &m_localVarsCount);

    if (dir == 0 && m_localVarsCount > 0) {
        // Reading - allocate local vars
        if (m_pLocalVars != 0) {
            operator_delete(m_pLocalVars);
        }
        m_pLocalVars = (short*)operator_new(m_localVarsCount * sizeof(short));
    }

    for (int i = 0; i < m_localVarsCount; i++) {
        ReconBuffer_StreamShort(buf, &m_pLocalVars[i]);
    }

    // Stream priority
    ReconBuffer_StreamInt(buf, &m_priority);

    // Stream tree ID
    ReconBuffer_StreamShort(buf, &m_treeID);

    // Stream attenuation
    ReconBuffer_StreamFloat(buf, &m_attenuation);

    // Stream name BString2
    ReconBuffer_StreamBString(buf, (char*)this + 0x34);

    // Stream unique ID
    ReconBuffer_StreamInt(buf, &m_uniqueID);

    // Stream flags
    ReconBuffer_StreamInt(buf, &m_flags);
}

#endif // Reference decompilation
