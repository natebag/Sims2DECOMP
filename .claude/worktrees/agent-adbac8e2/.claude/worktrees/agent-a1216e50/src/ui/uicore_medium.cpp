// uicore_medium.cpp - GetVariableCommandTable / SetVariableCommandTable / GetLocalizableCommandTable
// Object file: uicore.obj
// 30 medium functions (65-256 bytes)
//
// All three command tables follow an identical linked-list pattern.
// The tables manage callbacks for APT variable get/set/localize operations.

#include "ui/uicore.h"

extern "C" {
    void* operator_new(u32 size);        // 0x802d11b0
    void operator_delete(void* ptr);      // 0x802d1220
    void SmallBlockAllocator_Free(void* ptr);  // 0x8039be60
    void* SmallBlockAllocator_Alloc(u32 size);  // 0x8039bdf8
    int AptVar_Hash(char* str);           // AptVar::Hash
    int strcmp_impl(const char* a, const char* b);  // 0x80243838
}

// Command table record layout (same for all three table types)
struct CmdRecord {
    CmdRecord* m_prev;       // 0x00
    CmdRecord* m_next;       // 0x04
    char* m_name;            // 0x08
    u32 m_hash;              // 0x0C
    u8 m_functor[0x10];      // 0x10 - CBFunctorBase data
};

struct CmdTable {
    CmdRecord* m_head;       // 0x00
    CmdRecord* m_tail;       // 0x04
    int m_count;             // 0x08
};

// Static singletons
static CmdTable* s_getVarTable = 0;
static CmdTable* s_setVarTable = 0;
static CmdTable* s_getLocTable = 0;

// ============================================================================
// GetVariableCommandTable
// ============================================================================

// 0x80177da8 | 160 bytes
void GetVariableCommandTable_ctor(CmdTable* self) {
    CmdRecord* head = (CmdRecord*)SmallBlockAllocator_Alloc(sizeof(CmdRecord));
    CmdRecord* tail = (CmdRecord*)SmallBlockAllocator_Alloc(sizeof(CmdRecord));
    head->m_prev = 0;
    head->m_next = tail;
    head->m_name = 0;
    head->m_hash = 0;
    tail->m_prev = head;
    tail->m_next = 0;
    tail->m_name = 0;
    tail->m_hash = 0xFFFFFFFF;
    self->m_head = head;
    self->m_tail = tail;
    self->m_count = 0;
}

// 0x80177e48 | 160 bytes
void GetVariableCommandTable_dtor(CmdTable* self) {
    CmdRecord* node = self->m_head;
    while (node != 0) {
        CmdRecord* next = node->m_next;
        u32 size = sizeof(CmdRecord);
        if (size > 128) {
            operator_delete(node);
        } else {
            SmallBlockAllocator_Free(node);
        }
        node = next;
    }
    self->m_head = 0;
    self->m_tail = 0;
    self->m_count = 0;
}

// 0x80177ee8 | 100 bytes
void GetVariableCommandTable_AddRecord(CmdTable* self, char* name, void* functor) {
    CmdRecord* rec = (CmdRecord*)SmallBlockAllocator_Alloc(sizeof(CmdRecord));
    rec->m_name = name;
    rec->m_hash = AptVar_Hash(name);
    // Copy functor (16 bytes)
    u32* src = (u32*)functor;
    u32* dst = (u32*)rec->m_functor;
    dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; dst[3] = src[3];
    // Insert at end (before tail)
    CmdRecord* tail = self->m_tail;
    CmdRecord* prev = tail->m_prev;
    rec->m_prev = prev;
    rec->m_next = tail;
    prev->m_next = rec;
    tail->m_prev = rec;
    self->m_count++;
}

// 0x80177f4c | 144 bytes
void GetVariableCommandTable_RemoveRecord(CmdTable* self, CmdRecord* record) {
    if (record == 0) return;
    CmdRecord* prev = record->m_prev;
    CmdRecord* next = record->m_next;
    if (prev) prev->m_next = next;
    if (next) next->m_prev = prev;
    u32 size = sizeof(CmdRecord);
    if (size > 128) {
        operator_delete(record);
    } else {
        SmallBlockAllocator_Free(record);
    }
    self->m_count--;
}

