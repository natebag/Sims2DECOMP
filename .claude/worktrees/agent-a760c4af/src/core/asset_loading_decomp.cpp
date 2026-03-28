// asset_loading_decomp.cpp - Asset Loading Pipeline Decompilation
// Part of the Sims 2 GC decompilation
//
// This file documents and decompiles the complete asset loading pipeline:
//   DVD → ArcFileInfo → EResourceManager → EResourceLoaderImpl → EResource
//   DVD → NghResFile (neighborhood save/load)
//   DVD → IFFResFile2 (IFF container parsing)
//   ChainResFile (multi-file resource chaining)
//
// Original source files (from build log):
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\E3\src\eresource.cpp
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\E3\src\eresourcemanager.cpp
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\E3\src\eresourceloaderimpl.cpp
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\E3\src\nghresfile.cpp
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\E3\src\iffresfile2.cpp
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\E3\src\chainresfile.cpp
//   c:\BuildAgent\cm3-build25-NGC\CMBuild\E3\src\arcfileinfo.cpp

#include "types.h"

//=============================================================================
// FORWARD DECLARATIONS
//=============================================================================
class iResFile;
class EFile;
class EResource;
class EResourceManager;
class EResourceLoaderImpl;
class EResourceMap;
class EResPrefetch;
class EResPrefetchFile;
class IFFResFile2;
class IFFResNode;
class IFFResMap;
class IFFResList;
class IFFHeader;
class NghResFile;
class ChainResFile;
class ArcFileInfo;
class ArcCopier;
class MemFile;
struct StringBuffer;
struct NghResFileSectionHeader;
struct NghResFileWriteInfo;
struct NghLayout;
class MemoryCardCache;
struct EResLoadCmd;
struct EResLoadCmdResult;
struct EScratchBuffUser;
struct EPrefetchMsg;
namespace Memory { class HandleNode; }


//=============================================================================
//
//  PART 1: .ARC ARCHIVE FORMAT DOCUMENTATION
//
//=============================================================================
//
// The Sims 2 GC stores all game assets in .arc archive files on the DVD.
// Located at: files/DATA/*.arc (approximately 1.2GB total)
//
// === .ARC Archive Format ===
//
// The .arc format is a simple indexed archive used by the EA E3 engine.
// It is NOT the same as typical Nintendo .arc files.
//
// The EResourceManager manages access to .arc files via ArcFileInfo.
// Each EResourceManager instance corresponds to one resource category
// (textures, models, sounds, etc.) and may have its own .arc file.
//
// Archive Structure (from ArcFileInfo::Validate disassembly at 0x803217D8):
//
//   1. The archive path is constructed from a base path + resource name + ".arc"
//      (see EResourceManager::CalcPath at 0x80325AD8)
//
//   2. ArcFileInfo::Validate opens the archive via the EResourceLoaderImpl
//      file system and reads a 1024-byte header/index block
//
//   3. The archive contains a global resource index that maps:
//        resource_id (u32) → { offset (u32), size (u32) }
//      This index is sorted by resource_id for binary search
//      (see EResourceManager::BinarySearch at 0x80325E6C)
//
//   4. Resources are stored sequentially after the index. Each resource
//      is identified by a 32-bit hash of its filename
//      (see EResourceManager::CalcId at 0x80327534)
//
// Archive Index Entry (reconstructed from EResourceManager field layout):
//   struct ArcIndexEntry {
//       u32 resourceId;     // Hash of resource name
//       u32 offset;         // Byte offset into archive
//       u32 size;           // Uncompressed size in bytes
//   };
//
// The EResourceManager keeps a sorted array of resource IDs at offset 0x058
// (within the 0xCC4-byte padding region) for binary search lookup.
//
// === DVD vs HDD Loading ===
//
// The game supports two loading paths (from ArcFileInfo at 0x80321CFC):
//   1. Direct DVD read - streaming from disc
//   2. HDD cache - copied to memory card / hard drive for faster access
//
// ArcFileInfo tracks both paths:
//   - m_bIsUsingHDD (0x000): pointer to source name (DVD path)
//   - m_bIsUsingHDD_004 (0x004): pointer to destination name (HDD path)
//   - m_field_008 (0x008): source file size
//   - m_field_010 (0x010): archive file handle / validation state
//
// ArcCopier::Copy (at 0x80877D20, 1268 bytes) handles streaming the archive
// from DVD to HDD with progress tracking and cancellation support.


//=============================================================================
//
//  PART 2: iResFile - BASE RESOURCE FILE INTERFACE
//
//=============================================================================
//
// iResFile is the abstract base class for all resource file types.
// Size: 0x10 (16 bytes)
// vtable at 0x000 (inherited)
//
// Key virtual methods (from symbols):
//   Create, Delete, Open, Close, CloseForReopen, Reopen
//   Update, Writable, ValidFile
//   CountTypes, GetIndType, Count
//   GetByID, GetByName, GetByIndex
//   GetName, GetResType, GetID, GetIndex
//   FindUniqueName, FindUniqueID
//   Detach, Load, SetID
//   Add, Write, Remove, SetInfo
//   IsLittleEndian, GetLanguage
//   AddWithLanguage, GetByIDAndLanguage
//
// Field layout (0x10 bytes):
//   0x000: [inherited vtable]
//   0x008: u32 m_error          - error code
//   0x00C: u32 m_resFileData    - pointer to ResFile data

// --- iResFile constructor ---
// Address: 0x8039AFB0, Size: 96 bytes
// NON_MATCHING - stub only
void iResFile_ctor() {
    // Initializes base fields, sets vtable
    // m_error = 0
    // m_resFileData = NULL
}


//=============================================================================
//
//  PART 3: IFFResFile2 - IFF CONTAINER FILE PARSER
//
//=============================================================================
//
// IFFResFile2 parses .iff (Interchange File Format) containers, which are
// the fundamental resource container format used by Maxis/EA games since
// SimCity. The Sims 2 GC uses IFF version 2.
//
// Size: 0x150 (336 bytes)
//
// === IFF File Format ===
//
// From IFFResFile2::Open disassembly (0x800BDE58, 1036 bytes):
//
// IFF Header (64 bytes, read at stack offset 0x58):
//   Bytes 0x00-0x03: Magic signature (validated byte-by-byte)
//                    The code checks against a 64-byte pattern at 0x8042408C
//                    with wildcard bytes (0x2A = '*')
//   Bytes 0x09-0x0A: Version number (major.minor as ASCII digits)
//                    Parsed as: major = (byte[0x09] - '0') << 8
//                               minor = (byte[0x0B] - '0')
//                    Supported versions: 0x0200 (v2.0) and 0x0205 (v2.5)
//   Bytes 0x3C-0x3F: Resource map offset (v2.5 only)
//                    Read as big-endian u32: (b[0]<<24)|(b[1]<<16)|(b[2]<<8)|b[3]
//                    Stored at this+0x140 (m_field_140)
//
// IFF Block Headers:
//   The file contains typed blocks, each with:
//     u32 typeTag;    // 4-char type code (e.g., 'rsmp', 'BHAV', 'TPRP', 'POSI')
//     s16 blockId;    // Block ID within type
//     u16 flags;      // Block flags (bit 2 = compressed?)
//     u32 offset;     // File offset
//     u32 size;       // Block data size
//
// Known Type Tags (from IFFResFile2::Open at 0x800BE1F4-0x800BE240):
//   'rsmp' = 0x72736D70  - Resource map (main index block)
//   'BHAV' = 0x42484156  - Behavior trees (SimAntics bytecode)
//   'POSI' = 0x504F5349  - Position data
//   'TPRP' = 0x54505250  - Tree property data
//
// IFF Resource Map ('rsmp' block):
//   The resource map is the central index that tracks all blocks in the file.
//   It contains:
//     - Type directory: list of unique 4-char type codes
//     - Per-type block lists: arrays of IFFResNode entries
//     - Names and IDs for each block
//
// IFFResFile2 Field Layout (0x150 bytes):
//   0x000: vtable*
//   0x004: u32 m_iD              - current resource being accessed
//   0x006: u16 m_iD_006          - short form of current ID
//   0x008: s16 m_language         - language code for localization
//   0x00A: u16 m_field_00A       - flags
//   0x00C: u32 m_index            - block index counter
//   0x010: u32 m_field_010       - file offset tracking
//   0x014-0x133: [0x120 bytes]   - MemFile embedded object (for I/O)
//   0x134: u32 m_field_134       - allocated flag / state
//   0x138: u32 m_resType         - IFFResMap* (type map)
//   0x13C: u32 m_field_13C       - block header tracking
//   0x140: u32 m_blockHeader     - resource map offset (from header)
//   0x144: u32 m_blockHeader_144 - block header cache pointer
//   0x148: u32 m_field_148       - block header count
//   0x14C: u32 m_field_14C       - reopen state

