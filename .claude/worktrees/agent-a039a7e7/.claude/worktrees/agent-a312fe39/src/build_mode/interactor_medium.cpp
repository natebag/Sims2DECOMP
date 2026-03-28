// interactor_medium.cpp - Interactor base class medium functions (65-256 bytes)
// Object file: interactor.obj
// All NON_MATCHING due to: GCC vs SN Systems codegen differences

#include "build_mode/interactor.h"

namespace InteractorModule {

// External functions
extern "C" void EMat4_Identity(void*);

// ============================================================================
// Interactor::Interactor
// interactor.obj | 0x802091BC | 196 bytes
// Default constructor - initializes all fields
// ============================================================================
// NON_MATCHING: init sequence, float constant loading
Interactor::Interactor() {
    m_playerId = 0;
    m_camera = 0;
    m_pos.x = 0.0f;
    m_pos.y = 0.0f;
    m_pos.z = 0.0f;
    m_prevPos.x = 0.0f;
    m_prevPos.y = 0.0f;
    m_prevPos.z = 0.0f;
    m_snappedPos.x = 0.0f;
    m_snappedPos.y = 0.0f;
    m_snappedPos.z = 0.0f;
    m_snapped = 0;
    m_inputState = 0;
    m_leftStick.x = 0.0f;
    m_leftStick.y = 0.0f;
    m_rightStick.x = 0.0f;
    m_rightStick.y = 0.0f;
    m_leftStickActive = 0;
    m_rightStickActive = 0;
    m_drawState = 0;
    m_extents.x = 0.5f;
    m_extents.y = 0.5f;
    m_idleTime = 0.0f;
    m_vtable = 0; // set by derived class
}

// ============================================================================
// Interactor::OnCommandReleased
// interactor.obj | 0x802092EC | 104 bytes
// Handles command release events (stick centering)
// ============================================================================
// NON_MATCHING: switch codegen
void Interactor::OnCommandReleased(InteractorInputManager::InteractorCommand cmd) {
    switch (cmd) {
        case InteractorInputManager::kCmdLeftStickX:
            m_leftStick.x = 0.0f;
            m_leftStickActive = 0;
            break;
        case InteractorInputManager::kCmdLeftStickY:
            m_leftStick.y = 0.0f;
            m_leftStickActive = 0;
            break;
        case InteractorInputManager::kCmdRightStickX:
            m_rightStick.x = 0.0f;
            m_rightStickActive = 0;
            break;
        case InteractorInputManager::kCmdRightStickY:
            m_rightStick.y = 0.0f;
            m_rightStickActive = 0;
            break;
        default:
            break;
    }
}

// ============================================================================
// Interactor::OnCommandUpdate
// interactor.obj | 0x80209354 | 88 bytes
// Handles command update events (stick value changes)
// ============================================================================
// NON_MATCHING: switch codegen
void Interactor::OnCommandUpdate(InteractorInputManager::InteractorCommand cmd, float value) {
    switch (cmd) {
        case InteractorInputManager::kCmdLeftStickX:
            m_leftStick.x = value;
            m_leftStickActive = 1;
            break;
        case InteractorInputManager::kCmdLeftStickY:
            m_leftStick.y = value;
            m_leftStickActive = 1;
            break;
        case InteractorInputManager::kCmdRightStickX:
            m_rightStick.x = value;
            m_rightStickActive = 1;
            break;
        case InteractorInputManager::kCmdRightStickY:
            m_rightStick.y = value;
            m_rightStickActive = 1;
            break;
        default:
            break;
    }
}

// ============================================================================
// Interactor::ResetInputState
// interactor.obj | 0x802093AC | 68 bytes
// Resets all input state to neutral
// ============================================================================
// NON_MATCHING: zero pattern codegen
void Interactor::ResetInputState() {
    m_leftStick.x = 0.0f;
    m_leftStick.y = 0.0f;
    m_rightStick.x = 0.0f;
    m_rightStick.y = 0.0f;
    m_leftStickActive = 0;
    m_rightStickActive = 0;
    m_inputState = 0;
}

// ============================================================================
// Interactor::GetSelectionRadius
// interactor.obj | 0x802093F0 | 100 bytes
// Returns selection radius based on camera zoom
// ============================================================================
// NON_MATCHING: FP codegen
f32 Interactor::GetSelectionRadius() {
    if (m_camera == 0) return 0.5f;
    // Get zoom ratio from camera
    // Scale selection radius by zoom
    float zoomRatio = 0.5f; // placeholder
    return 0.5f + zoomRatio * 0.5f;
}

// ============================================================================
// Interactor::Moved
// interactor.obj | 0x80209584 | 72 bytes
// Returns true if position changed since last frame
// ============================================================================
// NON_MATCHING: FP comparison codegen
int Interactor::Moved() {
    if (m_pos.x != m_prevPos.x) return 1;
    if (m_pos.y != m_prevPos.y) return 1;
    if (m_pos.z != m_prevPos.z) return 1;
    return 0;
}

} // namespace InteractorModule
