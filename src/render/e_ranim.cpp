// e_ranim.cpp - ERAnim, ERBinary, ERCharacter, etc. (animation resources)
// Part of the Sims 2 GC decompilation
// Original: engine_ngc_release_dvd.lib(e_ranim.obj)
//
// Small functions (<=64 bytes) decompiled from the e_ranim object file.
// ERAnim and related classes are resource types for animations.

#include "types.h"

// Forward declarations
class EStream;
class EFile;
class EStorable;
class ETypeInfo;

// External functions
extern EStream& EStorable_StreamOut(EStream& stream, EStorable* obj);
extern EStream& EStorable_StreamIn(EStream& stream, EStorable*& obj);
extern EFile& EStorable_FileIn(EFile& file, EStorable*& obj);
extern void* EAHeap_GetCurrentHeap();
extern void EAHeap_Free(void* heap, void* ptr);

// Type info externs
extern ETypeInfo ERAnim_typeInfo;
extern ETypeInfo ERBinary_typeInfo;
extern ETypeInfo ERCharacter_typeInfo;
extern ETypeInfo ERDataset_typeInfo;
extern ETypeInfo ERSoundEvent_typeInfo;
extern ETypeInfo ERSoundTrackData_typeInfo;

// Placement new
inline void* operator new(unsigned int, void* ptr) { return ptr; }

// Macro for generating streaming operators (common pattern)
#define STREAMING_OPS(ClassName) \
    EStream& operator<<(EStream& stream, ClassName* obj) { \
        return EStorable_StreamOut(stream, (EStorable*)obj); \
    } \
    EStream& operator>>(EStream& stream, ClassName*& obj) { \
        EStorable* tmp; \
        EStorable_StreamIn(stream, tmp); \
        obj = (ClassName*)tmp; \
        return stream; \
    } \
    EFile& operator>>(EFile& file, ClassName*& obj) { \
        EStorable* tmp; \
        EStorable_FileIn(file, tmp); \
        obj = (ClassName*)tmp; \
        return file; \
    }

// Macro for generating type info accessors
#define TYPE_INFO_OPS(ClassName, typeInfoVar) \
    class ClassName { \
    public: \
        const ETypeInfo* GetTypeInfo() const { return &typeInfoVar; } \
        static const ETypeInfo* GetTypeInfoStatic() { return &typeInfoVar; } \
        static void* operator new(unsigned int, void* p) { return p; } \
        static void operator delete(void* ptr) { \
            void* heap = EAHeap_GetCurrentHeap(); \
            EAHeap_Free(heap, ptr); \
        } \
        void SafeDelete(); \
    };

// Generate streaming operators for animation resource classes
class ERAnim;
class ERBinary;
class ERCharacter;
class ERDataset;
class ERSoundEvent;
class ERSoundTrackData;

STREAMING_OPS(ERAnim)
STREAMING_OPS(ERBinary)
STREAMING_OPS(ERCharacter)
STREAMING_OPS(ERDataset)
STREAMING_OPS(ERSoundEvent)
STREAMING_OPS(ERSoundTrackData)
