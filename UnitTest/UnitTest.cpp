#include "pch.h"
#include "CppUnitTest.h"
#include "../Algoritm.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::vector<std::string> text{"aaaabbbbCcc" };
			std::map<std::string, unsigned> chars{ {"a",0},{"b",0},{"c",0},{"C",0} };
			CharCountAlghoritm(&chars, text);
			Assert::IsTrue(chars["a"]==4);
			Assert::IsTrue(chars["b"] == 4);
			Assert::IsTrue(chars["c"] == 2);
			Assert::IsFalse(chars["C"] == 5);
		}
		TEST_METHOD(TestMethod2)
		{
			std::vector<std::string> text{ "testTEST","dddd"};
			std::map<std::string, unsigned> chars{ { "t", 0 }, { "e",0 }, { "s",0 }, { "t",0 } };
			CharCountAlghoritm(&chars, text);
			Assert::IsTrue(chars["t"] == 2);
			Assert::IsTrue(chars["e"] == 1);
			Assert::IsTrue(chars["s"] == 1);
			Assert::IsFalse(chars["s"] == 2);
		}
		TEST_METHOD(TestMethod3)
		{
			std::vector<std::string> text{ "pointPOINT","aaaa"};
			std::map<std::string, unsigned> chars{ {"p",0},{"o",0},{"i",0},{"n",0},{"t",0},{"a",0} };
			CharCountAlghoritm(&chars, text);
			Assert::IsTrue(chars["p"] == 1);
			Assert::IsTrue(chars["o"] == 1);
			Assert::IsTrue(chars["i"] == 1);
			Assert::IsTrue(chars["n"] == 1);
			Assert::IsTrue(chars["t"] == 1);
			Assert::IsFalse(chars["a"] == 5);
		}
		TEST_METHOD(TestMethod4)
		{
			std::vector<std::string> text{ "23344455556666677" };
			std::map<std::string, unsigned> chars{ { "2", 0 }, { "3",0 }, { "4",0 }, { "5",0 },{ "6",0 },{ "7",0 } };
			CharCountAlghoritm(&chars, text);
			Assert::IsTrue(chars["2"] == 1);
			Assert::IsTrue(chars["3"] == 2);
			Assert::IsTrue(chars["4"] == 3);
			Assert::IsTrue(chars["5"] == 4);
			Assert::IsTrue(chars["6"] == 5);
			Assert::IsTrue(chars["7"] == 2);
		}
		TEST_METHOD(TestMethod5)
		{
			std::vector<std::string> text{ "aaavvv" }; 
			std::map<std::string, unsigned> chars{ {"a",0},{"v",0},{"c",0}};
			CharCountAlghoritm(&chars, text);
			Assert::IsTrue(chars["a"] == 3);
			Assert::IsTrue(chars["v"] == 3);
			Assert::IsTrue(chars["c"] == 0);
		}
	};
}