// 0x80177fdc | 132 bytes
void GetVariableCommandTable_InstallCommand(CmdTable* self, char* name, void* functor) {
    // Check if already installed
    u32 hash = AptVar_Hash(name);
    CmdRecord* node = self->m_head->m_next;
    while (node != 0 && node->m_next != 0) {
        if (node->m_hash == hash) {
            return;  // Already exists
        }
        node = node->m_next;
    }
    GetVariableCommandTable_AddRecord(self, name, functor);
}

// 0x80178060 | 120 bytes
void GetVariableCommandTable_UnInstallCommand(CmdTable* self, char* name) {
    u32 hash = AptVar_Hash(name);
    CmdRecord* node = self->m_head->m_next;
    while (node != 0 && node->m_next != 0) {
        if (node->m_hash == hash) {
            GetVariableCommandTable_RemoveRecord(self, node);
            return;
        }
        node = node->m_next;
    }
}

// 0x801780d8 | 96 bytes
void GetVariableCommandTable_UnInstallAllCommands(CmdTable* self, void* functor) {
    CmdRecord* node = self->m_head->m_next;
    while (node != 0 && node->m_next != 0) {
        CmdRecord* next = node->m_next;
        // Compare functor data
        if (*(u32*)node->m_functor == *(u32*)functor) {
            GetVariableCommandTable_RemoveRecord(self, node);
        }
        node = next;
    }
}

// 0x80178138 | 96 bytes
int GetVariableCommandTable_ContainsCommand(CmdTable* self, char* name) {
    u32 hash = AptVar_Hash(name);
    CmdRecord* node = self->m_head->m_next;
    while (node != 0 && node->m_next != 0) {
        if (node->m_hash == hash) {
            return 1;
        }
        node = node->m_next;
    }
    return 0;
}

// 0x80178198 | 212 bytes
// NON_MATCHING - complex functor dispatch
char* GetVariableCommandTable_ExecuteCommand(CmdTable* self, char* name, char* outVar) {
    u32 hash = AptVar_Hash(name);
    CmdRecord* node = self->m_head->m_next;
    while (node != 0 && node->m_next != 0) {
        if (node->m_hash == hash) {
            // Call functor thunk
            typedef char* (*ThunkFn)(void*, char*);
            void* thunk = *(void**)node->m_functor;
            return ((ThunkFn)thunk)((void*)node->m_functor, outVar);
        }
        node = node->m_next;
    }
    return 0;
}

// ============================================================================
// SetVariableCommandTable (identical pattern to GetVariable)
// ============================================================================

// 0x8017826c | 160 bytes
void SetVariableCommandTable_ctor(CmdTable* self) {
    CmdRecord* head = (CmdRecord*)SmallBlockAllocator_Alloc(sizeof(CmdRecord));
    CmdRecord* tail = (CmdRecord*)SmallBlockAllocator_Alloc(sizeof(CmdRecord));
    head->m_prev = 0; head->m_next = tail; head->m_name = 0; head->m_hash = 0;
    tail->m_prev = head; tail->m_next = 0; tail->m_name = 0; tail->m_hash = 0xFFFFFFFF;
    self->m_head = head; self->m_tail = tail; self->m_count = 0;
}

// 0x8017830c | 160 bytes
void SetVariableCommandTable_dtor(CmdTable* self) {
    CmdRecord* node = self->m_head;
    while (node != 0) {
        CmdRecord* next = node->m_next;
        u32 size = sizeof(CmdRecord);
        if (size > 128) { operator_delete(node); } else { SmallBlockAllocator_Free(node); }
        node = next;
    }
    self->m_head = 0; self->m_tail = 0; self->m_count = 0;
}

// 0x801783ac | 100 bytes
void SetVariableCommandTable_AddRecord(CmdTable* self, char* name, void* functor) {
    CmdRecord* rec = (CmdRecord*)SmallBlockAllocator_Alloc(sizeof(CmdRecord));
    rec->m_name = name; rec->m_hash = AptVar_Hash(name);
    u32* src = (u32*)functor; u32* dst = (u32*)rec->m_functor;
    dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; dst[3] = src[3];
    CmdRecord* tail = self->m_tail; CmdRecord* prev = tail->m_prev;
    rec->m_prev = prev; rec->m_next = tail; prev->m_next = rec; tail->m_prev = rec;
    self->m_count++;
}

