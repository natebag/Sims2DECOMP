// bbi_stubs.cpp - Stub implementations for Bbi
// Auto-generated from symbols.json - 44 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x8007AA68 | 48 bytes
BBI::InventoryItem::InventoryItem(void) { }

// 0x8007AA98 | 52 bytes
BBI::InventoryItem::~InventoryItem(void) { }

// 0x8007AACC | 136 bytes
void BBI::InventoryItem::SetItemCategory(int) { }

// 0x8007AB54 | 12 bytes
void BBI::InventoryItem::GetItemCategory(void) const { }

// 0x8007AB60 | 136 bytes
void BBI::InventoryItem::SetItemSubcategory(int) { }

// 0x8007ABE8 | 12 bytes
void BBI::InventoryItem::GetItemSubcategory(void) const { }

// 0x8007ABF4 | 200 bytes
void BBI::InventoryItem::DoStream(ReconBuffer *, int) { }

// 0x8007ACBC | 8 bytes
void BBI::InventoryItem::GetItemGuid(void) const { }

// 0x8007ACC4 | 52 bytes
void BBI::InventoryItem::SetItemGuid(int) { }

// 0x8007ACF8 | 80 bytes
void BBI::InventoryItem::SetItemCount(int) { }

// 0x8007AD48 | 12 bytes
void BBI::InventoryItem::GetItemCount(void) const { }

// 0x8007AD54 | 52 bytes
void BBI::InventoryItem::SetItemColorIndex(unsigned char) { }

// 0x8007AD88 | 8 bytes
void BBI::InventoryItem::GetItemColorIndex(void) const { }

// 0x8007AD90 | 60 bytes
void BBI::InventoryItem::CopyTo(int *) const { }

// 0x8007ADCC | 32 bytes
BBI::InventoryItems::InventoryItems(void) { }

// 0x8007ADEC | 64 bytes
BBI::InventoryItems::~InventoryItems(void) { }

// 0x8007AE2C | 308 bytes
void BBI::InventoryItems::CanAddItemsByGuid(int, int, unsigned char) const { }

// 0x8007AF60 | 316 bytes
void BBI::InventoryItems::AddItemsByGuid(int, int, unsigned char) { }

// 0x8007B09C | 120 bytes
void BBI::InventoryItems::RemoveItemsByGuid(int, int, unsigned char) { }

// 0x8007B114 | 440 bytes
void BBI::InventoryItems::DeleteItem(int *) { }

// 0x8007B2CC | 128 bytes
void BBI::InventoryItems::Clear(void) { }

// 0x8007B34C | 96 bytes
void BBI::InventoryItems::GetItemCount(void) const { }

// 0x8007B3AC | 120 bytes
void BBI::InventoryItems::CountItemsByGuid(int) const { }

// 0x8007B424 | 140 bytes
void BBI::InventoryItems::CountItemsByCategory(int) const { }

// 0x8007B4B0 | 160 bytes
void BBI::InventoryItems::GetItemsByCategory(int, int **, unsigned int) const { }

// 0x8007B550 | 68 bytes
void BBI::InventoryItems::GetItemByGuid(int, unsigned char) const { }

// 0x8007B594 | 116 bytes
void BBI::InventoryItems::IsItemInInventory(int) const { }

// 0x8007B608 | 8 bytes
void BBI::InventoryItems::GetContainerSize(void) const { }

// 0x8007B610 | 144 bytes
void BBI::InventoryItems::GetItemAtIndex(int) const { }

// 0x8007B6A0 | 144 bytes
void BBI::InventoryItems::CanAddBuilderItem(int, int, int) const { }

// 0x8007B730 | 204 bytes
void BBI::InventoryItems::AddBuilderItem(int, int, int) { }

// 0x8007B7FC | 116 bytes
void BBI::InventoryItems::RemoveBuilderItem(int, int, int) { }

// 0x8007B870 | 68 bytes
void BBI::InventoryItems::GetBuilderItem(int, int) const { }

// 0x8007B8B4 | 144 bytes
void BBI::InventoryItems::GetBuilderItemIndex(int, int) const { }

// 0x8007B944 | 184 bytes
void BBI::InventoryItems::DoStreamWrite(ReconBuffer *, int) { }

// 0x8007B9FC | 496 bytes
void BBI::InventoryItems::DoStreamRead(ReconBuffer *, int) { }

// 0x8007BBEC | 296 bytes
void BBI::InventoryItems::DoStream(ReconBuffer *, int) { }

// 0x8007BD14 | 68 bytes
void BBI::InventoryItems::GetNewItemIndex(void) const { }

// 0x8007BD58 | 140 bytes
void BBI::InventoryItems::GetItemIndexByGuid(int, unsigned char) const { }

// 0x8007BDE4 | 92 bytes
void BBI::InventoryItems::CreateNewItemFromGuid(int) const { }

// 0x8007BE40 | 116 bytes
void BBI::InventoryItems::CreateNewBuilderItem(int, int) const { }

// 0x8007BEB4 | 216 bytes
void BBI::InventoryItems::CreateNewItemFromSelector(ObjSelector *) const { }

// 0x8007BF8C | 172 bytes
void BBI::InventoryItems::GetItemCategoryFromObjDefinition(ObjDefinition *) { }

// 0x8023C32C | 32 bytes
BBI::InventoryTest::~InventoryTest(void) { }
