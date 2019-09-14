#include "HashMap.hpp"
#include "output.hpp"




int main()
{
	std::string DEBUG = "OFF";
	std::string input = "";

	HashMap* hm = new HashMap;

	while (true)
	{
		std::string* answerArray = new std::string[3];

		std::string answer1 = "";
		std::string answer2 = "";
		std::string answer3 = "";

		getline(std::cin, input);
		std::stringstream ssin(input);

		for (int counter = 0; counter < 3; counter++)
		{
			ssin >> answerArray[counter];
		}

		answer1 = answerArray[0];
		answer2 = answerArray[1];
		answer3 = answerArray[2];


		if (answer1 == "CREATE" && answer2 != "" && answer3 != "")
		{
			CreateCommand(hm, answer2, answer3);
		}


		else if (answer1 == "LOGIN" && answer2 != "" && answer3 != "")
		{
			LoginCommand(hm, answer2, answer3);
		}

		else if (answer1 == "REMOVE" && answer2 != "")
		{
			RemoveCommand(hm, answer2);
		}


		else if (answer1 == "CLEAR")
		{
			ClearCommand(hm);
		}


		else if (answer1 == "QUIT")
		{
			GoodByeCommand(hm);
			delete[] answerArray;
			return 0;
		}


		else if (answer1 == "DEBUG" && answer2 == "ON")
		{
			DEBUG = DebugOnCommand(DEBUG);
		}


		else if (answer1 == "DEBUG" && answer2 == "OFF")
		{
			DEBUG = DebugOffCommand(DEBUG);
		}


		else if (answer1 == "LOGIN" && answer2 == "COUNT")
		{
			LoginCountCommand(hm, DEBUG);
		}

		else if (answer1 == "BUCKET" && answer2 == "COUNT")
		{
			BucketCountCommand(hm, DEBUG);
		}


		else if (answer1 == "LOAD" && answer2 == "FACTOR")
		{
			LoadFactorCommand(hm, DEBUG);
		}


		else if (answer1 == "MAX" && answer2 == "BUCKET" && answer3 == "SIZE")
		{
			MaxBucketSizeCommand(hm, DEBUG);
		}


		else
		{
			std::cout << "INVALID" << std::endl;
		}

		delete[] answerArray;

	}

}