// 0x80178410 | 144 bytes
void SetVariableCommandTable_RemoveRecord(CmdTable* self, CmdRecord* record) {
    if (record == 0) return;
    CmdRecord* prev = record->m_prev; CmdRecord* next = record->m_next;
    if (prev) prev->m_next = next; if (next) next->m_prev = prev;
    u32 size = sizeof(CmdRecord);
    if (size > 128) { operator_delete(record); } else { SmallBlockAllocator_Free(record); }
    self->m_count--;
}

// 0x801784a0 | 132 bytes
void SetVariableCommandTable_InstallCommand(CmdTable* self, char* name, void* functor) {
    u32 hash = AptVar_Hash(name);
    CmdRecord* node = self->m_head->m_next;
    while (node != 0 && node->m_next != 0) {
        if (node->m_hash == hash) return;
        node = node->m_next;
    }
    SetVariableCommandTable_AddRecord(self, name, functor);
}

// 0x80178524 | 120 bytes
void SetVariableCommandTable_UnInstallCommand(CmdTable* self, char* name) {
    u32 hash = AptVar_Hash(name);
    CmdRecord* node = self->m_head->m_next;
    while (node != 0 && node->m_next != 0) {
        if (node->m_hash == hash) { SetVariableCommandTable_RemoveRecord(self, node); return; }
        node = node->m_next;
    }
}

// 0x8017859c | 96 bytes
void SetVariableCommandTable_UnInstallAllCommands(CmdTable* self, void* functor) {
    CmdRecord* node = self->m_head->m_next;
    while (node != 0 && node->m_next != 0) {
        CmdRecord* next = node->m_next;
        if (*(u32*)node->m_functor == *(u32*)functor) { SetVariableCommandTable_RemoveRecord(self, node); }
        node = next;
    }
}

// 0x801785fc | 96 bytes
int SetVariableCommandTable_ContainsCommand(CmdTable* self, char* name) {
    u32 hash = AptVar_Hash(name);
    CmdRecord* node = self->m_head->m_next;
    while (node != 0 && node->m_next != 0) {
        if (node->m_hash == hash) return 1;
        node = node->m_next;
    }
    return 0;
}

// 0x8017865c | 216 bytes
// NON_MATCHING - functor dispatch with 3 args
void SetVariableCommandTable_ExecuteCommand(CmdTable* self, char* name, char* value, char* extra) {
    u32 hash = AptVar_Hash(name);
    CmdRecord* node = self->m_head->m_next;
    while (node != 0 && node->m_next != 0) {
        if (node->m_hash == hash) {
            typedef void (*ThunkFn)(void*, char*, char*);
            void* thunk = *(void**)node->m_functor;
            ((ThunkFn)thunk)((void*)node->m_functor, value, extra);
            return;
        }
        node = node->m_next;
    }
}

// ============================================================================
// GetLocalizableCommandTable (identical pattern)
// ============================================================================

// 0x80178734 | 160 bytes
void GetLocalizableCommandTable_ctor(CmdTable* self) {
    CmdRecord* head = (CmdRecord*)SmallBlockAllocator_Alloc(sizeof(CmdRecord));
    CmdRecord* tail = (CmdRecord*)SmallBlockAllocator_Alloc(sizeof(CmdRecord));
    head->m_prev = 0; head->m_next = tail; head->m_name = 0; head->m_hash = 0;
    tail->m_prev = head; tail->m_next = 0; tail->m_name = 0; tail->m_hash = 0xFFFFFFFF;
    self->m_head = head; self->m_tail = tail; self->m_count = 0;
}

// 0x801787d4 | 160 bytes
void GetLocalizableCommandTable_dtor(CmdTable* self) {
    CmdRecord* node = self->m_head;
    while (node != 0) {
        CmdRecord* next = node->m_next;
        u32 size = sizeof(CmdRecord);
        if (size > 128) { operator_delete(node); } else { SmallBlockAllocator_Free(node); }
        node = next;
    }
    self->m_head = 0; self->m_tail = 0; self->m_count = 0;
}

// 0x80178874 | 100 bytes
void GetLocalizableCommandTable_AddRecord(CmdTable* self, char* name, void* functor) {
    CmdRecord* rec = (CmdRecord*)SmallBlockAllocator_Alloc(sizeof(CmdRecord));
    rec->m_name = name; rec->m_hash = AptVar_Hash(name);
    u32* src = (u32*)functor; u32* dst = (u32*)rec->m_functor;
    dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; dst[3] = src[3];
    CmdRecord* tail = self->m_tail; CmdRecord* prev = tail->m_prev;
    rec->m_prev = prev; rec->m_next = tail; prev->m_next = rec; tail->m_prev = rec;
    self->m_count++;
}