// --- IFFResFile2 constructor ---
// Address: 0x800BDDE8, Size: 112 bytes
// NON_MATCHING - structural decomp
void IFFResFile2_ctor(IFFResFile2* this_) {
    // Calls iResFile base constructor
    // Sets vtable to IFFResFile2 vtable (at 0x8045F5F0)
    // m_field_134 = 0  (no allocation)
    // m_resType = NULL
    // m_field_13C = 0
    // m_blockHeader = NULL
    // m_blockHeader_144 = NULL
    // m_field_148 = 0
    // m_field_14C = 0
}

// --- IFFResFile2::Open ---
// Address: 0x800BDE58, Size: 1036 bytes
// NON_MATCHING - annotated pseudocode
//
// Opens an IFF file and parses its header and block directory.
//
// int IFFResFile2::Open(StringBuffer& filename) {
//     // Check if already open
//     if (ValidFile()) return -47; // ERR_ALREADY_OPEN
//
//     // Copy filename to internal buffer at this+0x10
//     MemFile_SetFilename(&m_memfile, &filename);
//
//     // Open the physical file
//     int result = MemFile_Open(&m_memfile, 0);
//     if (result != 0) {
//         // Try read-only mode
//         u32 mode = 0x40;  // READ_ONLY
//         result = MemFile_OpenMode(&m_memfile, 0, &mode);
//         if (result != 0) goto error;
//
//         // Read 64-byte IFF header from file
//         u8 header[64];
//         result = MemFile_Read(&m_memfile, header, &mode);
//         if (result != 0) goto error;
//
//         // Validate magic signature against expected pattern
//         // Pattern at 0x8042408C uses '*' (0x2A) as wildcard
//         u8* pattern = (u8*)0x8042408C;
//         for (int i = 0; i < 64; i++) {
//             if (pattern[i] == '*') continue;  // wildcard
//             if (header[i] != pattern[i]) {
//                 result = -93;  // ERR_INVALID_FORMAT
//                 break;
//             }
//         }
//         if (result != 0) goto error;
//
//         // Parse version: bytes at offset 9 and 11
//         u16 version = ((header[9] - '0') << 8) | (header[11] - '0');
//         if (version == 0x0200) {
//             // IFF v2.0 - standard format
//         } else if (version == 0x0205) {
//             // IFF v2.5 - has resource map offset at bytes 0x3C-0x3F
//             u32 rsmpOffset = (header[0x3C]<<24) | (header[0x3D]<<16) |
//                              (header[0x3E]<<8) | header[0x3F];
//             m_blockHeader = rsmpOffset;  // at this+0x140
//         } else {
//             result = -93;  // ERR_INVALID_FORMAT
//         }
//     }
//     if (result != 0) return result;
//
//     // Allocate block header map (20 bytes)
//     m_resType = new IFFResMap();  // at this+0x138
//     // ... zero-init the map fields ...
//
//     // If v2.5 with resource map offset, read the 'rsmp' block directly
//     if (rsmpOffset != 0) {
//         GetBlockHeader(header_buf, rsmpOffset);
//         // Validate type == 'rsmp' (0x72736D70)
//         if (header_buf.type == 0x72736D70) {
//             // Load the resource map node
//             IFFResNode* node = CreateNodeForBlock(...);
//             LoadNode(node, NULL, header_buf.type);
//             // ... process resource map entries ...
//         }
//     } else {
//         // Sequential scan: read blocks from offset 64 onward
//         u32 blockOffset = 64;
//         u32 maxOffset = 0x3FFFFB4; // ~1GB sanity limit
//         while (GetBlockHeader(header_buf, blockOffset) == 0) {
//             if (header_buf.size > maxOffset) break;
//             // Parse block header, create node, add to map
//             // ...
//             blockOffset += header_buf.size;
//         }
//     }
//
//     // Register known block types in the map for fast lookup
//     RegisterType('BHAV');  // Behavior trees
//     RegisterType('TREE');  // Tree tables
//     RegisterType('POSI');  // Position data
//     RegisterType('TPRP');  // Tree properties
//     RegisterType('rsmp');  // Resource map
//
//     m_field_14C = 0;  // clear reopen state
//     return 0;
// }


