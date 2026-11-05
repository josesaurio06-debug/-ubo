#include <Geode/Geode.hpp>
#include <Geode/modify/MusicDownloadManager.hpp>
#include <fstream>
#include <string>

using namespace geode::prelude;

class $modify(SwapMusicManager, MusicDownloadManager) {
    std::string pathForSong(int id) {
        auto dir = Mod::get()->getSaveDir();
        for (auto ext : {"mp3", "ogg", "wav"}) {
            auto file = dir / fmt::format("{}.{}", id, ext);
            std::string path = file.string();
            if (std::ifstream(path).good()) {
                return path;
            }
        }
        return MusicDownloadManager::pathForSong(id);
    }
};
