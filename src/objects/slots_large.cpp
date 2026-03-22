// slots_large.cpp - Large functions (257-1024 bytes) from slots.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\slots.obj
//
// 5 large functions decompiled from slots.obj
//
// NON_MATCHING causes:
//   - GCC virtual dispatch (bctr vs blrl)
//   - GCC register allocation differences
//   - GCC loop codegen
//   - SDA-relative addressing

#include "types.h"

// Forward declarations
class SpriteSlot;
class SlotDescriptor;
class IFFSlotDescList;
class cXObject;
class cXPerson;
class ObjSelector;
class ReconBuffer;
struct ObjectDataID;

// External functions
extern void* operator_new(unsigned int size);
extern void operator_delete(void* ptr);
extern void memcpy(void* dst, const void* src, unsigned int size);
extern void memmove(void* dst, const void* src, unsigned int size);
extern void memset(void* dst, int val, unsigned int size);

#if 0  // Reference decompilation - not compiled

// ============================================================================
// SpriteSlot::Tick(void)
// Address: 0x801430D4 | Size: 708 bytes
// NON_MATCHING - GCC register alloc, animation frame logic
//
// Advances the sprite slot animation by one tick. Handles frame advancement,
// looping, alternating sprites, activation timers, and deactivation.
// This is the core animation update for sprite overlays on objects
// (thought bubbles, skill meters, status icons, etc.).
//
// Key logic:
//   1. If not active, return early
//   2. Advance tick counter
//   3. When enough ticks pass, advance to next frame
//   4. Handle loop wrap / completion
//   5. Handle alternating sprite mode
//   6. Handle activation timer (ticks or loops)
//   7. Update alpha/fade for pop-in/pop-out effects
// ============================================================================
void SpriteSlot::Tick() {
    // Check if active
    int options = m_options;
    if (!(options & 0x01)) return;  // Not active

    // Advance tick counter
    m_tickCount++;

    int ticksPerFrame = GetTicksPerFrame();
    if (ticksPerFrame <= 0) ticksPerFrame = 1;

    // Check if time to advance frame
    if (m_tickCount < ticksPerFrame) return;
    m_tickCount = 0;

    // Advance frame
    m_currentFrame++;

    // Check for frame wrap
    if (m_currentFrame >= m_numFrames) {
        m_currentFrame = 0;

        // Check loop count
        if (options & 0x04) {
            // Counting loops
            int* pLoopCount = (int*)((char*)this + 0x34);
            (*pLoopCount)--;

            if (*pLoopCount <= 0) {
                // Done - check for alternating sprite
                if (m_altSpriteID != 0 && m_altFrameCount > 0) {
                    // Switch to alternate sprite
                    int temp = m_spriteID;
                    m_spriteID = m_altSpriteID;
                    m_altSpriteID = temp;

                    int tempFrames = m_numFrames;
                    m_numFrames = m_altFrameCount;
                    m_altFrameCount = tempFrames;

                    m_currentFrame = 0;
                } else {
                    // Deactivate
                    Deactivate();
                    return;
                }
            }
        }

        if (options & 0x02) {
            // Counting ticks
            int* pTicksLeft = (int*)((char*)this + 0x38);
            (*pTicksLeft)--;

            if (*pTicksLeft <= 0) {
                Deactivate();
                return;
            }
        }
    }

    // Update alpha for pop effects
    if (options & 0x10) {
        // Pop-in effect
        float targetAlpha = 1.0f;
        float rate = 0.1f;
        if (m_alpha < targetAlpha) {
            m_alpha += rate;
            if (m_alpha > targetAlpha) m_alpha = targetAlpha;
        }
    }

    // Update pop size
    if (m_popSize > 0.0f) {
        float targetSize = 1.0f;
        float rate = 0.05f;
        if (m_sizeMultiplierX < targetSize) {
            m_sizeMultiplierX += rate;
            m_sizeMultiplierY += rate;
            if (m_sizeMultiplierX > targetSize) {
                m_sizeMultiplierX = targetSize;
                m_sizeMultiplierY = targetSize;
            }
        }
    }
}

