#pragma once

#include <midf.hpp>

#include <string>

MIDF_DECL_PORT(plugin_manager, 25001);

// interface for managing plugins
MIDF_DECL_FUNC_NO_ARGS(std::vector<std::string>, plugin_manager, get_plugins_list);
MIDF_DECL_FUNC_NO_ARGS(std::vector<std::string>, plugin_manager, get_installed_plugins_list);

MIDF_DECL_FUNC(bool, plugin_manager, install, std::string);
MIDF_DECL_FUNC(bool, plugin_manager, uninstall, std::string);
MIDF_DECL_FUNC(bool, plugin_manager, enable, std::string);
MIDF_DECL_FUNC(bool, plugin_manager, disable, std::string);
MIDF_DECL_FUNC(bool, plugin_manager, is_installed, std::string);
MIDF_DECL_FUNC(bool, plugin_manager, is_enabled, std::string);

// inteface for the plugins' initialization
/*
 * The plugin must register itself and its functions each time it starts.
 */
MIDF_DECL_FUNC(bool, plugin_manager, register_plugin, std::string /*name*/);
MIDF_DECL_FUNC(bool, plugin_manager, register_function,
    std::string /*plugin name*/,
    std::string /*function name*/,
    midf::function<std::string, std::string> /*the function*/,
    std::string /*function description*/);

MIDF_DECL_FUNC(bool, plugin_manager, unregister_plugin, std::string /*name*/);

// interface to interract with the plugins
MIDF_DECL_FUNC(std::string, plugin_manager, get_plugin_info, std::string /*plugin name*/);
MIDF_DECL_FUNC(std::string, plugin_manager, get_function_info,
    std::string /*plugin name*/,
    std::string /*function name*/);

using PluginFunction = midf::function<std::string, std::string>; // fix preprocessing error
MIDF_DECL_FUNC(PluginFunction, plugin_manager, get_function,
    std::string /*plugin name*/,
    std::string /*function name*/);

MIDF_DECL_FUNC(bool, plugin_manager, function_exists,
    std::string /*plugin name*/,
    std::string /*function name*/)
