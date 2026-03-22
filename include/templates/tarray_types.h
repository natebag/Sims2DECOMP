#ifndef TARRAY_TYPES_H
#define TARRAY_TYPES_H

// Forward declarations for all types used as TArray template parameters
// Auto-generated from symbol map

#include "types.h"

// Forward class/struct declarations
struct BSplineVolume;
struct EAnimEvent;
struct EAnimNodeDataPos;
struct EAnimNote;
struct EBound3;
struct ECharacterNode;
struct EFontPage;
struct EILight;
struct ENCamera;
struct ENCameraPoint;
struct ENDummy;
struct ENDummyPoint;
struct ENLattice;
struct ENLatticePoints;
struct ERModel;
struct ESMSStrip;
struct EString;
struct EString2;
struct ESubModel;
struct ESubModelShader;
struct EVec3;
struct SimsLightInfo;
struct SndEvtHitPatch;

// EFileSystem nested type
struct EFileSystem { struct FileCreator; };

// Stream class
class EStream;

// Allocator types
struct TArrayDefaultAllocator;
struct TArrayERModelAllocator;
struct TArrayERAnimAllocator;
struct TArrayERCharacterAllocator;
struct TArrayERSoundEventAllocator;

// TArray template class
template <typename T, typename Allocator>
class TArray {
public:
    T* m_data;
    int m_size;
    int m_capacity;

    TArray(void);
    TArray(TArray &other);
    ~TArray(void);

    void Init(void);
    void Destruct(T *items, int count);
    void Construct(T *items, int count);
    void Copy(T *dst, T *src, int count);
    void CopyReverse(T *dst, T *src, int count);
    void SetSize(int size, int grow);
    void Deallocate(void);
    void Add(T &item);
    void Insert(T *pos, int index, int count);
    TArray &operator=(TArray &other);
    void DeleteAll(void);
    void FreeAll(void);
    void SafeDeleteAll(void);
};

#endif // TARRAY_TYPES_H