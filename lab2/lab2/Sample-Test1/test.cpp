#include "pch.h"
#include "hashTable.h"

TEST(ConstrucorTest, Test1)
{
	HashTable a;
	ASSERT_NO_THROW(HashTable a);
	EXPECT_EQ(0, a.size());
	EXPECT_TRUE(a.empty());
}

struct HashTableTest : testing::Test
{
	HashTable* hashTable;

	HashTableTest()
	{
		hashTable = new HashTable;
	}
	~HashTableTest()
	{
		delete(hashTable);
	}
};

struct studentForTest
{
	std::string studentName;
	Student value;
};

struct ICETest : HashTableTest, testing::WithParamInterface<studentForTest>
{

};

TEST_P(ICETest, SimpleTest)
{
	auto as = GetParam();
	ASSERT_TRUE(hashTable->insert(as.studentName, as.value));
	ASSERT_TRUE(hashTable->contains(as.studentName));
	ASSERT_EQ(1,hashTable->size());
	ASSERT_FALSE(hashTable->insert(as.studentName, as.value));
	ASSERT_TRUE(hashTable->contains(as.studentName));
	ASSERT_TRUE(hashTable->erase(as.studentName));
	ASSERT_EQ(0, hashTable->size());
	ASSERT_FALSE(hashTable->contains(as.studentName));
	ASSERT_FALSE(hashTable->erase(as.studentName));
	ASSERT_TRUE(hashTable->insert(as.studentName, as.value));
	ASSERT_EQ(1, hashTable->size());
}

INSTANTIATE_TEST_CASE_P(Default, ICETest,
	testing::Values(
		studentForTest{ "Valera",{19,75} },
		studentForTest{ "Dasha",{19,45} },
		studentForTest{ "Vanya",{19,60} }
));

TEST_F(HashTableTest, SizeTest)
{
	ASSERT_TRUE(hashTable->insert("Valera", { 19,75 }));
	ASSERT_TRUE(hashTable->insert("Dasha", { 19,45 }));
	ASSERT_EQ(2, hashTable->size());
	ASSERT_TRUE(hashTable->insert("Vanya", { 19,60 }));
	ASSERT_EQ(3,hashTable->size());
}

TEST_F(HashTableTest, findingElementWithAtTest)
{
	Student student;
	ASSERT_TRUE(hashTable->insert("Valera", { 19,75 }));
	ASSERT_NO_THROW(student = hashTable->at("Valera"));
	EXPECT_EQ(19,student.age);
	EXPECT_EQ(75, student.weight);
	ASSERT_ANY_THROW(student = hashTable->at("valera"));
}

TEST_F(HashTableTest, findingDeletedElementWithAtTest)
{
	Student student;
	ASSERT_TRUE(hashTable->insert("Valera", { 19,75 }));
	hashTable->erase("Valera");
	ASSERT_ANY_THROW(student = hashTable->at("Valera"));
}

TEST_F(HashTableTest, CatTest)
{
	Student student;
	ASSERT_TRUE(hashTable->insert("Valera", { 19,75 }));
	ASSERT_NO_THROW(student = hashTable->at("Valera"));
	ASSERT_NO_THROW(student.age = 8);
	ASSERT_NO_THROW(student.weight = 9);
}

TEST_F(HashTableTest, ResizeTest)
{
	unsigned char c;
	std::string str;
	for (c = 0; c < 255; ++c)
	{
		str.push_back(c);
		ASSERT_TRUE(hashTable->insert(str, { 5,10 }));
	}
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}