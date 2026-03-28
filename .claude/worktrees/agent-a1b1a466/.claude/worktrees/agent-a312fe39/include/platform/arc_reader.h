#ifndef ARC_READER_H
#define ARC_READER_H

#include "types.h"
#include <vector>

// Forward declarations
struct ArcEntry;
struct ArcArchive;

// Entry in an .arc archive
struct ArcEntry {
    char     tag[5];        // 4-char type tag + null
    char     name[256];     // resource name
    u32      data_offset;   // absolute offset in archive file
    u32      data_size;     // size of raw data
    u32      header_value;  // first u32 of entry header
};

// Opened .arc archive
struct ArcArchive;

// Open/close archives
ArcArchive* arc_open(const char* filepath);
void        arc_close(ArcArchive* arc);

// Find entries
const ArcEntry* arc_find(ArcArchive* arc, const char* name);

// Read entry data (caller must free() the returned buffer)
u8*  arc_read(ArcArchive* arc, const ArcEntry* entry, u32* out_size);
u8*  arc_read_entry(ArcArchive* arc, const char* name, u32* out_size);

// Debug
void arc_list(ArcArchive* arc);

// Global registry
int          arc_open_all(const char* data_dir);
ArcArchive*  arc_get(int index);
int          arc_count();

#endif // ARC_READER_H
