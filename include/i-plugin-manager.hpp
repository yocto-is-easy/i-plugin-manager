#pragma once

#include <midf.hpp>

#include <string>

MIDF_DECL_PORT(plugin_manager, 25001);

MIDF_DECL_FUNC_NO_ARGS(std::vector<std::string>, plugin_manager, get_plugins_list);
MIDF_DECL_FUNC_NO_ARGS(std::vector<std::string>, plugin_manager, get_installed_plugins_list);

MIDF_DECL_FUNC(bool, plugin_manager, install, std::string);
MIDF_DECL_FUNC(bool, plugin_manager, uninstall, std::string);
MIDF_DECL_FUNC(bool, plugin_manager, enable, std::string);
MIDF_DECL_FUNC(bool, plugin_manager, disable, std::string);
MIDF_DECL_FUNC(bool, plugin_manager, is_installed, std::string);
MIDF_DECL_FUNC(bool, plugin_manager, is_enabled, std::string);
