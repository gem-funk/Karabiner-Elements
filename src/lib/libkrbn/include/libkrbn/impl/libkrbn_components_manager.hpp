#pragma once

#include "libkrbn/impl/libkrbn_connected_devices_monitor.hpp"
#include "libkrbn/impl/libkrbn_frontmost_application_monitor.hpp"
#include "libkrbn/impl/libkrbn_log_monitor.hpp"
#include "libkrbn/impl/libkrbn_system_preferences_monitor.hpp"
#include "libkrbn/impl/libkrbn_version_monitor.hpp"

class libkrbn_components_manager {
public:
  ~libkrbn_components_manager(void) {
    version_monitor_ = nullptr;
    system_preferences_monitor_ = nullptr;
    frontmost_application_monitor_ = nullptr;
    log_monitor_ = nullptr;
  }

  // version_monitor_

  void enable_version_monitor(libkrbn_version_monitor_callback callback,
                              void* refcon) {
    version_monitor_ = std::make_unique<libkrbn_version_monitor>(callback,
                                                                 refcon);
  }

  void disable_version_monitor(void) {
    version_monitor_ = nullptr;
  }

  // system_preferences_monitor_

  void enable_system_preferences_monitor(libkrbn_system_preferences_monitor_callback callback,
                                         void* refcon) {
    system_preferences_monitor_ = std::make_unique<libkrbn_system_preferences_monitor>(callback,
                                                                                       refcon);
  }

  void disable_system_preferences_monitor(void) {
    system_preferences_monitor_ = nullptr;
  }

  // connected_devices_monitor_

  void enable_connected_devices_monitor(libkrbn_connected_devices_monitor_callback callback,
                                        void* refcon) {
    connected_devices_monitor_ = std::make_unique<libkrbn_connected_devices_monitor>(callback,
                                                                                     refcon);
  }

  void disable_connected_devices_monitor(void) {
    connected_devices_monitor_ = nullptr;
  }

  // frontmost_application_monitor_

  void enable_frontmost_application_monitor(libkrbn_frontmost_application_monitor_callback callback,
                                            void* refcon) {
    frontmost_application_monitor_ = std::make_unique<libkrbn_frontmost_application_monitor>(callback,
                                                                                             refcon);
  }

  void disable_frontmost_application_monitor(void) {
    frontmost_application_monitor_ = nullptr;
  }

  // log_monitor_

  void enable_log_monitor(libkrbn_log_monitor_callback callback,
                          void* refcon) {
    log_monitor_ = std::make_unique<libkrbn_log_monitor>(callback,
                                                         refcon);
  }

  void disable_log_monitor(void) {
    log_monitor_ = nullptr;
  }

private:
  std::unique_ptr<libkrbn_version_monitor> version_monitor_;
  std::unique_ptr<libkrbn_system_preferences_monitor> system_preferences_monitor_;
  std::unique_ptr<libkrbn_connected_devices_monitor> connected_devices_monitor_;
  std::unique_ptr<libkrbn_frontmost_application_monitor> frontmost_application_monitor_;
  std::unique_ptr<libkrbn_log_monitor> log_monitor_;
};
