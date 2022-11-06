#include "pch.h"
#include "CppUnitTest.h"
#include "..\DEC\DEC.cpp"
#include "..\DEC\NODE.h"
#include <random>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DeckTests
{
	TEST_CLASS(DeckTests)
	{
	public:

		TEST_METHOD(Default_constructor_successed)
		{
			Deck a;
			Assert::IsTrue(a.GetSize() == 0);
		}

		TEST_METHOD(PushLeft_successed)
		{
			Deck a;
			size_t size = 9;
			int LowLimit = -100;
			int HightLimit = 100;
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> distrib(LowLimit, HightLimit);
			for (size_t i = 0; i < size; i++)
			{
				int k = distrib(gen);
				a.PushLeft(k);
				Assert::IsTrue(a.PrintLeft() == k);
			}
		}

		TEST_METHOD(PushRight_successed)
		{
			Deck a;
			size_t size = 9;
			int LowLimit = -100;
			int HightLimit = 100;
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> distrib(LowLimit, HightLimit);
			for (size_t i = 0; i < size; i++)
			{
				int k = distrib(gen);
				a.PushRight(k);
				Assert::IsTrue(a.PrintRight() == k);
			}
		}

		TEST_METHOD(DeleteLeft_successed)
		{
			Deck a;
			int LowLimit = -100;
			int HightLimit = 100;
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> distrib(LowLimit, HightLimit);
			int k = distrib(gen);
			a.PushLeft(k);
			Assert::IsTrue(k == a.DeleteLeft());
		}

		TEST_METHOD(DeleteRight_successed)
		{
			Deck a;
			int LowLimit = -100;
			int HightLimit = 100;
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> distrib(LowLimit, HightLimit);
			int k = distrib(gen);
			a.PushRight(k);
			Assert::IsTrue(k == a.DeleteRight());
		}

		TEST_METHOD(GetSize_successed)
		{
			Deck a;
			int LowLimit = -100;
			int HightLimit = 100;
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> distrib(LowLimit, HightLimit);
			int k = distrib(gen);
			a.PushRight(k);
			Assert::IsTrue(a.GetSize() == 1);
		}

		TEST_METHOD(PrintLeft_successed)
		{
			Deck a;
			int LowLimit = -100;
			int HightLimit = 100;
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> distrib(LowLimit, HightLimit);
			int k = distrib(gen);
			a.PushLeft(k);
			Assert::IsTrue(k == a.PrintLeft());
		}

		TEST_METHOD(PrintRight_successed)
		{
			Deck a;
			int LowLimit = -100;
			int HightLimit = 100;
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> distrib(LowLimit, HightLimit);
			int k = distrib(gen);
			a.PushRight(k);
			Assert::IsTrue(k == a.PrintRight());
		}

		TEST_METHOD(ChangeLeft_successed)
		{
			Deck a;
			size_t size = 9;
			int LowLimit = -100;
			int HightLimit = 100;
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> distrib(LowLimit, HightLimit);
			int k = distrib(gen);
			a.PushLeft(k);
			k = distrib(gen);
			a.ChangeLeft(k);
			Assert::IsTrue(k == a.PrintLeft());
		}

		TEST_METHOD(ChangeRight_successed)
		{
			Deck a;
			int LowLimit = -100;
			int HightLimit = 100;
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> distrib(LowLimit, HightLimit);
			int k = distrib(gen);
			a.PushRight(k);
			k = distrib(gen);
			a.ChangeRight(k);
			Assert::IsTrue(k == a.PrintRight());
		}

		TEST_METHOD(Operator_successed)
		{
			Deck a;
			int LowLimit = -100;
			int HightLimit = 100;
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> distrib(LowLimit, HightLimit);
			int k = distrib(gen);
			a.PushLeft(k);
			std::stringstream temp;
			temp << k << " ";
			std::string tempStr = temp.str();
			std::stringstream out;
			out << a;
			Assert::IsTrue(tempStr == out.str());
		}
	};
}