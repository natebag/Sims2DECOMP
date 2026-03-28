// misc_small_functions.cpp - Miscellaneous small functions from various obj files
// Part of the Sims 2 GC decompilation
//
// This file collects small functions (<=64 bytes) from many obj files that
// each have only a few small functions, to maximize coverage.

#include "types.h"
#include "stub_classes.h"

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
extern void* EAHeap_Alloc(void* heap, u32 size, int align);
extern void EAHeap_Free(void* heap, void* ptr);

// Placement new
inline void* operator new(unsigned int, void* ptr) { return ptr; }

//=============================================================================
// collisionmap.obj
//=============================================================================
namespace CollisionMapFuncs {
    // Intersection::Reset - clears intersection data
    // Address: 0x8039DB10, Size: 16
    struct Intersection {
        float m_dist;  // 0x00
        int m_flags;   // 0x04
        void Reset() {
            m_dist = 0.0f;
            m_flags = 0;
        }
    };
}

//=============================================================================
// boneparticle.obj - no small functions
//=============================================================================

//=============================================================================
// e_ngcaram.obj - ARAM (auxiliary RAM) manager
//=============================================================================
namespace ENgcAramFuncs {
    // ENgcAram::Close - close ARAM file
    // Address: 0x8036C40C, Size: 24
    // NON_MATCHING - sdata access
    void Close();

    // ENgcAram::AvailableMemory
    // Address: 0x8036C468, Size: 20
    // NON_MATCHING - sdata access
    int AvailableMemory();

    // AramRequestCallback
    // Address: 0x8036C510, Size: 12
    // NON_MATCHING - sdata flag set
    void AramRequestCallback(unsigned long);
}

//=============================================================================
// Resource type streaming operators - common pattern used by many obj files
// Each resource class has operator<<, operator>>(EStream&), operator>>(EFile&)
// plus type info accessors and New/Construct/Destruct/SafeDelete
//=============================================================================

// Forward declare all resource classes
class ERShader;
class ERTexture;
class ERFlash;
class ERFont;
class EResource;
class ERLevel;
class EBoundTreeNode;
class EREdithTreeSet;
class REffectsAttachment;
class REffectsEmitter;
class REffectsSequencer;
class RParticle;
class ERAmbientScore;

// Type info externs
extern ETypeInfo ERShader_typeInfo;
extern ETypeInfo ERTexture_typeInfo;
extern ETypeInfo ERFlash_typeInfo;
extern ETypeInfo ERFont_typeInfo;
extern ETypeInfo EResource_typeInfo;
extern ETypeInfo EBoundTreeNode_typeInfo;
extern ETypeInfo EREdithTreeSet_typeInfo;
extern ETypeInfo REffectsAttachment_typeInfo;
extern ETypeInfo REffectsEmitter_typeInfo;
extern ETypeInfo REffectsSequencer_typeInfo;
extern ETypeInfo RParticle_typeInfo;
extern ETypeInfo ERAmbientScore_typeInfo;

// Generate streaming operators for resource classes
#define IMPL_STREAM_OPS(ClassName) \
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

// These streaming operators appear across many .obj files
// Each set is 32 + 64 + 64 = 160 bytes of code
IMPL_STREAM_OPS(ERShader)
IMPL_STREAM_OPS(ERTexture)
IMPL_STREAM_OPS(ERFlash)
IMPL_STREAM_OPS(ERFont)
IMPL_STREAM_OPS(EResource)
IMPL_STREAM_OPS(EBoundTreeNode)
IMPL_STREAM_OPS(EREdithTreeSet)
IMPL_STREAM_OPS(REffectsAttachment)
IMPL_STREAM_OPS(REffectsEmitter)
IMPL_STREAM_OPS(REffectsSequencer)
IMPL_STREAM_OPS(RParticle)
IMPL_STREAM_OPS(ERAmbientScore)
