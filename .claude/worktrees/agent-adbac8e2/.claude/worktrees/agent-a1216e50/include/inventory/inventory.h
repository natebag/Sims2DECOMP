#ifndef INVENTORY_H
#define INVENTORY_H

#include "types.h"

// Forward declarations
class ReconBuffer;
class ObjDefinition;
class ObjSelector;

namespace BBI {

// ============================================================================
// InventoryItem - Single item in the Sims 2 inventory system
// Object file: inventory.obj
//
// Memory layout (12 bytes):
//   +0x00: s8  m_category      (eItemCategory)
//   +0x01: s8  m_count         (clamped 0-99)
//   +0x02: u8  m_colorIndex
//   +0x03: s8  m_subcategory   (eItemSubcategory)
//   +0x04: int m_guid
//   +0x08: vtable pointer (4 bytes)
// ============================================================================
class InventoryItem {
public:
    enum eItemCategory {
        // Values determined from usage context
    };

    enum eItemSubcategory {
        // Values determined from usage context
    };

    // +0x00
    s8 m_category;
    // +0x01
    s8 m_count;
    // +0x02
    u8 m_colorIndex;
    // +0x03
    s8 m_subcategory;
    // +0x04
    int m_guid;

    InventoryItem();
    virtual ~InventoryItem();

    void SetItemCategory(eItemCategory category);
    eItemCategory GetItemCategory() const;

    void SetItemSubcategory(eItemSubcategory subcategory);
    eItemSubcategory GetItemSubcategory() const;

    int GetItemGuid() const;
    void SetItemGuid(int guid);

    void SetItemCount(int count);
    int GetItemCount() const;

    void SetItemColorIndex(unsigned char colorIndex);
    unsigned char GetItemColorIndex() const;

    virtual int CopyTo(InventoryItem* dest) const;
    virtual void DoStream(ReconBuffer* buffer, int version);
};

// ============================================================================
// InventoryItems - Container of 36 inventory item pointers
// Object file: inventory.obj
//
// Memory layout (144 bytes):
//   +0x00: InventoryItem* m_items[36]  (array of 36 pointers)
// ============================================================================
class InventoryItems {
public:
    static const int kContainerSize = 36;

    InventoryItem* m_items[kContainerSize];

    InventoryItems();
    ~InventoryItems();

    void Clear();
    int GetContainerSize() const;
    InventoryItem* GetItemAtIndex(int index) const;
    int GetItemCount() const;

    int CanAddItemsByGuid(int guid, int count, unsigned char colorIndex) const;
    void AddItemsByGuid(int guid, int count, unsigned char colorIndex);
    void RemoveItemsByGuid(int guid, int count, unsigned char colorIndex);
    void DeleteItem(InventoryItem* item);

    InventoryItem* GetItemByGuid(int guid, unsigned char colorIndex) const;
    int GetNewItemIndex() const;
    InventoryItem* CreateNewItemFromGuid(int guid) const;
    int GetItemIndexByGuid(int guid, unsigned char colorIndex) const;

    int CountItemsByCategory(InventoryItem::eItemCategory category) const;
    int CountItemsByGuid(int guid) const;
    int GetItemsByCategory(InventoryItem::eItemCategory category, InventoryItem** items, unsigned int maxItems) const;
    int IsItemInInventory(int guid) const;

    int CanAddBuilderItem(InventoryItem::eItemSubcategory subcategory, int guid, int count) const;
    InventoryItem* GetBuilderItem(InventoryItem::eItemSubcategory subcategory, int guid) const;
    void AddBuilderItem(InventoryItem::eItemSubcategory subcategory, int guid, int count);
    InventoryItem* CreateNewBuilderItem(InventoryItem::eItemSubcategory subcategory, int guid) const;
    void RemoveBuilderItem(InventoryItem::eItemSubcategory subcategory, int guid, int count);
    int GetBuilderItemIndex(InventoryItem::eItemSubcategory subcategory, int guid) const;

    void DoStreamWrite(ReconBuffer* buffer, int version);
    void DoStreamRead(ReconBuffer* buffer, int version);
    void DoStream(ReconBuffer* buffer, int version);

    InventoryItem* CreateNewItemFromSelector(ObjSelector* selector) const;

    static InventoryItem::eItemCategory GetItemCategoryFromObjDefinition(ObjDefinition* def);
};

} // namespace BBI

// ============================================================================
// IngredientManager - Manages food ingredients and recipes
// Object file: inventory.obj
// ============================================================================

// Forward declarations
struct IngredientType;
struct Ingredient;
struct FoodResult;

class IngredientManager {
public:
    IngredientManager();
    ~IngredientManager();

    int GetIngredientTypes(IngredientType** types, unsigned int maxTypes) const;
    int GetIngredientsByType(short type, Ingredient** ingredients, unsigned int maxIngredients) const;
    int GetIngredients(Ingredient** ingredients, unsigned int maxIngredients) const;
    Ingredient* GetIngredient(short id) const;
    FoodResult* GetFoodResult(short id) const;
    short MixIngredients(short a, short b, short c, short d) const;
};

// Global function to get the singleton IngredientManager
IngredientManager* GetIngredientManager();

// Comparison function for sorting
int less_int16_t(void* a, void* b);

// Helper functions
void get_ingredient_type_array(FoodResult* result, short* types);
void make_ingredient_type_array(short a, short b, short c, short d, short* types);

#endif // INVENTORY_H