//=============================================================================
//
//  PART 4: NghResFile - NEIGHBORHOOD RESOURCE FILE (.NGH FORMAT)
//
//=============================================================================
//
// NghResFile manages .NGH neighborhood files, which store the complete
// game state: neighborhoods, houses, sims, families, thumbnails, and
// save game data. It extends iResFile with save/load and memory card support.
//
// Size: 0x194 (404 bytes)
//
// === .NGH File Format ===
//
// From NghResFile::ReadFromFile (0x800D74F0, 704 bytes) and
// NghResFile::DecompressSection (0x800D4960, 604 bytes):
//
// The .NGH file is a sectioned archive with three major section types:
//   Section 0: "Host" section  - neighborhood/house data (host-specific)
//   Section 1: "Both" section  - shared data (cross-platform compatible)
//   Section 2: "Thumb" section - thumbnail images
//
// Each section has a header (NghResFileSectionHeader):
//   struct NghResFileSectionHeader {
//       u32 sectionType;      // 0x00: Section type identifier
//       u32 dataOffset;       // 0x04: Offset to section data
//       u32 uncompressedSize; // 0x08: Size when decompressed
//       u32 compressedSize;   // 0x0C: Size in file (if compressed)
//       u32 checksum;         // 0x10: CRC32 or similar checksum
//       u32 compressionType;  // 0x14: Compression algorithm ID
//       u32 numEntries;       // 0x18: Number of resource entries
//       // ... more fields follow
//   };
//
// Compression Types (from DecompressSection at 0x800D4A88-0x800D4A98):
//   Type 2: RefPack / EA compression (calls 0x800D90D0)
//   Type 7-8: Valid section range (compressionType must be 7 or 8)
//   Other: Alternative decompression (calls 0x8030A920)
//
// Each section contains an array of resource entries:
//   struct NghResourceEntry {
//       u32 resourceType;   // 4-char type code
//       u32 dataOffset;     // Offset within section
//       u32 dataSize;       // Size of resource data
//       u16 resourceId;     // Short ID for quick lookup
//   };
//
// === Section Loading Flow ===
//
// ReadFromFile(filename):
//   1. Build path from filename (StackString<260>)
//   2. Open file via DVDFileSystem
//   3. Set m_bHasCardChanged = 1 (at offset 0x20)
//   4. Store filename in path buffer (at offset 0x28)
//   5. FlushSection(0) - clear host section
//   6. Get NghLayout global → read section sizes
//   7. Allocate buffer, DVDRead host section data
//   8. ReadHostSection(buffer, false) - parse host section
//   9. FlushSection(1) - clear both section
//  10. Allocate buffer, DVDRead both section data
//  11. ReadBothSection(buffer, false) - parse both section
//  12. FlushSection(2) - clear thumb section
//  13. Allocate buffer, DVDRead thumb section data
//  14. ReadThumbSection(buffer, false) - parse thumb section
//  15. Free all temporary buffers
//
// NghResFile Field Layout (0x194 bytes):
//   0x000: vtable*
//   0x004: u32 m_byID              - resource lookup by ID data
//   0x008: u16 m_byID_008          - ID count
//   0x00C: u32 m_field_00C         - vtable pointer to inner class
//   0x010: u32 m_memoryCardCache   - MemoryCardCache* pointer
//   0x014: u32 m_field_014         - registry data pointer
//   0x018: u32 m_field_018         - current section data
//   0x020: u32 m_bHasCardChanged   - dirty flag for memory card
//   0x024: u32 m_bIsSectionLoaded  - bitfield: which sections are loaded
//   0x028: u32 m_field_028         - total data size
//   0x02C-0x133: [0x108 bytes]     - StackString<260> for file path
//   0x134: u8  m_field_134         - source type flag
//   0x138: u32 m_sectionState_138  - section 1 (Both) loaded state
//   0x13C-0x17B: [0x40 bytes]      - section data arrays (16 entries x 4 bytes)
//   0x17C: u32 m_sectionState_17C  - section 2 (Thumb) loaded state
//   0x180: u32 m_byIndex_180       - index lookup data
//   0x184: u16 m_field_184         - house count / section count
//   0x188: u32 m_field_188         - write state
//   0x18C: u32 m_field_18C         - endian swap state
//   0x190: u32 m_memoryCardCache_190 - secondary cache pointer

// --- NghResFile constructor ---
// Address: 0x800D39E4, Size: 180 bytes
// NON_MATCHING - structural decomp from disassembly
//
// NghResFile::NghResFile() {
//     // Call base class ctor (iResFile linkage at 0x80135588)
//     iResFile_link();
//
//     // Set vtable
//     m_vtable_00C = &NghResFile_vtable;  // 0x80460830
//
//     // Initialize fields
//     m_memoryCardCache = NULL;           // 0x010
//     m_field_014 = NULL;                 // 0x014
//     m_field_018_init = 0;              // 0x018 (sub-field at +4)
//     m_bHasCardChanged = 1;              // 0x020
//     m_bIsSectionLoaded = 0;             // 0x024
//
//     // Initialize path StackString<260> at 0x028
//     StackString_init(&m_path, &m_path_buf, 260);
//
//     m_field_18C = 1;                    // 0x18C
//     m_field_134 = 0;                    // 0x134 (byte)
//     m_byIndex_180 = 0;                  // 0x180
//     m_field_184 = 0;                    // 0x184 (u16)
//     m_field_188 = 1;                    // 0x188
//
//     // Allocate registry node (28 bytes)
//     RegistryNode* reg = malloc(28);     // at 0x802D11B0
//     m_memoryCardCache_190 = reg;        // 0x190
//     memset(reg, 0, 28);                // 7 fields x 4 bytes
//
//     // Call init()
//     init();
// }

// --- NghResFile::init ---
// Address: 0x800D4148, Size: 272 bytes
// NON_MATCHING - structural decomp
//
// void NghResFile::init() {
//     // Allocate section type lookup table (4 entries x 4 bytes = 16 bytes)
//     m_sectionTypeTable = malloc(16);    // at this+0x138 (offset 312)
//     memset(m_sectionTypeTable, 0, 16);
//
//     // Allocate per-section data (16 sections, each with 6 fields = 24 bytes)
//     // Sections stored at this+0x13C through this+0x178
//     for (int i = 0; i < 16; i++) {     // covers offset 0x13C to 0x178
//         u32* sectionData = malloc(24);
//         m_sections[i] = sectionData;
//         memset(sectionData, 0, 24);
//     }
//
//     // Allocate character data table (2 entries x 4 bytes = 8 bytes)
//     m_characterData = malloc(8);        // at this+0x17C
//     memset(m_characterData, 0, 8);
//
//     // Initialize linked list of resource entries
//     // Walks from m_memoryCardCache (0x10) through ->next pointers
//     // Resets list head to end of list
//
//     // Clear all 36 slots in extended registry
//     // (from this+0x194 backwards, 36 entries x 4 bytes)
//     for (int i = 35; i >= 0; i--) {
//         m_registryExtended[i] = 0;
//     }
// }

// --- NghResFile::DecompressSection ---
// Address: 0x800D4960, Size: 604 bytes
// NON_MATCHING - annotated pseudocode
//
// void* NghResFile::DecompressSection(NghResFileSectionHeader* header, bool isFromCard) {
//     u32 dataOffset = header->dataOffset;    // +0x04
//     u32 compressedSize = header->compressedSize;  // +0x0C
//
//     // If not from memory card, byte-swap header fields (big-endian → native)
//     if (!isFromCard) {
//         SwapFourByteNumber(&dataOffset);
//         SwapFourByteNumber(&compressedSize);
//         SwapFourByteNumber(&header->checksum);  // +0x10
//     }
//
//     // Validate checksum: compute CRC over section data
//     u32 savedChecksum = header->checksum;
//     header->checksum = 0;
//     u32 totalDataSize = dataOffset + compressedSize;
//     u32 computed = CRC32(header, totalDataSize);  // call at 0x802C5E44
//     header->checksum = savedChecksum;
//
//     if (computed != savedChecksum) {
//         return NULL;  // checksum mismatch
//     }
//
//     // If not from card, byte-swap remaining header fields
//     if (!isFromCard) {
//         SwapFourByteNumber(&header->sectionType);
//         SwapFourByteNumber(&header->dataOffset);
//         SwapFourByteNumber(&header->uncompressedSize);  // +0x08
//         SwapFourByteNumber(&header->compressedSize);
//         SwapFourByteNumber(&header->field_14);
//         SwapFourByteNumber(&header->numEntries);  // +0x18
//     }
//
//     // Allocate output buffer for decompressed data
//     u32 allocSize = header->dataOffset + header->uncompressedSize;
//     void* outBuf = EAHeap_Alloc(allocSize, 64, 0, 0);  // 64-byte aligned
//
//     // Copy header into output buffer
//     memcpy(outBuf, header, header->dataOffset);
//
//     // Check compression type (at header+0x14)
//     u32 compType = header->field_14;
//     if (compType < 7 || compType > 8) {
//         return NULL;  // unsupported compression
//     }
//
//     // Decompress based on section type
//     if (header->sectionType == 2) {
//         // RefPack / EA compression
//         u32 srcOffset = header->dataOffset;
//         void* src = (u8*)header + srcOffset;
//         void* dst = (u8*)outBuf + srcOffset;
//         u32 decompSize = RefPack_Decompress(
//             (u8*)header + srcOffset,   // compressed source
//             header->compressedSize,     // compressed size
//             (u8*)outBuf + srcOffset,   // output
//             header->uncompressedSize    // expected output size
//         );  // call at 0x800D90D0
//
//         if (decompSize != header->uncompressedSize) {
//             goto decompress_failed;
//         }
//
//         // For card data, also handle palette swizzling
//         if (!isFromCard && decompSize > 0) {
//             // Re-allocate and copy with palette fix
//             void* fixedBuf = EAHeap_Alloc(...);
//             memcpy(fixedBuf, outBuf, ...);
//
//             // Copy 32 bytes of header data starting at offset 12
//             memcpy(fixedBuf_data + 12, outBuf_data + 12, 32);
//
//             // Byte-swap 256 palette entries (RGBA → BGRA or similar)
//             u8* palette = fixedBuf_data + 1036;
//             for (int i = 0; i < 256; i++) {
//                 u8 tmp = palette[0];
//                 palette[0] = palette[2];
//                 palette[2] = tmp;
//                 palette += 4;
//             }
//             EAHeap_Free(outBuf);
//             return fixedBuf;
//         }
//     } else {
//         // Alternative decompression (LZSS or similar)
//         u32 decompSize = LZSS_Decompress(
//             (u8*)header + header->dataOffset,
//             header->compressedSize,
//             (u8*)outBuf + header->dataOffset,
//             header->uncompressedSize
//         );  // call at 0x8030A920
//
//         if (decompSize != header->uncompressedSize) {
//             EAHeap_Free(outBuf);
//             return NULL;
//         }
//     }
//
//     return outBuf;
// }