// ============================================================================
// SlotDescriptor::DoStream(ReconBuffer *, int)
// Address: 0x80143560 | Size: 692 bytes
// NON_MATCHING - GCC register alloc, serialization codegen
//
// Serializes/deserializes a SlotDescriptor to/from a ReconBuffer.
// Handles all slot fields including type, offsets, flags, distances,
// and facing data. Supports both routing slots and object slots.
// ============================================================================
void SlotDescriptor::DoStream(ReconBuffer* buffer, int direction) {
    if (buffer == 0) return;

    // Stream slot type
    ReconBuffer_StreamShort(buffer, (short*)&m_type);

    // Stream position offsets
    ReconBuffer_StreamFloat(buffer, &m_xOffset);
    ReconBuffer_StreamFloat(buffer, &m_yOffset);
    ReconBuffer_StreamFloat(buffer, &m_altOffset);

    // Stream type-specific data
    if (m_type == 0) {
        // Routing slot data
        // Multipliers (3 ints for above/level/below)
        for (int i = 0; i < 3; i++) {
            int* pMult = (int*)((char*)m_data + i * 4);
            ReconBuffer_StreamInt(buffer, pMult);
        }

        // Flags
        ReconBuffer_StreamInt(buffer, (int*)((char*)m_data + 0x0C));

        // Snap target slot
        ReconBuffer_StreamInt(buffer, (int*)((char*)m_data + 0x10));

        // Distances (min, max, optimal)
        ReconBuffer_StreamInt(buffer, (int*)((char*)m_data + 0x14));
        ReconBuffer_StreamInt(buffer, (int*)((char*)m_data + 0x18));
        ReconBuffer_StreamInt(buffer, (int*)((char*)m_data + 0x1C));

        // Gradient
        ReconBuffer_StreamFloat(buffer, (float*)((char*)m_data + 0x20));

        // Facing direction
        ReconBuffer_StreamInt(buffer, (int*)((char*)m_data + 0x24));

        // Resolution
        ReconBuffer_StreamInt(buffer, (int*)((char*)m_data + 0x28));
    } else if (m_type == 1) {
        // Object slot data
        // Height
        ReconBuffer_StreamInt(buffer, (int*)((char*)m_data + 0x00));

        // Default height
        ReconBuffer_StreamInt(buffer, (int*)((char*)m_data + 0x04));

        // Flags
        ReconBuffer_StreamInt(buffer, (int*)((char*)m_data + 0x08));
    } else if (m_type == 2) {
        // Sprite slot data
        // All sprite-specific fields
        ReconBuffer_StreamData(buffer, m_data, 0x38);
    }
}

// ============================================================================
// IFFSlotDescList::AddSlot(SlotDescriptor &)
// Address: 0x80144960 | Size: 704 bytes
// NON_MATCHING - GCC register alloc, vector insert codegen
//
// Adds a new slot descriptor to the IFF slot list. Grows the internal
// vector if needed, copies the descriptor, and updates the count.
// ============================================================================
int IFFSlotDescList::AddSlot(SlotDescriptor& desc) {
    // Get current slot vector
    SlotDescriptor* slotsBegin = *(SlotDescriptor**)((char*)this + 0x54);
    SlotDescriptor* slotsEnd = *(SlotDescriptor**)((char*)this + 0x58);

    int currentCount = 0;
    if (slotsBegin != 0 && slotsEnd != 0) {
        currentCount = (int)(slotsEnd - slotsBegin);
    }

    // Grow if needed
    int newCount = currentCount + 1;

    // Check capacity
    SlotDescriptor* slotsCapEnd = *(SlotDescriptor**)((char*)this + 0x5C);
    int currentCap = 0;
    if (slotsBegin != 0 && slotsCapEnd != 0) {
        currentCap = (int)(slotsCapEnd - slotsBegin);
    }

    if (newCount > currentCap) {
        // Need to grow
        int newCap = currentCap > 0 ? currentCap * 2 : 4;
        if (newCap < newCount) newCap = newCount;

        SlotDescriptor* newMem = (SlotDescriptor*)operator_new(
            newCap * sizeof(SlotDescriptor));

        // Copy existing slots
        if (currentCount > 0 && slotsBegin != 0) {
            memcpy(newMem, slotsBegin, currentCount * sizeof(SlotDescriptor));
        }

        // Free old storage
        if (slotsBegin != 0) {
            operator_delete(slotsBegin);
        }

        *(SlotDescriptor**)((char*)this + 0x54) = newMem;
        *(SlotDescriptor**)((char*)this + 0x58) = newMem + newCount;
        *(SlotDescriptor**)((char*)this + 0x5C) = newMem + newCap;

        slotsBegin = newMem;
    } else {
        // Just update end pointer
        *(SlotDescriptor**)((char*)this + 0x58) = slotsBegin + newCount;
    }

    // Copy new slot to end
    memcpy(&slotsBegin[currentCount], &desc, sizeof(SlotDescriptor));

    return currentCount;  // Return index of new slot
}

