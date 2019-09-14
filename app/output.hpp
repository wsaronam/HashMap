#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include "HashMap.hpp"



void CreateCommand(HashMap* hm, std::string username, std::string password);
void LoginCommand(HashMap* hm, std::string username, std::string password);
void RemoveCommand(HashMap* hm, std::string username);
void ClearCommand(HashMap* hm);
void GoodByeCommand(HashMap* hm);

std::string DebugOnCommand(std::string status);
std::string DebugOffCommand(std::string status);
void LoginCountCommand(HashMap* hm, std::string status);
void BucketCountCommand(HashMap* hm, std::string status);
void LoadFactorCommand(HashMap* hm, std::string status);
void MaxBucketSizeCommand(HashMap* hm, std::string status);




#endif	// OUTPUT_HPP