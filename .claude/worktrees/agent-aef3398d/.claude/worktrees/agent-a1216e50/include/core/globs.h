#ifndef GLOBS_H
#define GLOBS_H

#include "types.h"

// Forward declarations
class iResFile;

// LightingParameters - 0x44 (68) bytes, zeroed on construction
// Data symbol at 0x80485e38
struct LightingParameters {
    char data[0x44]; // opaque data, zeroed by memset

    LightingParameters(void);
    ~LightingParameters(void);
};

// Globs - global game data singleton
// The global 'globs' pointer is stored at r13-32060 (0x804fdbe4 area)
class Globs {
public:
    static iResFile* pNghResFile;           // 0x804fdbe8
    static BOOL bPlaybackMode;              // 0x804fdbec
    static BOOL bStupidMode;                // 0x804fdbf0
    static BOOL s_handlingPlacementObject;  // 0x804fdbf4
    static int iSaveFileVersion;            // 0x804fdbf8

    Globs(void);
    ~Globs(void);
    void Startup(void);
    void Shutdown(void);
};

// Global instance pointer stored at r13-32060
extern Globs* globs;

// Static init/destroy (compiler-generated)
extern "C" void __static_initialization_and_destruction_0(int, int);

#endif // GLOBS_H
