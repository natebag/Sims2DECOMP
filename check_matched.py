import os, re

code_funcs = [
    (0x80038E34, 28, "EyeToyClient::ApplyPresetFilter(int)"),
    (0x80039200, 32, "EyeToyClient::GetRepTexture(int)"),
    (0x80039220, 32, "EyeToyClient::GetRepShaderERTextureID(EyeToyClient::RepShaderMapping)"),
    (0x80039498, 32, "EyeToyClient::Debug::GetTierNthRepShader(int, int)"),
    (0x8008FF18, 24, "LiveModeInitState::DatasetPendingAddRefAsync(void)"),
    (0x8009018C, 24, "ChangeHouseLoadHouse::DatasetPendingAddRefAsync(void)"),
    (0x80090BB8, 24, "LoadingScreenStateMachine::IsReadyToLoad(void)"),
    (0x800922DC, 24, "MUStatesSaveNewGame::Reset(void)"),
    (0x8009B768, 24, "BitArray64::operator=(BitArray64 &)"),
    (0x800D9430, 24, "ObjDefinition::GetMultiTileOffsets(int *, int *) const"),
    (0x800EAA48, 32, "cXObjectImpl::SetMiscFlag(cXObject::MiscFlag, bool)"),
    (0x800EAA68, 24, "cXObjectImpl::GetMiscFlag(cXObject::MiscFlag)"),
    (0x800EB218, 24, "cXObjectImpl::CountObjectSlots(void)"),
    (0x800EB378, 28, "cXObjectImpl::IsMultiTile(void)"),
    (0x800EB3F4, 32, "cXObjectImpl::GetNumRoutingSlots(void)"),
    (0x800F9988, 32, "ObjectModuleImpl::GetPeople(int)"),
    (0x800F99F0, 32, "ObjectModuleImpl::GetNumGlobalRoutingSlots(void)"),
    (0x80142B64, 32, "RoutingSlot::AllowDirection(int)"),
    (0x801453EC, 28, "SpriteSlot::GetSelector(void) const"),
    (0x801454D0, 28, "RoutingSlot::IsDirectionAllowed(int) const"),
    (0x80145560, 32, "RoutingSlot::SetIgnoreRooms(bool)"),
    (0x8014563C, 32, "RoutingSlot::SetAllowFailureTrees(bool)"),
    (0x80145668, 32, "RoutingSlot::SetAllowDifferentAlts(bool)"),
    (0x80145694, 32, "RoutingSlot::SetUseAverageObjectLocation(bool)"),
    (0x80146998, 24, "TileWalls::HasWall(TileWallsSegment) const"),
    (0x80147050, 28, "TileWalls::RotateSegment(TileWallsSegment, int)"),
    (0x8014706C, 28, "TileWalls::RotateDiagonal(DiagonalSideSelector, int)"),
    (0x80146FDC, 28, "TileWalls::GetFloorValue(DiagonalSideSelector) const"),
    (0x8017BF2C, 24, "UIHDTV::IsFoundNumberNegative(char *, int)"),
    (0x80183120, 24, "ActionMenu::MenuItem::GetNthItem(int)"),
    (0x801845C4, 32, "GetSelectedActionMenuItem(unsigned int)"),
    (0x80189A18, 28, "HUDTarget::RequestQuitGame(bool)"),
    (0x80189A34, 28, "HUDTarget::GetJobBarCount(void)"),
    (0x80189AB0, 24, "HUDTarget::IsPlayerHUDVisible(int) const"),
    (0x80190DF4, 24, "InteractionHelper::GetNext(IHRecord *)"),
    (0x801C1144, 24, "M2MTarget::GetMemCardPort(void)"),
    (0x801DCD68, 32, "R2LTarget::RecordIndexToGridIndex(int)"),
    (0x801ECC58, 32, "StaticGetShaderId(InteractorModule::WallPaperData *)"),
    (0x801ECC78, 32, "StaticGetShaderId(InteractorModule::WallData *)"),
    (0x801ECC98, 32, "StaticGetShaderId(InteractorModule::FloorData *)"),
    (0x8020AF88, 32, "InteractorModule::InteractorInputManager::GetSessionData(int)"),
    (0x80210240, 32, "InteractorModule::InteractorResourceSet::GetOrderTableDataCount(void)"),
    (0x8021CEF0, 24, "FadeSquare::StopDraw(void)"),
    (0x8021CFB0, 28, "FadeSquare::ShouldDraw(void)"),
    (0x80223FD0, 32, "InteractorModule::WallManipulator::GetFenceShaderID(void)"),
    (0x80224048, 24, "InteractorModule::WallManipulator::GetAffectedWallHeight(void)"),
    (0x8023AA74, 32, "CDirtyXmlNode::firstChild(void)"),
]

# collect matched addrs
matched = set()
vd = set()
for root, dirs, files in os.walk('src/matched'):
    for f in files:
        m = re.search(r'0x([0-9a-fA-F]{8})', f)
        if m:
            matched.add(int(m.group(1), 16))

for root, dirs, files in os.walk('src/wip/version_diff'):
    for f in files:
        m = re.search(r'0x([0-9a-fA-F]{8})', f)
        if m:
            vd.add(int(m.group(1), 16))

for addr, size, name in code_funcs:
    st = "MATCHED" if addr in matched else ("vd" if addr in vd else "OPEN")
    print(f"{st:8} 0x{addr:08X} {size:3}B {name}")
