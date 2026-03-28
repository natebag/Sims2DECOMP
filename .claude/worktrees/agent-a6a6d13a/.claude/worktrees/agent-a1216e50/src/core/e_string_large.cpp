// e_string_large.cpp - EString large functions (257-1024 bytes)
// Object file: base_ngc_release_dvd.lib(e_string.obj)
// All NON_MATCHING due to: GCC vs SN Systems codegen differences

#include "core/e_string.h"

// Forward declarations
extern "C" void* EAHeap_Alloc(int size);
extern "C" void EAHeap_Free2(void* ptr);
extern "C" int strcmp(const char*, const char*);
extern "C" int stricmp(const char*, const char*);
extern "C" int strlen(const char*);
extern "C" void memcpy(void*, const void*, u32);

// ============================================================================
// EString::CompareSymbol(char*) const
// Address: 0x802D2E58
// Size: 276 bytes
// NON_MATCHING - compares string against a symbol name
// ============================================================================

// EString layout (from existing header):
// 0x00 = data pointer (char*)
// 0x04 = length (int)
// 0x08 = capacity (int)
// 0x0C = flags

struct EStringInternal {
    char* m_data;       // 0x00
    int m_length;       // 0x04
    int m_capacity;     // 0x08
    u32 m_flags;        // 0x0C
};

int EString_CompareSymbol(const void* self, char* symbol)
{
    const EStringInternal* str = (const EStringInternal*)self;

    if (!symbol) return 1;
    if (!str->m_data) {
        if (symbol[0] == 0) return 0;
        return -1;
    }

    // Case-insensitive comparison
    const char* s1 = str->m_data;
    const char* s2 = symbol;

    while (*s1 && *s2) {
        char c1 = *s1;
        char c2 = *s2;

        // Convert to lowercase for comparison
        if (c1 >= 'A' && c1 <= 'Z') c1 += 'a' - 'A';
        if (c2 >= 'A' && c2 <= 'Z') c2 += 'a' - 'A';

        if (c1 != c2) {
            return (c1 < c2) ? -1 : 1;
        }

        s1++;
        s2++;
    }

    if (*s1 == 0 && *s2 == 0) return 0;
    if (*s1 == 0) return -1;
    return 1;
}

// ============================================================================
// TArray<EString, TArrayDefaultAllocator>::SetSize(int, int)
// Address: 0x803C28EC
// Size: 292 bytes
// NON_MATCHING - template array resize for EString
// ============================================================================
struct TArrayEString {
    void* m_data;      // 0x00
    int m_size;        // 0x04
    int m_capacity;    // 0x08
    int m_allocFlags;  // 0x0C
};

void TArrayEString_SetSize(void* self, int newSize, int flags)
{
    TArrayEString* arr = (TArrayEString*)self;

    if (newSize <= 0) {
        // Free existing data
        if (arr->m_data) {
            // Destruct existing EString elements
            u8* data = (u8*)arr->m_data;
            for (int i = 0; i < arr->m_size; i++) {
                // EString destructor (free internal buffer)
                EStringInternal* str = (EStringInternal*)(data + i * 16);
                if (str->m_data && (str->m_flags & 0x01) == 0) {
                    EAHeap_Free2(str->m_data);
                }
            }
            EAHeap_Free2(arr->m_data);
            arr->m_data = 0;
        }
        arr->m_size = 0;
        arr->m_capacity = 0;
        return;
    }

    if (newSize > arr->m_capacity) {
        // Need to grow
        int newCap = newSize;
        if (newCap < arr->m_capacity * 2) {
            newCap = arr->m_capacity * 2;
        }
        if (newCap < 4) newCap = 4;

        // Allocate new buffer (EString = 16 bytes each)
        void* newData = EAHeap_Alloc(newCap * 16);
        if (!newData) return;

        // Copy existing elements
        if (arr->m_data && arr->m_size > 0) {
            memcpy(newData, arr->m_data, arr->m_size * 16);
        }

        // Zero new elements
        u8* p = (u8*)newData;
        for (int i = arr->m_size; i < newCap; i++) {
            *(u32*)(p + i * 16 + 0) = 0;
            *(u32*)(p + i * 16 + 4) = 0;
            *(u32*)(p + i * 16 + 8) = 0;
            *(u32*)(p + i * 16 + 12) = 0;
        }

        // Free old buffer
        if (arr->m_data) {
            EAHeap_Free2(arr->m_data);
        }

        arr->m_data = newData;
        arr->m_capacity = newCap;
    }

    arr->m_size = newSize;
}
