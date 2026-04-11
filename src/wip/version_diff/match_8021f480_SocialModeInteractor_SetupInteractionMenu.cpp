struct GameData_SIM2;
extern GameData_SIM2 _gd;
extern void *g_uiaudio;

void SMI_ResetChosenAction2(void *self);
int HUDTarget_IsMenuAvailable2(void *hud, int personID);
int FlashPiMenu_CreateInteractionMenu2(void *piMenu, void *xobj, void *interactionList);
void HUDTarget_ShowMenu2(void *hud, int personID);
void *op_new_SIM2(int size);
void *UIAUDIO_ctor2(void *mem);
void UIAUDIO_PlaySound2(void *audio, unsigned int soundID);

struct SocialModeInteractor_SIM2 {
    int m_personID;
    char pad_04[0x5C];
    short m_chosenAction;

    int SetupInteractionMenu(void *xobj, void *interactionList);
};

int SocialModeInteractor_SIM2::SetupInteractionMenu(void *xobj, void *interactionList) {
    SMI_ResetChosenAction2(this);

    char *gd = (char *)&_gd;

    void *hud = *(void **)(gd + 0x44);
    if (hud != 0) {
        if (HUDTarget_IsMenuAvailable2(hud, m_personID) == 0) {
            return 0;
        }
    }

    int pid = m_personID;
    void *piMenu = *(void **)(gd + pid * 16 + 0xFC);
    if (piMenu != 0) {
        if (FlashPiMenu_CreateInteractionMenu2(piMenu, xobj, interactionList) != 0) {
            HUDTarget_ShowMenu2(*(void **)(gd + 0x44), m_personID);

            if (g_uiaudio == 0) {
                void *mem = op_new_SIM2(120);
                g_uiaudio = UIAUDIO_ctor2(mem);
            }

            UIAUDIO_PlaySound2(g_uiaudio, 0x374BDCEAu);
        }
    }

    return 1;
}
