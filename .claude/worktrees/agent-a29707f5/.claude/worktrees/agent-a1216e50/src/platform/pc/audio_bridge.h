#ifndef AUDIO_BRIDGE_H
#define AUDIO_BRIDGE_H

// Basic audio playback for PC port.
// The GC game uses:
//   AX (audio mixer) — low-level voice management
//   DSP — hardware audio processing
//   AI (audio interface) — DMA to audio hardware
//   ARAM — auxiliary RAM for audio samples
//
// For the PC port, we use Win32 waveOut for basic PCM playback.
// This is a minimal implementation to get sound effects playing.
// A proper implementation would use XAudio2 or OpenAL.

// Initialize audio system (call once at startup)
int audio_init(void);

// Shutdown audio system
void audio_shutdown(void);

// Play a raw PCM sample
// data: PCM sample data (16-bit signed, mono or stereo)
// dataSize: size in bytes
// sampleRate: samples per second (typically 32000 for GC)
// channels: 1 = mono, 2 = stereo
// Returns a voice handle, or -1 on failure
int audio_play_sample(const void* data, int dataSize, int sampleRate, int channels);

// Stop a playing voice
void audio_stop_voice(int voiceHandle);

// Set master volume (0.0 = silent, 1.0 = full)
void audio_set_volume(float volume);

#endif // AUDIO_BRIDGE_H
