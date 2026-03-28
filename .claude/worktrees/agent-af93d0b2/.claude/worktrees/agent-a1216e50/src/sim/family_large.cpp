// family_large.cpp - Large functions (257-1024 bytes) from family.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\family.obj
//
// 7 large functions decompiled from family.obj
// (2 are vtable data, 1 is STL vector code)
//
// NON_MATCHING causes:
//   - GCC virtual dispatch (bctr vs blrl)
//   - GCC register allocation differences
//   - GCC memcpy/memmove inlining
//   - STL vector implementation differences

#include "types.h"
#include "stub_classes.h"

// Forward declarations
class FamilyImpl;
class FamilyMember;
class ReconBuffer;
class iResFile;

// External functions
extern void* operator_new(unsigned int size);
extern void operator_delete(void* ptr);
extern void memcpy(void* dst, const void* src, unsigned int size);
extern void memmove(void* dst, const void* src, unsigned int size);

#if 0  // Reference decompilation - not compiled

// ============================================================================
// FamilyImpl::RemoveFamilyFromLot(void)
// Address: 0x800B61CC | Size: 260 bytes
// NON_MATCHING - GCC register alloc, virtual dispatch
//
// Removes all family members from the current lot. Iterates through the
// members vector and calls a removal function for each active sim on the lot.
// Resets lot-related state in the family.
// ============================================================================
void FamilyImpl::RemoveFamilyFromLot() {
    // Iterate members
    int* begin = m_membersBegin;
    int* end = m_membersEnd;

    while (begin != end) {
        int memberGUID = *begin;
        if (memberGUID != 0) {
            // Look up the sim by GUID
            void* simInstance = FindSimByGUID(memberGUID);
            if (simInstance != 0) {
                // Remove sim from lot
                // Virtual call through sim's vtable
                int* vtbl = *(int**)simInstance;
                short offset = *(short*)((char*)vtbl + 0x30);
                void* fn = *(void**)((char*)vtbl + 0x34);
                ((void(*)(void*))fn)((char*)simInstance + offset);
            }
        }
        begin++;
    }

    // Reset lot state
    m_houseNumber = -1;
}

// ============================================================================
// FamilyImpl::LoadByResID(iResFile *, short, int *)
// Address: 0x800B6650 | Size: 260 bytes
// NON_MATCHING - GCC register alloc, resource loading
//
// Loads family data from a resource file by resource ID. Reads the family
// header data (name, number, funds, etc.) and member list from the
// resource file's data stream.
// ============================================================================
void FamilyImpl::LoadByResID(iResFile* file, short resID, int* outResult) {
    if (file == 0 || outResult == 0) {
        if (outResult) *outResult = -1;
        return;
    }

    // Open the resource by ID
    void* stream = OpenResource(file, resID);
    if (stream == 0) {
        *outResult = -1;
        return;
    }

    // Read family header
    // Read name (EString at +0x04)
    ReadString(stream, (char*)this + 0x04);

    // Read numeric fields
    ReadInt(stream, &m_number);
    ReadInt(stream, &m_houseNumber);
    ReadInt(stream, &m_creationOrder);
    ReadInt(stream, &m_funds);
    ReadInt(stream, &m_houseValue);
    ReadInt(stream, &m_friendCount);
    ReadInt(stream, &m_flags);

    // Read member count and members
    int memberCount = 0;
    ReadInt(stream, &memberCount);

    // Clear existing members
    if (m_membersBegin != 0) {
        operator_delete(m_membersBegin);
        m_membersBegin = 0;
        m_membersEnd = 0;
        m_membersCapEnd = 0;
    }

    if (memberCount > 0) {
        int* newMem = (int*)operator_new(memberCount * sizeof(int));
        m_membersBegin = newMem;
        m_membersEnd = newMem + memberCount;
        m_membersCapEnd = newMem + memberCount;

        for (int i = 0; i < memberCount; i++) {
            ReadInt(stream, &newMem[i]);
        }
    }

    CloseResource(stream);
    *outResult = 0;
}

// ============================================================================
// FamilyImpl::DoStream(ReconBuffer *, int)
// Address: 0x800B6548 | Size: 264 bytes
// NON_MATCHING - GCC register alloc, serialization codegen
//
// Serializes/deserializes family data to/from a ReconBuffer. Direction
// parameter determines read (0) or write (1). Streams all family fields
// and the members vector.
// ============================================================================
int FamilyImpl::DoStream(ReconBuffer* buffer, int direction) {
    if (buffer == 0) {
        return -1;
    }

    // Stream name (EString at +0x04)
    ReconBuffer_StreamString(buffer, (char*)this + 0x04);

    // Stream numeric fields
    ReconBuffer_StreamInt(buffer, &m_number);
    ReconBuffer_StreamInt(buffer, &m_houseNumber);
    ReconBuffer_StreamInt(buffer, &m_creationOrder);
    ReconBuffer_StreamInt(buffer, &m_funds);
    ReconBuffer_StreamInt(buffer, &m_houseValue);
    ReconBuffer_StreamInt(buffer, &m_friendCount);
    ReconBuffer_StreamInt(buffer, &m_friendCountDirty);
    ReconBuffer_StreamInt(buffer, &m_flags);

    // Stream members vector
    int memberCount;
    if (direction == 1) {
        // Writing
        memberCount = (int)(m_membersEnd - m_membersBegin);
        ReconBuffer_StreamInt(buffer, &memberCount);
        for (int i = 0; i < memberCount; i++) {
            ReconBuffer_StreamInt(buffer, &m_membersBegin[i]);
        }
    } else {
        // Reading
        ReconBuffer_StreamInt(buffer, &memberCount);

        // Resize members vector
        if (m_membersBegin != 0) {
            operator_delete(m_membersBegin);
        }
        if (memberCount > 0) {
            int* newMem = (int*)operator_new(memberCount * sizeof(int));
            m_membersBegin = newMem;
            m_membersEnd = newMem + memberCount;
            m_membersCapEnd = newMem + memberCount;
            for (int i = 0; i < memberCount; i++) {
                ReconBuffer_StreamInt(buffer, &newMem[i]);
            }
        } else {
            m_membersBegin = 0;
            m_membersEnd = 0;
            m_membersCapEnd = 0;
        }
    }

    return 0;
}

