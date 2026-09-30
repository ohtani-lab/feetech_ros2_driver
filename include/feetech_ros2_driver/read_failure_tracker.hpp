#pragma once

namespace feetech_ros2_driver {

class ReadFailureTracker {
 public:
  static constexpr unsigned int kMaxConsecutiveFailures = 3;

  void reset_for_activation() {
    consecutive_failures_ = 0;
    has_successful_read_ = false;
  }

  void record_success() {
    consecutive_failures_ = 0;
    has_successful_read_ = true;
  }

  bool record_failure() { return ++consecutive_failures_ >= kMaxConsecutiveFailures; }

  unsigned int consecutive_failures() const { return consecutive_failures_; }
  bool has_successful_read() const { return has_successful_read_; }

 private:
  unsigned int consecutive_failures_ = 0;
  bool has_successful_read_ = false;
};

}  // namespace feetech_ros2_driver
