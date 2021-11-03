#include "pch.h"
#include "hashTable.h"

TEST(ConstrucorTest, Test1)
{
	HashTable a;
	ASSERT_NO_THROW(HashTable a);
	EXPECT_FALSE(a.size());
	EXPECT_TRUE(a.empty());
}

struct HashTableTest : testing::Test
{
	HashTable* hashTable;
	std::string studentName1 = "Valera";
	std::string studentName2 = "valera";
	std::string studentName3 = "Vanya";
	std::string studentName4 = "Dasha";
	unsigned age1 = 19, weight1 = 75;
	unsigned age2 = 10, weight2 = 40;
	Student value1 = { age1, weight1 };
	Student value2 = { age2, weight2 };
	std::string studentName;
	Student student;

	HashTableTest()
	{
		hashTable = new HashTable;
	}
	~HashTableTest()
	{
		delete(hashTable);
	}
};

TEST_F(HashTableTest, ICETest)
{
	ASSERT_TRUE(hashTable->insert(studentName1, value1));
	ASSERT_TRUE(hashTable->contains(studentName1));
	ASSERT_EQ(1,hashTable->size());
	ASSERT_FALSE(hashTable->insert(studentName1, value1));
	ASSERT_TRUE(hashTable->contains(studentName1));
	ASSERT_TRUE(hashTable->erase(studentName1));
	ASSERT_EQ(0, hashTable->size());
	ASSERT_FALSE(hashTable->contains(studentName1));
	ASSERT_FALSE(hashTable->erase(studentName1));
	ASSERT_TRUE(hashTable->insert(studentName1, value1));
	ASSERT_EQ(1, hashTable->size());
}

TEST_F(HashTableTest, SizeTest)
{
	ASSERT_TRUE(hashTable->insert(studentName1,value1));
	ASSERT_TRUE(hashTable->insert(studentName2, value1));
	ASSERT_EQ(2, hashTable->size());
	ASSERT_TRUE(hashTable->insert(studentName3, value1));
	ASSERT_EQ(3,hashTable->size());
}

TEST_F(HashTableTest, AtAndCatSimpleTest)
{
	ASSERT_TRUE(hashTable->insert(studentName1, value1));
	ASSERT_TRUE(hashTable->insert(studentName2, value2));
	ASSERT_NO_THROW(student = hashTable->at(studentName1));
	EXPECT_EQ(age1,student.age);
	EXPECT_EQ(weight1, student.weight);
	ASSERT_NO_THROW(student = hashTable->at(studentName2));
	EXPECT_EQ(age2, student.age);
	EXPECT_EQ(weight2, student.weight);
	ASSERT_NO_THROW(student = hashTable->cat(studentName1));
	EXPECT_EQ(age1, student.age);
	EXPECT_EQ(weight1, student.weight);
	ASSERT_NO_THROW(student = hashTable->cat(studentName2));
	EXPECT_EQ(age2, student.age);
	EXPECT_EQ(weight2, student.weight);
}

TEST_F(HashTableTest, AtAndCatExceptionTest)
{
	ASSERT_ANY_THROW(hashTable->at(studentName1));
	ASSERT_ANY_THROW(hashTable->cat(studentName1));
}

TEST_F(HashTableTest, OperatorSquareBracketsTest)
{
	ASSERT_TRUE(hashTable->insert(studentName1, value1));
	ASSERT_TRUE(hashTable->insert(studentName2, value2));
	ASSERT_NO_THROW(student = (*hashTable)[studentName1]);
	EXPECT_EQ(age1, student.age);
	EXPECT_EQ(weight1, student.weight);
	ASSERT_NO_THROW(student = (*hashTable)[studentName2]);
	EXPECT_EQ(age2, student.age);
	EXPECT_EQ(weight2, student.weight);
}

TEST_F(HashTableTest, OperatorSquareCreateElementTest)
{
	ASSERT_NO_THROW((*hashTable)[studentName1]);
	ASSERT_NO_THROW((*hashTable)[studentName2]);
	ASSERT_NO_THROW(hashTable->at(studentName1));
	ASSERT_NO_THROW(hashTable->at(studentName2));
}

TEST_F(HashTableTest, findingDeletedElementWithAtAndCatTest)
{
	ASSERT_TRUE(hashTable->insert(studentName1, value1));
	hashTable->erase(studentName1);
	ASSERT_ANY_THROW(student = hashTable->cat(studentName1));
	ASSERT_ANY_THROW(student = hashTable->at(studentName1));
}

TEST_F(HashTableTest, ResizeTest)
{
	unsigned char c;
	for (c = 0; c < 255; ++c)
	{
		studentName.push_back(c);
		ASSERT_TRUE(hashTable->insert(studentName,value1));
	}
	ASSERT_EQ(255, hashTable->size());
}

