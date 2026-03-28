#ifndef PASSIVEINFLUENCEMAP_H
#define PASSIVEINFLUENCEMAP_H

#include "types.h"

// Forward declarations
class cXObject;
class cXPerson;
class ReconBuffer;
struct EVec3;

// ============================================================================
// PassiveInfluenceItem - Base class for passive influence items
// From: passiveinfluencemap.obj
// Layout: { void* vtable(0x00); cXObject* m_object(0x04); EVec3 m_tileVector(0x08) }
// ============================================================================
class PassiveInfluenceItem {
public:
    virtual ~PassiveInfluenceItem(void);
    virtual cXObject* GetObject(void) = 0;
    virtual int GetType(void) = 0;
    virtual EVec3* GetTileVector(void) = 0;

protected:
    cXObject* m_object;  // 0x04
    // EVec3 m_tileVector at 0x08 (in subclasses)
};

// ============================================================================
// PassiveInfluencePerson - Person influence item (type 0)
// ============================================================================
class PassiveInfluencePerson : public PassiveInfluenceItem {
public:
    virtual ~PassiveInfluencePerson(void);
    virtual cXObject* GetObject(void);   // returns m_object at +0x04
    virtual int GetType(void);           // returns 0
    virtual EVec3* GetTileVector(void);  // returns this + 0x08
};

// ============================================================================
// PassiveInfluenceObject - Object influence item (type 1)
// ============================================================================
class PassiveInfluenceObject : public PassiveInfluenceItem {
public:
    virtual ~PassiveInfluenceObject(void);
    virtual cXObject* GetObject(void);   // returns m_object at +0x04
    virtual int GetType(void);           // returns 1
    virtual EVec3* GetTileVector(void);  // returns this + 0x08
};

// ============================================================================
// PassiveInfluenceTarget - Target influence item (type 2)
// ============================================================================
class PassiveInfluenceTarget : public PassiveInfluenceItem {
public:
    PassiveInfluenceTarget(void);
    virtual ~PassiveInfluenceTarget(void);
    virtual cXObject* GetObject(void);   // returns m_object at +0x04
    virtual int GetType(void);           // returns 2
    virtual EVec3* GetTileVector(void);  // returns this + 0x08
};

// ============================================================================
// PassiveInfluenceMap - Grid-based passive influence map
// From: passiveinfluencemap.obj
// ============================================================================
class PassiveInfluenceMap {
public:
    PassiveInfluenceMap(int width, int height);
    ~PassiveInfluenceMap(void);

    void EmptyMap(void);
    void AddItemToMap(PassiveInfluenceItem* item);
    void RemoveItemFromMap(PassiveInfluenceItem* item);
    void NotifySimulator(cXPerson* person, int x, int y);
    BOOL ValidateMissing(PassiveInfluenceItem* item);
    void CheckObjectInfluence(PassiveInfluenceTarget* target);
    void ApplyInfluence(PassiveInfluenceObject* obj, PassiveInfluenceTarget* target);
    void CalculateAffectedArea(PassiveInfluenceItem* item);
    void CalculateTargetArea(PassiveInfluenceItem* item);
    void* GetListForTile(int x, int y);
    void Validate(void);

    static PassiveInfluenceMap* s_passiveInfluenceMap;
};

// ============================================================================
// PassiveInfluenceSystem - Global passive influence system
// From: passiveinfluencemap.obj
// ============================================================================
class PassiveInfluenceSystem {
public:
    PassiveInfluenceSystem(void);
    ~PassiveInfluenceSystem(void);

    void FlushSystem(void);
    void DoStream(ReconBuffer* buffer, int mode);
    void AddObjectToMap(cXObject* obj, signed char a, signed char b, signed char c, signed char d);
    void RemoveObjectFromMap(cXObject* obj);
    void MoveObjectInWorld(cXObject* obj);
    void CheckObjects(int count);
    void SetInfluenceMotiveDelta(cXObject* obj, unsigned char motive, float delta, short val);
    void ClearInfluenceMotiveDeltas(cXObject* obj);
    void SetSkillNameID(cXObject* obj, void* animRef);
    static void NotifySimulator(cXPerson* person, int x, int y);
};

#endif // PASSIVEINFLUENCEMAP_H
