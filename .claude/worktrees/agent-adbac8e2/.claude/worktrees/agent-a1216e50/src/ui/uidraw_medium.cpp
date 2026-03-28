// uidraw_medium.cpp - UIDrawTable medium functions (65-256 bytes)
// Object file: uidraw.obj
// 10 functions

#include "ui/uidraw.h"

// External functions
extern "C" {
    void* operator_new(u32 size);        // 0x802d11b0
    void operator_delete(void* ptr);      // 0x802d1220
    void SmallBlockAllocator_Free(void* ptr);  // 0x8039be60
    int strcmp_impl(const char* a, const char* b);  // 0x80243838
    void* SmallBlockAllocator_Alloc(u32 size);  // 0x8039bdf8
}

// Linked list node for draw table
struct DrawNode {
    DrawNode* m_prev;       // 0x00
    DrawNode* m_next;       // 0x04
    int m_priority;         // 0x08
    void* m_functorThunk;   // 0x0C
    u8 m_functorData[0x0C]; // 0x10
    char* m_name;           // 0x1C
};

struct UIDrawTableObj {
    DrawNode* m_head;       // 0x00
    DrawNode* m_tail;       // 0x04
    int m_count;            // 0x08
    int m_flags;             // 0x0C
};

// Static instance pointer
static UIDrawTableObj* s_drawTableInstance = 0;

// 0x8017a64c | 168 bytes
// NON_MATCHING - constructor allocates sentinel nodes
void UIDrawTable_ctor(UIDrawTableObj* self) {
    // Allocate head sentinel
    DrawNode* head = (DrawNode*)SmallBlockAllocator_Alloc(sizeof(DrawNode));
    // Allocate tail sentinel
    DrawNode* tail = (DrawNode*)SmallBlockAllocator_Alloc(sizeof(DrawNode));

    head->m_prev = 0;
    head->m_next = tail;
    head->m_priority = -999999;
    head->m_name = 0;

    tail->m_prev = head;
    tail->m_next = 0;
    tail->m_priority = 999999;
    tail->m_name = 0;

    self->m_head = head;
    self->m_tail = tail;
    self->m_count = 0;
    self->m_flags = 0;
}

// 0x8017a6f4 | 160 bytes
// NON_MATCHING - destructor frees all nodes
void UIDrawTable_dtor(UIDrawTableObj* self) {
    // Walk the list and free all nodes
    DrawNode* node = self->m_head;
    while (node != 0) {
        DrawNode* next = node->m_next;
        // Free node
        u32 size = sizeof(DrawNode);
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

// 0x8017a794 | 204 bytes
// NON_MATCHING - inserts record in priority order
void UIDrawTable_AddRecord(UIDrawTableObj* self, int priority, void* functor, char* name) {
    // Allocate new node
    DrawNode* newNode = (DrawNode*)SmallBlockAllocator_Alloc(sizeof(DrawNode));
    newNode->m_priority = priority;
    newNode->m_name = name;

    // Copy functor data (16 bytes)
    u32* src = (u32*)functor;
    newNode->m_functorThunk = (void*)src[0];
    u32* dst = (u32*)newNode->m_functorData;
    dst[0] = src[1];
    dst[1] = src[2];
    dst[2] = src[3];

    // Find insertion point (sorted by priority)
    DrawNode* cur = self->m_head->m_next;
    while (cur != 0 && cur->m_priority <= priority) {
        cur = cur->m_next;
    }

    // Insert before cur
    DrawNode* prev = cur->m_prev;
    newNode->m_prev = prev;
    newNode->m_next = cur;
    prev->m_next = newNode;
    cur->m_prev = newNode;

    self->m_count++;
}

// 0x8017a860 | 156 bytes
// Removes a record from the linked list
void UIDrawTable_RemoveRecord(UIDrawTableObj* self, DrawNode* record) {
    if (record == 0) return;

    // Unlink
    DrawNode* prev = record->m_prev;
    DrawNode* next = record->m_next;
    if (prev) prev->m_next = next;
    if (next) next->m_prev = prev;

    // Free node
    u32 size = sizeof(DrawNode);
    if (size > 128) {
        operator_delete(record);
    } else {
        SmallBlockAllocator_Free(record);
    }

    self->m_count--;
}

// 0x8017a8fc | 92 bytes
void UIDrawTable_InstallEntry(UIDrawTableObj* self, int priority, void* functor, char* name) {
    UIDrawTable_AddRecord(self, priority, functor, name);
}

// 0x8017a958 | 84 bytes
// Finds and removes an entry by functor match
void UIDrawTable_UnInstallEntry(UIDrawTableObj* self, void* functor) {
    DrawNode* node = self->m_head;
    while (node != 0) {
        void* nodeThunk = node->m_functorThunk;
        if (nodeThunk == *(void**)functor) {
            UIDrawTable_RemoveRecord(self, node);
            return;
        }
        node = node->m_next;
    }
}

// 0x8017a9ac | 112 bytes
// Removes all entries with matching name
void UIDrawTable_UnInstallAllName(UIDrawTableObj* self, char* name) {
    DrawNode* node = self->m_head;
    while (node != 0) {
        DrawNode* next = node->m_next;
        if (node->m_name != 0 && strcmp_impl(node->m_name, name) == 0) {
            UIDrawTable_RemoveRecord(self, node);
        }
        node = next;
    }
}

// 0x8017aa50 | 100 bytes
// Executes pre-flash draw callbacks
void UIDrawTable_ExecuteDrawsPreFlash(UIDrawTableObj* self, void* rc) {
    DrawNode* node = self->m_head;
    while (node != 0) {
        if (node->m_priority < 0 && node->m_functorThunk != 0) {
            // Call functor
            typedef void (*ThunkFn)(void*, void*);
            ((ThunkFn)node->m_functorThunk)((void*)&node->m_functorThunk, rc);
        }
        node = node->m_next;
    }
}

// 0x8017aab4 | 100 bytes
// Executes post-flash draw callbacks
void UIDrawTable_ExecuteDrawsPostFlash(UIDrawTableObj* self, void* rc) {
    DrawNode* node = self->m_head;
    while (node != 0) {
        if (node->m_priority >= 0 && node->m_functorThunk != 0) {
            typedef void (*ThunkFn)(void*, void*);
            ((ThunkFn)node->m_functorThunk)((void*)&node->m_functorThunk, rc);
        }
        node = node->m_next;
    }
}

// 0x8017ab54 | 76 bytes
void UIDrawTable_Shutdown() {
    if (s_drawTableInstance != 0) {
        UIDrawTable_dtor(s_drawTableInstance);
        u32 size = sizeof(UIDrawTableObj);
        if (size > 128) {
            operator_delete(s_drawTableInstance);
        } else {
            SmallBlockAllocator_Free(s_drawTableInstance);
        }
        s_drawTableInstance = 0;
    }
}
