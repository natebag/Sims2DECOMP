// arc_reader.cpp — EA GameCube .arc archive reader for PC port
//
// Format (reverse engineered from Sims 2 GC disc):
//   Header (16 bytes):
//     u32 LE: data_size
//     u32 BE: version (0x00000100)
//     u64 LE: timestamp (Windows FILETIME)
//
//   Entries (sequential, variable length):
//     u32 BE: header_value (varies per type)
//     4 bytes: type tag ASCII ("ANIM", "MODL", "TXFL", "FONT", etc.)
//     u32 BE: 0xFFFFFFFF sentinel
//     u32 BE: name_length (including null terminator)
//     name_length bytes: null-terminated filename
//     [padding to 4-byte alignment]
//     raw data bytes until next entry

#include "types.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>

// Big-endian read helpers
static u32 read_be_u32(const u8* p) {
    return ((u32)p[0] << 24) | ((u32)p[1] << 16) | ((u32)p[2] << 8) | p[3];
}

static u32 read_le_u32(const u8* p) {
    return p[0] | ((u32)p[1] << 8) | ((u32)p[2] << 16) | ((u32)p[3] << 24);
}

// ============================================================================
// ArcEntry — a single resource within an .arc archive
// ============================================================================
struct ArcEntry {
    char     tag[5];        // 4-char type tag + null (e.g., "MODL", "TXFL")
    char     name[256];     // resource name
    u32      data_offset;   // offset of data within the archive file
    u32      data_size;     // size of raw data in bytes
    u32      header_value;  // first u32 of entry header (varies per type)
};

// ============================================================================
// ArcArchive — represents an opened .arc file
// ============================================================================
struct ArcArchive {
    char                filepath[512];
    FILE*               file;
    u32                 data_size;
    u32                 version;
    u64                 timestamp;
    std::vector<ArcEntry> entries;
    bool                loaded;
};

// ============================================================================
// arc_open — open an .arc file and parse its directory
// ============================================================================
ArcArchive* arc_open(const char* filepath) {
    FILE* f = fopen(filepath, "rb");
    if (!f) {
        fprintf(stderr, "[ARC] Failed to open: %s\n", filepath);
        return nullptr;
    }

    // Get file size
    fseek(f, 0, SEEK_END);
    long file_size = ftell(f);
    fseek(f, 0, SEEK_SET);

    if (file_size < 16) {
        fprintf(stderr, "[ARC] File too small: %s (%ld bytes)\n", filepath, file_size);
        fclose(f);
        return nullptr;
    }

    // Read header
    u8 header[16];
    fread(header, 1, 16, f);

    ArcArchive* arc = new ArcArchive();
    strncpy(arc->filepath, filepath, sizeof(arc->filepath) - 1);
    arc->file = f;
    arc->data_size = read_le_u32(header);
    arc->version = read_be_u32(header + 4);
    arc->timestamp = *(u64*)(header + 8);
    arc->loaded = true;

    if (file_size <= 16) {
        // Empty archive
        return arc;
    }

    // Parse entries
    // Read the rest of the file into memory for parsing
    long remaining = file_size - 16;
    u8* data = (u8*)malloc(remaining);
    if (!data) {
        fprintf(stderr, "[ARC] Out of memory reading %s\n", filepath);
        return arc;
    }
    fread(data, 1, remaining, f);

    long pos = 0;
    while (pos < remaining - 12) {
        // Check if we have a tagged entry:
        // [u32 header_val] [4-char tag] [0xFFFFFFFF] [u32 name_len] [name] [data]
        u32 header_val = read_be_u32(data + pos);

        // Check if bytes 4-7 are ASCII (type tag)
        bool is_ascii_tag = true;
        for (int i = 4; i < 8 && pos + i < remaining; i++) {
            u8 c = data[pos + i];
            if (c < 32 || c >= 127) { is_ascii_tag = false; break; }
        }

        if (!is_ascii_tag || pos + 16 > remaining) break;

        // Check for sentinel
        u32 sentinel = read_be_u32(data + pos + 8);
        if (sentinel != 0xFFFFFFFF) break;

        // Read name length
        u32 name_len = read_be_u32(data + pos + 12);
        if (name_len == 0 || name_len > 1024 || pos + 16 + name_len > remaining) break;

        ArcEntry entry;
        memcpy(entry.tag, data + pos + 4, 4);
        entry.tag[4] = '\0';
        entry.header_value = header_val;

        // Copy name (excluding null terminator)
        u32 copy_len = name_len - 1;
        if (copy_len > 255) copy_len = 255;
        memcpy(entry.name, data + pos + 16, copy_len);
        entry.name[copy_len] = '\0';

        // Data starts after name, aligned to 4 bytes
        u32 data_start = 16 + name_len;
        while (data_start % 4 != 0) data_start++;

        entry.data_offset = 16 + (u32)pos + data_start; // absolute offset in file

        // Find next entry to determine data size
        // Scan forward for next sentinel pattern
        u32 next_entry_pos = data_start;
        bool found_next = false;

        for (long scan = pos + data_start + 4; scan < remaining - 12; scan += 4) {
            // Look for ASCII tag followed by 0xFFFFFFFF
            bool tag_ok = true;
            for (int i = 0; i < 4; i++) {
                u8 c = data[scan + i];
                if (c < 32 || c >= 127) { tag_ok = false; break; }
            }
            if (tag_ok && read_be_u32(data + scan + 4) == 0xFFFFFFFF) {
                // Found next entry — back up 4 bytes for header_val
                u32 next_start = (u32)(scan - 4);
                entry.data_size = next_start - (u32)pos - data_start;
                pos = next_start;
                found_next = true;
                break;
            }
        }

        if (!found_next) {
            entry.data_size = (u32)(remaining - pos - data_start);
            arc->entries.push_back(entry);
            break;
        }

        arc->entries.push_back(entry);
    }

    free(data);

    printf("[ARC] Opened %s: %zu entries\n", filepath, arc->entries.size());
    return arc;
}