// --- NghResFile::ReadHostSection ---
// Address: 0x800D4E5C, Size: 844 bytes
// NON_MATCHING - annotated pseudocode
//
// This function reads the "Host" section of the .NGH file.
// The Host section contains neighborhood-specific data that may differ
// between platforms (GameCube, PS2, Xbox).
//
// int NghResFile::ReadHostSection(void* sectionData, bool isFromCard) {
//     // Get NghLayout global (at 0x80486330)
//     NghLayout* layout = g_nghLayout;
//     u32 sectionOffset = layout->hostSection.offset;
//     u32 sectionSize   = layout->hostSection.size;
//
//     // Check if section is already loaded
//     if (IsSectionLoaded(0) == true) return 1;  // already loaded
//
//     // Read section from file/card if not provided
//     u32 readOk = 1;
//     void* buffer = sectionData;
//     if (sectionData == NULL) {
//         buffer = ReadSection(sectionOffset, sectionSize, &needsByteSwap, &readOk);
//     }
//     if (readOk != 1) goto done;
//
//     // Decompress the section
//     NghResFileSectionHeader* header = DecompressSection(buffer, isFromCard);
//
//     // Parse resource directory from decompressed data
//     // The directory is at header->dataOffset, containing:
//     //   u32 numEntries = header->numEntries (at +0x18)
//     //   Followed by parallel arrays:
//     //     u32 typeIds[numEntries]     - resource type codes
//     //     u32 offsets[numEntries]     - data offsets within section
//     //     u32 sizes[numEntries]       - data sizes
//     //     u16 resIds[numEntries]      - short resource IDs
//
//     StackString<64> nameBuffer;
//     u32 numEntries = header->numEntries;
//     u8* base = (u8*)header + header->dataOffset;
//     u32* typeArray   = (u32*)(base);
//     u32* offsetArray = typeArray + numEntries;
//     u32* sizeArray   = offsetArray + numEntries;
//     u16* idArray     = (u16*)(sizeArray + numEntries);
//
//     // Read global entries first (index 0)
//     u32 resType = typeArray[0];
//     u32 resOffset = offsetArray[0];
//     u32 resSize = sizeArray[0];
//     u16 resId = idArray[0];
//
//     if (!isFromCard) {
//         SwapFourByteNumber(&resType);
//         SwapFourByteNumber(&resOffset);
//         SwapFourByteNumber(&resSize);
//         SwapTwoByteNumber(&resId);
//     }
//
//     // Allocate HandleNode for resource
//     Memory::HandleNode* node = new HandleNode(resSize);
//     if (resSize > 0) {
//         node->data = malloc(resSize);
//     }
//     node->refCount = 1;
//     memcpy(node->data, (u8*)header + resOffset, resSize);
//
//     // Add resource to this file's lookup via vtable call
//     this->Add(node, resType, resId, nameBuffer, true);
//
//     // Read per-house entries (indices 1..15)
//     u32 startHouse = m_bIsSectionLoaded + 1;
//     for (int house = 1; house <= 15; house++) {
//         for (int entry = 0; entry < 2; entry++) {
//             // Read entry from parallel arrays
//             resType = *typeArray++;
//             resOffset = *offsetArray++;
//             resSize = *sizeArray++;
//             resId = *idArray++;
//
//             if (!isFromCard) {
//                 SwapFourByteNumber(&resType);
//                 SwapFourByteNumber(&resOffset);
//                 SwapFourByteNumber(&resSize);
//                 SwapTwoByteNumber(&resId);
//             }
//
//             node = new HandleNode(resSize);
//             if (resSize > 0) node->data = malloc(resSize);
//             node->refCount = 1;
//             memcpy(node->data, (u8*)header + resOffset, resSize);
//             this->Add(node, resType, resId, nameBuffer, true);
//         }
//     }
//
//     // Free decompressed buffer
//     EAHeap_Free(header);
//
//     // Advance section loaded counter
//     this->SetCurrentHouse(startHouse);
//
//     return readOk;
// }

// --- NghResFile::ReadSection ---
// Address: 0x800D47E4, Size: 380 bytes
// NON_MATCHING - annotated pseudocode
//
// Reads a section from the .NGH file on DVD or from memory card cache.
//
// void* NghResFile::ReadSection(u32 sectionOffset, u32 sectionSize,
//                                bool* needsByteSwap, EMC_OpStatus* status) {
//     u32 result = 0;
//
//     // Allocate read buffer (64-byte aligned)
//     void* buffer = EAHeap_Alloc(sectionSize, 64, 0, 0);
//     *status = 0;
//
//     // Try to read from file path (m_path at offset 0x28)
//     StringBuffer* path = &m_path;
//     int fileResult = DVDFile_Open(path, g_dvdFileHandle, 0);
//
//     if (fileResult >= 0) {
//         // File found - read from DVD
//         u32 pathLen = StackString_GetLength(path);
//         // Open file via EResourceLoaderImpl file system
//         void* fileHandle = DVDFileSystem_Open(path, pathLen, ...);
//
//         if (fileHandle == NULL) {
//             EAHeap_Free(buffer);
//             *status = 0;
//             return NULL;
//         }
//
//         // Read data: DVDRead(handle, buffer, size, offset, ...)
//         u32 bytesRead = EResourceLoaderImpl_ReadData(
//             fileHandle, buffer, sectionOffset, sectionSize, true, NULL
//         );
//
//         // Close file
//         DVDFileSystem_Close(fileHandle);
//
//         if (bytesRead == sectionSize) {
//             *status = 1;  // success
//         }
//     } else {
//         // File not on DVD - try memory card cache
//         *status = 1;
//         NghResFile_BeginCardRead(this);  // sets up card read state
//
//         NghLayout* layout = g_nghLayoutPtr;
//         bool cached = MemoryCardCache::GetSection(
//             layout, path, sectionOffset, sectionSize
//         );
//
//         if (cached) {
//             *status = 0;  // signal that we got cached data
//         }
//         *needsByteSwap = 1;  // card data needs byte swap
//     }
//
//     if (*status != 1) {
//         EAHeap_Free(buffer);
//         buffer = NULL;
//     }
//
//     return buffer;
// }