TEST_F(HashTableTest, RehashTest)
{
	unsigned char c;
	for (c = 0; c < 5; ++c)
	{
		studentName.push_back(c);
		ASSERT_TRUE(hashTable->insert(studentName, value1));
	}
	studentName.erase();
	for (c = 0; c < 3; ++c)
	{
		studentName.push_back(c);
		ASSERT_TRUE(hashTable->erase(studentName));
	}
	ASSERT_EQ(2, hashTable->size());
	for (c = 3; c < 5; ++c)
	{
		studentName.push_back(c);
		ASSERT_FALSE(hashTable->insert(studentName,value1));
	}
	studentName.erase();
	for (c = 5; c < 255; ++c)
	{
		studentName.push_back(c);
		ASSERT_TRUE(hashTable->insert(studentName, value1));
	}
	ASSERT_EQ(252, hashTable->size());
}

TEST_F(HashTableTest, CopyConstructorAndEqualityTest1)
{
	HashTable hashTable2 = *hashTable;
	EXPECT_TRUE(*hashTable == hashTable2);
	EXPECT_FALSE(*hashTable != hashTable2);
	hashTable2.insert(studentName1, value1);
	EXPECT_FALSE(*hashTable == hashTable2);
	EXPECT_TRUE(*hashTable != hashTable2);
	hashTable->insert(studentName1, value1);
	EXPECT_TRUE(*hashTable == hashTable2);
	EXPECT_FALSE(*hashTable != hashTable2);
	hashTable2.erase(studentName1);
	EXPECT_FALSE(*hashTable == hashTable2);
	EXPECT_TRUE(*hashTable != hashTable2);
	hashTable->erase(studentName1);
	EXPECT_TRUE(*hashTable == hashTable2);
	EXPECT_FALSE(*hashTable != hashTable2);
}

TEST_F(HashTableTest, CopyConstructorAndEqualityTest2)
{
	HashTable hashTable2 = *hashTable;
	hashTable2.insert(studentName1, value1);
	hashTable->insert(studentName1, value2);
	EXPECT_FALSE(*hashTable == hashTable2);
	EXPECT_TRUE(*hashTable != hashTable2);
}

TEST_F(HashTableTest, AssignmentOperatorandEqualityTest)
{
	HashTable hashTable2;
	hashTable2 = *hashTable;
	EXPECT_TRUE(*hashTable == hashTable2);
	EXPECT_FALSE(*hashTable != hashTable2);
	hashTable2.insert(studentName1, value1);
	EXPECT_FALSE(*hashTable == hashTable2);
	EXPECT_TRUE(*hashTable != hashTable2);
	hashTable->insert(studentName1, value1);
	EXPECT_TRUE(*hashTable == hashTable2);
	EXPECT_FALSE(*hashTable != hashTable2);
	hashTable2.erase(studentName1);
	EXPECT_FALSE(*hashTable == hashTable2);
	EXPECT_TRUE(*hashTable != hashTable2);
	hashTable->erase(studentName1);
	EXPECT_TRUE(*hashTable == hashTable2);
	EXPECT_FALSE(*hashTable != hashTable2);
}

TEST_F(HashTableTest, MoveConstructorTest)
{
	hashTable->insert(studentName1, value1);
	HashTable hashTable2 = std::move(*hashTable);
	ASSERT_TRUE(hashTable2.size());
	ASSERT_TRUE(hashTable->empty());
	ASSERT_TRUE(hashTable2.contains(studentName1));
}

TEST_F(HashTableTest, MoveAssignmentOperatorTest)
{
	hashTable->insert(studentName1, value1);
	HashTable hashTable2;
	hashTable2 = std::move(*hashTable);
	ASSERT_TRUE(hashTable2.size());
	ASSERT_TRUE(hashTable->empty());
	ASSERT_TRUE(hashTable2.contains(studentName1));
}

TEST_F(HashTableTest, SwapTest)
{
	hashTable->insert(studentName1, value1);
	HashTable hashTable2;
	hashTable2.insert(studentName1, value1);
	hashTable2.insert(studentName2, value1);
	hashTable2.swap(*hashTable);
	ASSERT_EQ(1, hashTable2.size());
	ASSERT_EQ(2, hashTable->size());
	ASSERT_TRUE(hashTable2.contains(studentName1));
	ASSERT_TRUE(hashTable->contains(studentName1));
	ASSERT_FALSE(hashTable2.contains(studentName2));
	ASSERT_TRUE(hashTable->contains(studentName2));
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}