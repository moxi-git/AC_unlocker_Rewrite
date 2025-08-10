#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <string>

namespace fs = std::filesystem;

// Simulate embedded collider.kn5 data as a byte array
// (In reality, you’d load from a resource or embed via compiler-specific method)
const std::vector<uint8_t> colliderData = {
    // Put your actual binary data here if you want to embed it,
    // or load from a file on disk if embedding is too complex for now.
};

int main() {
    std::cout << "Assetto Corsa DLC Unlocker Rewritten\nCode on: https://github.com/moxi-git/AC_unlocker_Rewrite\n\n";

    std::cout << "Default root folder: 'C:/Program Files (x86)/Steam/steamapps/common/assettocorsa/content'\n";
    std::cout << "(leave empty to use the default one)\n\n";

    std::cout << "Enter the file path: ";
    std::string path;
    std::getline(std::cin, path);

    if (path.empty()) {
        path = R"(C:\Program Files (x86)\Steam\steamapps\common\assettocorsa\content)";
    }

    try {
        path = fs::absolute(fs::path(path)).string();
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error resolving the path: " << e.what() << "\n";
        return 1;
    }

    std::cout << "\nRoot folder set to: " << path << "\n";

    fs::path carsPath = fs::path(path) / "cars";
    std::cout << "\nReading files in the cars folder...\n";

    std::error_code ec;
    auto dirIter = fs::directory_iterator(carsPath, ec);
    if (ec) {
        std::cerr << "Error reading directory: " << ec.message() << "\n";
        return 1;
    }

    std::string errMessage =
        "Make sure the game is closed and the file path is correct.\n\n"
        "If the problem persists report it on https://github.com/moxi-git/AC_unlocker_Rewrite/issues\n\n";

    std::cout << "\nDoing the magic...\n";

    for (auto& entry : dirIter) {
        if (entry.is_directory()) {
            fs::path colliderFile = entry.path() / "collider.kn5";
            std::ofstream outFile(colliderFile, std::ios::binary);
            if (!outFile) {
                std::cerr << "Something went wrong while creating the new collider file: " << colliderFile << "\n" << errMessage;
                return 1;
            }

            // Write embedded data to file
            outFile.write(reinterpret_cast<const char*>(colliderData.data()), colliderData.size());
            if (!outFile) {
                std::cerr << "Something went wrong while writing the collider file: " << colliderFile << "\n" << errMessage;
                return 1;
            }
        }
    }

    std::cout << "Done, enjoy :)\n\np.s give it a star\n";
    std::cout << "Press ENTER to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return 0;
}
