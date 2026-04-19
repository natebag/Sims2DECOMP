// 0x8001621C (60B) CameraMotionSystem::MoveCamera(float)
// if (t==0) SnapCamera; if (t!=1) SnapCamera; else RubberBandMove(delta).
// Two separate guards tail-merged to single SnapCamera call.

struct CameraMotionSystem {
    int m_motionType;

    void MoveCamera(float delta);
    void RubberBandMove(float delta);
    void SnapCamera();
};

void CameraMotionSystem::MoveCamera(float delta) {
    int t = m_motionType;
    if (t == 0) goto snap;
    if (t != 1) goto snap;
    RubberBandMove(delta);
    return;
snap:
    SnapCamera();
}