//=============================================================================
//
//  PART 5: ChainResFile - MULTI-FILE RESOURCE CHAIN
//
//=============================================================================
//
// ChainResFile chains multiple iResFile instances together, searching them
// in order when looking up resources. This allows the game to layer:
//   1. Save game overrides (NghResFile)
//   2. Object definition files (ObjResFile)
//   3. Base game resources (StdResFile / IFFResFile2)
//
// Size: 0x14 (20 bytes) for the base object, but the actual storage is an
// inline array of 8 slots, each 24 bytes, starting at offset 0x14.
// Total effective size: 0x14 + (8 * 24) = 0xD4 (212 bytes)
//
// Field Layout:
//   0x000: u32 m_byIndex      - count of chained files? vtable data?
//   0x004: [8 bytes padding]
//   0x00C: u32 m_byIndex_00C  - file count
//   0x010: u32 m_file         - pointer to active file list
//
// Each slot in the inline array (24 bytes per slot):
//   0x00: u32 filePtr     - iResFile* pointer (NULL = empty slot)
//   0x04: u32 nextOffset  - offset to next valid entry
//   0x08-0x0F: [8 bytes]  - prohibited/exclusive type filters
//   0x10: u32 isActive    - 1 if slot is in use
//   0x14-0x17: [4 bytes]  - padding

// --- ChainResFile::AddFile ---
// Address: 0x800B1E98, Size: 64 bytes
// NON_MATCHING - decompiled from disassembly
//
// Adds an iResFile to the chain. Searches for first empty slot in the
// inline array of 8 slots (max 8 chained files).
//
// void ChainResFile::AddFile(iResFile* file) {
//     // r3 = this, r4 = file
//     u8* slot = (u8*)this + 0x14;  // addi r3, r3, 20 → first slot
//     int i = 0;
//
//     while (i <= 7) {
//         u32* slotFile = (u32*)(slot - 4);  // filePtr at slot[-4]
//         if (*slotFile == 0) {
//             // Empty slot found
//             u32 nextOffset = *(u32*)slot;  // current next pointer
//             *slotFile = (u32)file;          // store file pointer
//             *(u32*)(slot + 4) = nextOffset; // move next to +4
//             *(u32*)(slot + 16) = 1;         // mark active
//             return;
//         }
//         i++;
//         slot += 24;  // advance to next slot
//     }
//     // All 8 slots full - file not added
// }

// --- ChainResFile::GetByID ---
// Address: 0x800B2A48, Size: 60 bytes
// NON_MATCHING
//
// Searches all chained files for a resource by type and ID.
// Falls through to GetByIDAndLanguage with default language.
//
// Memory::HandleNode* ChainResFile::GetByID(int type, short id,
//                                            void (*callback)(void*, int)) {
//     return GetByIDAndLanguage(type, id, 0, callback);
// }

// --- ChainResFile::GetByIDAndLanguage ---
// Address: 0x800B2970, Size: 216 bytes
// NON_MATCHING - annotated pseudocode
//
// Memory::HandleNode* ChainResFile::GetByIDAndLanguage(
//     int type, short id, char language, void (*callback)(void*, int))
// {
//     // Walk through chained files in order
//     for (int i = 0; i < m_fileCount; i++) {
//         iResFile* file = GetFile(i);
//         if (file == NULL) continue;
//
//         // Check type filters (prohibited/exclusive lists)
//         // ... filter logic ...
//
//         // Try to find resource in this file
//         Memory::HandleNode* node = file->GetByIDAndLanguage(
//             type, id, language, callback
//         );
//         if (node != NULL) return node;
//     }
//     return NULL;  // not found in any file
// }


//=============================================================================
//
//  PART 6: EResourceManager - RESOURCE LIFECYCLE MANAGER
//
//=============================================================================
//
// EResourceManager is the high-level resource manager that handles:
//   - Loading resources from .arc archives
//   - Reference counting and caching
//   - Resource ID hashing and lookup
//   - Memory management for loaded resources
//
// Size: 0xD20 (3360 bytes)
//
// Each resource category (textures, models, sounds, etc.) has its own
// EResourceManager instance. The EResourceLoaderImpl coordinates all
// managers and handles async loading.
//
// Field Layout (key fields):
//   0x000: vtable*
//   0x004-0x00B: [padding/base fields]
//   0x00C: s16 m_ref_00C       - reference tracking
//   0x040: u32 m_field_040      - resource name string pointer
//   0x044: u32 m_archiveFile    - archive file name string
//   0x048: u32 m_field_048      - resource count / state
//   0x04C: u32 m_field_04C      - loaded resource tracking
//   0x050: u32 m_archiveFile_050 - EFile* for open archive
//   0x054: u32 m_archiveFile_054 - ArcFileInfo* for validation
//   0x058-0xD1B: [0xCC4 bytes]  - ResourceIndexRecord array
//                                  Sorted array of {resourceId, offset, size}
//                                  Used for binary search
//   0xD1C: u32 m_field_D1C      - EAHeap* for allocations
//
// Resource Index Record (from BinarySearch at 0x80325E6C):
//   struct ResourceIndexRecord {
//       u32 id;       // Resource ID (hash of name)
//       u32 offset;   // File offset in .arc
//       u32 size;     // Resource size
//   };
//   Maximum capacity: 0xCC4 / 12 = ~272 resources per manager

// --- EResourceManager::Init ---
// Address: 0x80325798, Size: 832 bytes
// NON_MATCHING - annotated pseudocode
//
// Initializes the resource manager with a category name string.
// The name determines which .arc file to load and the resource capacity.
//
// void EResourceManager::Init(char* name) {
//     m_field_040 = name;                    // Store name at offset 0x40
//     CalcPath();                             // Build archive file path
//
//     // Register with EResourceLoaderImpl singleton
//     EResourceLoaderImpl* loader = g_resourceLoader;
//     loader->AddManager(this);
//
//     // Determine resource capacity based on category name
//     // The game uses string comparison to set different capacities:
//     //
//     // Category name matching (approximate from string table at 0x80420ED4+):
//     //   "level" / "lvl"     → capacity 800
//     //   "shader" / "shd"    → capacity 150
//     //   "shaderlow"         → capacity 100
//     //   "fontpage"          → capacity  20
//     //   "texture"           → capacity  50
//     //   "tquantize"         → capacity 700
//     //   "model" / "mdl"     → capacity 500
//     //   "anim"              → capacity 250
//     //   "flash"             → capacity 550
//     //   "sample"            → capacity  10
//     //   "binary"            → capacity  16
//     //   Default             → capacity   4
//
//     int capacity;
//     if (strcmp(name, "level") == 0 || strcmp(name, "lvl") == 0) {
//         capacity = 800;
//     } else if (strstr(name, "shader") && !strstr(name, "shaderlow")) {
//         capacity = 150;
//     } else if (strcmp(name, "shaderlow") == 0) {
//         capacity = 100;
//     } else if (strcmp(name, "fontpage") == 0) {
//         capacity = 20;
//     } else if (strcmp(name, "texture") == 0) {
//         capacity = 50;
//     } else if (strcmp(name, "tquantize") == 0) {
//         capacity = 700;
//     } else if (strcmp(name, "model") == 0 || strcmp(name, "mdl") == 0) {
//         capacity = 500;
//     } else if (strcmp(name, "anim") == 0) {
//         capacity = 250;
//     } else if (strcmp(name, "flash") == 0) {
//         capacity = 550;
//     } else if (strcmp(name, "sample") == 0) {
//         capacity = 10;
//     } else if (strcmp(name, "binary") == 0) {
//         capacity = 16;
//     } else {
//         capacity = 4;
//     }
//
//     // Initialize resource map with capacity
//     m_resourceMap.SetCapacity(capacity, name);  // at this+0xD08
//
//     m_field_048 = 1;  // mark as initialized
// }

