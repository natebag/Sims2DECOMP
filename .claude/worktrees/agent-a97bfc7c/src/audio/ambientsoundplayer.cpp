// ambientsoundplayer.cpp - Ambient sound player (individual sound instances)
// Object file: ambientsoundplayer.obj
// Small functions decompiled from Sims 2 GC
// 3 MATCHING, 8 NON_MATCHING
//
// AmbientSoundPlayer layout (48 bytes, 0x30):
//   +0x00: AmbientScorePlayer* m_scorePlayer
//   +0x04: ERAmbientSound* m_ambientSound
//   +0x08: void* m_soundHandle     (sound instance with vtable)
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
// Sound handle vtable layout (SN Systems 8-byte entries: [s16 adjustor, u16 pad, u32 func_ptr]):
//   vtable[0x18/0x1C]: Release/Destroy
//   vtable[0x28/0x2C]: IsPlaying
//   vtable[0x30/0x34]: Stop
//   vtable[0x38/0x3C]: Pause
//   vtable[0x40/0x44]: UnPause

#include "audio/ambientsoundplayer.h"
#include "audio/ambientscoreplayer.h"

// MATCHING
// AmbientSoundPlayer::SetScorePlayer(AmbientScorePlayer*) @ 0x800a9330, 8 bytes
void AmbientSoundPlayer::SetScorePlayer(AmbientScorePlayer* player) {
    m_scorePlayer = player;
}

// MATCHING
// AmbientSoundPlayer::SetAmbientSound(ERAmbientSound*) @ 0x800a9338, 8 bytes
void AmbientSoundPlayer::SetAmbientSound(ERAmbientSound* sound) {
    m_ambientSound = sound;
}

// NON_MATCHING: GCC inlines UpdateSoundPosition into Update and tail-calls UpdatePanAndVolume;
// original makes two separate bl calls with r30 saved via stmw
// AmbientSoundPlayer::Update(void) @ 0x800a9340, 52 bytes
void AmbientSoundPlayer::Update() {
    UpdateSoundPosition();
    UpdatePanAndVolume();
}

// MATCHING
// AmbientSoundPlayer::GetAmbientSound(void) @ 0x800aa9b4, 8 bytes
ERAmbientSound* AmbientSoundPlayer::GetAmbientSound() {
    return m_ambientSound;
}

// NON_MATCHING: GCC uses addic/subfe for bool conversion on second check;
// original uses li r9,0 / beq / lwz / cmpwi / beq / li r9,1 / mr r3,r9
// AmbientSoundPlayer::IsValid(void) @ 0x800aaa18, 40 bytes
int AmbientSoundPlayer::IsValid() {
    if (m_scorePlayer == 0) {
        return 0;
    }
    if (m_ambientSound == 0) {
        return 0;
    }
    return 1;
}

// NON_MATCHING: GCC uses cntlzw/srwi for bool conversion and bctrl for indirect call;
// original uses cmpwi/bne and blrl
// AmbientSoundPlayer::IsFinished(void) @ 0x800aa9bc, 92 bytes
int AmbientSoundPlayer::IsFinished() {
    if (m_soundHandle != 0) {
        // SN vtable dispatch: vtable = *(void**)m_soundHandle
        // adjustor = *(s16*)(vtable + 0x28), func = *(u32*)(vtable + 0x2C)
        void** vtable = *(void***)m_soundHandle;
        s16 adjustor = *(s16*)((char*)vtable + 0x28);
        typedef int (*IsPlayingFunc)(void*);
        IsPlayingFunc func = (IsPlayingFunc)(*(u32*)((char*)vtable + 0x2C));
        void* adjusted = (void*)((char*)m_soundHandle + adjustor);
        int playing = func(adjusted);
        if (playing != 0) {
            return 0;
        }
    }
    return 1;
}

// NON_MATCHING: GCC uses bctrl instead of blrl; moves prologue/epilogue around the null check
// instead of having it before; also duplicates return value at two paths
// AmbientSoundPlayer::Pause(void) @ 0x800a97b4, 68 bytes
int AmbientSoundPlayer::Pause() {
    if (m_soundHandle != 0) {
        void** vtable = *(void***)m_soundHandle;
        s16 adjustor = *(s16*)((char*)vtable + 0x38);
        typedef void (*PauseFunc)(void*);
        PauseFunc func = (PauseFunc)(*(u32*)((char*)vtable + 0x3C));
        void* adjusted = (void*)((char*)m_soundHandle + adjustor);
        func(adjusted);
    }
    return 1;
}

