//  MIT License
//
//  Copyright (c) 2019 Marc Fyrbiak
//  Copyright (c) 2019 Sebastian Wallat
//  Copyright (c) 2019 Max Hoffmann
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.

#include "pragma_once.h"
#ifndef __HAL_INTERFACE_BASE_H__
#define __HAL_INTERFACE_BASE_H__

#include "def.h"

#include "core/log.h"

#include <set>
#include <string>

/**
 * Enum for all possible plugin types
 */
enum class interface_type : u32
{
    base = 0,
    cli,
    interactive_ui,
    gui
};

/**
 * @ingroup core
 */
class CORE_API i_base
{
public:
    i_base()          = default;
    virtual ~i_base() = default;

    /**
     * Get the name of the plugin.
     *
     * @returns Plugin name.
     */
    virtual std::string get_name() = 0;

    /**
     * Get the version of the plugin.
     *
     * @returns Plugin version.
     */
    virtual std::string get_version() = 0;

    /**
     * Get the plugin types.
     *
     * @returns Set of types.
     */
    virtual std::set<interface_type> get_type();

    /**
     * This function is automatically executed when the plugin is loaded by the plugin manager
     */
    virtual void on_load();

    /**
     * This function is automatically executed when the plugin is unloaded by the plugin manager
     */
    virtual void on_unload();

    /**
     * Initializes the logging channel(s) of a plugin. <br>
     * If not overwritten, a logging channel equal to the plugin name is created.
     */
    virtual void initialize_logging();

    /**
     * Shorthand for fast text logging.
     *
     * @param[in] args - The format string, followed by values.
     */
    template<typename... Args>
    inline void log(const Args&... args)
    {
        log_info(get_name(), args...);
    }
};

#endif /* __HAL_INTERFACE_BASE_H__ */