// --- EResourceManager::GetArchiveFile ---
// Address: 0x80325BC0, Size: 296 bytes
// NON_MATCHING - annotated pseudocode
//
// Gets or opens the archive file for this resource manager.
// Handles both DVD and HDD (cached) archive access.
//
// EFile* EResourceManager::GetArchiveFile() {
//     // If archive already open, return it
//     if (m_archiveFile_050 != NULL) {
//         return m_archiveFile_050;
//     }
//
//     // Lock resource loader mutex
//     EResourceLoaderImpl* loader = g_resourceLoader;
//     loader->Lock();
//
//     bool useHDD = false;
//     if (m_archiveFile_054 != NULL) {
//         useHDD = true;  // Archive has been validated for HDD
//     }
//
//     // Check if DVD file system is available
//     if (DVDFileSystem_IsReady() && DVDFileSystem_HasFile()) {
//         // Check if archive is NOT already cached to HDD
//         if (!useHDD) {
//             // Check if archive name matches a known HDD-cached archive
//             if (ArcFileInfo_CompareName(m_archiveFile)) {
//                 // Open from DVD with HDD caching
//                 DVDFileSystem_OpenArchive(
//                     &m_archiveFile_050,    // output file handle
//                     m_archiveFile,         // archive name
//                     "files/DATA/",         // base path on DVD
//                     0,                     // no flags
//                     useHDD,                // use HDD copy
//                     0                      // no callback
//                 );
//             } else {
//                 goto open_dvd;
//             }
//         } else {
//             goto open_dvd;
//         }
//     } else {
//     open_dvd:
//         // Open directly from DVD
//         DVDFileSystem_OpenArchive(
//             &m_archiveFile_050,
//             m_archiveFile,
//             "files/DATA/",
//             0x80000000,            // DVD_FLAG - force DVD read
//             useHDD,
//             0
//         );
//     }
//
//     // Unlock mutex
//     loader->Unlock();
//
//     // Retry if file still not open (loop back)
//     if (m_archiveFile_050 == NULL) {
//         goto retry;
//     }
//
//     return m_archiveFile_050;
// }

// --- EResourceManager::CalcPath ---
// Address: 0x80325AD8, Size: 232 bytes
// NON_MATCHING - annotated pseudocode
//
// Constructs the archive file path from the resource category name.
// Example: name="texture" → path="files/DATA/texture.arc"
//
// void EResourceManager::CalcPath() {
//     EString archivePath;
//     EString* nameStr = &m_nameString;  // at this+0x44
//
//     // Copy name to working string
//     nameStr->assign(m_field_040);
//
//     // If name is longer than 8 chars, truncate
//     int len = nameStr->length();
//     if (len > 8) {
//         EString truncated;
//         truncated.assign(nameStr, 0, 8);  // first 8 chars
//         nameStr->assign(truncated);
//     }
//
//     // Clear and rebuild: name → UPPERCASE
//     nameStr->toUpper();
//
//     // Build full path: "files/DATA/" + name + ".arc"
//     EString prefix;
//     prefix.sprintf("%s%s", nameStr->c_str(), m_archiveFile);
//
//     EString fullPath;
//     fullPath.sprintf("%s%s", prefix.c_str(), ".arc");
//
//     // Store the computed path
//     nameStr->assign(fullPath);
//
//     // Clean up temporaries
//     prefix.destroy();
//     fullPath.destroy();
// }

// --- EResourceManager::BinarySearch ---
// Address: 0x80325E6C, Size: 100 bytes
// NON_MATCHING - decompiled from disassembly
//
// Binary search through sorted resource ID array.
// Returns index of matching entry, or -1 if not found.
//
// int EResourceManager::BinarySearch(u32 targetId, u32* idArray, int count) {
//     int low = 0;
//     int high = count - 1;
//
//     while (low <= high) {
//         int mid = (low + high) / 2;
//         u32 midId = idArray[mid];
//
//         if (midId == targetId) {
//             return mid;
//         } else if (midId < targetId) {
//             low = mid + 1;
//         } else {
//             high = mid - 1;
//         }
//     }
//     return -1;
// }

// --- EResourceManager::LookupId ---
// Address: 0x80325ED0, Size: 144 bytes
// NON_MATCHING - annotated pseudocode
//
// Looks up a resource by ID and returns its offset and size in the archive.
//
// bool EResourceManager::LookupId(u32 resourceId, u32& outOffset, u32& outSize) {
//     // Get the sorted ID array and count from the resource index
//     u32* ids = &m_resourceIndex[0];  // at this+0x058
//     int count = m_field_04C;
//
//     // Binary search for the resource ID
//     int index = BinarySearch(resourceId, ids, count);
//     if (index < 0) return false;
//
//     // Retrieve offset and size from parallel arrays
//     outOffset = m_offsetArray[index];
//     outSize = m_sizeArray[index];
//     return true;
// }


//=============================================================================
//
//  PART 7: EResourceLoaderImpl - ASYNC RESOURCE LOADER
//
//=============================================================================
//
// EResourceLoaderImpl is the central coordinator for all resource loading.
// It runs on a separate thread and processes a command queue for async I/O.
//
// Size: 0xD08 (3336 bytes)
//
// The loader maintains:
//   - A message queue for load/unload commands (EResLoaderMsgQueue)
//   - An array of registered EResourceManager instances
//   - Thread synchronization primitives (semaphore, mutex)
//   - A global resource index for cross-manager lookups
//
// Field Layout (key fields):
//   0x000: vtable*
//   0x004-0x03C: EResLoadCmd message queue fields
//                 Commands: LOAD=3, UNLOAD=4, READ=5, WRITE=6, CLOSE=7
//   0x040: u32 m_managerArray    - pointer to EResourceManager* array
//   0x348: u32 m_managerCount    - number of registered managers
//   0x350: u32 m_isInitialized   - init state flag
//   0x3E4: u32 m_bIsBusy         - loader thread busy flag
//   0x3E8: u32 m_bIsBusy_3E8    - secondary busy flag
//   0xD04: u32 m_managerCapacity - max managers

// --- EResourceLoaderImpl::Init ---
// Address: 0x80310434, Size: 124 bytes
// NON_MATCHING - decompiled from disassembly
//
// void EResourceLoaderImpl::Init() {
//     m_bIsBusy = 0;                        // not busy
//
//     // Initialize the message queue
//     EResLoaderMsgQueue_Init(&m_msgQueue);   // at this+0x08
//
//     // Set up thread with 1500 byte stack
//     EThread_Init(&m_thread, 1500);          // at this+0x378
//
//     // Set thread name for debugging
//     m_thread.name = "ResLoader";            // string at 0x80420428
//
//     // Create thread: priority 17, stack size 32KB
//     EThread_Create(&m_thread, 17, 0x8000, 0);
//
//     // Start the thread
//     EThread_Start(&m_thread);
//
//     m_bIsBusy_3E8 = 0;
//     m_isInitialized = 1;
// }

