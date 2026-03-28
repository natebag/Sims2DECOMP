/**
 * catalogresource.cpp - Catalog/buy mode resource management
 *
 * Decompiled from catalogresource.obj in u2_ngc_release_dvd
 * Original source: c:\BuildAgent\cm3-build22-NGC\CMBuild\
 *
 * Manages catalog data for objects in buy mode. Uses a sorted array
 * of CatalogData with binary search (FindRes<CatalogData>) for lookups.
 *
 * NOTE: Original was compiled with SN Systems ProDG for GameCube.
 * Functions returning StringHandle use SN's struct-return ABI where
 * r3 = hidden return pointer, r4 = this. GCC uses a different ABI
 * for struct returns, so these are NON_MATCHING.
 */

#include "objects/catalogresource.h"

// External functions
extern void* __builtin_new(u32 size);
extern void __builtin_delete(void* ptr);

// Static default string handle (r13-relative, ZERO_AD)
// In original: ZERO_AD.753 at 0x804FF968
static u32 ZERO_AD = 0;

// CatalogResourceImpl::pDefault
CatalogData* CatalogResourceImpl::pDefault = 0;

// ============================================================================
// CatalogResource static functions
// ============================================================================

// 0x800B1C44 | 0x44 bytes | NON_MATCHING
// Allocates 0x10 bytes, sets vtable to CatalogResourceImpl,
// initializes m_name/m_description/m_shortName to ZERO_AD pointer
// SN Systems: uses mr r11,r3 pattern; GCC uses r3 directly
CatalogResource* CatalogResource::CreateInstance(void) {
    CatalogResourceImpl* impl = new CatalogResourceImpl();
    return impl;
}

// 0x800B1C88 | 0x40 bytes
// SafeDelete pattern: if non-null, read vtable, get destructor offset/ptr, call with r4=3
void CatalogResource::DestroyInstance(CatalogResource* instance) {
    if (instance != 0) {
        delete instance;
    }
}

// ============================================================================
// CatalogResourceImpl
// ============================================================================

// 0x800B1D40 | 0x24 bytes | NON_MATCHING
// Sets vtable, initializes all three string handles to ZERO_AD
// SN Systems: lis r9,vtable_hi; mr r11,r3; addi r0,r13,ZERO_AD_off;
//             addi r9,vtable_lo; stw r9,0(r11); stw r0,12(r11);
//             stw r0,4(r11); stw r0,8(r11); blr
CatalogResourceImpl::CatalogResourceImpl(void) {
    m_name = ZERO_AD;
    m_description = ZERO_AD;
    m_shortName = ZERO_AD;
}

// 0x800B1D64 | 0x10 bytes | NON_MATCHING
// SN struct-return ABI: r3=return ptr, r4=this
// Loads this->m_name (offset +4 from r4), stores to return ptr (r3)
StringHandle CatalogResourceImpl::GetName(void) {
    StringHandle h;
    h.m_handle = m_name;
    return h;
}

// 0x800B1D74 | 0x10 bytes | NON_MATCHING
// Same pattern, loads this->m_description (offset +8)
StringHandle CatalogResourceImpl::GetDescription(void) {
    StringHandle h;
    h.m_handle = m_description;
    return h;
}

// 0x800B1D84 | 0x10 bytes | NON_MATCHING
// Same pattern, loads this->m_shortName (offset +12)
StringHandle CatalogResourceImpl::GetShortName(void) {
    StringHandle h;
    h.m_handle = m_shortName;
    return h;
}

// 0x800B1CC8 | 0x78 bytes
// Loads catalog data from ObjSelector. Finds CatalogData by ID using binary search.
// If found, copies name/description/shortName handles from the CatalogData entry.
// Returns 0 on success, -1 on failure (item not found).
int CatalogResourceImpl::Load(ObjSelector* selector, short id, bool flag) {
    // Get the catalog data array from the ObjSelector
    // The array is accessed via selector->field_54->field_1C
    // Binary search for the entry matching 'id'
    CatalogData* dataArray = (CatalogData*)(*(u32*)((u8*)selector + 0x54));
    CatalogData* begin = (CatalogData*)(*(u32*)((u8*)dataArray + 0x1C));
    CatalogData* end = begin;
    if (begin != 0) {
        int count = *(int*)((u8*)begin - 4);
        end = begin + count;
    }
    CatalogData* found = FindRes_CatalogData(begin, end, (int)id);
    if (found == 0) {
        return -1;
    }
    m_name = found->m_name;
    m_description = found->m_description;
    m_shortName = found->m_shortName;
    return 0;
}

// 0x803A2E14 | 0x34 bytes | NON_MATCHING
// SN destructor ABI: sets vtable to CatalogResource base (0x8045EA80),
// tests r4 & 1, conditionally calls operator delete
CatalogResourceImpl::~CatalogResourceImpl() {
}

// 0x803A2E48 | 0x34 bytes | NON_MATCHING
// SN destructor ABI: sets vtable to CatalogResource base (0x8045EA80),
// tests r4 & 1, conditionally calls operator delete
CatalogResource::~CatalogResource() {
}

// ============================================================================
// FindRes<CatalogData> - Binary search template instantiation
// ============================================================================

// 0x803A2DB4 | 0x60 bytes
// Binary search on a sorted CatalogData array by m_id field
// Each CatalogData is 16 bytes (0x10), uses srawi r0,4 to get count
// Uses iterative binary search: compares middle element's m_id with key
CatalogData* FindRes_CatalogData(CatalogData* begin, CatalogData* end, int key) {
    while (true) {
        int count = end - begin;
        if (count <= 0) {
            return 0;
        }
        if (count == 1) {
            if (begin->m_id == key) {
                return begin;
            }
            return 0;
        }
        int mid = count / 2;
        CatalogData* pivot = begin + mid;
        if (pivot->m_id == key) {
            return pivot;
        }
        if (key > pivot->m_id) {
            begin = pivot + 1;
        } else {
            end = pivot;
        }
    }
}
