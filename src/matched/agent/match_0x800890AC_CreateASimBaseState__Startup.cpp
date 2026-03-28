/* CreateASimBaseState::Startup(void) at 0x800890AC (148B) */

extern char g_casDialogPaths[];

void AptViewer_SetCurrentPath(char* paths);
void CAS_LoadFile_01(); void CAS_LoadMovie_01();
void CAS_LoadFile_02(); void CAS_LoadMovie_02();
void CAS_LoadFile_03(); void CAS_LoadMovie_03();
void CAS_LoadFile_04(); void CAS_LoadMovie_04();
void CAS_LoadFile_05(); void CAS_LoadMovie_05();
void CAS_LoadFile_06(); void CAS_LoadMovie_06();
void CAS_LoadFile_07(); void CAS_LoadMovie_07();
void CAS_LoadFile_08(); void CAS_LoadMovie_08();
void CAS_LoadFile_09(); void CAS_LoadMovie_09();
void CAS_LoadFile_10(); void CAS_LoadMovie_10();
void CAS_LoadFile_11(); void CAS_LoadMovie_11();
void CAS_LoadFile_12(); void CAS_LoadMovie_12();
void CAS_LoadFile_13(); void CAS_LoadMovie_13();
void CAS_FinalizeLoad();

struct CreateASimBaseState {
    void Startup();
};

void CreateASimBaseState::Startup() {
    AptViewer_SetCurrentPath(g_casDialogPaths);
    CAS_LoadFile_01(); CAS_LoadMovie_01();
    CAS_LoadFile_02(); CAS_LoadMovie_02();
    CAS_LoadFile_03(); CAS_LoadMovie_03();
    CAS_LoadFile_04(); CAS_LoadMovie_04();
    CAS_LoadFile_05(); CAS_LoadMovie_05();
    CAS_LoadFile_06(); CAS_LoadMovie_06();
    CAS_LoadFile_07(); CAS_LoadMovie_07();
    CAS_LoadFile_08(); CAS_LoadMovie_08();
    CAS_LoadFile_09(); CAS_LoadMovie_09();
    CAS_LoadFile_10(); CAS_LoadMovie_10();
    CAS_LoadFile_11(); CAS_LoadMovie_11();
    CAS_LoadFile_12(); CAS_LoadMovie_12();
    CAS_LoadFile_13(); CAS_LoadMovie_13();
    CAS_FinalizeLoad();
}
