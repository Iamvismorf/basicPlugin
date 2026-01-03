#define WLR_USE_UNSTABLE

#include "globals.hpp"

#include <hyprland/src/Compositor.hpp>
#include <hyprland/src/desktop/view/Window.hpp>

APICALL EXPORT std::string PLUGIN_API_VERSION() { return HYPRLAND_API_VERSION; }

void onNewWindow(void *, SCallbackInfo &, std::any data) {
  auto window = std::any_cast<PHLWINDOW>(data);
  HyprlandAPI::addNotification(PHANDLE, "hi", CHyprColor{1.0, 0.2, 0.2, 1.0},
                               5000);
}
APICALL EXPORT PLUGIN_DESCRIPTION_INFO PLUGIN_INIT(HANDLE handle) {
  PHANDLE = handle;

  static auto P =
      HyprlandAPI::registerCallbackDynamic(PHANDLE, "openWindow", &onNewWindow);

  const std::string COMPOSITOR_HASH = __hyprland_api_get_hash();
  const std::string CLIENT_HASH = __hyprland_api_get_client_hash();

  if (COMPOSITOR_HASH != CLIENT_HASH) {
    HyprlandAPI::addNotification(
        PHANDLE, "[MyPlugin] Mismatched headers! Can't proceed.",
        CHyprColor{1.0, 0.2, 0.2, 1.0}, 5000);
    throw std::runtime_error("[MyPlugin] Version mismatch");
  }

  return {"MyPlugin", "An amazing plugin that is going to change the world!",
          "Me", "1.1"};
}

APICALL EXPORT void PLUGIN_EXIT() {}
