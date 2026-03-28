#ifndef BIGF_READER_H
#define BIGF_READER_H

#include "types.h"

// EA BIGF container format reader
// Used by flashes.arc entries to pack APT UI files

struct BigfEntry {
    u32  offset;       // offset within BIGF data
    u32  size;         // size in bytes
    char name[128];    // filename (null-terminated)
};

struct BigfFile {
    u8*         data;        // raw BIGF data (owned)
    u32         dataSize;    // total BIGF data size
    BigfEntry*  entries;     // entry array (owned)
    int         numEntries;  // number of entries
};

// Parse a BIGF container from raw data.
// The data pointer is NOT owned — caller must keep it alive.
// Returns NULL on failure.
BigfFile* bigf_parse(const u8* data, u32 dataSize);

// Free a parsed BIGF file.
void bigf_free(BigfFile* bigf);

// Get entry data pointer (returns pointer within the BIGF data).
const u8* bigf_get_entry_data(const BigfFile* bigf, int index);

// Find entry by name (case-insensitive, partial match on extension).
int bigf_find(const BigfFile* bigf, const char* name);

#endif // BIGF_READER_H
