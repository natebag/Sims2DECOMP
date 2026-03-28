/* TrackDataReader::TrackDataReader(void) - 0x801162E0 - 20 bytes */

class ERSoundTrackData;

class TrackDataReader {
public:
    ERSoundTrackData* m_trackData;
    int m_index;

    TrackDataReader(void);
};

TrackDataReader::TrackDataReader(void) : m_index(0), m_trackData(0) {
}
