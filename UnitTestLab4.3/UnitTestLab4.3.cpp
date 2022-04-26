#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab4.3/Lab4.3.cpp"
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab43
{
	TEST_CLASS(UnitTestLab43)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char f[6] = "f.dat";
			PrintTXT(f);
	
			//int t = SearchTXT(f,"369045");
			//Assert::AreEqual(t, -1);
		}
	};
}
