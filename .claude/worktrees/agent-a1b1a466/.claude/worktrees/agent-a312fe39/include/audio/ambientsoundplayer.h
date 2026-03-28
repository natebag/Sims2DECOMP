#ifndef AMBIENTSOUNDPLAYER_H
#define AMBIENTSOUNDPLAYER_H

#include "types.h"

// Forward declarations
class AmbientScorePlayer;
class ERAmbientSound;

// AmbientSoundPlayer class
// Object file: ambientsoundplayer.obj
//
// Memory layout (from disassembly):
//   +0x00: AmbientScorePlayer* m_scorePlayer
//   +0x04: ERAmbientSound* m_ambientSound
//   +0x08: void* m_soundHandle     (sound instance pointer, has vtable)
//   +0x0C: int m_field_0C
//   +0x10: int m_field_10
//   +0x14: float m_posX
//   +0x18: float m_posY
//   +0x1C: float m_field_1C
//   +0x20: float m_velX
//   +0x24: float m_velY
//   +0x28: int m_field_28
//   +0x2C: int m_soundId           (default -1)
//
// Total size: 48 bytes (0x30)
class AmbientSoundPlayer {
public:
    AmbientScorePlayer* m_scorePlayer;  // +0x00
    ERAmbientSound* m_ambientSound;     // +0x04
    void* m_soundHandle;                // +0x08  (sound instance with vtable)
    int m_field_0C;                     // +0x0C
    int m_field_10;                     // +0x10
    float m_posX;                       // +0x14
    float m_posY;                       // +0x18
    float m_field_1C;                   // +0x1C
    float m_velX;                       // +0x20
    float m_velY;                       // +0x24
    int m_field_28;                     // +0x28
    int m_soundId;                      // +0x2C

    AmbientSoundPlayer();
    ~AmbientSoundPlayer();

    void SetScorePlayer(AmbientScorePlayer* player);
    void SetAmbientSound(ERAmbientSound* sound);
    void Update();
    void UpdateSoundPosition();
    void UpdatePanAndVolume();
    void UpdateLoopingSoundPosition();
    void UpdateSoundVolume();
    int Start();
    int Stop();
    int Pause();
    int UnPause();
    ERAmbientSound* GetAmbientSound();
    int IsFinished();
    int IsValid();
    void SetInitialSoundPosition();
};

#endif // AMBIENTSOUNDPLAYER_H