// ============================================================================
// FamilyImpl::AddMember(int)
// Address: 0x800B6818 | Size: 444 bytes
// NON_MATCHING - GCC vector grow, register alloc
//
// Adds a new family member by GUID. First checks if the GUID is already
// in the members vector. If not, appends it. Handles vector growth if
// capacity is exceeded.
// ============================================================================
int FamilyImpl::AddMember(int guid) {
    // Check if already a member
    int* begin = m_membersBegin;
    int* end = m_membersEnd;

    while (begin != end) {
        if (*begin == guid) {
            return 0;  // Already a member
        }
        begin++;
    }

    // Need to add - check capacity
    begin = m_membersBegin;
    end = m_membersEnd;
    int* capEnd = m_membersCapEnd;
    int currentSize = (int)(end - begin);
    int currentCap = (int)(capEnd - begin);

    if (end == capEnd) {
        // Need to grow
        int newCap = currentCap > 0 ? currentCap * 2 : 4;
        int* newMem = (int*)operator_new(newCap * sizeof(int));

        // Copy existing members
        if (currentSize > 0) {
            memcpy(newMem, begin, currentSize * sizeof(int));
        }

        // Free old storage
        if (begin != 0) {
            operator_delete(begin);
        }

        m_membersBegin = newMem;
        m_membersEnd = newMem + currentSize;
        m_membersCapEnd = newMem + newCap;

        begin = newMem;
        end = newMem + currentSize;
    }

    // Append the new member
    *end = guid;
    m_membersEnd = end + 1;

    // Mark friend count as dirty
    m_friendCountDirty = 1;

    return 1;
}

// ============================================================================
// vector<FamilyMember, allocator<FamilyMember> >::_M_fill_insert(...)
// Address: 0x803A3118 | Size: 744 bytes
// NON_MATCHING - GCC STL vector fill_insert implementation
//
// Standard STL vector::_M_fill_insert - inserts 'count' copies of 'value'
// at position 'pos'. Handles reallocation if needed, with move semantics
// for elements after the insertion point.
// ============================================================================
void vector_FamilyMember_fill_insert(void* vec, void* pos, unsigned int count, void* value) {
    // vec layout: [begin, end, capacity_end]
    char** pBegin = (char**)vec;
    char** pEnd = (char**)((char*)vec + 4);
    char** pCapEnd = (char**)((char*)vec + 8);

    char* vBegin = *pBegin;
    char* vEnd = *pEnd;
    char* vCapEnd = *pCapEnd;

    int elemSize = sizeof(FamilyMember);
    int remainingCap = (int)(vCapEnd - vEnd) / elemSize;

    if ((int)count <= remainingCap) {
        // Enough capacity - shift elements after pos right
        int afterCount = (int)(vEnd - (char*)pos) / elemSize;

        if (afterCount > (int)count) {
            // Copy tail elements to uninitialized space
            memmove((char*)pos + count * elemSize, (char*)pos, afterCount * elemSize);
            // Fill inserted positions
            for (unsigned int i = 0; i < count; i++) {
                memcpy((char*)pos + i * elemSize, value, elemSize);
            }
        } else {
            // Fill after existing end first
            for (unsigned int i = afterCount; i < count; i++) {
                memcpy(vEnd + (i - afterCount) * elemSize, value, elemSize);
            }
            // Move existing elements
            if (afterCount > 0) {
                memmove(vEnd, (char*)pos, afterCount * elemSize);
            }
            // Fill remaining
            for (int i = 0; i < afterCount; i++) {
                memcpy((char*)pos + i * elemSize, value, elemSize);
            }
        }
        *pEnd = vEnd + count * elemSize;
    } else {
        // Need reallocation
        int oldSize = (int)(vEnd - vBegin) / elemSize;
        int newCap = oldSize + ((int)count > oldSize ? (int)count : oldSize);

        char* newMem = (char*)operator_new(newCap * elemSize);

        // Copy elements before pos
        int beforeCount = (int)((char*)pos - vBegin) / elemSize;
        if (beforeCount > 0) {
            memcpy(newMem, vBegin, beforeCount * elemSize);
        }

        // Fill new elements
        for (unsigned int i = 0; i < count; i++) {
            memcpy(newMem + (beforeCount + i) * elemSize, value, elemSize);
        }

        // Copy elements after pos
        int afterCount = (int)(vEnd - (char*)pos) / elemSize;
        if (afterCount > 0) {
            memcpy(newMem + (beforeCount + count) * elemSize, (char*)pos, afterCount * elemSize);
        }

        // Free old storage
        if (vBegin != 0) {
            operator_delete(vBegin);
        }

        *pBegin = newMem;
        *pEnd = newMem + (oldSize + count) * elemSize;
        *pCapEnd = newMem + newCap * elemSize;
    }
}

// ============================================================================
// FamilyImpl virtual table
// Address: 0x8045EC60 | Size: 360 bytes
// This is vtable data, not a function
// ============================================================================
// FamilyImpl vtable - 90 entries at 4 bytes each

// ============================================================================
// Family virtual table
// Address: 0x8045EDC8 | Size: 360 bytes
// This is vtable data, not a function
// ============================================================================
// Family vtable - 90 entries at 4 bytes each

#endif // Reference decompilation
