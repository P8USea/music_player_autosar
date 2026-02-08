#ifndef APP_ERROR_CODES_HPP
#define APP_ERROR_CODES_HPP

#include <cstdint>

namespace AutosarMusicPlayer {
namespace Common {

/**
 * @brief Bảng mã lỗi hệ thống
 * Tuân thủ tư duy "Defensive Programming"
 */
enum class ErrorCode : uint8_t
{
    SUCCESS = 0,        // Không có lỗi
    NOT_FOUND,          // Không tìm thấy bài hát/thiết bị
    PERMISSION_DENIED,  // Không có quyền truy cập file
    HARDWARE_FAILURE,   // Lỗi chip Audio hoặc Bus CAN
    OUT_OF_MEMORY,      // Lỗi cấp phát bộ nhớ (Heap full)
    INVALID_PARAMETER,  // Tham số truyền vào không hợp lệ
    BUSY,               // Hệ thống đang bận xử lý tác vụ khác
    UNKNOWN_ERROR       // Lỗi không xác định
};

/**
 * @brief Helper function để kiểm tra lỗi nhanh (Mục 1: inline)
 */
inline bool isSuccess(ErrorCode code)
{
    return code == ErrorCode::SUCCESS;
}

}  // namespace Common
}  // namespace AutosarMusicPlayer

#endif  // APP_ERROR_CODES_HPP