// --- EResourceLoaderImpl::Load ---
// Address: 0x80310778, Size: 276 bytes
// NON_MATCHING - annotated pseudocode
//
// Initiates loading of a resource. If the loader thread is available and
// this is a synchronous call, loads directly. Otherwise, enqueues an
// async load command.
//
// EResource* EResourceLoaderImpl::Load(
//     EResourceManager* manager,
//     u32 resourceId,
//     EFile* file,
//     u32 offset,
//     u32 size,
//     bool async)
// {
//     EResource* result = NULL;
//
//     // Check if we're on the loader thread
//     if (IsCallingThread()) {
//         // Direct synchronous load (we're already on the loader thread)
//         result = DoLoadResource(manager, resourceId, file, offset, size);
//     } else {
//         // Enqueue async load command
//         // Allocate command (40 bytes)
//         EResLoadCmd* cmd = new EResLoadCmd();
//         cmd->type = 3;               // LOAD command
//         cmd->offset = offset;
//         cmd->size = size;
//         cmd->fileOffset = fileOffset;
//         cmd->file = file;
//         cmd->manager = manager;
//         cmd->async = async;
//
//         // Send command to message queue
//         sendCommand(cmd);
//
//         // If synchronous (async=false), wait for completion
//         if (!async) {
//             // Wait for thread to process
//             WaitForSemaphore();
//
//             // Get result from manager's GetRef
//             result = manager->GetRef(resourceId);
//
//             // Notify waiting thread if needed
//             if (g_waitingThread != NULL) {
//                 NotifyThread(g_waitingThread);
//             }
//         }
//     }
//
//     return result;
// }

// --- EResourceLoaderImpl::DoLoadResource ---
// Address: 0x80311A50, Size: 484 bytes
// NON_MATCHING - annotated pseudocode
//
// Actually loads a resource from an archive file into memory.
// Called on the loader thread.
//
// EResource* EResourceLoaderImpl::DoLoadResource(
//     EResourceManager* manager,
//     u32 resourceId,
//     EFile* file,
//     u32 offset,
//     u32 size)
// {
//     u32 fileOffset = 0;
//     u32 fileSize = 0;
//     void* tempFile = NULL;
//     u32 readOffset = 0;
//
//     if (file != NULL) {
//         // Loading from explicit file
//         char* managerName = manager->m_field_040;
//         if (strcmp(managerName, "level") == 0) {
//             // Level resources: seek and read from file
//             file->Seek(offset, 0);    // SEEK_SET
//             // Read will happen below
//         } else {
//             // Other resources: get current file position
//             readOffset = file->Tell() + size;
//         }
//     } else {
//         // Loading from archive - lookup resource position
//         bool found = manager->LookupId(resourceId, fileOffset, fileSize);
//         if (!found) return NULL;
//
//         // Get the archive file handle
//         EFile* archiveFile = manager->GetArchiveFile();
//         if (archiveFile == NULL) return NULL;
//
//         // Seek to resource position in archive
//         archiveFile->Seek(fileOffset, 0);
//         file = archiveFile;
//     }
//
//     // Ask the manager's vtable to create the resource object
//     // This is a virtual call that constructs the appropriate EResource subclass
//     EResource* resource = manager->CreateResource(
//         file, fileSize, resourceId
//     );
//
//     // Check if resource has inline data flag
//     if (resource != NULL) {
//         u32 flags = resource->m_flags;  // at +0x10
//         if ((flags >> 8) == 0) {
//             // No type set - set from file size
//             flags |= (fileSize << 8);
//             resource->m_flags = flags;
//         }
//
//         // Register with manager
//         manager->AddResource(resource, resourceId, true);
//
//         // If sync load, also read sub-resources
//         if (!async) {
//             manager->AddRef(resource);
//         }
//     }
//
//     // Clean up temp file if allocated
//     if (tempFile != NULL) {
//         DVDFileSystem_Close(tempFile);
//     }
//
//     return resource;
// }


//=============================================================================
//
//  PART 8: EResource - BASE RESOURCE OBJECT
//
//=============================================================================
//
// EResource is the base class for all loaded game resources. Each resource
// type (texture, model, sound, etc.) has a subclass with type-specific
// loading and rendering logic.
//
// Size: 0x0E (14 bytes) minimum, typically larger for subclasses
//
// Field Layout:
//   0x000: vtable*
//   0x004: u32 m_field_004       - resource manager back-pointer
//   0x008: [4 bytes]             - padding/alignment
//   0x00C: s16 m_refCount        - reference count
//
// Known Subclasses (from ERxxx symbols in map):
//   ERTexture       - Texture resources (.tpl)
//   ERModel         - 3D model resources
//   ERShader        - Shader programs
//   ERFont          - Font data
//   ERAnim          - Animation data
//   ERCharacter     - Character definitions
//   ERBinary        - Raw binary data
//   ERLevel         - Level/map data
//   ERDataset       - Dataset resources
//   ERFlash         - Flash/APT UI resources
//   ERMovie         - Video resources
//   ERSampledata    - Audio sample data
//   ERSoundEvent    - Sound event definitions
//   ERSoundTrackData - Music track data
//   ERAmbientScore  - Ambient music score
//   ERAmbientSound  - Ambient sound effects
//   ERQuickdata     - Quick-access data
//   EREdithTreeSet  - Edith behavior tree sets
//   ERTQuantize     - Texture quantization data

// --- EResource::Read ---
// Address: 0x80848998, Size: 260 bytes
// NON_MATCHING - annotated pseudocode
//
// Reads a resource from a stream. This is the base implementation that
// reads the resource header (type, name, size, version).
//
// void EResource::Read(EStream& stream) {
//     // Read type info
//     u16 typeKey = stream.ReadU16();
//     u16 version = stream.ReadU16();
//     u32 size = stream.ReadU32();
//
//     // Read resource name (null-terminated string)
//     char name[64];
//     stream.ReadString(name, 64);
//
//     SetResName(name);
//     SetResSize(size);
//     // Version info stored for subclass deserialization
// }

// --- EResource::Load ---
// Address: 0x80848A9C, Size: 248 bytes
// NON_MATCHING - annotated pseudocode
//
// Loads a resource from a file. Opens a read stream on the file and
// delegates to Read().
//
// void EResource::Load(EFile& file) {
//     EMemoryReadStream stream;
//     stream.Init(&file);
//     Read(stream);
//     // Subclasses override Read() to handle type-specific data
// }


