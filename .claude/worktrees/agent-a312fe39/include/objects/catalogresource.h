#ifndef CATALOGRESOURCE_H
#define CATALOGRESOURCE_H

#include "types.h"

// Forward declarations
class ObjSelector;

// ============================================================================
// CatalogData - Data element in the catalog resource array
// Size: 0x10
// Used by FindRes<CatalogData> binary search
// ============================================================================
struct CatalogData {
    int m_id;           // +0x00 - sort key for binary search
    u32 m_name;         // +0x04 - string handle/pointer for name
    u32 m_description;  // +0x08 - string handle/pointer for description
    u32 m_shortName;    // +0x0C - string handle/pointer for short name
};

// ============================================================================
// StringHandle - Opaque handle returned by GetName/GetDescription/GetShortName
// Size: 0x04 (single pointer/handle)
// SN Systems ABI: returned via hidden first parameter (struct return)
// ============================================================================
struct StringHandle {
    u32 m_handle;
};

// ============================================================================
// CatalogResource - Abstract base class for catalog/buy mode resources
// Size: 0x04 (vtable only)
// Vtable at 0x8045EA80
// Object file: catalogresource.obj
// ============================================================================
class CatalogResource {
public:
    virtual ~CatalogResource();

    // Pure virtual functions
    virtual int Load(ObjSelector* selector, short id, bool flag) = 0;
    virtual StringHandle GetName(void) = 0;
    virtual StringHandle GetDescription(void) = 0;
    virtual StringHandle GetShortName(void) = 0;

    // Static factory functions
    static CatalogResource* CreateInstance(void);
    static void DestroyInstance(CatalogResource* instance);
};

// ============================================================================
// CatalogResourceImpl - Concrete implementation of CatalogResource
// Size: 0x10
// Vtable at 0x8045EA48
//
// Layout:
//   +0x00: vtable pointer
//   +0x04: u32 m_name       (string handle)
//   +0x08: u32 m_description (string handle)
//   +0x0C: u32 m_shortName  (string handle)
// ============================================================================
class CatalogResourceImpl : public CatalogResource {
public:
    u32 m_name;         // +0x04
    u32 m_description;  // +0x08
    u32 m_shortName;    // +0x0C

    CatalogResourceImpl(void);
    virtual ~CatalogResourceImpl();

    virtual int Load(ObjSelector* selector, short id, bool flag);
    virtual StringHandle GetName(void);
    virtual StringHandle GetDescription(void);
    virtual StringHandle GetShortName(void);

    // Static data
    static CatalogData* pDefault;
};

// ============================================================================
// Template function: binary search in sorted CatalogData array
// ============================================================================
CatalogData* FindRes_CatalogData(CatalogData* begin, CatalogData* end, int key);

#endif // CATALOGRESOURCE_H
