#include "python-binding/plugin_python_shell.h"

#include "core/program_arguments.h"
#include "core/utils.h"
#include "def.h"

#include <Python.h>
#include <cstring>

std::string plugin_python_shell::get_name()
{
    return std::string("python shell");
}

std::string plugin_python_shell::get_version()
{
    return std::string("0.1");
}

std::set<interface_type> plugin_python_shell::get_type()
{
    std::set<interface_type> types = {interface_type::base, interface_type::interactive_ui};
    return types;
}

bool plugin_python_shell::exec(program_arguments& args)
{
    int argc;
    const char** argv;

    args.get_original_arguments(&argc, &argv);

    /* copy command line interface options */
    int argc_new       = argc - 1;
    wchar_t** argv_new = (wchar_t**)std::malloc((argc_new) * sizeof(wchar_t*));

    /* pass all parameters to python shell */
    for (int i = 0; i < argc_new; i++)
    {
        argv_new[i] = (wchar_t*)std::malloc((std::strlen(argv[i + 1]) + 1) * sizeof(wchar_t));
        std::mbstowcs(argv_new[i], argv[i + 1], std::strlen(argv[i + 1]) + 1);
    }

    // initiliaze python shell
    Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString(std::string("sys.path.append(\"" + core_utils::get_library_directory().string() + "\")").c_str());
    PyRun_SimpleString("from hal_py import *");
    //    PyRun_SimpleString(g = hal_py.hdl_parser_dispatcher().parse('XILINX_ISE_SIMPRIM', 'VHDL', '../test_designs/aes128_fast.vhd'));
    Py_Main(argc_new, argv_new);
    Py_Finalize();

    /* cleanup of copied command line interface options */
    for (int j = 0; j < argc_new; ++j)
        std::free(argv_new[j]);
    std::free(argv_new);
    return 0;
}
