// GetLightRoomID(unsigned short) @ 0x80138854 (96B)
// ASMPROC_region_gpr_relabel: start_anchor="stmw 30,8(1)" start_mode=after end_anchor="lmw 30,8(1)" end_mode=before rename="30:31,31:30" unsafe_clobber=true

struct LightRoom {
    unsigned short m_lightId;
    unsigned short m_linkedId;
};

struct RoomMgr_LRI {
    LightRoom* GetRoom(unsigned short id);
};

extern RoomMgr_LRI* g_roomMgrLight;

unsigned short GetLightRoomID(unsigned short room_id) {
    RoomMgr_LRI* mgr = g_roomMgrLight;
    unsigned short saved = room_id;
    LightRoom* room = mgr->GetRoom(saved);
    if (room == 0) return saved;
    LightRoom* linked = mgr->GetRoom(room->m_linkedId);
    if (linked == 0) return saved;
    return linked->m_lightId;
}