// ============================================================================
// arc_close — close an archive
// ============================================================================
void arc_close(ArcArchive* arc) {
    if (!arc) return;
    if (arc->file) fclose(arc->file);
    delete arc;
}

// ============================================================================
// arc_find — find an entry by name (case-insensitive)
// ============================================================================
const ArcEntry* arc_find(ArcArchive* arc, const char* name) {
    if (!arc) return nullptr;
    for (size_t i = 0; i < arc->entries.size(); i++) {
#ifdef _WIN32
        if (_stricmp(arc->entries[i].name, name) == 0)
#else
        if (strcasecmp(arc->entries[i].name, name) == 0)
#endif
            return &arc->entries[i];
    }
    return nullptr;
}

// ============================================================================
// arc_find_by_tag — find entries by type tag
// ============================================================================
std::vector<const ArcEntry*> arc_find_by_tag(ArcArchive* arc, const char* tag) {
    std::vector<const ArcEntry*> results;
    if (!arc) return results;
    for (size_t i = 0; i < arc->entries.size(); i++) {
        if (strcmp(arc->entries[i].tag, tag) == 0)
            results.push_back(&arc->entries[i]);
    }
    return results;
}

// ============================================================================
// arc_read — read an entry's data into a buffer
// ============================================================================
u8* arc_read(ArcArchive* arc, const ArcEntry* entry, u32* out_size) {
    if (!arc || !entry || !arc->file) return nullptr;

    u8* buf = (u8*)malloc(entry->data_size);
    if (!buf) return nullptr;

    fseek(arc->file, entry->data_offset, SEEK_SET);
    size_t read = fread(buf, 1, entry->data_size, arc->file);

    if (out_size) *out_size = (u32)read;
    return buf;
}

// ============================================================================
// arc_read_entry — convenience: find by name and read
// ============================================================================
u8* arc_read_entry(ArcArchive* arc, const char* name, u32* out_size) {
    const ArcEntry* entry = arc_find(arc, name);
    if (!entry) return nullptr;
    return arc_read(arc, entry, out_size);
}

// ============================================================================
// arc_list — print all entries (debug)
// ============================================================================
void arc_list(ArcArchive* arc) {
    if (!arc) return;
    printf("[ARC] %s: %zu entries\n", arc->filepath, arc->entries.size());
    for (size_t i = 0; i < arc->entries.size(); i++) {
        const ArcEntry& e = arc->entries[i];
        printf("  [%3zu] %s | %-40s | %8u bytes @ 0x%08X\n",
               i, e.tag, e.name, e.data_size, e.data_offset);
    }
}

// ============================================================================
// Global archive registry — maps category names to open archives
// ============================================================================
static ArcArchive* g_archives[32] = {};
static int g_archive_count = 0;

void arc_register(ArcArchive* arc) {
    if (g_archive_count < 32) {
        g_archives[g_archive_count++] = arc;
    }
}

ArcArchive* arc_get(int index) {
    if (index >= 0 && index < g_archive_count)
        return g_archives[index];
    return nullptr;
}

int arc_count() { return g_archive_count; }

// ============================================================================
// arc_open_all — open all .arc files in a directory
// ============================================================================
int arc_open_all(const char* data_dir) {
    const char* arc_files[] = {
        "ambients.arc", "animatio.arc", "audiostr.arc", "binaries.arc",
        "characte.arc", "datasets.arc", "edithtre.arc", "effectsa.arc",
        "effectse.arc", "effectss.arc", "emitters.arc", "flashes.arc",
        "fonts.arc", "levels.arc", "models.arc", "movies.arc",
        "quickdat.arc", "samples.arc", "shaders.arc", "soundeve.arc",
        "soundtra.arc", "textures.arc", nullptr
    };

    int count = 0;
    for (int i = 0; arc_files[i]; i++) {
        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", data_dir, arc_files[i]);

        ArcArchive* arc = arc_open(path);
        if (arc) {
            arc_register(arc);
            count++;
        }
    }

    printf("[ARC] Opened %d archives from %s\n", count, data_dir);
    return count;
}