// ============================================================================
// IFFSlotDescList::RemoveSlot(int)
// Address: 0x80144C20 | Size: 260 bytes
// NON_MATCHING - GCC register alloc, vector erase codegen
//
// Removes a slot descriptor by index from the IFF slot list. Shifts
// remaining elements down and decrements the count.
// ============================================================================
int IFFSlotDescList::RemoveSlot(int index) {
    SlotDescriptor* slotsBegin = *(SlotDescriptor**)((char*)this + 0x54);
    SlotDescriptor* slotsEnd = *(SlotDescriptor**)((char*)this + 0x58);

    if (slotsBegin == 0 || slotsEnd == 0) return -1;

    int currentCount = (int)(slotsEnd - slotsBegin);
    if (index < 0 || index >= currentCount) return -1;

    // Shift remaining elements down
    int moveCount = currentCount - index - 1;
    if (moveCount > 0) {
        memmove(&slotsBegin[index], &slotsBegin[index + 1],
                moveCount * sizeof(SlotDescriptor));
    }

    // Decrement count
    *(SlotDescriptor**)((char*)this + 0x58) = slotsEnd - 1;

    return 0;
}

// ============================================================================
// IFFSlotDescList::LoadFromIndex(unsigned int, int)
// Address: 0x80144DF8 | Size: 264 bytes
// NON_MATCHING - GCC register alloc, resource loading
//
// Loads slot descriptors from a resource file by index. Reads the slot
// count and each descriptor from the resource data.
// ============================================================================
int IFFSlotDescList::LoadFromIndex(unsigned int index, int type) {
    // Get resource file
    void* resFile = GetResourceFile(type);
    if (resFile == 0) return -1;

    // Load raw resource data
    void* rawData = 0;
    int dataSize = 0;
    int result = LoadRawResource(resFile, index, &rawData, &dataSize);
    if (result < 0 || rawData == 0) return -1;

    // Parse slot count
    int slotCount = *(int*)rawData;
    if (slotCount <= 0) {
        ReleaseRawResource(rawData);
        return 0;
    }

    // Clear existing slots
    SlotDescriptor* oldBegin = *(SlotDescriptor**)((char*)this + 0x54);
    if (oldBegin != 0) {
        operator_delete(oldBegin);
    }

    // Allocate slot storage
    SlotDescriptor* newSlots = (SlotDescriptor*)operator_new(
        slotCount * sizeof(SlotDescriptor));
    *(SlotDescriptor**)((char*)this + 0x54) = newSlots;
    *(SlotDescriptor**)((char*)this + 0x58) = newSlots + slotCount;
    *(SlotDescriptor**)((char*)this + 0x5C) = newSlots + slotCount;

    // Read each slot descriptor
    ReconBuffer reconBuf;
    InitReconBuffer(&reconBuf, (char*)rawData + 4, dataSize - 4, 0);

    for (int i = 0; i < slotCount; i++) {
        memset(&newSlots[i], 0, sizeof(SlotDescriptor));
        newSlots[i].DoStream(&reconBuf, 0);  // Read
    }

    // Store resource name and data ID
    SetResourceName_Internal(resFile, index);

    // Release raw data
    ReleaseRawResource(rawData);

    return 0;
}

#endif // Reference decompilation
