#ifndef APP_TYPES_HPP
#define APP_TYPES_HPP

#include <cstdint>
#include <string>

namespace AutosarMusicPlayer {
namespace Common {

/**
 * @brief Định nghĩa các bí danh kiểu dữ liệu (Type Aliases)
 * Giúp code dễ đọc và dễ porting sang các dòng chip ECU khác nhau.
 */
using id_t = uint32_t;
using year_t = uint16_t;
using duration_t = uint32_t;  // Tính bằng giây

/**
 * @brief Trạng thái của Player (Dùng cho State Pattern)
 */
enum class PlayerState : uint8_t
{
    IDLE,
    PLAYING,
    PAUSED,
    STOPPED,
    ERROR
};

/**
 * @brief Nguồn dữ liệu (Dùng cho Strategy Pattern)
 */
enum class MediaSourceType : uint8_t
{
    USB,
    BLUETOOTH,
    AUX
};

/**
 * @brief Hằng số cấu hình hệ thống (Mục 1: constexpr)
 */
struct Config
{
    static constexpr uint8_t MAX_PLAYLIST_SIZE = 100;
    static constexpr uint8_t MAX_VOLUME = 30;
    static constexpr uint8_t DEFAULT_VOLUME = 15;
};

}  // namespace Common
}  // namespace AutosarMusicPlayer

#endif  // APP_TYPES_HPP
