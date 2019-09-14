// HashMapTests.cpp
//
// ICS 45C Fall 2016
// Project #3: Maps and Legends
//
// Write unit tests for your HashMap class here.  I've provided one test already,
// though I've commented it out, because it won't compile until you've implemented
// three things: the HashMap constructor, the HashMap destructor, and HashMap's
// size() member function.

#include <gtest/gtest.h>
#include <typeinfo>

#include "HashMap.hpp"


TEST(TestHashMap, sizeOfNewlyCreatedHashMapIsZero)
{
    HashMap empty;
    ASSERT_EQ(0, empty.size());
}



TEST(TestHashMap, bucketCountOfNewlyCreatedHashMapIsInitialBucketCount)
{
	HashMap empty;
	ASSERT_EQ(10, empty.bucketCount());
}



TEST(TestHashMap, maxBucketCountOfNewlyCreatedHashMapIsZero)
{
	HashMap empty;
	ASSERT_EQ(0, empty.maxBucketSize());
}



TEST(TestHashMap, loadFactorOfNewlyCreatedHashMapIsZero)
{
	HashMap empty;
	ASSERT_EQ(0, empty.loadFactor());
}



TEST(TestHashMap, canCopyHashMapUsingCopyConstructor)
{
	HashMap empty;
	HashMap other{empty};
}



TEST(TestHashMap, canCopyHashMapUsingAssignmentOperator)
{
	HashMap empty;
	HashMap other = empty;
}



TEST(TestHashMap, canAddOneThingToAHashMap)
{
	HashMap hm;
	hm.add("Billy Joe", "bj");
}



TEST(TestHashMap, canAddMultipleThingsToAHashMap)
{
	HashMap hm;
	hm.add("Billy Joe", "bj");
	hm.add("How is it cool?", "Because it is?");
	hm.add("Forever 21", "is a nice store.");
	hm.add("Alex Thornton", "is really cool guy!");
	hm.add("Boo Thornton", "is cooler, though.");
	hm.add("Jack", "is the best");
	hm.add("Frogs", "have different colors!");
	hm.add("wsaronam", "80408898");
	hm.add("what", "Swag");
	hm.add("almost there", "not really");
	hm.add("Please have", "mercy on my grade");
	hm.remove("what");
}



TEST(TestHashMap, containMethodWorksForHashMap)
{
	HashMap hm;
	hm.add("Billy Joe", "bj");
	hm.add("How is it cool?", "Because it is?");
	hm.add("Forever 21", "is a nice store.");
	hm.add("Alex Thornton", "is really cool guy!");
	hm.add("Boo Thornton", "is cooler, though.");
	hm.add("Jack", "is the best");
	hm.add("Frogs", "have different colors!");
	hm.add("wsaronam", "80408898");
	hm.add("what", "Swag");
	hm.add("almost there", "not really");
	hm.add("Please have", "mercy on my grade");

	hm.contains("Frogs");

}



TEST(TestHashMap, sizeOfHashMapWorksCorrectly)
{
	HashMap hm;

	hm.add("Billy Joe", "bj");
	ASSERT_EQ(1, hm.size());

	hm.add("How is it cool?", "Because it is?");
	ASSERT_EQ(2, hm.size());

	hm.add("Forever 21", "is a nice store.");
	ASSERT_EQ(3, hm.size());

	hm.add("Alex Thornton", "is really cool guy!");
	ASSERT_EQ(4, hm.size());
}



TEST(TestHashMap, valueOfHashMapWorksCorrectly)
{
	HashMap hm;
	hm.add("Billy Joe", "bj");
	hm.add("How is it cool?", "Because it is?");
	hm.add("Forever 21", "is a nice store.");
	hm.add("Alex Thornton", "is really cool guy!");
	hm.add("Boo Thornton", "is cooler, though.");
	hm.add("Jack", "is the best");
	hm.add("Frogs", "have different colors!");
	hm.add("wsaronam", "80408898");
	hm.add("what", "Swag");
	hm.add("almost there", "not really");
	hm.add("Please have", "mercy on my grade");

	std::string value = hm.value("almost there");

	ASSERT_EQ("not really", value);
}



TEST(TestHashMap, bucketCountOfHashMapWorksCorrectly)
{
	HashMap hm;
	hm.add("Billy Joe", "bj");
	hm.add("How is it cool?", "Because it is?");
	hm.add("Forever 21", "is a nice store.");
	hm.add("Alex Thornton", "is really cool guy!");
	hm.add("Boo Thornton", "is cooler, though.");
	hm.add("Jack", "is the best");
	hm.add("Frogs", "have different colors!");
	hm.add("wsaronam", "80408898");
	hm.add("what", "Swag");
	hm.add("almost there", "not really");
	hm.add("Please have", "mercy on my grade");

	unsigned int size = hm.bucketCount();

	ASSERT_EQ(21, size);
}



TEST(TestHashMap, loadFactorOfHashMapWorksCorrectly)
{
	HashMap hm;
	hm.add("Billy Joe", "bj");
	hm.add("How is it cool?", "Because it is?");
	hm.add("Forever 21", "is a nice store.");
	hm.add("Alex Thornton", "is really cool guy!");
	hm.add("Boo Thornton", "is cooler, though.");
	hm.add("Jack", "is the best");
	hm.add("Frogs", "have different colors!");
	hm.add("wsaronam", "80408898");
	hm.add("what", "Swag");
	hm.add("almost there", "not really");
	hm.add("Please have", "mercy on my grade");

	ASSERT_EQ(0.52381, hm.loadFactor());
}



TEST(TestHashMap, maxBuketSizeOfHashMapsWorks)
{
	HashMap hm;
	hm.add("Billy Joe", "bj");
	hm.add("How is it cool?", "Because it is?");
	hm.add("Forever 21", "is a nice store.");
	hm.add("Alex Thornton", "is really cool guy!");
	hm.add("Boo Thornton", "is cooler, though.");
	hm.add("Jack", "is the best");
	hm.add("Frogs", "have different colors!");
	hm.add("wsaronam", "80408898");
	hm.add("what", "Swag");
	hm.add("almost there", "not really");
	hm.add("Please have", "mercy on my grade");
	hm.maxBucketSize();
}



TEST(TestHashMap, canRemoveThingsFromAHashMap)
{
	HashMap hm;
	hm.add("Billy Joe", "bj");
	hm.add("How is it cool?", "Because it is?");
	hm.add("Forever 21", "is a nice store.");
	hm.add("Alex Thornton", "is really cool guy!");
	hm.add("Boo Thornton", "is cooler, though.");
	hm.add("Jack", "is the best");
	hm.add("Frogs", "have different colors!");
	hm.add("wsaronam", "80408898");
	hm.add("what", "Swag");
	hm.add("almost there", "not really");
	hm.add("Please have", "mercy on my grade");
	hm.remove("How is it cool?");
	hm.remove("wsaronam");
	hm.remove("Please have");
}
