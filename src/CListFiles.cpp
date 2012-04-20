#include "CListFiles.h"

std::vector<std::string>CListFiles::ListFiltredFiles(std::string dir, std::string extention){
  std::vector<std::string> retval;
  boost::filesystem::directory_iterator end_it;  
  boost::filesystem::path path = dir;
  
  try{
    if(boost::filesystem::exists(path) && boost::filesystem::is_directory(path)){
      for(boost::filesystem::directory_iterator dir_it(path); dir_it != end_it; ++dir_it){
        if(dir_it->path().extension() == extention){
          retval.push_back(dir_it->path().filename().string());
        }
      }
    }else{
      std::cout << "Does not exist..." << std::endl;
    }
  }catch(const boost::filesystem::filesystem_error& ex){
    std::cout << ex.what() << std::endl;
  }
  return retval;
}