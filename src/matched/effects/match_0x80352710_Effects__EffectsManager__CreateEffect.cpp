struct REffectsSequencer;
namespace Effects {
struct ClientParams;
struct EffectsManager {
    int CreateEffect(REffectsSequencer &, int, ClientParams *);
};
}
int Effects::EffectsManager::CreateEffect(REffectsSequencer &, int, Effects::ClientParams *) { return 0; }
