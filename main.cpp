#include <hyprland/src/plugins/PluginAPI.hpp>

inline HANDLE PHANDLE = nullptr;

APICALL EXPORT std::string PLUGIN_API_VERSION() { return HYPRLAND_API_VERSION; }

APICALL EXPORT PLUGIN_DESCRIPTION_INFO PLUGIN_INIT(HANDLE handle) {
  PHANDLE = handle;

  const std::string COMPOSITOR_HASH = __hyprland_api_get_hash();
  const std::string CLIENT_HASH = __hyprland_api_get_client_hash();

  if (COMPOSITOR_HASH != CLIENT_HASH) {
    HyprlandAPI::addNotification(
        PHANDLE, "[MyPlugin] Mismatched headers! Can't proceed.",
        CHyprColor{1.0, 0.2, 0.2, 1.0}, 5000);
    throw std::runtime_error("[MyPlugin] Version mismatch");
  }

  return {"MyPlugin", "An amazing plugin that is going to change the world!",
          "Me", "1.0"};
}

APICALL EXPORT void PLUGIN_EXIT() {}
