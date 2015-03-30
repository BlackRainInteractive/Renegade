/*
#include <AL/al.h>
#include <AL/alc.h>
#include <fstream>

struct AudioData {

    int channels,
            sampleRate,
            bitsPerSecond,
            size;

    char* data;
};

bool IsBigEndian () {

    int i = 1;

    return !((char*) &i)[0];
}

int CharToInt (char* Buffer, int Length) {

    int a = 0;

    for (int i = 0; i < Length; ++i)
        ((char*) &a) [(!IsBigEndian () ? i : 3 - i)] = Buffer [i];

    return a;
}

AudioData LoadWav (const char* File) {

    AudioData data;

    char buffer [4];
    std::ifstream in (File, std::ios::binary);

    in.read (buffer, 4);
    in.read (buffer, 4);
    in.read (buffer, 4);
    in.read (buffer, 4);
    in.read (buffer, 4);
    in.read (buffer, 2);
    in.read (buffer, 2);

    data.channels = CharToInt (buffer, 2);

    in.read (buffer, 4);
    data.sampleRate = CharToInt (buffer, 4);

    in.read (buffer, 4);
    in.read (buffer, 2);
    in.read (buffer, 2);

    data.bitsPerSecond = CharToInt (buffer, 2);

    in.read (buffer, 4);
    in.read (buffer, 4);

    data.size = CharToInt (buffer, 4);
    data.data = new char [data.size];

    in.read (data.data, data.size);

    return data;
}

int main() {

    AudioData audioData = LoadWav ("test.wav");

    ALCdevice* device = alcOpenDevice (nullptr);
    ALCcontext* context = alcCreateContext (device, nullptr);

    if (!device || !context)
        return 0;

    alcMakeContextCurrent (context);

    unsigned int bufferId, format;
    alGenBuffers (1,&bufferId);

    if (audioData.channels == 1)
        format = audioData.bitsPerSecond == 8 ? AL_FORMAT_MONO8 : AL_FORMAT_MONO16;

    else
        format = audioData.bitsPerSecond == 8 ? AL_FORMAT_STEREO8 : AL_FORMAT_STEREO16;

    alBufferData (bufferId, format, audioData.data, audioData.size, audioData.sampleRate);

    unsigned int sourceId;
    alGenSources (1,&sourceId);
    alSourcei (sourceId, AL_BUFFER, bufferId);

    alSourcePlay (sourceId);

    ALenum state = AL_PLAYING;

    while (state == AL_PLAYING) {

        alGetSourcei (sourceId, AL_SOURCE_STATE, &state);
    }

    alDeleteSources (1, &sourceId);
    alDeleteBuffers (1, &bufferId);

    alcDestroyContext (context);
    alcCloseDevice (device);
    delete[] audioData.data;

    return 0;
}
*/
