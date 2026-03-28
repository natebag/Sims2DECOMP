#ifndef EDATASETMANAGER_H
#define EDATASETMANAGER_H

#include "types.h"

// EDatasetManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0xD24 (3364 bytes)
// 3 known fields (0 named), 46 methods

class EDatasetManager {
public:
    // Constructors / Destructors
    EDatasetManager(void)  // 0x80888A48
    ~EDatasetManager(void);  // 0x8088895C

    // Methods
    void AddRef(char *, EFile *, int);  // 0x80888308 (324B)
    void AddRef(unsigned int, EFile *, int);  // 0x80888ACC (92B)
    void DelRef(char *, EResourceManager::DelRefMode);  // 0x80888C08 (72B)
    void DelRef(unsigned int, EResourceManager::DelRefMode);  // 0x80888BC0 (72B)
    void DelRef(EResource *, EResourceManager::DelRefMode);  // 0x808885DC (96B)
    /* ? */ GetRef(unsigned int);  // 0x80888838 (100B)
    void AddRefAsyncIfNotLoaded(char *);  // 0x80888514 (200B)
    /* ? */ GetRef(char *);  // 0x808887E0 (88B)
    void AddRefAsync(char *);  // 0x808884A4 (112B)
    void PreloadResource(char *);  // 0x80888770 (112B)
    void AddRefAsync(unsigned int);  // 0x80888B28 (76B)
    void SetLoadProgress(float);  // 0x80888744 (44B)
    void ManageDasFile(char *);  // 0x80888120 (488B)
    void AddRef(EResource *);  // 0x8088844C (88B)
    /* ? */ GetLoadProgress(void);  // 0x8088863C (44B)
    void AllocateAndLoadResource(EFile *, unsigned int, unsigned int);  // 0x80888668 (220B)
    void SetLoadingEnabled(bool);  // 0x8088889C (44B)
    /* ? */ GetLoadingEnabled(void);  // 0x808888C8 (44B)
    void OutputDatasets(bool);  // 0x808888F4 (104B)
    bool CanCache(EResource *);  // 0x80888AA0 (44B)
    void PreloadResource(unsigned int);  // 0x80888B74 (76B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [W] (AllocateAndLoadResource)
    u8 _pad_00C[0xD10];  // 0x00C
    u32 m_field_D1C;  // 0xD1C [R/W] (AddRefAsyncIfNotLoaded, EDatasetManager)
    f32 m_field_D20;  // 0xD20 [W] (EDatasetManager)
};

#endif // EDATASETMANAGER_H
