#include <Geode/Geode.hpp>
#include <Geode/modify/MusicDownloadManager.hpp>

using namespace geode::prelude;

class $modify(SwapMusicManager, MusicDownloadManager) {
    gd::string pathForSong(int id) {
        auto dir = Mod::get()->getSaveDir();
        for (auto ext : {"mp3", "ogg", "wav"}) {
            auto file = dir / fmt::format("{}.{}", id, ext);
            if (std::filesystem::exists(file)) {
                return gd::string(file.string());
            }
        }
        return MusicDownloadManager::pathForSong(id);
    }
};
