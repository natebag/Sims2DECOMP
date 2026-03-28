/* ECheatDMI::ECheatDMI(ECheatLookup *) at 0x800218EC (68B) */

extern int ECheatDMI_vtable[];

struct EDebugMenuItem {
    char pad[0x08];
    EDebugMenuItem();
};

struct ECheatLookup;

struct ECheatDMI : public EDebugMenuItem {
    int* m_vtable;
    ECheatLookup* m_cheat;

    ECheatDMI(ECheatLookup*);
};

ECheatDMI::ECheatDMI(ECheatLookup* cheat) : EDebugMenuItem() {
    m_cheat = cheat;
    m_vtable = ECheatDMI_vtable;
}
