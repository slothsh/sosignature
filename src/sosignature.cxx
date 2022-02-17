#include <fmt/core.h>
#include <cxxopts.hpp>
#include <string>
#include <string_view>
#include <cstdint>
#include <exception>

constexpr int MAJ_VER = 1;
constexpr int MIN_VER = 1;
constexpr int SUB_VER = 1;
constexpr std::string_view BUILD_DATE{ "17-feb-2022" };
constexpr std::string_view BUILD_YEAR{ "2022" };

template<typename T, std::size_t N>
constexpr std::size_t length(const T (&)[N])
{
    return N;
}

constexpr std::string_view SIGNATURE {
     "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⠿⠿⠿⠻⠿⢿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
     "⣿⣿⣿⣿⣿⣿⡿⠟⠉⠈⠉⠉⠄⢠⠄⠄⢀⠄⠄⡬⠛⢿⢿⣿⣿⣿⣿⣿⣿⣿\n"
     "⣿⣿⣿⡿⡿⠉⠄⠄⠄⠄⠄⠄⠅⠄⠅⠄⠐⠄⠄⠄⠁⠤⠄⠛⢿⢿⣿⣿⣿⣿\n"
     "⣿⣿⣿⠍⠄⠄⠄⠄⠄⠄⠄⠄⣀⣀⠄⣀⣠⣀⠄⢈⣑⣢⣤⡄⠔⠫⢻⣿⣿⣿\n"
     "⣿⡏⠂⠄⠄⢀⣠⣤⣤⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣮⣔⠂⡙⣿⣿\n"
     "⡿⠄⠄⣠⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣈⣿\n"
     "⠇⠄⢠⣿⣿⣿⣿⣿⡿⠿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠿⠿⢿⡿⣿⣿⣿⣿⣿⡧⣼\n"
     "⠄⠄⠽⠿⠟⠋⠁⠙⠄⢠⣿⡿⢿⣿⣿⣿⣿⣿⣷⡠⢌⣧⠄⠈⠛⠉⠛⠐⡋⢹\n"
     "⠄⠄⠄⠄⠄⠄⠄⢀⣠⣾⡿⠑⠚⠋⠛⠛⠻⢿⣿⣿⣶⣤⡄⢀⣀⣀⡀⠈⠄⢸\n"
     "⣄⠄⠄⠄⢰⣾⠟⠋⠛⠛⠂⠄⠄⠄⠄⠒⠂⠛⡿⢟⠻⠃⠄⢼⣿⣿⣷⠤⠁⢸\n"
     "⣿⡄⠄⢀⢝⢓⠄⠄⠄⠄⠄⠄⠄⠄⠠⠠⠶⢺⣿⣯⣵⣦⣴⣿⣿⣿⣿⡏⠄⢸\n"
     "⣿⣿⡀⠄⠈⠄⠄⠄⠠⢾⣷⣄⢄⣀⡈⡀⠠⣾⣿⣿⣿⣿⣿⣿⣿⡿⠿⢏⣀⣾\n"
     "⣿⣿⣷⣄⠄⠄⠄⢀⠈⠈⠙⠑⠗⠙⠙⠛⠄⠈⠹⠻⢿⡻⣿⠿⢿⣝⡑⢫⣾⣿\n"
     "⣿⣿⣿⣿⣿⣆⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠑⠐⠚⣨⣤⣾⣿⣿\n"
     "⣿⣿⣿⣿⣿⣿⣿ STEFAN OLIVIER ⣿⣿⣿⣿⣿⣿⣿\n"
     "⣿⣿⣿⣿ Friendly ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
     "⣿⣿⣿⣿⣿⣿⣿ Neighbourhood ⣿⣿⣿⣿⣿⣿⣿⣿\n"
     "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ Sloth ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
};

inline void signature()
{
    fmt::print("\n{}\n\n", reinterpret_cast<const char*>(SIGNATURE.data()));
    return;
}

inline void version_info()
{
    fmt::print(
        "version: {}.{}.{}\n"
        "built on: {}\n"
        "Copyright {} (C) Stefan Oliver\n"
        "MIT License: <https://mit-license.org/>\n"
        "This is free software: you are free to change and redistribute it.\n"
        "There is NO WARRANTY, to the extent permitted by law.\n\n"
        "{}\n\n"
        "Written by Stefan Olivier\n"
        "<https://stefanolivier.com>\n",
        MAJ_VER, MIN_VER, SUB_VER, BUILD_DATE, BUILD_YEAR, reinterpret_cast<const char*>(SIGNATURE.data())
    );

    return;
}

int main(int argc, char** argv)
{
    cxxopts::Options opts("Stefan Olivier Signature", "Prints Stefan Olivier's signature terminal art");
    opts.allow_unrecognised_options();
    opts.add_options()
        ("v,version", "Print version info")
        ("h,help", "Print usage");
    
    try {
        const auto results = opts.parse(argc, argv);

        if (results.count("h")) {
            fmt::print("{}\n", opts.help());
            return EXIT_SUCCESS;
        }

        if (results.count("v")) {
            version_info();
            return EXIT_SUCCESS;
        }

        signature();

    } catch (std::exception& e) {
        fmt::print("{}", e.what());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
