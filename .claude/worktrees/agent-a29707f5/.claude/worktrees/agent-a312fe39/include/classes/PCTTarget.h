#ifndef PCTTARGET_H
#define PCTTARGET_H

#include "types.h"

// PCTTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x47F4 (18420 bytes)
// 70 known fields (27 named), 114 methods

class PCTTarget {
public:
    // Constructors / Destructors
    PCTTarget(PCTTarget::ePCTMode, int)  // 0x8052914C
    ~PCTTarget(void);  // 0x80529E38

    // Methods
    void static_GrabManipulatorCallback(InteractorModule::Interactor::CallbackData *);  // 0x80528510 (288B)
    void GrabManipulatorCallback(InteractorModule::Interactor::CallbackData *);  // 0x8052F86C (1744B)
    void static_PlaceModeCallback(InteractorModule::Interactor::CallbackData *);  // 0x80528630 (288B)
    void PlaceModeCallback(InteractorModule::Interactor::CallbackData *);  // 0x805305B8 (1196B)
    void static_WallManipulatorCallback(InteractorModule::Interactor::CallbackData *);  // 0x80528750 (288B)
    void WallManipulatorCallback(InteractorModule::Interactor::CallbackData *);  // 0x80530CDC (836B)
    void static_WallPainterCallback(InteractorModule::Interactor::CallbackData *);  // 0x80528870 (288B)
    void WallPainterCallback(InteractorModule::Interactor::CallbackData *);  // 0x80531560 (764B)
    void static_FloorPainterCallback(InteractorModule::Interactor::CallbackData *);  // 0x80528990 (288B)
    void FloorPainterCallback(InteractorModule::Interactor::CallbackData *);  // 0x80531A20 (588B)
    void SetVariable(char *, char *);  // 0x8052A0EC (3748B)
    void on_selection_changed(void);  // 0x8052D920 (1084B)
    void on_PCT_Scroll(int);  // 0x8052DD5C (488B)
    void on_tab_changed(void);  // 0x8052C664 (772B)
    void enter_place_tombstone_mode(void);  // 0x805301FC (212B)
    void on_PCT_ShowHelp(int);  // 0x8052EFE8 (604B)
    void on_PCT_EnterPlaceMode(void);  // 0x8052E0BC (1120B)
    void on_PCT_EnterToolMode(void);  // 0x8052DF44 (376B)
    void on_PCT_SetVisible(bool);  // 0x8052E51C (436B)
    /* ? */ GetVariable(char *);  // 0x8052AF90 (2052B)
    void get_cell_info_at_gridindex(unsigned int);  // 0x8052C5EC (120B)
    /* ? */ GetLocalizable(char *);  // 0x8052B794 (2648B)
    void get_motive_rating_value(unsigned int, unsigned wchar_t *);  // 0x8052ED24 (268B)
    void buy_fail_dialog_selection_callback(int);  // 0x8052FF3C (52B)
    void Update(void);  // 0x8052C1EC (888B)
    void Draw(ERC *);  // 0x8052C564 (76B)
    void get_cell_info_array_index(unsigned int);  // 0x8052C5B0 (60B)
    void on_tab_changed_objects(void);  // 0x8052CBA0 (972B)
    void on_tab_changed_wall(void);  // 0x8052CF6C (756B)
    void on_tab_changed_wallpaper(void);  // 0x8052D2DC (644B)
    void on_tab_changed_floor(void);  // 0x8052D614 (780B)
    void update_grid_shaders(void);  // 0x8052E6D0 (352B)
    void calc_motive_ratings(void);  // 0x8052E9CC (808B)
    void update_object_shader(void);  // 0x8052E830 (412B)
    void can_afford_selection(void);  // 0x8052EF14 (212B)
    void set_control_visible(char *, bool);  // 0x8052EE60 (48B)
    void refresh_text_field(char *, unsigned int);  // 0x8052EE30 (48B)
    void set_dialog_visible(bool);  // 0x8052EE90 (132B)
    void enter_place_mode(PCTTarget::cCellInfo *);  // 0x805302D0 (460B)
    void enter_tool_mode(PCTTarget::ePCTType, bool);  // 0x8052F5F8 (628B)
    void get_motive_rating_label(unsigned int, unsigned wchar_t *);  // 0x8052ECF4 (48B)
    void start_action_menu(void);  // 0x8052F244 (204B)
    void CreateGrabObjectMenu(TNodeList<ISimInstance *> &);  // 0x8052F310 (476B)
    void setup_interactor_camera(bool);  // 0x8052F4EC (268B)
    void enter_wall_mode(PCTTarget::cCellInfo *, bool);  // 0x80530A64 (632B)
    void enter_wallpaper_mode(PCTTarget::cCellInfo *, bool);  // 0x8053114C (672B)
    void enter_floor_mode(PCTTarget::cCellInfo *, bool);  // 0x8053185C (452B)
    void sell_dialog_selection_callback(int);  // 0x80530024 (472B)
    void delete_dialog_selection_callback(int);  // 0x8052FF70 (180B)
    void PickedUpObject(cXObject *);  // 0x8053049C (284B)
    void calc_wall_value(InteractorModule::Interactor::CallbackData *);  // 0x80531020 (300B)
    void calc_wallpaper_value(InteractorModule::Interactor::CallbackData *);  // 0x805313EC (372B)
    void calc_floor_tile_value(InteractorModule::Interactor::CallbackData *);  // 0x80531C6C (460B)
    void ZeroInputCallback(void);  // 0x80531E38 (48B)
    void DialogClosedCallback(void);  // 0x80531E68 (48B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_localizable;  // 0x000 [R/W] (GetLocalizable, PCTTarget, SetVariable, ...)
    u16 m_field_002;  // 0x002 [W] (PlaceModeCallback)
    f32 m_localizable_004;  // 0x004 [R/W] (GetLocalizable, PCTTarget, PlaceModeCallback, ...)
    f32 m_field_008;  // 0x008 [R/W] (PCTTarget, cCellInfo::GetName, cCellInfo::Init, ...)
    s16 m_localizable_00C;  // 0x00C [R/W] (GetLocalizable, GetVariable, PCTTarget, ...)
    u8 _pad_00E[2];  // 0x00E
    u32 m_field_010;  // 0x010 [R/W] (PCTTarget, cCellInfo::Init, calc_motive_ratings, ...)
    u16 m_localizable_014;  // 0x014 [R/W] (GetLocalizable, PCTTarget, cCellInfo::GetDesc, ...)
    u8 _pad_016[2];  // 0x016
    u8 m_field_018;  // 0x018 [R/W] (PCTTarget, enter_place_mode, enter_place_tombstone_mode, ...)
    u8 _pad_019[3];  // 0x019
    f32 m_variable;  // 0x01C [R/W] (PCTTarget, SetVariable, cCellInfo::Init, ...)
    u16 m_field_020;  // 0x020 [R/W] (PCTTarget, enter_floor_mode, enter_place_mode, ...)
    u8 _pad_022[2];  // 0x022
    s16 m_field_024;  // 0x024 [R/W] (PCTTarget, PlaceModeCallback, cCellInfo::GetPrice, ...)
    u8 _pad_026[2];  // 0x026
    u32 m_field_028;  // 0x028 [W] (PCTTarget)
    u32 m_field_02C;  // 0x02C [R] (enter_floor_mode, enter_place_mode, enter_place_tombstone_mode, ...)
    u8 _pad_030[8];  // 0x030
    u32 m_localizable_038;  // 0x038 [R/W] (GetLocalizable, PCTTarget, PlaceModeCallback, ...)
    u8 m_field_03C;  // 0x03C [R/W] (enter_floor_mode, enter_place_mode, enter_place_tombstone_mode, ...)
    u8 _pad_03D[0xB];  // 0x03D
    u32 m_field_048;  // 0x048 [W] (PCTTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (PCTTarget, ~PCTTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (PCTTarget, ~PCTTarget)
    u8 _pad_06C[8];  // 0x06C
    u32 m_variable_074;  // 0x074 [R/W] (SetVariable)
    u32 m_field_078;  // 0x078 [W] (PCTTarget)
    u32 m_variable_07C;  // 0x07C [R/W] (PCTTarget, SetVariable, on_selection_changed, ...)
    u32 m_variable_080;  // 0x080 [R/W] (PCTTarget, SetVariable, ~PCTTarget)
    u32 m_field_084;  // 0x084 [R/W] (FloorPainterCallback, GrabManipulatorCallback, PCTTarget, ...)
    u32 m_field_088;  // 0x088 [R/W] (PCTTarget, ~PCTTarget)
    u32 m_field_08C;  // 0x08C [R/W] (PCTTarget, ~PCTTarget)
    u32 m_variable_090;  // 0x090 [R/W] (GetVariable, PCTTarget, PlaceModeCallback, ...)
    u32 m_variable_094;  // 0x094 [R/W] (PCTTarget, SetVariable)
    u32 m_variable_098;  // 0x098 [R/W] (GetVariable, PCTTarget, SetVariable)
    u32 m_field_09C;  // 0x09C [R/W] (PCTTarget, on_tab_changed_floor, on_tab_changed_objects, ...)
    u32 m_field_0A0;  // 0x0A0 [R/W] (PCTTarget, on_tab_changed_objects)
    u32 m_field_0A4;  // 0x0A4 [R/W] (PCTTarget, on_tab_changed_objects, ~PCTTarget)
    u32 m_localizable_0A8;  // 0x0A8 [R/W] (GetLocalizable, GetVariable, PCTTarget, ...)
    u32 m_variable_0AC;  // 0x0AC [R/W] (GetVariable, PCTTarget, SetVariable, ...)
    u32 m_localizable_0B0;  // 0x0B0 [R/W] (GetLocalizable, GetVariable, PCTTarget, ...)
    u32 m_variable_0B4;  // 0x0B4 [R/W] (GetVariable, PCTTarget, on_PCT_Scroll, ...)
    u32 m_localizable_0B8;  // 0x0B8 [R/W] (GetLocalizable, GetVariable, PCTTarget, ...)
    u32 m_field_0BC;  // 0x0BC [R/W] (PCTTarget, calc_motive_ratings, get_cell_info_at_gridindex, ...)
    u32 m_variable_0C0;  // 0x0C0 [R/W] (GetVariable, PCTTarget, calc_motive_ratings, ...)
    u32 m_variable_0C4;  // 0x0C4 [R/W] (GetVariable, PCTTarget, on_selection_changed)
    u32 m_variable_0C8;  // 0x0C8 [R/W] (GetVariable, PCTTarget, on_selection_changed)
    u32 m_field_0CC;  // 0x0CC [R] (on_selection_changed)
    u32 m_field_0D0;  // 0x0D0 [R] (on_selection_changed)
    u32 m_field_0D4;  // 0x0D4 [R] (on_selection_changed)
    u32 m_field_0D8;  // 0x0D8 [R] (on_selection_changed)
    u32 m_field_0DC;  // 0x0DC [R] (on_selection_changed)
    u32 m_field_0E0;  // 0x0E0 [R] (on_selection_changed)
    u32 m_field_0E4;  // 0x0E4 [R/W] (CreateGrabObjectMenu, PCTTarget, Update, ...)
    u32 m_field_0E8;  // 0x0E8 [R/W] (PCTTarget, WallManipulatorCallback, WallPainterCallback, ...)
    u32 m_field_0EC;  // 0x0EC [R/W] (PCTTarget, on_PCT_SetVisible, on_PCT_ShowHelp)
    u32 m_variable_0F0;  // 0x0F0 [R/W] (GetVariable, GrabManipulatorCallback, PCTTarget, ...)
    u32 m_field_0F4;  // 0x0F4 [W] (GrabManipulatorCallback, PCTTarget, Update, ...)
    u32 m_field_0F8;  // 0x0F8 [W] (GrabManipulatorCallback, Update, on_PCT_EnterPlaceMode)
    u8 _pad_0FC[4];  // 0x0FC
    u32 m_field_100;  // 0x100 [W] (GrabManipulatorCallback)
    u8 _pad_104[4];  // 0x104
    u32 m_field_108;  // 0x108 [W] (GrabManipulatorCallback, on_PCT_EnterPlaceMode)
    u8 _pad_10C[0x38];  // 0x10C
    u32 m_field_144;  // 0x144 [W] (GrabManipulatorCallback, PCTTarget, Update, ...)
    u8 _pad_148[0xC];  // 0x148
    u32 m_field_154;  // 0x154 [W] (GrabManipulatorCallback, PCTTarget, Update, ...)
    u8 _pad_158[0xC];  // 0x158
    u32 m_field_164;  // 0x164 [W] (GrabManipulatorCallback, PCTTarget, Update, ...)
    u8 _pad_168[0x9C];  // 0x168
    u32 m_variable_204;  // 0x204 [R] (GetVariable, SetVariable)
    u8 _pad_208[4];  // 0x208
    u32 m_variable_20C;  // 0x20C [R/W] (FloorPainterCallback, GetVariable, PCTTarget, ...)
    u32 m_field_210;  // 0x210 [R/W] (PCTTarget, calc_floor_tile_value, calc_wall_value, ...)
    u32 m_localizable_214;  // 0x214 [R/W] (FloorPainterCallback, GetLocalizable, GrabManipulatorCallback, ...)
    u32 m_field_218;  // 0x218 [R/W] (PCTTarget, on_selection_changed, on_tab_changed_objects, ...)
    u32 m_field_21C;  // 0x21C [R/W] (PCTTarget, on_selection_changed, ~PCTTarget)
    u8 _pad_220[0xC];  // 0x220
    u32 m_field_22C;  // 0x22C [R/W] (PCTTarget, PlaceModeCallback)
    u32 m_field_230;  // 0x230 [R/W] (PCTTarget, PlaceModeCallback)
    u32 m_variable_234;  // 0x234 [R/W] (GetVariable, PCTTarget, PlaceModeCallback, ...)
    u32 m_variable_238;  // 0x238 [R/W] (GetVariable, PCTTarget, PlaceModeCallback, ...)
    u32 m_variable_23C;  // 0x23C [R/W] (GetVariable, PCTTarget, PlaceModeCallback, ...)
    u32 m_field_240;  // 0x240 [R/W] (PCTTarget, PlaceModeCallback, ~PCTTarget)
    u8 _pad_244[0x45AC];  // 0x244
    f32 m_field_47F0;  // 0x47F0 [R] (enter_tool_mode)
};

#endif // PCTTARGET_H
