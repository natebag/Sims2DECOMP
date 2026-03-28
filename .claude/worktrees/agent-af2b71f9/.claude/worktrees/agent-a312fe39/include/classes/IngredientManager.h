#ifndef INGREDIENTMANAGER_H
#define INGREDIENTMANAGER_H

#include "types.h"

// IngredientManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 3 known fields (3 named), 16 methods

class IngredientManager {
public:
    // Constructors / Destructors
    IngredientManager(void)  // 0x800E0DC0
    ~IngredientManager(void);  // 0x800E0ED0

    // Methods
    /* ? */ GetIngredientTypes(IngredientType **, unsigned int);  // 0x800E0F20 (408B)
    /* ? */ GetIngredientsByType(short, Ingredient **, unsigned int);  // 0x800E10B8 (480B)
    /* ? */ GetIngredients(Ingredient **, unsigned int);  // 0x800E1298 (312B)
    /* ? */ GetIngredient(short);  // 0x800E174C (212B)
    /* ? */ GetFoodResult(short);  // 0x800E1820 (232B)
    void MixIngredients(short, short, short, short);  // 0x800E1908 (464B)

    // ---- Field Layout (from assembly analysis) ----
    s16 m_foodResult;  // 0x000 [R/W] (GetFoodResult, GetIngredient, GetIngredientTypes, ...)
    u8 _pad_002[2];  // 0x002
    u32 m_foodResult_004;  // 0x004 [R] (GetFoodResult, GetIngredient, GetIngredientTypes, ...)
    u8 _pad_008[4];  // 0x008
    u32 m_foodResult_00C;  // 0x00C [R] (GetFoodResult, GetIngredient, GetIngredientTypes, ...)
};

#endif // INGREDIENTMANAGER_H
