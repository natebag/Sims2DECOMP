/* 0x80053E74 (12 bytes) - ISimsObjectModel::ShouldKillAllAnimTracks(unsigned int) */
class ISimsObjectModel {
public:
    int ShouldKillAllAnimTracks(unsigned int id);
};

int ISimsObjectModel::ShouldKillAllAnimTracks(unsigned int id) {
    return id == 0;
}
