#!/bin/bash
cd "$(dirname "$0")/../.."
TMPF="src/wip/_tmp_blr_test.cpp"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" > "$TMPF"
echo "// 0x8000AC28 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8000AC28 4 2>&1 | tail -1)
echo "0x8000AC28 freeTexture(void: $OUT"
echo "// 0x8000ACE0 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8000ACE0 4 2>&1 | tail -1)
echo "0x8000ACE0 bindTexture(void: $OUT"
echo "// 0x8000DDD8 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8000DDD8 4 2>&1 | tail -1)
echo "0x8000DDD8 AptAuxPCEorGL_FinishAsyncLoads(void): $OUT"
echo "// 0x80015500 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80015500 4 2>&1 | tail -1)
echo "0x80015500 AptLine::~AptLine(void): $OUT"
echo "// 0x80019360 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80019360 4 2>&1 | tail -1)
echo "0x80019360 AwarenessManager::~AwarenessManager(void): $OUT"
echo "// 0x80019768 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80019768 4 2>&1 | tail -1)
echo "0x80019768 AwarenessManager::AwarenessAnimateHeadLeadsMotion(unsigned: $OUT"
echo "// 0x8001A2B4 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8001A2B4 4 2>&1 | tail -1)
echo "0x8001A2B4 AwarenessManager::GetActiveMemoryCategory(cXObject: $OUT"
echo "// 0x8001C82C (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8001C82C 4 2>&1 | tail -1)
echo "0x8001C82C TArray<ENLatticePoints,: $OUT"
echo "// 0x8001EAB8 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8001EAB8 4 2>&1 | tail -1)
echo "0x8001EAB8 TArray<int,: $OUT"
echo "// 0x80020CAC (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80020CAC 4 2>&1 | tail -1)
echo "0x80020CAC TArray<EVec3,: $OUT"
echo "// 0x8002269C (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8002269C 4 2>&1 | tail -1)
echo "0x8002269C SimsCameraParameters::SetupWindow(CUIWindow: $OUT"
echo "// 0x80036E6C (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80036E6C 4 2>&1 | tail -1)
echo "0x80036E6C void: $OUT"
echo "// 0x80035014 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80035014 4 2>&1 | tail -1)
echo "0x80035014 ESimsDataManager::UnloadSelectorData(ObjSelector: $OUT"
echo "// 0x80037D1C (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80037D1C 4 2>&1 | tail -1)
echo "0x80037D1C EHouse::SetNextWallMode(void): $OUT"
echo "// 0x8004A2D4 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8004A2D4 4 2>&1 | tail -1)
echo "0x8004A2D4 EGEVert::operator=(EGEVert: $OUT"
echo "// 0x8004AA60 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8004AA60 4 2>&1 | tail -1)
echo "0x8004AA60 operator>>(EStream: $OUT"
echo "// 0x8004F8D4 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8004F8D4 4 2>&1 | tail -1)
echo "0x8004F8D4 ESim::DrawSim(bool): $OUT"
echo "// 0x80050414 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80050414 4 2>&1 | tail -1)
echo "0x80050414 TArray<EVec3,: $OUT"
echo "// 0x80052008 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80052008 4 2>&1 | tail -1)
echo "0x80052008 TArray<EVec3,: $OUT"
echo "// 0x8005971C (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8005971C 4 2>&1 | tail -1)
echo "0x8005971C EyeToyClient::GetRepSlotUnLockedBits(int): $OUT"
echo "// 0x8005F5CC (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8005F5CC 4 2>&1 | tail -1)
echo "0x8005F5CC TArray<ENLatticePoints,: $OUT"
echo "// 0x80065FF0 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80065FF0 4 2>&1 | tail -1)
echo "0x80065FF0 TArray<ENDummyPoint,: $OUT"
echo "// 0x80069168 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80069168 4 2>&1 | tail -1)
echo "0x80069168 EGlobal::GetMemCardString(char: $OUT"
echo "// 0x80070550 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80070550 4 2>&1 | tail -1)
echo "0x80070550 EStream: $OUT"
echo "// 0x80071450 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80071450 4 2>&1 | tail -1)
echo "0x80071450 _Deque_base<StateMachineStatus: $OUT"
echo "// 0x8007800C (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8007800C 4 2>&1 | tail -1)
echo "0x8007800C TArray<ENCameraPoint,: $OUT"
echo "// 0x8007D110 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8007D110 4 2>&1 | tail -1)
echo "0x8007D110 EParticleObj::~EParticleObj(void): $OUT"
echo "// 0x800871B4 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800871B4 4 2>&1 | tail -1)
echo "0x800871B4 TArray<ENCameraPoint,: $OUT"
echo "// 0x80087B30 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80087B30 4 2>&1 | tail -1)
echo "0x80087B30 _Deque_base<StateMachineStatus: $OUT"
echo "// 0x80087E88 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80087E88 4 2>&1 | tail -1)
echo "0x80087E88 TArray<EILight: $OUT"
echo "// 0x80088984 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80088984 4 2>&1 | tail -1)
echo "0x80088984 EmitterSpr3d::~EmitterSpr3d(void): $OUT"
echo "// 0x8008BB64 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8008BB64 4 2>&1 | tail -1)
echo "0x8008BB64 TArray<EVec3,: $OUT"
echo "// 0x8008CE10 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8008CE10 4 2>&1 | tail -1)
echo "0x8008CE10 _Rb_global<bool>::_Rebalance(_Rb_tree_node_base: $OUT"
echo "// 0x800912CC (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800912CC 4 2>&1 | tail -1)
echo "0x800912CC TArray<EVec3,: $OUT"
echo "// 0x80093EA8 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80093EA8 4 2>&1 | tail -1)
echo "0x80093EA8 TArray<ENCameraPoint,: $OUT"
echo "// 0x8009417C (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8009417C 4 2>&1 | tail -1)
echo "0x8009417C __node_alloc<false,: $OUT"
echo "// 0x8009607C (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8009607C 4 2>&1 | tail -1)
echo "0x8009607C TArray<ENCameraPoint,: $OUT"
echo "// 0x800964D4 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800964D4 4 2>&1 | tail -1)
echo "0x800964D4 MoviePlayerEndgameMovieState::Update(float): $OUT"
echo "// 0x8009F1E4 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8009F1E4 4 2>&1 | tail -1)
echo "0x8009F1E4 TArray<ENCameraPoint,: $OUT"
echo "// 0x800A04FC (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800A04FC 4 2>&1 | tail -1)
echo "0x800A04FC SAnimator2::SAnimator2(void): $OUT"
echo "// 0x800B76A4 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800B76A4 4 2>&1 | tail -1)
echo "0x800B76A4 SAnimator2::stopIdleOverlay(void): $OUT"
echo "// 0x800B4748 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800B4748 4 2>&1 | tail -1)
echo "0x800B4748 SAnimator2::DetachMonitoredTrack(void): $OUT"
echo "// 0x800A526C (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800A526C 4 2>&1 | tail -1)
echo "0x800A526C SAnimator2::followMoveToTurnUpdate(float: $OUT"
echo "// 0x800A76F8 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800A76F8 4 2>&1 | tail -1)
echo "0x800A76F8 SAnimator2::handleSidestepAnimation(void): $OUT"
echo "// 0x800A7618 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800A7618 4 2>&1 | tail -1)
echo "0x800A7618 SAnimator2::getFootSound(char: $OUT"
echo "// 0x800B24C0 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800B24C0 4 2>&1 | tail -1)
echo "0x800B24C0 TArray<EVec3,: $OUT"
echo "// 0x800B3170 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800B3170 4 2>&1 | tail -1)
echo "0x800B3170 _Deque_base<StateMachineStatus: $OUT"
echo "// 0x800B3648 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800B3648 4 2>&1 | tail -1)
echo "0x800B3648 TArray<EAnimNote,: $OUT"
echo "// 0x800B42B0 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800B42B0 4 2>&1 | tail -1)
echo "0x800B42B0 SAnimator2::addSkillAnimationName(char: $OUT"
echo "// 0x800C6040 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800C6040 4 2>&1 | tail -1)
echo "0x800C6040 TArray<ENDummyPoint,: $OUT"
echo "// 0x800C7D84 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800C7D84 4 2>&1 | tail -1)
echo "0x800C7D84 TArray<int,: $OUT"
echo "// 0x800D2558 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800D2558 4 2>&1 | tail -1)
echo "0x800D2558 TArray<EVec3,: $OUT"
echo "// 0x800D25E8 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800D25E8 4 2>&1 | tail -1)
echo "0x800D25E8 TArray<ENLatticePoints,: $OUT"
echo "// 0x800D8EE4 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800D8EE4 4 2>&1 | tail -1)
echo "0x800D8EE4 DlgWrapper::DialogPaneHide(void): $OUT"
echo "// 0x800D9480 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800D9480 4 2>&1 | tail -1)
echo "0x800D9480 __node_alloc<false,: $OUT"
echo "// 0x800D95F0 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800D95F0 4 2>&1 | tail -1)
echo "0x800D95F0 _Deque_base<StateMachineStatus: $OUT"
echo "// 0x800DCB4C (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800DCB4C 4 2>&1 | tail -1)
echo "0x800DCB4C MUWrapper::Reset(void): $OUT"
echo "// 0x800EA6AC (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800EA6AC 4 2>&1 | tail -1)
echo "0x800EA6AC WrapperPaneBase::GetButtonFontSize(WrapperPaneBase::ButtonTy: $OUT"
echo "// 0x800EAAB8 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800EAAB8 4 2>&1 | tail -1)
echo "0x800EAAB8 WrapperPaneBase::SetButtonFontSize(WrapperPaneBase::ButtonTy: $OUT"
echo "// 0x800EAD94 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800EAD94 4 2>&1 | tail -1)
echo "0x800EAD94 WrapperPaneBase::SetAcceptText(unsigned: $OUT"
echo "// 0x800EB110 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800EB110 4 2>&1 | tail -1)
echo "0x800EB110 WrapperPaneBase::SetAcceptPosY(float): $OUT"
echo "// 0x800EB3F0 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800EB3F0 4 2>&1 | tail -1)
echo "0x800EB3F0 WrapperPaneBase::SetDeclinePos(EVec2: $OUT"
echo "// 0x800EE144 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x800EE144 4 2>&1 | tail -1)
echo "0x800EE144 TArray<EVec3,: $OUT"
echo "// 0x80108380 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80108380 4 2>&1 | tail -1)
echo "0x80108380 MUStatesFormat::MUStatesFormat(int): $OUT"
echo "// 0x80109044 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80109044 4 2>&1 | tail -1)
echo "0x80109044 MUStatesTransitionAutoSaveExisting::MUStatesTransitionAutoSa: $OUT"
echo "// 0x8010FB0C (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8010FB0C 4 2>&1 | tail -1)
echo "0x8010FB0C StateMachine::GetReturnStateId(void): $OUT"
echo "// 0x80112D3C (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80112D3C 4 2>&1 | tail -1)
echo "0x80112D3C TheSimsMaxisLogoState::Update(float): $OUT"
echo "// 0x80117EA8 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80117EA8 4 2>&1 | tail -1)
echo "0x80117EA8 TArray<ENCameraPoint,: $OUT"
echo "// 0x80119F5C (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80119F5C 4 2>&1 | tail -1)
echo "0x80119F5C _Deque_base<StateMachineStatus: $OUT"
echo "// 0x8011EC78 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8011EC78 4 2>&1 | tail -1)
echo "0x8011EC78 BString::resize(unsigned: $OUT"
echo "// 0x8011F068 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8011F068 4 2>&1 | tail -1)
echo "0x8011F068 BString::rfind(BString: $OUT"
echo "// 0x80123728 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80123728 4 2>&1 | tail -1)
echo "0x80123728 BString2::find(unsigned: $OUT"
echo "// 0x80124AD8 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80124AD8 4 2>&1 | tail -1)
echo "0x80124AD8 IsoToWorld(float: $OUT"
echo "// 0x801253D0 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x801253D0 4 2>&1 | tail -1)
echo "0x801253D0 CTGDump::operator<<(char): $OUT"
echo "// 0x8012D034 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8012D034 4 2>&1 | tail -1)
echo "0x8012D034 TArray<int,: $OUT"
echo "// 0x80130588 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80130588 4 2>&1 | tail -1)
echo "0x80130588 ResourceBehavior::ResourceBehavior(void): $OUT"
echo "// 0x80138E6C (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80138E6C 4 2>&1 | tail -1)
echo "0x80138E6C CareersImpl::GetCareerByID(int): $OUT"
echo "// 0x80140E0C (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80140E0C 4 2>&1 | tail -1)
echo "0x80140E0C cSoundPlayer::PauseSounds(void): $OUT"
echo "// 0x80141A48 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80141A48 4 2>&1 | tail -1)
echo "0x80141A48 TArray<EVec3,: $OUT"
echo "// 0x801499E4 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x801499E4 4 2>&1 | tail -1)
echo "0x801499E4 __node_alloc<false,: $OUT"
echo "// 0x801455BC (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x801455BC 4 2>&1 | tail -1)
echo "0x801455BC cGZSnd::Pause(void): $OUT"
echo "// 0x80145800 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80145800 4 2>&1 | tail -1)
echo "0x80145800 cGZSnd::FadeVolume(int,: $OUT"
echo "// 0x801460C0 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x801460C0 4 2>&1 | tail -1)
echo "0x801460C0 cGZMusic::Pause(void): $OUT"
echo "// 0x80146728 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80146728 4 2>&1 | tail -1)
echo "0x80146728 GZSndMenu::DrawWindow(CUIWindow: $OUT"
echo "// 0x80149100 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80149100 4 2>&1 | tail -1)
echo "0x80149100 TArray<EVec3,: $OUT"
echo "// 0x801493E0 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x801493E0 4 2>&1 | tail -1)
echo "0x801493E0 TArray<ENDummyPoint,: $OUT"
echo "// 0x80149C30 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80149C30 4 2>&1 | tail -1)
echo "0x80149C30 __node_alloc<false,: $OUT"
echo "// 0x8014A008 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8014A008 4 2>&1 | tail -1)
echo "0x8014A008 global: $OUT"
echo "// 0x80152DD8 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80152DD8 4 2>&1 | tail -1)
echo "0x80152DD8 Interaction::Interaction(Interaction: $OUT"
echo "// 0x80153324 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80153324 4 2>&1 | tail -1)
echo "0x80153324 Interaction::~Interaction(void): $OUT"
echo "// 0x8015E5C4 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8015E5C4 4 2>&1 | tail -1)
echo "0x8015E5C4 Neighbor::FindDuplicateBookmark(WantFear::Bookmark: $OUT"
echo "// 0x8015E6F8 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8015E6F8 4 2>&1 | tail -1)
echo "0x8015E6F8 Neighbor::ForceNewTree(unsigned: $OUT"
echo "// 0x801622F0 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x801622F0 4 2>&1 | tail -1)
echo "0x801622F0 NeighborhoodImpl::Unload(void): $OUT"
echo "// 0x8016241C (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8016241C 4 2>&1 | tail -1)
echo "0x8016241C NeighborhoodImpl::Load(NghResFile: $OUT"
echo "// 0x80167EFC (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80167EFC 4 2>&1 | tail -1)
echo "0x80167EFC __node_alloc<false,: $OUT"
echo "// 0x80172C10 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80172C10 4 2>&1 | tail -1)
echo "0x80172C10 NghResFile::ReadCharacterData(char: $OUT"
echo "// 0x80180344 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80180344 4 2>&1 | tail -1)
echo "0x80180344 cXObjectImpl::SyncObjectIsReady(void): $OUT"
echo "// 0x801885A8 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x801885A8 4 2>&1 | tail -1)
echo "0x801885A8 EStream: $OUT"
echo "// 0x80194CB4 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80194CB4 4 2>&1 | tail -1)
echo "0x80194CB4 int: $OUT"
echo "// 0x801909F0 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x801909F0 4 2>&1 | tail -1)
echo "0x801909F0 ObjectFolderImpl::CreateNewUserSelector(void): $OUT"
echo "// 0x80190E08 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80190E08 4 2>&1 | tail -1)
echo "0x80190E08 ObjectFolderImpl::CreatingInstance(ObjSelector: $OUT"
echo "// 0x80193F28 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80193F28 4 2>&1 | tail -1)
echo "0x80193F28 __node_alloc<false,: $OUT"
echo "// 0x801948A8 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x801948A8 4 2>&1 | tail -1)
echo "0x801948A8 void: $OUT"
echo "// 0x80194EC0 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80194EC0 4 2>&1 | tail -1)
echo "0x80194EC0 _Rb_tree<int,: $OUT"
echo "// 0x801A1D38 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x801A1D38 4 2>&1 | tail -1)
echo "0x801A1D38 SimCUIProbeDisplay::DrawWindow(CUIWindow: $OUT"
echo "// 0x801BD084 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x801BD084 4 2>&1 | tail -1)
echo "0x801BD084 TArray<EVec3,: $OUT"
echo "// 0x801C6FA0 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x801C6FA0 4 2>&1 | tail -1)
echo "0x801C6FA0 cHitMan::Init(void): $OUT"
echo "// 0x801F00F0 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x801F00F0 4 2>&1 | tail -1)
echo "0x801F00F0 QuickResFile::Detach(Memory::HandleNode: $OUT"
echo "// 0x801F3784 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x801F3784 4 2>&1 | tail -1)
echo "0x801F3784 __node_alloc<false,: $OUT"
echo "// 0x801F4518 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x801F4518 4 2>&1 | tail -1)
echo "0x801F4518 iResFile::Open(StringBuffer: $OUT"
echo "// 0x801F74A0 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x801F74A0 4 2>&1 | tail -1)
echo "0x801F74A0 Room::PrintStats(void): $OUT"
echo "// 0x801F6164 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x801F6164 4 2>&1 | tail -1)
echo "0x801F6164 RoomManager::GetOutsideAmbientLevel(void): $OUT"
echo "// 0x80204F38 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80204F38 4 2>&1 | tail -1)
echo "0x80204F38 resolveSkillForPassiveInfluence(cXObject: $OUT"
echo "// 0x802096AC (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x802096AC 4 2>&1 | tail -1)
echo "0x802096AC SimpleReconObject<ReconStreamVector<SlotDescriptor>: $OUT"
echo "// 0x8020B6A4 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8020B6A4 4 2>&1 | tail -1)
echo "0x8020B6A4 TileWalls::GetStyle(TileWallsSegment): $OUT"
echo "// 0x8020C148 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8020C148 4 2>&1 | tail -1)
echo "0x8020C148 TreeStack::~TreeStack(void): $OUT"
echo "// 0x802140FC (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x802140FC 4 2>&1 | tail -1)
echo "0x802140FC TArray<int,: $OUT"
echo "// 0x80225084 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80225084 4 2>&1 | tail -1)
echo "0x80225084 FTilePt::operator==(FTilePt: $OUT"
echo "// 0x80229220 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x80229220 4 2>&1 | tail -1)
echo "0x80229220 __node_alloc<false,: $OUT"
echo "// 0x8022A4D8 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8022A4D8 4 2>&1 | tail -1)
echo "0x8022A4D8 _Rb_tree<pair<unsigned: $OUT"
echo "// 0x8022B0F8 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8022B0F8 4 2>&1 | tail -1)
echo "0x8022B0F8 TreeTableQuickData::TreeTableQuickData(void): $OUT"
echo "// 0x8022DADC (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8022DADC 4 2>&1 | tail -1)
echo "0x8022DADC TreeTableQuickData::Save(unsigned: $OUT"
echo "// 0x8022E6A0 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8022E6A0 4 2>&1 | tail -1)
echo "0x8022E6A0 TArray<EVec3,: $OUT"
echo "// 0x8022FAF0 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8022FAF0 4 2>&1 | tail -1)
echo "0x8022FAF0 TArray<int,: $OUT"
echo "// 0x802331F4 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x802331F4 4 2>&1 | tail -1)
echo "0x802331F4 TArray<EVec3,: $OUT"
echo "// 0x8023C2F0 (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8023C2F0 4 2>&1 | tail -1)
echo "0x8023C2F0 TSC3TestSuite::TSC3TestSuite(char: $OUT"
echo "// 0x8023CADC (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8023CADC 4 2>&1 | tail -1)
echo "0x8023CADC CasClothingUnlocks::GetFlags(bool,: $OUT"
echo "// 0x8023EE8C (4B)" > "$TMPF"
echo "struct _T { void _f(void); }; void _T::_f(void) {}" >> "$TMPF"
OUT=$(bash tools/verify_match.sh "$TMPF" 0x8023EE8C 4 2>&1 | tail -1)
echo "0x8023EE8C CasCostumes::CreateNewCostumesList(void): $OUT"
rm -f "$TMPF"