//=============================================================================
//
//  PART 9: COMPLETE LOADING PIPELINE DIAGRAM
//
//=============================================================================
//
// === DVD → Memory Loading Pipeline ===
//
//   +------------------+
//   |  GameCube DVD    |
//   |  /files/DATA/    |
//   |    *.arc files   |
//   |    *.NGH files   |
//   +--------+---------+
//            |
//            v
//   +------------------+     +------------------+
//   |  DVDFileSystem   |---->|  ENgcFile         |
//   |  (Dolphin SDK)   |     |  (file I/O)       |
//   +--------+---------+     +------------------+
//            |
//            v
//   +------------------+
//   | ArcFileInfo      |  Validates archive headers,
//   | (per-archive)    |  handles DVD→HDD caching
//   +--------+---------+
//            |
//            +------------+------------------+
//            |            |                  |
//            v            v                  v
//   +-------------+  +-------------+  +-------------+
//   |EResource    |  | NghResFile  |  |IFFResFile2  |
//   |Manager      |  | (.NGH)      |  | (.iff)      |
//   | (per-type)  |  |             |  |             |
//   +------+------+  +------+------+  +------+------+
//          |                |                |
//          v                v                v
//   +-------------+  +-------------+  +-------------+
//   |EResource    |  | Sections:   |  | Block Map:  |
//   |LoaderImpl   |  |  Host       |  |  'rsmp'     |
//   | (thread)    |  |  Both       |  |  'BHAV'     |
//   +------+------+  |  Thumb      |  |  'POSI'     |
//          |         +------+------+  |  'TPRP'     |
//          v                |         +------+------+
//   +-------------+         |                |
//   |EResourceMap |         v                v
//   | (hash table)|  +-------------+  +-------------+
//   +------+------+  |ChainResFile |  | IFFResMap   |
//          |         | (layered    |  | (type dir)  |
//          v         |  lookup)    |  +-------------+
//   +-------------+  +------+------+
//   | EResource   |         |
//   | subclasses: |         v
//   |  ERTexture  |  +-------------+
//   |  ERModel    |  | Memory::    |
//   |  ERShader   |  | HandleNode  |
//   |  ERFont     |  | (ref-counted|
//   |  ERAnim     |  |  data)      |
//   |  ERLevel    |  +-------------+
//   |  ERFlash    |
//   |  ...        |
//   +-------------+
//
// === Loading Sequence (typical game asset) ===
//
//  1. Game code calls EResourceManager::AddRef("texture_name")
//  2. EResourceManager::CalcId() hashes the name to a u32
//  3. EResourceManager::TryIncrementResource() checks if already loaded
//  4. If not loaded, EResourceManager::addRef() is called
//  5. addRef() calls EResourceLoaderImpl::Load() (may be async)
//  6. Loader thread calls DoLoadResource()
//  7. DoLoadResource() calls manager->LookupId() → binary search
//  8. Gets archive file via GetArchiveFile() (opens .arc if needed)
//  9. Seeks to resource offset in archive
// 10. Reads resource data via EFile::Read()
// 11. Creates appropriate EResource subclass via factory
// 12. Calls EResource::Read() to deserialize
// 13. Adds to EResourceMap for future lookups
// 14. Returns EResource* to caller
//
// === Loading Sequence (.NGH save/neighborhood) ===
//
//  1. Game code calls NghResFile::ReadFromFile(filename)
//  2. Opens file via DVDFileSystem
//  3. Reads host section:
//     a. NghResFile::ReadSection() reads raw bytes from DVD
//     b. NghResFile::DecompressSection() decompresses (RefPack or LZSS)
//     c. NghResFile::ReadHostSection() parses resource directory
//     d. For each entry: creates HandleNode, copies data, adds to lookup
//  4. Reads both section (same flow, shared data)
//  5. Reads thumb section (same flow, thumbnails)
//  6. Sections are cached to MemoryCardCache for fast reload
//
// === Loading Sequence (IFF container) ===
//
//  1. IFFResFile2::Open(filename) opens the .iff file
//  2. Reads and validates 64-byte IFF header (magic + version)
//  3. For IFF v2.5: reads 'rsmp' resource map directly
//  4. For IFF v2.0: scans all blocks sequentially
//  5. Builds IFFResMap (type directory + per-type block lists)
//  6. ChainResFile layers IFF files for fallback lookup
//  7. Game code calls GetByID(type, id) on ChainResFile
//  8. ChainResFile walks its file chain until resource is found
//  9. IFFResFile2::Load() reads and returns the block data
//
// === Key Constants ===
//
// IFF Magic (validated byte-by-byte with wildcards):
//   Pattern at 0x8042408C (64 bytes), wildcard = 0x2A ('*')
//   IFF v2.0 version code: 0x0200
//   IFF v2.5 version code: 0x0205
//
// NGH Section Types:
//   0 = Host section (platform-specific data)
//   1 = Both section (cross-platform data)
//   2 = Thumb section (thumbnail images)
//
// NGH Compression:
//   Type 2 = RefPack (EA's proprietary LZ-based compression)
//   Types 7-8 = Valid compression range marker
//
// Resource Manager Capacities (from Init string matching):
//   level:      800 entries
//   tquantize:  700 entries
//   flash:      550 entries
//   model:      500 entries
//   anim:       250 entries
//   shader:     150 entries
//   shaderlow:  100 entries
//   texture:     50 entries
//   fontpage:    20 entries
//   binary:      16 entries
//   sample:      10 entries
//   default:      4 entries
//
// ChainResFile: max 8 chained files, 24 bytes per slot
// EResourceMap: hash table for loaded resource lookup
// Maximum resources per manager: ~272 (0xCC4 / 12 bytes per record)


//=============================================================================
//
//  PART 10: PC PORT CONSIDERATIONS
//
//=============================================================================
//
// For a PC port, the following changes are needed to the asset loading pipeline:
//
// 1. FILE SYSTEM REPLACEMENT
//    - Replace ENgcFile / DVDFileSystem with standard fopen/fread
//    - The DVDFileSystem uses Dolphin SDK's DVDOpen/DVDReadAsync
//    - PC version should use memory-mapped files for large archives
//    - Key functions to replace:
//      * DVDFileSystem_Open (0x802C6EA8)
//      * DVDFileSystem_Read (0x802C7000)
//      * DVDFileSystem_Close (0x802C70BC)
//
// 2. ENDIAN CONVERSION
//    - GameCube is big-endian, PC is little-endian
//    - NghResFile::SwapFourByteNumber (0x800D8A84) and
//      SwapTwoByteNumber (0x800D8A70) handle byte swapping
//    - IFF files are big-endian on disc
//    - All archive index entries need byte swapping
//    - The game already has byte-swap code for memory card cross-platform support
//
// 3. ARCHIVE EXTRACTION
//    - .arc files can be extracted using the sorted index at the start
//    - Binary search with EResourceManager::BinarySearch()
//    - Resource IDs are 32-bit hashes of filenames (EResourceManager::CalcId)
//    - For PC: could load assets from flat directory structure instead
//
// 4. THREADING
//    - EResourceLoaderImpl runs on a GameCube OS thread
//    - Replace with std::thread / platform threads
//    - Message queue (EResLoaderMsgQueue) can use std::queue with mutex
//    - Semaphore (ESemaphore) → std::counting_semaphore or condition_variable
//
// 5. MEMORY MANAGEMENT
//    - EAHeap is the custom EA allocator
//    - For PC: can use standard malloc/free or a modern allocator
//    - EAHeap_Alloc alignment (64-byte) can be relaxed on PC
//    - EFrameAllocGroup for per-frame scratch memory → arena allocator
//
// 6. .NGH FILE HANDLING
//    - .NGH files store save game state
//    - PC version should read from local files instead of memory card
//    - RefPack decompression (at 0x800D90D0) needs to be preserved
//    - Checksum validation (CRC32) must match original
//
// 7. IFF FILE HANDLING
//    - IFF format is well-documented from The Sims modding community
//    - Version 2.5 with 'rsmp' resource map is the primary format
//    - Block types (BHAV, POSI, TPRP, etc.) are the same as Sims 2 PC
//    - SimAntics bytecode in BHAV blocks is platform-independent
//
// 8. PREFETCH SYSTEM
//    - EResPrefetch handles background loading for streaming
//    - On PC: can simplify or replace with async file I/O
//    - The prefetch buffer system (EScratchBuffUser) manages temp memory
//    - PC version could use larger buffers for faster loading

// End of asset loading pipeline decompilation
