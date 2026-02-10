
#include "strategies/usb_source.hpp"

#include "app_error_codes.hpp"

#include <iostream>
#include <thread>
#include <chrono>

namespace AutosarMusicPlayer {
namespace Asw{

    Common::ErrorCode UsbSourceStrategy::loadMediaSource(const std::string& source) {

        // Giả lập thời gian Mount(USB thường mất 1 - 2s để nhận diện)
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));

        // Kiểm tra tính hợp lệ
        if(source.empty()) {
            return Common::ErrorCode::INVALID_PARAMETER;
        }

        if(source.find("/") == std::string::npos && source.find(":") == std::string::npos) {
            return Common::ErrorCode::NOT_FOUND;
        }
        return Common::ErrorCode::SUCCESS;


    }
    std::vector<std::unique_ptr<Song>> UsbSourceStrategy::getSongs() const {
        std::vector<std::unique_ptr<Song>> playlist;
        return playlist;
    }

}  // namespace Asw
} // namespace AutosarMusicPlayer