// 0x801788d8 | 144 bytes
void GetLocalizableCommandTable_RemoveRecord(CmdTable* self, CmdRecord* record) {
    if (record == 0) return;
    CmdRecord* prev = record->m_prev; CmdRecord* next = record->m_next;
    if (prev) prev->m_next = next; if (next) next->m_prev = prev;
    u32 size = sizeof(CmdRecord);
    if (size > 128) { operator_delete(record); } else { SmallBlockAllocator_Free(record); }
    self->m_count--;
}

// 0x80178968 | 132 bytes
void GetLocalizableCommandTable_InstallCommand(CmdTable* self, char* name, void* functor) {
    u32 hash = AptVar_Hash(name);
    CmdRecord* node = self->m_head->m_next;
    while (node != 0 && node->m_next != 0) {
        if (node->m_hash == hash) return;
        node = node->m_next;
    }
    GetLocalizableCommandTable_AddRecord(self, name, functor);
}

// 0x801789ec | 120 bytes
void GetLocalizableCommandTable_UnInstallCommand(CmdTable* self, char* name) {
    u32 hash = AptVar_Hash(name);
    CmdRecord* node = self->m_head->m_next;
    while (node != 0 && node->m_next != 0) {
        if (node->m_hash == hash) { GetLocalizableCommandTable_RemoveRecord(self, node); return; }
        node = node->m_next;
    }
}

// 0x80178a64 | 96 bytes
void GetLocalizableCommandTable_UnInstallAllCommands(CmdTable* self, void* functor) {
    CmdRecord* node = self->m_head->m_next;
    while (node != 0 && node->m_next != 0) {
        CmdRecord* next = node->m_next;
        if (*(u32*)node->m_functor == *(u32*)functor) { GetLocalizableCommandTable_RemoveRecord(self, node); }
        node = next;
    }
}

// 0x80178ac4 | 96 bytes
int GetLocalizableCommandTable_ContainsCommand(CmdTable* self, char* name) {
    u32 hash = AptVar_Hash(name);
    CmdRecord* node = self->m_head->m_next;
    while (node != 0 && node->m_next != 0) {
        if (node->m_hash == hash) return 1;
        node = node->m_next;
    }
    return 0;
}

// 0x80178b24 | 212 bytes
// NON_MATCHING - functor dispatch returning wchar_t*
unsigned short* GetLocalizableCommandTable_ExecuteCommand(CmdTable* self, char* name, char* outVar) {
    u32 hash = AptVar_Hash(name);
    CmdRecord* node = self->m_head->m_next;
    while (node != 0 && node->m_next != 0) {
        if (node->m_hash == hash) {
            typedef unsigned short* (*ThunkFn)(void*, char*);
            void* thunk = *(void**)node->m_functor;
            return ((ThunkFn)thunk)((void*)node->m_functor, outVar);
        }
        node = node->m_next;
    }
    return 0;
}

// 0x80178c34 | 76 bytes
void GetVariableCommandTable_Shutdown() {
    if (s_getVarTable != 0) {
        GetVariableCommandTable_dtor(s_getVarTable);
        u32 size = sizeof(CmdTable);
        if (size > 128) { operator_delete(s_getVarTable); } else { SmallBlockAllocator_Free(s_getVarTable); }
        s_getVarTable = 0;
    }
}

// 0x80178cbc | 76 bytes
void SetVariableCommandTable_Shutdown() {
    if (s_setVarTable != 0) {
        SetVariableCommandTable_dtor(s_setVarTable);
        u32 size = sizeof(CmdTable);
        if (size > 128) { operator_delete(s_setVarTable); } else { SmallBlockAllocator_Free(s_setVarTable); }
        s_setVarTable = 0;
    }
}

// 0x80178d44 | 76 bytes
void GetLocalizableCommandTable_Shutdown() {
    if (s_getLocTable != 0) {
        GetLocalizableCommandTable_dtor(s_getLocTable);
        u32 size = sizeof(CmdTable);
        if (size > 128) { operator_delete(s_getLocTable); } else { SmallBlockAllocator_Free(s_getLocTable); }
        s_getLocTable = 0;
    }
}
