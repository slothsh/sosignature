#include <fmt/core.h>
#include <fmt/format.h>
#include <cxxopts.hpp>
#include <stdlib.h>
#include <string>
#include <string_view>
#include <utility>
#include <cstdint>
#include <exception>
#include <locale>

constexpr int MAJ_VER = 1;
constexpr int MIN_VER = 0;
constexpr int SUB_VER = 0;
constexpr std::string_view BUILD_DATE{ "16-feb-2022" };

template<typename T, std::size_t N>
constexpr std::size_t length(const T (&)[N])
{
    return N;
}

constexpr char SIGNATURE[] = {
    "+++++++ STEFAN OLIVIER +++++++\n"
    "++++ Friendly ++++++++++++++++\n"
    "+++++++ Neighbourhood ++++++++\n"
    "+++++++++++++ Sloth ++++++++++"
};

constexpr std::size_t SIGNATURE_SIZE{ length(SIGNATURE) };

inline void signature()
{
    fmt::print("\n{}\n\n", SIGNATURE);
    return;
}

inline void version_info()
{
    fmt::print(
        "version: {}.{}.{}\n"
        "built on: {}\n\n"
        "{}\n\n"
        "Stefan Olivier Signature\n"
        "Always be kind\n",
        MAJ_VER, MIN_VER, SUB_VER, BUILD_DATE, SIGNATURE
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
