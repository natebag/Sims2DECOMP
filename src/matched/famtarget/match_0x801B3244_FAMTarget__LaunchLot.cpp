// 0x801b3244 FAMTarget::LaunchLot (64B)

extern void ESimsApp_SetStartLot(char*, int);
extern void UIObjectBase_UIRouter_FlowGoto(char*);
extern const char FAM_startlot_string[];
extern const char FAM_launchlot_flow[];

class FAMTarget {
public:
    char pad[0x14C];
    int m_selectedLotIndex;  // 0x14C

    int ConvertSelectedLotIndexToActualGameIndex(int idx);
    void LaunchLot(void);
};

void FAMTarget::LaunchLot(void) {
    ESimsApp_SetStartLot((char*)FAM_startlot_string, ConvertSelectedLotIndexToActualGameIndex(m_selectedLotIndex));
    UIObjectBase_UIRouter_FlowGoto((char*)FAM_launchlot_flow);
}