// NON_MATCHING: Same issues as Pause - bctrl vs blrl, different prologue placement
// AmbientSoundPlayer::UnPause(void) @ 0x800a97f8, 68 bytes
int AmbientSoundPlayer::UnPause() {
    if (m_soundHandle != 0) {
        void** vtable = *(void***)m_soundHandle;
        s16 adjustor = *(s16*)((char*)vtable + 0x40);
        typedef void (*UnPauseFunc)(void*);
        UnPauseFunc func = (UnPauseFunc)(*(u32*)((char*)vtable + 0x44));
        void* adjusted = (void*)((char*)m_soundHandle + adjustor);
        func(adjusted);
    }
    return 1;
}

// NON_MATCHING: GCC uses beqlr+ (conditional return) instead of beq past bl;
// also uses different SDA addressing for delta time
// AmbientSoundPlayer::UpdateSoundPosition(void) @ 0x800aa050, 84 bytes
// Interpolates position: posX += velX * delta, posY += velY * delta
// Then checks looping flag on ERAmbientSound and calls UpdateLoopingSoundPosition if set
void AmbientSoundPlayer::UpdateSoundPosition() {
    extern float _SDA2_delta_time;
    float delta = _SDA2_delta_time;

    m_posX = m_velX * delta + m_posX;
    m_posY = m_velY * delta + m_posY;

    u8 flags = *((u8*)m_ambientSound + 0x19);
    if (flags & 1) {
        UpdateLoopingSoundPosition();
    }
}

// NON_MATCHING: GCC uses bctrl instead of blrl for vtable dispatch; different prologue;
// GCC moves mflr/stwu inside the if block; tail-call optimization differences
// AmbientSoundPlayer::Stop(void) @ 0x800a9738, 124 bytes
int AmbientSoundPlayer::Stop() {
    if (m_soundHandle != 0) {
        // Stop the sound via vtable[0x30/0x34]
        {
            void** vtable = *(void***)m_soundHandle;
            s16 adjustor = *(s16*)((char*)vtable + 0x30);
            typedef void (*StopFunc)(void*);
            StopFunc func = (StopFunc)(*(u32*)((char*)vtable + 0x34));
            void* adjusted = (void*)((char*)m_soundHandle + adjustor);
            func(adjusted);
        }
        // Release the handle via vtable[0x18/0x1C]
        {
            void** vtable = *(void***)m_soundHandle;
            s16 adjustor = *(s16*)((char*)vtable + 0x18);
            typedef void (*ReleaseFunc)(void*);
            ReleaseFunc func = (ReleaseFunc)(*(u32*)((char*)vtable + 0x1C));
            void* adjusted = (void*)((char*)m_soundHandle + adjustor);
            func(adjusted);
        }
        m_soundHandle = 0;
    }
    m_soundId = -1;
    return 1;
}

// NON_MATCHING: GCC init order differs; uses single float constant load;
// original accesses through r11 (this+0x14) alias pattern
// AmbientSoundPlayer::AmbientSoundPlayer(void) @ 0x800a9270, 76 bytes
AmbientSoundPlayer::AmbientSoundPlayer() {
    m_scorePlayer = 0;
    m_ambientSound = 0;
    m_soundHandle = 0;
    m_field_0C = 0;
    m_field_10 = 0;
    m_posX = 0.0f;
    m_posY = 0.0f;
    m_field_1C = 0.0f;
    m_velX = 0.0f;
    m_field_28 = 0;
    m_soundId = -1;
    m_velY = 0.0f;
}

// NON_MATCHING: GCC D0/D1 destructor split vs SN single destructor with delete flag;
// GCC omits null-clearing of m_scorePlayer/m_ambientSound before delete check
// AmbientSoundPlayer::~AmbientSoundPlayer(void) @ 0x800a92bc, 116 bytes
AmbientSoundPlayer::~AmbientSoundPlayer() {
    if (m_soundHandle != 0) {
        void** vtable = *(void***)m_soundHandle;
        s16 adjustor = *(s16*)((char*)vtable + 0x18);
        typedef void (*ReleaseFunc)(void*);
        ReleaseFunc func = (ReleaseFunc)(*(u32*)((char*)vtable + 0x1C));
        void* adjusted = (void*)((char*)m_soundHandle + adjustor);
        func(adjusted);
        m_soundHandle = 0;
    }
    m_scorePlayer = 0;
    m_ambientSound = 0;
}
