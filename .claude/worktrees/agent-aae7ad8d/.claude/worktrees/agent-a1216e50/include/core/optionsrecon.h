#ifndef OPTIONSRECON_H
#define OPTIONSRECON_H

#include "types.h"

// OptionsRecon - Options/settings manager
// From: optionsrecon.obj
// Layout includes at least:
//   0x10: int m_pref (some preference value)
//   0x50: int m_savedPref (preserved copy for online)
class OptionsRecon {
public:
    // Stubbed - always returns 0
    int WriteToMemoryCard(char* filename, unsigned char flags);
    // Stubbed - always returns 0
    int ReadFromMemoryCard(char* filename, unsigned char flags);

    // Copies m_pref to m_savedPref, sets global flag
    void PreservePrefsForOnline(void);
    // Restores m_pref from m_savedPref
    void RestorePrefsForOnline(void);

private:
    char _pad0[0x10];
    int m_pref;            // offset 0x10
    char _pad1[0x3C];      // 0x14..0x4F
    int m_savedPref;       // offset 0x50
};

// SDA global: online prefs preserved flag (r13-0x7E64)
extern int g_onlinePrefsPreserved;

#endif // OPTIONSRECON_H
