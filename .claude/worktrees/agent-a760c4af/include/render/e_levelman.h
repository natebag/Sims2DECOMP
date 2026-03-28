#ifndef E_LEVELMAN_H
#define E_LEVELMAN_H

#include "types.h"
#include "render/e_instance.h"
#include "core/e_vec3.h"

// Forward declarations
class EStream;
class EFile;
class EMat4;
class EILight;
class EBoundSphere;
class ELevelDrawData;
class E3DWindow;
class EOrderTableData;
struct LevelLightingEntry;
struct LevelLighting;
struct levelraininfo;

// Enums
enum EWallUpDownStateType {
    WALL_STATE_DEFAULT = 0
};

// TNodeList template (simple linked list)
template<typename T>
class TNodeList {
public:
    T m_head; // first node
};

// HTIteratorPtrType (hash table iterator)
struct HTIteratorPtrType {
    void* data;
};

// ----- ERLevel -----
// Large struct, this + 0x30000+ offsets
// The offsets use addis r3,r3,3 => offset 0x30000 relative to this
class ERLevel : public EStorable {
public:
    virtual void SafeDelete();
    virtual const ETypeInfo* GetTypeInfo() const;
    virtual const char* GetTypeName() const;
    virtual u32 GetTypeKey() const;
    virtual u16 GetTypeVersion() const;
    virtual void Read(EStream& stream);
    virtual void Write(EStream& stream);
    virtual void Load(EFile& file);

    // ERLevel methods
    void AddInstancesFromList(TNodeList<EInstance*>& list);
    void InsertInstance(EInstance* inst, EInstance* after);
    int IsInstanceListKindaFull();
    void ValidateInstanceInLevel(EInstance* inst);
    void GroupWallInstances();
    void AddInstanceToIdMap(EInstance* inst);
    EInstance* FindInstance(char* name);
    EInstance* FindInstance(unsigned int id);
    int FindFirstInstance(unsigned int id, EInstance** out);
    int FindNextInstance(HTIteratorPtrType* iter, EInstance** out);
    void UpdateLightGrid();
    void UpdatePerRoomData();
    void DrawDOFForegroundObjects();
    void InitializeLightingGrid();
    void OutsideLightsInit(float val, LevelLightingEntry& entry);
    void InsertHouseObject(EOrderTableData* data);
    void RefreshRoomAssignment(EInstance* inst);
    void ClearWallIndexSaves();
    int GetNumInstances();
    EInstance* GetInstance(int index);
    int GetNumVisibleInstances();
    EInstance* GetVisInstance(int index);
    void SetDrawWallShadowsFunc(void (*fn)(TNodeList<EInstance*>&, EVec3&, ELevelDrawData&));
    void UpdateRooms(int count);
    void SetIdMapTableSize(int size);

    // Accessors
    EILight* GetSun();
    EILight* GetSunAmbient();
    void SetDayNightLightTable(LevelLighting* table);
    void SetRainInfoTable(levelraininfo* table);
    void SetSunYawOffset(float offset);
    void SetWallFadeState(EWallUpDownStateType state);
    EWallUpDownStateType WallFadeState();
    int IsDrawingOrderTable();
    int IsInUse();
    int GetRoomCount();
    void SetRainBlend(float blend);
    u32 GetStorableVersion() const;

    static ERLevel* New();
    static void Construct(ERLevel* level);
    static void Destruct(ERLevel* level);
    static const ETypeInfo* GetTypeInfoStatic();
    static u16 GetReadVersion();
    static void RegisterType(u16 version);
    EStorable* CreateCopy() const;

    void* operator new(unsigned int size);
    void* operator new(unsigned int size, void* ptr);
    void operator delete(void* ptr);

    static ETypeInfo m_typeInfo;
};

EStream& operator<<(EStream& stream, ERLevel* level);
EStream& operator>>(EStream& stream, ERLevel*& level);
EFile& operator>>(EFile& file, ERLevel*& level);

// ----- ELevelManager -----
class ELevelManager {
public:
    static void AllocateAndLoadResource(EFile* file, unsigned int a, unsigned int b);
    static void AddRef(unsigned int id, EFile* file, int count);
    static void AddRef(char* name, EFile* file, int count);
};

// ----- Emitter (for Emitter::SetSortPos) -----
namespace Emitter {
    void SetSortPos(EVec3& pos);
}

// ----- ENodeList -----
struct ENodeListEntry {
    void* m_data;        // 0x00
    ENodeListEntry* m_prev; // 0x04
    ENodeListEntry* m_next; // 0x08
};

class ENodeList {
public:
    ENodeListEntry* m_head; // 0x00
    ENodeListEntry* m_tail; // 0x04

    int GetSize() const;
    int GetSizeRev() const;
    ENodeListEntry* Search(unsigned int key) const;
};

#endif // E_LEVELMAN_H
