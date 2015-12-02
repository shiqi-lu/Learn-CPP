#include <windows.h>

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>

#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

namespace fs = boost::filesystem;

int main(int argc, char * argv[])
{
    if (argc != 4) {
        std::cerr << "Usage: distfile.exe nodenumber dayudir localfile" << std::endl;
        exit(1);
    }

    try {
        // test all the parameters
        int node_nums;
        node_nums = boost::lexical_cast<int>(std::string(argv[1]));

        fs::path dayu_dir = argv[2];
        fs::path local_file = argv[3];

        if (!fs::exists(dayu_dir)) {
            std::cerr << "ERROR: dayudir does not exists" << std::endl;
            exit(1);
        }
        /*
        if (!fs::exists(fs::canonical(local_file).parent_path())) {
            std::cerr << "ERROR:" 
                      << fs::canonical(local_file).parent_path().string() 
                      << " does not exists" << std::endl;
            exit(1);
        }*/

        // iterator all the file in dayu_dir to file_list
        std::vector<std::string> file_list;
        fs::path index_dir = dayu_dir / "dayu_iterator_index";
        fs::directory_iterator end;
        std::string tmp_string;
        for (fs::directory_iterator pos(dayu_dir); pos != end; ++pos) {
            if (fs::is_regular_file(*pos)) {
                tmp_string = fs::canonical(pos->path()).string();
                boost::replace_all(tmp_string, "/", "\\");
                file_list.push_back(tmp_string);
            }
        }

        // create index_dir
        if (!fs::exists(index_dir)) {
            fs::create_directories(index_dir);
        }

        // output the file_list to the local_file
        int div = file_list.size() / node_nums;
        int mod = file_list.size() % node_nums;
        for (int i = 0; i < node_nums; ++i) {
            std::string idx = "index" + boost::lexical_cast<std::string>(i);
            if (fs::exists(idx)) {
                Sleep(100);
                continue;
            }
            if (!fs::create_directories(index_dir / idx)) {
                Sleep(100);
                continue;
            }

            // open local file
            std::ofstream output(local_file.string().c_str(), std::ios::trunc);
            if (!output.is_open()) {
                std::cerr << "ERROR: can not open " << local_file.string()
                          << std::endl;
                exit(1);
            }

            // output certain files to local_file in the file_list
            if (i == node_nums - 1 && mod != 0) {
                std::copy(file_list.begin() + i * div,
                          file_list.end(),
                          std::ostream_iterator<std::string>(output, "\n"));
            } else {
                std::copy(file_list.begin() + i * div,
                          file_list.begin() + (i+1) * div,
                          std::ostream_iterator<std::string>(output, "\n"));
            }

            output.close();
            break;
        }
    } catch (const fs::filesystem_error & e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        exit(1);
    } catch (const std::exception & e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        exit(1);
    }

    return 0;
}
