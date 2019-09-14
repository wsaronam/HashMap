#include "HashMap.hpp"
#include "output.hpp"



void CreateCommand(HashMap* hm, std::string username, std::string password)
{
	if (hm->contains(username) == 1)
	{
		std::cout << "EXISTS" << std::endl;
	}

	else
	{
		hm->add(username, password);
		std::cout << "CREATED" << std::endl;
	}
}



void LoginCommand(HashMap* hm, std::string username, std::string password)
{
	if (hm->contains(username) == 1)
	{
		if (password == hm->value(username))
		{  std::cout << "SUCCEEDED" << std::endl;  }

		else
		{  std::cout << "FAILED" << std::endl;  }
	}

	else
	{  std::cout << "FAILED" << std::endl;  }
}



void RemoveCommand(HashMap* hm, std::string username)
{
	if (hm->contains(username) == 1)
	{
		hm->remove(username);
		std::cout << "REMOVED" << std::endl;
	}

	else
	{  std::cout << "NONEXISTANT" << std::endl;  }
}



void ClearCommand(HashMap* hm)
{
	delete hm;
	hm = new HashMap;
	std::cout << "CLEARED" << std::endl;
}



std::string DebugOnCommand(std::string status)
{
	if (status == "ON")
	{  
		std::cout << "ALREADY ON" << std::endl;  
		return status;
	}

	else
	{
		status = "ON";
		std::cout << "ON NOW" << std::endl;
		return status;
	}
}



std::string DebugOffCommand(std::string status)
{
	if (status == "ON")
	{  
		status = "OFF";
		std::cout << "OFF NOW" << std::endl;  
		return status;
	}

	else
	{
		std::cout << "ALREADY OFF" << std::endl;
		return status;
	}
}



void LoginCountCommand(HashMap* hm, std::string status)
{
	if (status == "ON")
	{
		std::cout << std::to_string(hm->size()) << std::endl;
	}

	else
	{
		std::cout << "INVALID" << std::endl;
	}
}



void BucketCountCommand(HashMap* hm, std::string status)
{
	if (status == "ON")
	{
		std::cout << std::to_string(hm->bucketCount()) << std::endl;
	}

	else
	{
		std::cout << "INVALID" << std::endl;
	}
}



void LoadFactorCommand(HashMap* hm, std::string status)
{
	if (status == "ON")
	{
		std::cout << std::to_string(hm->loadFactor()) << std::endl;
	}

	else
	{
		std::cout << "INVALID" << std::endl;
	}
}



void MaxBucketSizeCommand(HashMap* hm, std::string status)
{
	if (status == "ON")
	{
		std::cout << std::to_string(hm->maxBucketSize()) << std::endl;
	}

	else
	{
		std::cout << "INVALID" << std::endl;
	}
}



void GoodByeCommand(HashMap* hm)
{
	std::cout << "GOODBYE" << std::endl;
	delete hm;
}