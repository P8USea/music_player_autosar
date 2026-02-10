#include "strategies/usb_source.hpp"

#include <chrono>
#include <thread>

#include "app_error_codes.hpp"

namespace AutosarMusicPlayer {
namespace Asw {

Common::ErrorCode UsbSourceStrategy::loadMediaSource(const Common::MediaSourceType& source)
{
    // Giả lập thời gian Mount(USB thường mất 1 - 2s để nhận diện)
    std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));

    // Kiểm tra tính hợp lệ
    if (source != Common::MediaSourceType::USB) {
        return Common::ErrorCode::INVALID_PARAMETER;
    }
    // Giả lập kết nối thành công
    return Common::ErrorCode::SUCCESS;
}
std::vector<std::unique_ptr<Song>> UsbSourceStrategy::getSongs() const
{
    std::vector<std::unique_ptr<Song>> playlist;
    return playlist;
}

}  // namespace Asw
}  // namespace AutosarMusicPlayer
