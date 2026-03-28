#ifndef EPATHUTIL_H
#define EPATHUTIL_H

#include "types.h"

// EPathUtil - struct layout extracted from assembly analysis
// Estimated minimum size: 0x3 (3 bytes)
// 3 known fields (0 named), 20 methods

class EPathUtil {
public:
    // Methods
    void FixTrailingSlash(char *, char *);  // 0x8079799C (172B)
    void RemoveTrailingSlash(char *, char *);  // 0x80797AF8 (336B)
    void RemoveDriveLetter(char *, char *);  // 0x80797A48 (176B)
    void ExtractFilename(char *, char *);  // 0x80797C48 (212B)
    void ExtractRoot(char *, char *);  // 0x80797D1C (324B)
    void ExtractDirectory(char *, char *);  // 0x80797E60 (220B)
    void ExtractExtension(char *, char *);  // 0x80797F3C (196B)
    void MakeLegalFilename(char *, char *);  // 0x80797810 (264B)
    void RemoveRelationalDirectories(char *, char *);  // 0x80798000 (804B)
    void FixSlashesInPlace(char *);  // 0x80797918 (132B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_field_000;  // 0x000 [R/W] (ExtractDirectory, ExtractExtension, MakeLegalFilename, ...)
    u8 m_field_001;  // 0x001 [R/W] (ExtractDirectory, RemoveTrailingSlash)
    u8 m_field_002;  // 0x002 [W] (ExtractDirectory)
};

#endif // EPATHUTIL_H
