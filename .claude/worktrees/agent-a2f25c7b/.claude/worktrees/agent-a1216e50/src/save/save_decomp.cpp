// save_decomp.cpp - Sims 2 GameCube Save System Decompilation
// Comprehensive documentation of the memory card save/load architecture,
// derived from symbol analysis and disassembly of the original DOL.
//
// ==========================================================================
//  SAVE SYSTEM ARCHITECTURE OVERVIEW
// ==========================================================================
//
// The save system is a multi-layered architecture:
//
//   Layer 4 (UI):        SaveGameTarget / LoadGameTarget
//                          -- Dialog-driven save/load UI flow
//   Layer 3 (Game):      SimsMemCardWrap
//                          -- Game-facing save/load API with card checks
//   Layer 2 (File):      NghResFile
//                          -- .NGH save file format, section-based I/O
//                          -- MemoryCardCache -- in-RAM cache of card data
//   Layer 1 (Platform):  ENgcMemoryCard
//                          -- GameCube CARD library wrapper
//   Layer 0 (SDK):       CARDxxx functions (DolphinSDK)
//                          -- Raw memory card hardware access
//
// ==========================================================================
//  SECTION 1: HOW MEMORY CARD SAVE/LOAD WORKS
// ==========================================================================
//
// --------------------------------------------------------------------------
//  1.1 ENgcMemoryCard - GameCube Memory Card Driver
// --------------------------------------------------------------------------
//
// ENgcMemoryCard wraps the DolphinSDK CARD library for all low-level
// memory card operations. It derives from EMemoryCard (abstract base).
//
// Global instances:
//   _pMemoryCard  @ 0x804FF210 (4 bytes) -- ENgcMemoryCard* singleton
//   _ngcMemCard   @ 0x80500108 (8 bytes) -- static ENgcMemoryCard data
//   _ngcMemCardCardDead @ 0x804FF214      -- card error state flag
//
// ENgcMemoryCard vtable @ 0x8046C728 (312 bytes = 39 entries)
//   Inherits from EMemoryCard vtable @ 0x8046C860 (216 bytes = 27 entries)
//
// ENgcMemoryCard::InitMemoryCard() (0x80330020, 412 bytes):
//   1. Calls BeginCardOperation() to set the "in progress" flag
//   2. Calls CARDInit() (DolphinSDK) to initialize the CARD library
//   3. Calls CARDProbeEx(slot, ...) to detect card presence
//   4. Reads the card ID to check for recognized save data
//   5. Copies banner/icon data to a static buffer at 0x80440700
//      (2048 bytes of banner + icon pixel data for save file display)
//   6. If no card found, fills the banner buffer with default pattern (0x7F)
//   7. Calls CARDMount() and CARDGetResultCode() to mount the card
//
// The banner/icon data is a GC-format image (CI8 palette + indexed pixels)
// that the BIOS displays when browsing save files. SetComments() converts
// wchar_t strings to single-byte for the memory card comment fields (two
// 32-byte strings stored at 0x8043EEC0 and 0x8043EEE0).
//
// --------------------------------------------------------------------------
//  1.2 Synchronous I/O Operations
// --------------------------------------------------------------------------
//
// All save/load operations have synchronous ("S" suffix) and asynchronous
// ("A" suffix) variants. The GC build primarily uses synchronous operations.
//
// ENgcMemoryCard::SaveDataChunkS(char* filename, uint slot, uint offset,
//                                uint size, void* data)
//   @ 0x80330D80, 2184 bytes
//
// This is the largest and most complex save function. Pseudocode:
//
//   int ENgcMemoryCard::SaveDataChunkS(char* filename, uint slot,
//                                       uint offset, uint size, void* data) {
//       BeginCardOperation();
//       int memSize = 0, sectorSize = 0;
//
//       // Mount the card and get file info
//       int result = CARDProbeEx(slot, &memSize, &sectorSize);
//
//       // Map CARD error codes to internal error codes:
//       //   CARD_RESULT_READY (0)     -> EMC_OK (1)
//       //   CARD_RESULT_NOCARD (-3)   -> EMC_NO_CARD (-1)
//       //   CARD_RESULT_WRONGDEVICE   -> EMC_WRONG_DEVICE (-7)
//       //   CARD_RESULT_IOERROR (-5)  -> EMC_CARD_DEAD (-8), sets _ngcMemCardCardDead
//       //   CARD_RESULT_BROKEN (-6)   -> EMC_DAMAGED (-3)
//       //   CARD_RESULT_ENCODING (-13)-> EMC_CORRUPT (-6)
//       //   CARD_RESULT_NOPERM (-12)  -> EMC_ERROR (-4)
//       //   etc.
//
//       if (result != EMC_OK) {
//           EndCardOperation();
//           return result;
//       }
//
//       // Mount card
//       CARDMountAsync(slot, workArea, NULL);
//       // Wait for completion...
//       CARDGetResultCode(slot);
//
//       // Open the file
//       CARDOpen(slot, filename, &fileInfo);
//       if (result != CARD_RESULT_READY) { unmount; return error; }
//
//       // Write data at offset
//       CARDWrite(&fileInfo, data, size, offset);
//
//       // Close and unmount
//       CARDClose(&fileInfo);
//       CARDUnmount(slot);
//       EndCardOperation();
//       return EMC_OK;
//   }
//
// ENgcMemoryCard::LoadDataChunkS(char* filename, uint slot, uint offset,
//                                uint size, void* data)
//   @ 0x803301C4, 1496 bytes
//   Same flow as SaveDataChunkS but uses CARDRead instead of CARDWrite.
//
// ENgcMemoryCard::SaveDataS(char* filename, uint slot, uint size, void* data)
//   @ 0x80331608, 2052 bytes
//   Writes entire file (offset = 0). Also calls CheckAndWriteBannerAndIcon
//   to update the save file's banner/icon data.
//
// ENgcMemoryCard::LoadDataS(char* filename, uint slot, uint size, void* data)
//   @ 0x8033079C, 1492 bytes
//   Reads entire file from offset 0.
//
// ENgcMemoryCard::CreateFileS(char* filename, uint slot, uint size)
//   @ 0x80331E0C, 2216 bytes
//   1. CARDProbeEx() to check card
//   2. CARDMount() to mount
//   3. CARDCreate(slot, filename, size, &fileInfo) to create file
//   4. CARDSetStatus() to set file attributes
//   5. Writes initial banner/icon data
//   6. CARDClose() and CARDUnmount()
//
// ENgcMemoryCard::DeleteDataS(char* filename, uint slot)
//   @ 0x80332CE4, 776 bytes
//   1. CARDMount()
//   2. CARDOpen() to find file
//   3. CARDDelete() or CARDFastDelete() to remove
//   4. CARDUnmount()
//
// ENgcMemoryCard::FormatCardS(uint slot)
//   @ 0x80332FEC, 756 bytes
//   1. CARDFormat(slot) to erase all data
//   2. May reinitialize card state
//
// --------------------------------------------------------------------------
//  1.3 Card Status Queries
// --------------------------------------------------------------------------
//
// IsCardAvailable(uint slot)  @ 0x80333CD4 (364 bytes)
//   Probes the card slot and returns availability status.
//
// IsWrongDevice(uint slot)    @ 0x80333E40 (352 bytes)
//   Checks if the inserted card is a valid GC memory card (not e.g., SD adapter).
//
// AnyCardsPresent(int& slot)  @ 0x80333FA0 (160 bytes)
//   Checks both card slots (A and B) and returns which has a card.
//
// IsCardFormated(uint slot, bool& result) @ 0x80334040 (936 bytes)
//   Attempts to mount the card; if CARDMount returns CARD_RESULT_BROKEN,
//   the card needs formatting.
//
// DoesFileExist(char* filename, uint slot, bool& result) @ 0x80334898 (1184 bytes)
//   Mounts card, calls CARDOpen() to check for file existence.
//
// GetFreeSpaceS(uint slot, uint& freeBytes)  @ 0x80333318 (1132 bytes)
// GetFreeFilesS(uint slot, int& freeFiles)   @ 0x80333784 (1132 bytes)
//   Query available space and file slots on the card.
//
// IsSpaceAvailable(uint slot, uint requiredBytes, bool& result) @ 0x80333BF0 (108 bytes)
//   Convenience wrapper: checks if freeBytes >= requiredBytes.
//
// IsEnoughFiles(uint slot, uint requiredFiles, bool& result) @ 0x80333C5C (88 bytes)
//   Convenience wrapper: checks if freeFiles >= requiredFiles.
//
// GetSectorSize(int slot, uint& sectorSize) @ 0x80334D38 (356 bytes)
//   Returns the card's sector size (typically 8KB for GC memory cards).
//
// CheckAndWriteBannerAndIcon(char* filename, uint slot) @ 0x803326B4 (1584 bytes)
//   Updates the save file's banner and icon data (displayed by GC BIOS):
//   - Banner: 96x32 CI8 image
//   - Icon: 32x32 CI8 animation frames
//   - Written to the first sector of the save file
//
// Card operation locking:
//   BeginCardOperation() @ 0x8032FEE8 (16 bytes) -- sets flag
//   EndCardOperation()   @ 0x8032FEF8 (16 bytes) -- clears flag
//   IsCardOperationInProgress() @ 0x8032FED0 (24 bytes) -- checks flag
//   Prevents concurrent card access from multiple threads.
//
// ==========================================================================
//  SECTION 2: SimsMemCardWrap - Game Save/Load API
// ==========================================================================
//
// SimsMemCardWrap provides the game-level save/load interface. It wraps
// the low-level ENgcMemoryCard with game-specific logic: save validation,
// configuration files, house data, and multi-slot management.
//
// SimsMemCardWrap does NOT have its own instance allocation -- it operates
// through a platform-agnostic vtable interface stored at:
//   g_pMemCardInterface @ r13 - 0x98F0 (-26384)
//
// The vtable uses SN Systems calling convention:
//   Each entry = [s16 this-adjustor, u16 pad, u32 function_ptr]
//   So vtable entries are 8 bytes each, indexed by byte offset.
//
// SimsMemCardWrap layout (0xCC = 204 bytes):
//   +0x00: void**     vtable
//   +0x04: void*      m_nghResFile     (NghResFile* for current save)
//   +0x08-0xB7:       [internal state, card status cache, etc.]
//   +0xB8: s16        m_field_0B8      (card slot index?)
//   +0xC8: void*      m_field_0C8      (NghResFile pointer for writes)
//
// --------------------------------------------------------------------------
//  2.1 Initialization
// --------------------------------------------------------------------------
//
// SimsMemCardWrap::Init() (0x80074E60, 204 bytes):
//   1. Sets save file name via vtable[0xC0/0xC4] (SetName)
//   2. Configures max files (1) with 8192-byte blocks via vtable[0xB8/0xBC]
//   3. Queries total save game size via GetTotalSaveGameSize()
//   4. Prints debug info: "Save size: %d" and "Save blocks: %d"
//      (blocks = size >> 13, i.e., 8KB blocks)
//
// SimsMemCardWrap::InitPolling() (0x80074F2C, 80 bytes):
//   Starts the card polling system via vtable[0x88/0x8C].
//   Called once during startup to begin monitoring card insertion/removal.
//
// --------------------------------------------------------------------------
//  2.2 Card Status Checks
// --------------------------------------------------------------------------
//
// All status check functions follow the same pattern:
//   1. Load g_pMemCardInterface
//   2. Get vtable pointer
//   3. Extract this-adjustor and function pointer from vtable entry
//   4. Call the platform function with adjusted this pointer
//
// Function                                  Vtable Offset   Size
// IsCardInSlot(int slot, bool& result)      0xA0/0xA4       80B
// IsPolledCardInSlot(int slot, bool& result) 0x98/0x9C      80B
// IsWrongDevice(int slot, bool& result)     0xA8/0xAC       80B
// IsCardFormatted(int slot, bool& result)   0xB0/0xB4       64B
// IsCardCorrupted(int slot, bool& result)   (larger, 104B)
// IsCardDamaged(int slot, bool& result)     (larger, 100B)
// HasSavedGame(int slot, bool& result, int) 68B
// HasValidSavedGame(int slot, bool& r, int) 188B
// HasInvalidGame(int slot, bool& r, int)    80B
// HasSpaceForSave(int slot, bool& r, uint*) 144B
// CanBeUsed(int slot, bool& result, int)    312B
// IsDifferentCard(int slot, bool& result)   124B
//
// CanBeUsed() (0x80075394, 312 bytes) is the comprehensive card check:
//   Calls IsCardInSlot, IsWrongDevice, IsCardFormatted, IsCardCorrupted,
//   IsCardDamaged in sequence. Returns a combined status.
//
// HasValidSavedGame() (0x800751F8, 188 bytes):
//   Checks if a save game on the card is valid (not corrupted).
//   Calls NghResFile::IsSaveGameValid() to verify checksum integrity.
//
// --------------------------------------------------------------------------
//  2.3 Save Game Flow
// --------------------------------------------------------------------------
//
// SimsMemCardWrap::SaveGame(int slot, bool saveCache, bool overwrite, int id)
//   @ 0x800758BC, 280 bytes
//
// Pseudocode:
//   int SimsMemCardWrap::SaveGame(int slot, bool saveCache,
//                                  bool overwrite, int id) {
//       // Global state check
//       void* nghData = *(void**)(0x80475DCC);  // NghResFile data
//       if (nghData != NULL) {
//           void* buildAgent = *(void**)(0x80475B84);
//           if (*(int*)((char*)buildAgent + 0xE8) == 0) {
//               // Get the active lot/neighborhood
//               void* iface = g_pMemCardInterface;
//               // vtable[0x190/0x194] = GetActiveLot
//               void* lot = CallVtable(iface, 0x190);
//               void* ngh = *(void**)((char*)nghData + 0x54);
//               // Write lot data to NghResFile
//               WriteLotData(ngh);
//           }
//       }
//
//       // Begin actual save
//       void* iface = g_pMemCardInterface;
//       char* saveName = GetSaveName();  // r13 - 0x82C8
//       char* nghFile  = GetNghFile();   // r13 - 0x8344
//
//       // vtable[0x68/0x6C] = FormatDataForSave
//       FormatDataForSave(iface, saveName, nghFile);
//
//       // If auto-save check failed, skip checksums
//       if (*(int*)(0x80475C74) == 0 && !overwrite) {
//           goto skip_save;
//       }
//
//       // Check if we're in a valid state to save
//       int canSave = CheckSaveState();
//       if (!canSave) {
//           return 0;  // can't save right now
//       }
//
//       // Write save data to memory card
//       result = NghResFile::WriteToMemoryCard(saveName, (u8)slot);
//
//       if (result == 1) {  // success
//           // Save config file too
//           SaveConfigFile(slot);
//
//           // Update file descriptors
//           CheckForFileDescriptorLeaks(nghFile, slot);
//
//           // If requested, save the cache too
//           if (saveCache) {
//               result = SaveAllMemoryCardCache(slot);
//           }
//       }
//
//       return result;
//   }
//
// SimsMemCardWrap::SaveNewGame(int slot)
//   @ 0x800756DC, 176 bytes
//   Creates a new save file slot and writes initial game data.
//   Calls NghResFile::WriteToMemoryCard() after setting up new NghResFile.
//
// SimsMemCardWrap::SaveConfigFile(int slot)
//   @ 0x80075590, 76 bytes
//   Saves the options/preferences config to a separate section on the card.
//
// SimsMemCardWrap::SaveHouseAndGlobals(int slot, int houseId)
//   @ 0x80075ABC, 76 bytes
//   Saves just the current house data and global state (used for autosave).
//
// --------------------------------------------------------------------------
//  2.4 Load Game Flow
// --------------------------------------------------------------------------
//
// SimsMemCardWrap::LoadGame(int slot, int id)
//   @ 0x8007581C, 160 bytes
//
// Pseudocode:
//   int SimsMemCardWrap::LoadGame(int slot, int id) {
//       // First, load the memory card cache
//       int result = LoadCacheFromMemoryCard(slot);
//       if (result != 1) {
//           // Cache load failed, check file descriptors and abort
//           CheckForFileDescriptorLeaks(nghFile, slot);
//           return result;
//       }
//
//       // Get NghResFile pointer
//       NghResFile* nghRes = *(NghResFile**)(r13 - 0x8344);
//
//       // Validate the save game
//       StringBuffer filename;
//       StringBuffer_Init(&filename);
//
//       bool isValid = IsConfigFileValid(slot, filename);
//       if (!isValid) {
//           result = -4;  // EMC_INVALID_SAVE
//           goto cleanup;
//       }
//
//       // Read save data from memory card
//       char* saveName = *(char**)(r13 - 0x82C8);
//       result = NghResFile::ReadFromMemoryCard(saveName, (u8)slot);
//
//       if (result == 1) {
//           // Success -- apply loaded data to game state
//           void* gameState = *(void**)(0x80475F14);
//           ApplyLoadedState(gameState, &filename);
//       }
//
//   cleanup:
//       CheckForFileDescriptorLeaks(nghFile, slot);
//       return result;
//   }
//
// SimsMemCardWrap::PreloadGame(int slot)
//   @ 0x8007578C, 144 bytes
//   Reads just the save file header to check validity without loading all data.
//
// SimsMemCardWrap::LoadHouse(int slot)
//   @ 0x800759D4, 144 bytes
//   Loads house-specific data (lot, objects, sims in house).
//
// SimsMemCardWrap::ReloadHouseAndGlobals(int slot, int houseId)
//   @ 0x80075A64, 88 bytes
//   Reloads house and global data (used when entering a lot).
//
// SimsMemCardWrap::LoadConfigFile(int slot)
//   @ 0x80075548, 72 bytes
//   Loads options/preferences from the config section on the card.
//
// --------------------------------------------------------------------------
//  2.5 Preferences Management
// --------------------------------------------------------------------------
//
// PreservePrefs() / RestorePrefs() (40 bytes each):
//   Save and restore the OptionsRecon preferences to/from a backup buffer.
//   Used during save/load to prevent preferences from being overwritten
//   by loaded save data.
//
// IsFreeplayUnlocked() (16 bytes):
//   Returns OptionsRecon->m_freeplayUnlocked (offset 0x0C).
//   Freeplay mode is unlocked by completing specific goals.
//
// GetSpaceRequiredForSave() (32 bytes):
//   Returns the total bytes needed for a save file.
//   Delegates to GetTotalSaveGameSize() which sums all NghResFile sections.
//
// ==========================================================================
//  SECTION 3: SAVE FILE FORMAT (.NGH)
// ==========================================================================
//
// The .NGH format is a section-based binary format used by NghResFile.
// Each save file contains multiple sections for different game data.
//
// NghResFile layout (0x194 = 404 bytes):
//   +0x00: void**     vtable           (iResFile vtable)
//   +0x04: void*      m_resourceList   (list of resource handles)
//   +0x08: u16        m_numResources   (count of resources)
//   +0x0C: int        m_field_0C       (section state flags)
//   +0x10: void*      m_memoryCardCache (MemoryCardCache pointer)
//   +0x14: void*      m_field_14       (registry linked list head)
//   +0x18: int        m_field_18       (section count / state)
//   +0x20: int        m_hasCardChanged (dirty flag for card detection)
//   +0x24: int        m_sectionLoadedFlags (bitfield of loaded sections)
//   +0x28: void*      m_field_28       (file size or data pointer)
//   +0x134: u8        m_sourceType     (0=file, 1=card, 2=cache)
//   +0x138: int       m_neighborDataLoaded
//   +0x17C: int       m_characterDataLoaded
//   +0x180: int       m_byIndex_180    (resource index)
//   +0x184: u16       m_field_184      (save slot or version)
//   +0x188: int       m_field_188      (write state)
//   +0x18C: int       m_field_18C      (endianness flag)
//   +0x190: void*     m_cachePointer   (secondary cache)
//
// --------------------------------------------------------------------------
//  3.1 Section Layout
// --------------------------------------------------------------------------
//
// The save file is divided into sections, each identified by a SectionID:
//
// typedef enum NghResFile::SectionID {
//     SECTION_HOST      = 0,   // Host/global data (neighborhood state)
//     SECTION_BOTH      = 1,   // Shared data (both host and character)
//     SECTION_THUMB     = 2,   // Thumbnail images
//     SECTION_CHARACTER = 3,   // Character data (Sims, relationships)
//     SECTION_HOUSE_0   = 4,   // House lot 0
//     SECTION_HOUSE_1   = 5,   // House lot 1
//     // ... more house sections
// };
//
// Each section has a header (NghResFileSectionHeader) containing:
//   - Section type ID
//   - Compressed size
//   - Uncompressed size
//   - Checksum (for validation)
//
// The save file on disc has this structure:
//
//   +--------------------------+
//   | Banner + Icon Data       |  (first sector, ~8KB)
//   |  - 96x32 CI8 banner     |
//   |  - 32x32 CI8 icon       |
//   |  - Comment strings x2   |
//   +--------------------------+
//   | File Header              |
//   |  - Magic/version         |
//   |  - Section count         |
//   |  - Section offset table  |
//   +--------------------------+
//   | Section 0: Host          |  (neighborhood globals)
//   +--------------------------+
//   | Section 1: Both          |  (shared data)
//   +--------------------------+
//   | Section 2: Thumbnails    |  (CAS/lot thumbnails)
//   +--------------------------+
//   | Section 3: Characters    |  (Sim data)
//   +--------------------------+
//   | Section 4+: Houses       |  (per-lot data)
//   +--------------------------+
//   | Config Section           |  (options/preferences)
//   +--------------------------+
//   | Checksum                 |
//   +--------------------------+
//
// Total save size is reported by GetTotalSaveGameSize() @ 0x800D26E0.
// Number of sections by GetTotalNumberOfSaveGameSections() @ 0x800D26EC.
//
// --------------------------------------------------------------------------
//  3.2 Section I/O
// --------------------------------------------------------------------------
//
// NghResFile::WriteToMemoryCard(char* filename, u8 slot)
//   @ 0x800D786C, 452 bytes
//   Writes the entire save file to the memory card:
//   1. PrepareMemCardWrite() -- set up write state
//   2. For each section: serialize data and write via ENgcMemoryCard::SaveDataChunkS()
//   3. FinishMemCardWrite() -- write final checksums
//
// NghResFile::ReadFromMemoryCard(char* filename, u8 slot)
//   @ 0x800D85E4, 260 bytes
//   Reads the save file from the memory card:
//   1. Calls ENgcMemoryCard::LoadDataS() to read raw data
//   2. Parses section headers
//   3. Decompresses sections if compressed
//   4. Validates checksums
//
// NghResFile::WriteHostSection(void*) @ 0x8029521C (2248 bytes)
// NghResFile::WriteBothSection(void*) @ 0x80295AE4 (2228 bytes)
// NghResFile::WriteThumbSection(void*) @ 0x80296398 (2384 bytes)
//   Each section writer serializes specific game data categories.
//
// NghResFile::ReadHostSection(void*, bool) @ 0x80293FF0 (1628 bytes)
// NghResFile::ReadBothSection(void*, bool) @ 0x8029464C (984 bytes)
// NghResFile::ReadThumbSection(void*, bool) @ 0x80294DD8 (1092 bytes)
//   Each section reader deserializes and applies loaded data.
//
// NghResFile::DecompressSection(NghResFileSectionHeader*, bool)
//   @ 0x802933AC (1788 bytes)
//   Sections can be compressed. This function handles decompression.
//
// NghResFile::SaveHouseContents(uint houseId, void* data)
//   @ 0x8029807C (2412 bytes)
//   Serializes a single house lot: objects, Sim positions, build data.
//
// NghResFile::LoadHouseContents(uint houseId, void* data, bool validate)
//   @ 0x802974C0 (3004 bytes)
//   Deserializes a house lot and populates the game world.
//
// NghResFile::FlushHouseContents(uint houseId)
//   @ 0x802989E8 (452 bytes)
//   Frees loaded house data from memory.
//
// --------------------------------------------------------------------------
//  3.3 Save Validation
// --------------------------------------------------------------------------
//
// NghResFile::ValidateSaveGame(char* filename, int slot, bool fix)
//   @ 0x800D4BBC (320 bytes)
//   Reads checksums and validates the save file integrity.
//
// NghResFile::IsSaveGameValid(char* filename, int slot, bool& result)
//   @ 0x800D4CFC (352 bytes)
//   Returns whether the save file passes checksum validation.
//
// NghResFile::ReadChecksumFromCard(char* filename, int slot)
//   @ 0x802992F0 (456 bytes)
//   Reads just the checksum block from the card for quick validation.
//
// NghResFile::SetStoreChecksum(bool) / GetStoreChecksum()
//   Controls whether checksums are written during save operations.
//
// NghResFile::ResetChecksums() @ 0x8029CE38 (52 bytes)
//   Clears all stored checksums (used before full save).
//
// NghResFile::SwapFourByteNumber(uint*) / SwapTwoByteNumber(ushort*)
//   @ 0x8029C980 / 0x8029C924
//   Byte-swapping for cross-platform compatibility (the save format
//   supports both big-endian GC and little-endian PS2/Xbox).
//
// --------------------------------------------------------------------------
//  3.4 Registry System
// --------------------------------------------------------------------------
//
// NghResFile uses a registry for extensible section handling:
//
// NghResFile::RegisterSection(RegistryID id, void (*callback)(...))
//   @ 0x8029CA74 (220 bytes)
//   Registers a callback for loading/saving a specific section type.
//
// NghResFile::SectionLoadViaRegistry(RegistryID, SectionID, SaveRecord&)
//   @ 0x8029CD50 (144 bytes)
//   Dispatches section load to the registered callback.
//
// NghResFile::SectionSaveViaRegistry(RegistryID, SectionID, SaveRecord&)
//   @ 0x8029CC30 (144 bytes)
//   Dispatches section save to the registered callback.
//
// This allows game systems to register their own serialization code
// without NghResFile knowing the specifics of each data type.
//
// ObjectSaveTypeTable (at 0x800EC08C, 1528 bytes) is one such registered
// handler that serializes/deserializes game object data using a type table
// to map object IDs to their serialization format.
//
// ==========================================================================
//  SECTION 4: MemoryCardCache - RAM Cache for Card Data
// ==========================================================================
//
// MemoryCardCache (0x1C = 28 bytes) provides an in-RAM cache of memory card
// data, reducing the number of slow card I/O operations.
//
// MemoryCardCache layout:
//   +0x00: void**     vtable
//   +0x04: void**     m_sectionPtrs    (array of void*, one per section)
//   +0x08: void**     m_sectionData    (array of section data pointers)
//   +0x0C: void**     m_configPtrs     (array for config sections)
//   +0x10: int        m_isInitialized  (init flag)
//   +0x14: int        m_field_14       (dirty flag / version)
//   +0x18: NghLayout* m_layout         (pointer to layout descriptor)
//
// Init(NghLayout* layout) (0x800D2AB4, 312 bytes):
//   1. Checks if already initialized (returns 0 if so)
//   2. Frees any existing section data
//   3. Allocates section pointer array (4 bytes per section)
//   4. Initializes all section pointers to NULL
//   5. Stores the layout descriptor
//
// GetSection(NghLayout*, char* name, uint offset, uint size)
//   @ 0x800D2CC0 (220 bytes)
//   Returns a pointer to cached section data, loading from card if needed.
//
// PutSection(NghLayout*, char* name, uint offset, uint size)
//   @ 0x800D2D9C (224 bytes)
//   Writes section data to the cache.
//
// CacheNghSection(NghLayout*, char* name, uint offset, uint size)
//   @ 0x800D2E7C (320 bytes)
//   Copies a section from the NghResFile into the cache.
//
// SaveAllToMemoryCard(int slot) @ 0x800D333C (996 bytes)
//   Flushes all cached sections to the memory card.
//   Iterates through all sections, writing each dirty one.
//
// LoadCacheFromMemoryCard(int slot) @ 0x800D2FBC (36 bytes)
//   Entry point: delegates to the two-arg overload.
//
// LoadCacheFromMemoryCard(int slot, NghResFile* nghRes) @ 0x800D2FE0 (632 bytes)
//   Loads the entire cache from the memory card:
//   1. Read section directory from card
//   2. For each section: read data, allocate cache buffer, copy
//   3. Mark cache as initialized
//
// LoadConfigFromMemoryCard(int slot) @ 0x800D3258 (228 bytes)
//   Loads just the config/preferences section.
//
// GetConfig(char* key, uint size, int slot) @ 0x800D3720 (168 bytes)
//   Retrieves a named config value from the cache.
//
// PutConfig(char* key, uint size) @ 0x800D37C8 (152 bytes)
//   Stores a named config value in the cache.
//
// GetMemoryUsage(NghLayout*) @ 0x800D29DC (140 bytes)
//   Returns total cache memory usage.
//
// Destroy() @ 0x800D2BEC (212 bytes)
//   Frees all cached data and resets state.
//
// Global helper functions:
//   PutConfigInMemoryCardCache(char*, uint) @ 0x800D2514 (72 bytes)
//   GetConfigFromMemoryCardCache(char*, uint, int) @ 0x800D255C (80 bytes)
//   SaveAllMemoryCardCache(int slot) @ 0x800D25AC (64 bytes)
//   LoadCacheFromMemoryCard(int slot) @ 0x800D25EC (64 bytes)
//   GetTotalMemoryCardCacheSize() @ 0x800D2670 (48 bytes)
//   GetMemoryCardCacheSectionSize(uint) @ 0x800D26A0 (64 bytes)
//   GetTotalSaveGameSize() @ 0x800D26E0 (12 bytes)
//   GetTotalNumberOfSaveGameSections() @ 0x800D26EC (12 bytes)
//
// ==========================================================================
//  SECTION 5: SaveGameTarget / LoadGameTarget - UI Flow
// ==========================================================================
//
// SaveGameTarget and LoadGameTarget implement the save/load UI flow as
// dialog-driven state machines. They inherit from UIObjectBase and use
// the M2M (Menu-to-Menu) targeting system and UIDialog for prompts.
//
// --------------------------------------------------------------------------
//  5.1 SaveGameTarget
// --------------------------------------------------------------------------
//
// SaveGameTarget (0x168 = 360 bytes):
//   +0x00-0x7C:  [UIObjectBase fields, callbacks, dialog refs]
//   +0x80:       dialog flags
//   +0x84-0xD0:  dialog configuration fields
//   +0xD4-0x108: callback functor objects (CBMemberTranslator)
//   +0x10C:      int m_saveSlot
//   +0x110:      int m_playerNum
//   +0x114:      int m_device
//   +0x118:      int m_saveGameId
//   +0x11C:      int m_state      (state machine state)
//   +0x120:      int m_subState
//   +0x128-0x158: save progress fields
//   +0x15C:      int m_bgSaveResult
//   +0x160:      float m_timer1
//   +0x164:      float m_timer2
//
// SaveGameTarget::SaveGameTarget(M2MTarget*, int, int)
//   @ 0x8018CD18, 1888 bytes
//   Constructor: sets up all dialog callbacks and initial state.
//   Registers SelectionCallback, ZeroInputCallback for UI events.
//
// SaveGameTarget::Update() @ 0x8018D9BC (1064 bytes)
//   Per-frame state machine update. States include:
//     0: Initial -- begin memory card checks
//     1: Checking card
//     2: Card check complete -- decide next action
//     3: Waiting for format confirm
//     4: Formatting
//     5: Save confirm dialog
//     6: Saving (shows progress)
//     7: Save complete -- show success/failure
//     8: Done
//
// SaveGameTarget::PerformMemoryCardChecks() @ 0x8018DE10 (664 bytes)
//   Runs the full suite of card checks:
//   1. IsCardInSlot() -- card present?
//   2. IsWrongDevice() -- valid GC card?
//   3. IsCardFormatted() -- formatted?
//   4. IsCardCorrupted() -- data integrity?
//   5. IsCardDamaged() -- hardware OK?
//   6. HasSpaceForSave() -- enough room?
//   Based on results, spawns appropriate error dialog.
//
// SaveGameTarget::PerformSaveGame() @ 0x8018F944 (1452 bytes)
//   Actually performs the save:
//   1. Updates global state (world data, Sim data)
//   2. Calls SimsMemCardWrap::SaveGame() or SaveNewGame()
//   3. Handles success/failure with appropriate dialogs
//   4. Can run in background thread via BGCall_SaveGame()
//
// SaveGameTarget::BGExec_SaveGame(void*) @ 0x8018FF3C (80 bytes)
//   Background thread entry point for saving. Calls PerformSaveGame()
//   in a worker thread so the UI remains responsive during the write.
//
// Dialog spawning functions (each creates a UIDialog with localized text):
//   SpawnCheckingDialog()      @ 0x8018E0A8 (304 bytes)
//   SpawnFormatDecideDialog()  @ 0x8018E6DC (356 bytes)
//   SpawnFormatConfirmDialog() @ 0x8018E840 (348 bytes)
//   SpawnFormattingDialog()    @ 0x8018E99C (232 bytes)
//   SpawnFormatCancelDialog()  @ 0x8018EA84 (348 bytes)
//   SpawnFormatFailDialog()    @ 0x8018EBE0 (348 bytes)
//   SpawnFormatSuccessDialog() @ 0x8018ED3C (304 bytes)
//   SpawnNoSpaceDialog(NoSpaceType) @ 0x8018EE6C (612 bytes)
//   SpawnOverwriteDialog()     @ 0x8018F0D0 (420 bytes)
//   SpawnSaveConfirmDialog()   @ 0x8018F274 (424 bytes)
//   SpawnSavingDialog()        @ 0x8018F41C (296 bytes)
//   SpawnSaveSucceededDialog() @ 0x8018F544 (284 bytes)
//   SpawnSaveFailedDialog()    @ 0x8018F660 (376 bytes)
//   SpawnMemCardRemovedDialog()@ 0x8018F7D8 (364 bytes)
//   SpawnWrongDeviceDialog()   @ 0x8018E3A4 (356 bytes)
//   SpawnCardDamagedDialog()   @ 0x8018E508 (468 bytes)
//   SpawnCardCorruptDialog()   @ 0x8018E1D8 (460 bytes)
//
// --------------------------------------------------------------------------
//  5.2 LoadGameTarget
// --------------------------------------------------------------------------
//
// LoadGameTarget (0x14C = 332 bytes):
//   Same base structure as SaveGameTarget but with load-specific fields:
//   +0x10C: int m_loadSlot
//   +0x124: int m_selectedSaveIdx  (which save slot the player picked)
//   +0x128: int m_loadState
//   +0x12B: u8  m_loadFlags
//   +0x130: int m_loadProgress
//   +0x134: int m_loadResult
//   +0x144: int m_performLoadResult
//   +0x148: int m_bgLoadResult
//
// LoadGameTarget::LoadGameTarget(M2MTarget*, int, int)
//   @ 0x80189AD0, 1840 bytes
//   Constructor: identical pattern to SaveGameTarget.
//
// LoadGameTarget::Update() @ 0x8018A708 (992 bytes)
//   Per-frame state machine:
//     0: Initial -- begin card checks
//     1: Checking card
//     2: Card check complete
//     3: Show save slot selection
//     4: Load confirmation
//     5: Loading (shows progress)
//     6: Load complete
//     7: Done
//
// LoadGameTarget::PerformMemoryCardChecks() @ 0x8018AAF4 (580 bytes)
//   Same checks as SaveGameTarget, plus:
//   - HasSavedGame() -- any saves present?
//   - HasValidSavedGame() -- saves are valid?
//
// LoadGameTarget::PerformLoad() @ 0x8018AD38 (348 bytes)
//   1. Calls SimsMemCardWrap::LoadGame(slot, id)
//   2. Processes the loaded data
//   3. Updates game state
//
// LoadGameTarget::BackgroundPerformLoad() @ 0x8018CA90 (432 bytes)
//   Runs PerformLoad() in a background thread.
//   Uses BGCall_PerformLoad() / BGExec_PerformLoad() pattern.
//
// LoadGameTarget::ImportLoad / ImportSave / ImportSaveComplete
//   @ 0x8018AAF0 / 0x8018CCBC / 0x8018CCC0
//   Callback hooks for the registry system to process individual sections
//   as they are loaded from the save file.
//
// --------------------------------------------------------------------------
//  5.3 MU (Memory Unit) State Machines
// --------------------------------------------------------------------------
//
// The MUStates classes implement sub-states for save/load operations:
//
// MUStatesLoadGame (vtable @ 0x8045DD10):
//   Update(float dt) @ 0x80091B88 (1156 bytes) -- main load state machine
//   Manages the NghResFile load process step by step.
//
// MUStatesLoadHouse (vtable @ 0x8045DCC8):
//   Update(float dt) @ 0x8009201C (352 bytes) -- house-specific loading
//
// MUStatesAutoSaveNew (vtable @ 0x8045DC80):
//   Update(float dt) @ 0x8009217C (352 bytes) -- new save autosave
//
// MUStatesSaveNewGame (vtable @ 0x8045DC38):
//   Update(float dt) @ 0x80092340 (1608 bytes) -- new save flow
//   Largest save state machine: handles create file, write data, verify.
//
// MUStatesAutoSaveExisting (vtable @ 0x8045DBF0):
//   Update(float dt) @ 0x80092998 (368 bytes) -- existing save autosave
//
// MUStatesSaveExistingGame (vtable @ 0x8045DBA8):
//   Update(float dt) @ 0x80092B18 (556 bytes) -- overwrite existing save
//
// MUStatesLoadConfig (vtable @ 0x8045DAD0):
//   Update(float dt) @ 0x80093170 (64 bytes) -- load config only
//
// Each MUState has GetWrapper() returning the SimsMemCardWrap instance,
// and constructors taking an int parameter (the player/slot index).
//
// TheSimsMemCardCheckState (vtable @ 0x8045E3D0):
//   Boot-time memory card check that runs before the main menu.
//   Startup() @ 0x80097090 (88 bytes) -- initiates card detection
//   Draw(ERC*) @ 0x800970F0 (216 bytes) -- renders "checking card" screen
//
// ==========================================================================
//  SAVE SYSTEM FUNCTION INDEX
// ==========================================================================
//
// SimsMemCardWrap (26 functions, ~4.5KB total):
//   0x80074E60  Init()                              204B  system init
//   0x80074F2C  InitPolling()                        80B  start polling
//   0x80074F7C  PollCards(bool)                      60B
//   0x80074FB8  IsPolledCardInSlot(int, bool&)       80B
//   0x80075008  IsCardInSlot(int, bool&)             80B
//   0x80075058  IsWrongDevice(int, bool&)            80B
//   0x800750A8  IsCardFormatted(int, bool&)          64B
//   0x800750E8  IsCardCorrupted(int, bool&)         104B
//   0x80075150  IsCardDamaged(int, bool&)           100B
//   0x800751B4  HasSavedGame(int, bool&, int)        68B
//   0x800751F8  HasValidSavedGame(int, bool&, int)  188B
//   0x800752B4  HasInvalidGame(int, bool&, int)      80B
//   0x80075304  HasSpaceForSave(int, bool&, uint*)  144B
//   0x80075394  CanBeUsed(int, bool&, int)          312B
//   0x800754CC  IsDifferentCard(int, bool&)         124B
//   0x80075548  LoadConfigFile(int)                  72B
//   0x80075590  SaveConfigFile(int)                  76B
//   0x800755DC  PreservePrefs()                      40B
//   0x80075604  RestorePrefs()                       40B
//   0x8007562C  IsFreeplayUnlocked()                 16B
//   0x8007563C  FormatCard(int)                      60B
//   0x80075678  DeleteFile(int, int)                 64B
//   0x800756B8  XboxOnNoMemory()                      4B  stub
//   0x800756BC  GetSpaceRequiredForSave()            32B
//   0x800756DC  SaveNewGame(int)                    176B
//   0x8007578C  PreloadGame(int)                    144B
//   0x8007581C  LoadGame(int, int)                  160B
//   0x800758BC  SaveGame(int, bool, bool, int)      280B
//   0x800759D4  LoadHouse(int)                      144B
//   0x80075A64  ReloadHouseAndGlobals(int, int)      88B
//   0x80075ABC  SaveHouseAndGlobals(int, int)        76B
//
// ENgcMemoryCard (35 functions, ~24KB total):
//   0x8032FE7C  ENgcMemoryCard()                     32B  ctor
//   0x8032FE9C  ~ENgcMemoryCard()                    52B  dtor
//   0x8032FED0  IsCardOperationInProgress()          24B
//   0x8032FEE8  BeginCardOperation()                 16B
//   0x8032FEF8  EndCardOperation()                   16B
//   0x8032FF08  SetComments(wchar_t*, wchar_t*)     280B
//   0x80330020  InitMemoryCard()                    412B
//   0x803301BC  UnInitMemoryCard()                    8B
//   0x803301C4  LoadDataChunkS(...)                1496B
//   0x8033079C  LoadDataS(...)                     1492B
//   0x80330D80  SaveDataChunkS(...)                2184B
//   0x80331608  SaveDataS(...)                     2052B
//   0x80331E0C  CreateFileS(...)                   2216B
//   0x803326B4  CheckAndWriteBannerAndIcon(...)    1584B
//   0x80332CE4  DeleteDataS(...)                    776B
//   0x80332FEC  FormatCardS(uint)                   756B
//   0x80333318  GetFreeSpaceS(uint, uint&)         1132B
//   0x80333784  GetFreeFilesS(uint, int&)          1132B
//   0x80333BF0  IsSpaceAvailable(uint, uint, bool&) 108B
//   0x80333C5C  IsEnoughFiles(uint, uint, bool&)     88B
//   0x80333CD4  IsCardAvailable(uint)               364B
//   0x80333E40  IsWrongDevice(uint)                 352B
//   0x80333FA0  AnyCardsPresent(int&)               160B
//   0x80334040  IsCardFormated(uint, bool&)          936B
//   0x803343E8  GetFileList(uint, char*, uint, ...) 1184B
//   0x80334898  DoesFileExist(char*, uint, bool&)  1184B
//   0x80334D38  GetSectorSize(int, uint&)           356B
//
// NghResFile (58 functions, ~40KB+ total):
//   0x800D786C  WriteToMemoryCard(char*, u8)        452B
//   0x800D85E4  ReadFromMemoryCard(char*, u8)       260B
//   0x800D4BBC  ValidateSaveGame(char*, int, bool)  320B
//   0x800D4CFC  IsSaveGameValid(char*, int, bool&)  352B
//   0x802974C0  LoadHouseContents(uint, void*, bool) 3004B
//   0x8029807C  SaveHouseContents(uint, void*)      2412B
//   0x802989E8  FlushHouseContents(uint)             452B
//   0x8029A4D0  ReadFromFile(char*)                 1496B
//   0x8029B23C  CopyDefaultNghToCache(char*)        2372B
//   0x8029BB80  CopyDefaultNghToCard(char*, char*, u8) 1360B
//   And 48 more helper functions...
//
// MemoryCardCache (15 functions, ~4KB total):
//   0x800D2AB4  Init(NghLayout*)                    312B
//   0x800D2BEC  Destroy()                           212B
//   0x800D2CC0  GetSection(NghLayout*, ...)          220B
//   0x800D2D9C  PutSection(NghLayout*, ...)          224B
//   0x800D2E7C  CacheNghSection(NghLayout*, ...)     320B
//   0x800D2FBC  LoadCacheFromMemoryCard(int)          36B
//   0x800D2FE0  LoadCacheFromMemoryCard(int, NghResFile*) 632B
//   0x800D3258  LoadConfigFromMemoryCard(int)        228B
//   0x800D333C  SaveAllToMemoryCard(int)             996B
//   0x800D3720  GetConfig(char*, uint, int)          168B
//   0x800D37C8  PutConfig(char*, uint)               152B
//   0x800D29DC  GetMemoryUsage(NghLayout*)           140B
//   0x800D2A68  GetSubSectionMemoryUsage(...)         76B
