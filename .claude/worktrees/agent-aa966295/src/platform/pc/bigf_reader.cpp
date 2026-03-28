// bigf_reader.cpp — EA BIGF container format parser
//
// BIGF is EA's archive format used inside .arc entries for Flash/APT data.
// Each BIGF contains: .apt (bytecode), .const (constants), .geo (geometry),
// and .tgq (embedded textures).
//
// Format (mixed endianness):
//   Prefix:    2 bytes (variable, skip)
//   "BIGF":    4 bytes magic
//   Size:      4 bytes LE (total container size including header)
//   Count:     4 bytes BE (number of files)
//   Entries[]: { offset(4 BE), size(4 BE), name(null-terminated) }
//   File data follows at the specified offsets (relative to BIGF start)

#include "bigf_reader.h"
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cctype>

static u32 read_be32(const u8* p) {
    return ((u32)p[0] << 24) | ((u32)p[1] << 16) | ((u32)p[2] << 8) | p[3];
}

BigfFile* bigf_parse(const u8* data, u32 dataSize) {
    if (!data || dataSize < 16) return nullptr;

    // Find "BIGF" magic (usually at offset 2, sometimes 0)
    int magicOff = -1;
    for (int i = 0; i < 8 && i + 12 <= (int)dataSize; i++) {
        if (data[i] == 'B' && data[i+1] == 'I' && data[i+2] == 'G' && data[i+3] == 'F') {
            magicOff = i;
            break;
        }
    }
    if (magicOff < 0) return nullptr;

    const u8* bigf = data + magicOff;
    u32 bigfSize = dataSize - magicOff;

    if (bigfSize < 12) return nullptr;

    // Read header (count is BE, size bytes are LE but we don't need the total size)
    u32 numEntries = read_be32(bigf + 8);
    if (numEntries > 1000 || numEntries == 0) return nullptr;

    // Parse entry table
    BigfFile* file = (BigfFile*)calloc(1, sizeof(BigfFile));
    file->data = (u8*)data;  // not owned
    file->dataSize = dataSize;
    file->entries = (BigfEntry*)calloc(numEntries, sizeof(BigfEntry));
    file->numEntries = 0;

    u32 pos = 12;  // after magic + size + count
    for (u32 i = 0; i < numEntries; i++) {
        if (pos + 8 > bigfSize) break;

        BigfEntry entry;
        entry.offset = read_be32(bigf + pos) + magicOff;  // make relative to data start
        entry.size = read_be32(bigf + pos + 4);
        pos += 8;

        // Read name (null-terminated)
        int nameLen = 0;
        while (pos + nameLen < bigfSize && bigf[pos + nameLen] != '\0' && nameLen < 126) {
            nameLen++;
        }
        if (nameLen > 0) {
            memcpy(entry.name, bigf + pos, nameLen);
        }
        entry.name[nameLen] = '\0';
        pos += nameLen + 1;  // skip null terminator

        // Validate entry
        if (entry.offset < dataSize && entry.size <= dataSize) {
            file->entries[file->numEntries++] = entry;
        }
    }

    return file;
}

void bigf_free(BigfFile* bigf) {
    if (!bigf) return;
    free(bigf->entries);
    free(bigf);
}

const u8* bigf_get_entry_data(const BigfFile* bigf, int index) {
    if (!bigf || index < 0 || index >= bigf->numEntries) return nullptr;
    u32 off = bigf->entries[index].offset;
    if (off >= bigf->dataSize) return nullptr;
    return bigf->data + off;
}

int bigf_find(const BigfFile* bigf, const char* name) {
    if (!bigf || !name) return -1;

    for (int i = 0; i < bigf->numEntries; i++) {
        // Exact match
        if (strcmp(bigf->entries[i].name, name) == 0) return i;

        // Case-insensitive match
        const char* a = bigf->entries[i].name;
        const char* b = name;
        bool match = true;
        while (*a && *b) {
            if (tolower(*a) != tolower(*b)) { match = false; break; }
            a++; b++;
        }
        if (match && *a == '\0' && *b == '\0') return i;

        // Partial match: check if entry name ends with the search name
        int elen = (int)strlen(bigf->entries[i].name);
        int slen = (int)strlen(name);
        if (slen <= elen) {
            const char* suffix = bigf->entries[i].name + elen - slen;
            bool suffMatch = true;
            for (int j = 0; j < slen; j++) {
                if (tolower(suffix[j]) != tolower(name[j])) { suffMatch = false; break; }
            }
            if (suffMatch) return i;
        }
    }
    return -1;
}
